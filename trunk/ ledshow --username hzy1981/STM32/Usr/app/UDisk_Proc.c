#define UDISK_PROC_C
#include "Includes.h"
#include "FILE_SYS.H"

void UDisk_Init(void)
{
 INT8U Re;

  Unselect_SPI_Device();

  SPI1_CH376_Init();
  Delay_ms(100);
  //SET_CH376_CS(0);	//选中CH376
  Re = mInitCH376Host();
  if(Re != USB_INT_SUCCESS)
  {
    ASSERT_FAILED();
  }

  //SET_CH376_CS(1);	//不选中CH376
}


void Set_UDisk_Status(INT8U Status)
{
  Screen_Status.UDisk_Flag = Status;
}

INT8U Chk_UDisk_Processing(void)
{
   if(Screen_Status.UDisk_Flag EQ UDISK_ING) //当前有U盘插入，并且正在处理状态
     return 1;
   else
     return 0;

	/*
   //当前没有在U盘处理状态中
   if(Query376Interrupt() EQ TRUE)
   {
     //Set_UDisk_Status(UDISK_ING);
	 Screen_Status.UDisk_Flag = UDISK_ING;
     return 1;
   }
   else
   {
     Screen_Status.UDisk_Flag = UDISK_NULL;
     return 0;
	 }
   	  */
}
     
void UDisk_Proc(void)
{
    //static S_Int8U Flag = {CHK_BYTE, 0, CHK_BYTE};
    INT8U Re;
	INT8U Counts;
    INT16U RealCount,len;
	unsigned char buf[30];

    //if(Screen_Status.UDisk_Flag != UDISK_ING) //当前有U盘中断需要处理
	  //return;

	if(Query376Interrupt() EQ FALSE)//再次确认中断信号
	{
      Set_UDisk_Status(UDISK_NULL);
	  return;
	 }
    
	Set_UDisk_Status(UDISK_ING); 

	Set_RT_Show_Area(0, 0, 32, 16);
	RT_Play_Status_Enter(2);
	
    Unselect_SPI_Device();
	SPI1_CH376_Init();
	
	    Counts = 0;
		//while(!=USB_INT_SUCCESS) //SPI软件查询是否有U盘插入
 		do
		{
		  Re = CH376DiskConnect();
		  if(Re EQ USB_INT_DISCONNECT || Re EQ ERR_DISK_DISCON) //U盘被拔出
		  {
            Set_UDisk_Status(UDISK_NULL);
		    goto UDiskProcEnd;
		  }
					  
		  Counts++;
		  if(Counts >= 20)
		  {
            Set_UDisk_Status(UDISK_NULL);
		    goto UDiskProcEnd;
		   }
		   
		   Delay_ms(100);	   
		 }while(Re != USB_INT_SUCCESS);
		 
		Delay_ms(200);

		Counts = 0;
 		while(Counts <= 100)//for ( i = 0; i < 100; i ++ ) {  /* 最长等待时间,100*50mS */
	    {
			Re = CH376DiskMount( );  /* 初始化磁盘并测试磁盘是否就绪 */
			if ( Re == USB_INT_SUCCESS ) 
			   break;  /* 准备好 */
			else if ( Re == ERR_DISK_DISCON ) 
			{
			  /* 检测到断开,重新检测并计时 */
			   Set_UDisk_Status(UDISK_NULL);
		       goto UDiskProcEnd;
			}

			if ( CH376GetDiskStatus( ) >= DEF_DISK_MOUNTED && Counts >= 5 ) 
			    break;  /* 有的U盘总是返回未准备好,不过可以忽略,只要其建立连接MOUNTED且尝试5*50mS */
		    
		    Delay_ms(50);
			Counts ++;
		}

  		if ( CH376GetDiskStatus( ) < DEF_DISK_MOUNTED )/* 未知USB设备,例如USB键盘、打印机等 */ 
		{  
			//RT_LED_Print(FONT0, 0x01, 0, 0, 3, "err4");
			LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "err4");
			Set_UDisk_Status(UDISK_NULL);
			goto UDiskProcEnd;
		}

		if(CH376DiskMount()==USB_INT_SUCCESS) //磁盘就绪?
		{
			//strcpy((char *)buf, "\\led_data\\");
			//itoa(Screen_Para.COM_Para.Addr, buf + 10, 10); //文件名是板地址,找不到文件则以广播地址读
			//sprintf(buf, (const char *)"\\%d.dat", Screen_Para.COM_Para.Addr);
			strcpy((char *)buf, "\\LEDDATA\\0.DAT");
			if(CH376FileOpenPath(buf)!=USB_INT_SUCCESS)
			{
			  strcpy((char *)buf, "\\LEDDATA\\65536.DAT");

			  if(CH376FileOpenPath(buf)!=USB_INT_SUCCESS) //找不到文件则以广播地址读
			  {
			    Set_UDisk_Status(UDISK_NULL);
			    //RT_LED_Print(FONT0, 0x01, 0, 0, 3, "err0");
			    LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "err0");
				goto UDiskProcEnd;
			  }
			}

 			while(1)
			{
			    Set_Screen_Com_Time(1); //到计时1秒后重新播放节目

				CH376ByteRead((INT8U *)RCV_DATA_BUF, FLEN + 2, &RealCount );
                if(RealCount EQ 0)
				{
  				  //RT_LED_Print(FONT0, 0x01, 0, 0, 3, "ok");
				  LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "ok");
				  break;
				}
			    else if(RealCount != FLEN + 2)
				{
				  //Screen_Status.UDisk_Flag = UDISK_END; //处理完毕
				  //RT_LED_Print(FONT0, 0x01, 0, 0, 3, "err1");
				  LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "err1");
				  break;
				}

                memcpy(&len, (INT8U *)RCV_DATA_BUF + FLEN, 2);
				if(len <= sizeof(RCV_DATA_BUF) && len > FLEN + 2)
				{
				  CH376ByteRead((INT8U *)RCV_DATA_BUF + FLEN + 2, len - (FLEN + 2), &RealCount );
		          if(RealCount EQ len - (FLEN + 2) && Check_Frame_Format((INT8U *)RCV_DATA_BUF, len))
		          {

				    Re = Rcv_Frame_Proc(CH_UDISK, (INT8U *)RCV_DATA_BUF, len, sizeof(RCV_DATA_BUF)); 
                    
					Unselect_SPI_Device();
	                SPI1_CH376_Init();
					
					if(Re EQ 0)
					{
					  //Screen_Status.UDisk_Flag = UDISK_END; //处理完毕
					  ASSERT_FAILED();
					  //RT_LED_Print(FONT0, 0x01, 0, 0, 3, "err2");
					  LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "err2");
					  break;
					} 
		          }
		        }
				else
				{
				      //Screen_Status.UDisk_Flag = UDISK_END; //处理完毕
   					  ASSERT_FAILED();
					  //RT_LED_Print(FONT0, 0x01, 0, 0, 3, "err3");
					  LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "err3");
					  break;
				}
		    }

		CH376FileClose(FALSE);
	    Set_UDisk_Status(UDISK_NULL);
	}

UDiskProcEnd:
	Restore_Show_Area();
}
