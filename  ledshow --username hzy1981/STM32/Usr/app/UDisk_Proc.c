#define UDISK_PROC_C
#include "Includes.h"
#ifdef CHIP_USB_HOST
#include "ff.h"
#endif

#if UDISK_EN
#define UDISK_RT_PLAY_TIME 5

//FATFS fatfs;
//FIL file;

//extern esint8 efs_init(EmbeddedFileSystem * efs,eint8* opts);
/**
  ******************************************************************************
  * @file    command.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    22/07/2011
  * @brief   This file provides all the IAP command functions.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
//#include "command.h"

/** @addtogroup USBH_USER
  * @{
  */

/** @defgroup IAP_OVER_USB_COMMAND
  * @brief
  * @{
  */


/* External variables --------------------------------------------------------*/
//extern uint8_t CMD_index;
//extern uint8_t joystick_use;
/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
//Download_FileTypeDef Download_File [9];
#ifdef CHIP_USB_HOST
#ifdef USB_OTG_HS_INTERNAL_DMA_ENABLED
  #if defined ( __ICCARM__ ) /*!< IAR Compiler */
    #pragma data_alignment=4   
  #endif
#endif /* USB_OTG_HS_INTERNAL_DMA_ENABLED */
__ALIGN_BEGIN USB_OTG_CORE_HANDLE      USB_OTG_Core __ALIGN_END;

#ifdef USB_OTG_HS_INTERNAL_DMA_ENABLED
  #if defined ( __ICCARM__ ) /*!< IAR Compiler */
    #pragma data_alignment=4   
  #endif
#endif /* USB_OTG_HS_INTERNAL_DMA_ENABLED */
__ALIGN_BEGIN USBH_HOST                USB_Host __ALIGN_END;
#endif

void UDisk_Init(void)
{
#ifdef CHIP_USB_HOST
  USBH_Init(&USB_OTG_Core, 
#ifdef USE_USB_OTG_FS  
            USB_OTG_FS_CORE_ID,
#else 
            USB_OTG_HS_CORE_ID,
#endif 
            &USB_Host,
            &USBH_MSC_cb, 
            (USBH_Usr_cb_TypeDef *)&USR_cb);
#else
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
#endif
  //SET_CH376_CS(1);	//不选中CH376
}


void Set_UDisk_Status(INT8U Status)
{
  Screen_Status.UDisk_Flag = Status;
}

INT8U Chk_UDisk_Processing(void)
{
#if UDISK_EN
   if(Screen_Status.UDisk_Flag EQ UDISK_ING) //当前有U盘插入，并且正在处理状态
     return 1;
   else
     return 0;
#else
   return 0;
#endif
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
#ifdef CHIP_USB_HOST

    USBH_Process(&USB_OTG_Core, &USB_Host);

    if(UDisk_Res_Flag.Var != UDISK_RES_NO)
    {
	  Set_Screen_Com_Time(0); //参数0该函数保证扫描中断不停
	  Set_RT_Show_Area(0, 0, 64, 16);
 	  RT_Play_Status_Enter(3);
	  Clr_All_Show_Data();

	  debug("rt play time = 3\r\n");
	  		 
      if(UDisk_Res_Flag.Var EQ UDISK_RES_OK)
		LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "OK");
	  else
		LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "ERR%d", UDisk_Res_Flag.Var - 1);

	  UDisk_Res_Flag.Var = UDISK_RES_NO;
	 }

	 if(UDisk_Disc_Flag.Var EQ 0xAA)
	 {
	  UDisk_Disc_Flag.Var = 0;
	 }
    
#else
    //static S_Int8U Flag = {CHK_BYTE, 0, CHK_BYTE};
    volatile static INT8U Re;
	INT8U Counts;
    INT16U RealCount,len;
	unsigned char buf[30];
	char reStr[10];
    //if(Screen_Status.UDisk_Flag != UDISK_ING) //当前有U盘中断需要处理
	  //return;

	if(Query376Interrupt() EQ FALSE)//再次确认中断信号
	{
      Set_UDisk_Status(UDISK_NULL);
	  return;
	 }
    
	Set_UDisk_Status(UDISK_ING); 

    Unselect_SPI_Device();
	SPI1_CH376_Init();
	
	    Counts = 0;
		//while(!=USB_INT_SUCCESS) //SPI软件查询是否有U盘插入
 		do
		{
		  Re = CH376DiskConnect();
		  if(Re EQ USB_INT_DISCONNECT || Re EQ ERR_DISK_DISCON) //U盘被拔出
		  {
		    //RT_Play_Status_Exit(); //退出实时显示状态

            Set_UDisk_Status(UDISK_NULL);
		    //goto UDiskProcEnd;
			return;
		  }
					  
		  Counts++;
		  if(Counts >= 20)
		  {
            Set_UDisk_Status(UDISK_NULL);
		    return;//goto UDiskProcEnd;
		   }
		   
		   Delay_ms(100);	   
		 }while(Re != USB_INT_SUCCESS);
		 
		Delay_ms(200);

		Counts = 0;
 		while(Counts <= 10)//for ( i = 0; i < 100; i ++ ) {  /* 最长等待时间,100*50mS */
	    {
			Re = CH376DiskMount( );  /* 初始化磁盘并测试磁盘是否就绪 */
			if ( Re == USB_INT_SUCCESS ) 
			   break;  /* 准备好 */
			else if ( Re == ERR_DISK_DISCON ) 
			{
			  /* 检测到断开,重新检测并计时 */
			   Set_UDisk_Status(UDISK_NULL);
		       return;//goto UDiskProcEnd;
			}

			if ( CH376GetDiskStatus( ) >= DEF_DISK_MOUNTED && Counts >= 5 ) 
			    break;  /* 有的U盘总是返回未准备好,不过可以忽略,只要其建立连接MOUNTED且尝试5*50mS */
		    
		    Delay_ms(50);
			Counts ++;
		}

  		if ( CH376GetDiskStatus( ) < DEF_DISK_MOUNTED )/* 未知USB设备,例如USB键盘、打印机等 */ 
		{ 
			//Clr_All_Show_Data();
			//LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "ERR4");
			strcpy(reStr, "ERR4");
			Set_UDisk_Status(UDISK_NULL);
			goto UDiskProcEnd;
		}

		if(CH376DiskMount()==USB_INT_SUCCESS) //磁盘就绪?
		{
			//strcpy((char *)buf, "\\led_data\\");
			//itoa(Screen_Para.COM_Para.Addr, buf + 10, 10); //文件名是板地址,找不到文件则以广播地址读
			//sprintf(buf, (const char *)"\\%d.dat", Screen_Para.COM_Para.Addr);
			//strcpy((char *)buf, "\\LEDDATA\\0.DAT");
			sprintf((char *)buf, "\\LEDDATA\\%d.DAT", Screen_Para.COM_Para.Addr);
			Re = CH376FileOpenPath(buf);
			//LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "%d", Re);
			if(Re != USB_INT_SUCCESS)
			{
			  strcpy((char *)buf, "\\LEDDATA\\65535.DAT");
			  Re = CH376FileOpenPath(buf);
			  if(Re != USB_INT_SUCCESS) //找不到文件则以广播地址读
			  {
			    Set_UDisk_Status(UDISK_NULL);
			    //Clr_All_Show_Data();
			    strcpy(reStr, "ERR0");//LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "ERR0");
				goto UDiskProcEnd;
			  }
			}
			/*
			Set_Screen_Com_Time(0); //到计时0秒后重新播放节目
			Set_RT_Show_Area(0, 0, 64, 16);
			RT_Play_Status_Enter(500);
			Clr_All_Show_Data();

			LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "Updating");
			*/
 			while(1)
			{
			    Clr_Watch_Dog();
			    //Set_Screen_Com_Time(0); //到计时0秒后重新播放节目

				CH376ByteRead((INT8U *)RCV_DATA_BUF, FLEN + 2, &RealCount );
                if(RealCount EQ 0)
				{
  				  //Clr_All_Show_Data();
				  strcpy(reStr, "OK");//LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "OK");
				  break;
				}
			    else if(RealCount != FLEN + 2)
				{
				  //Screen_Status.UDisk_Flag = UDISK_END; //处理完毕
				  //Clr_All_Show_Data();
				  strcpy(reStr, "ERR1");//LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "ERR1");
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
					  //Clr_All_Show_Data();
					  strcpy(reStr, "ERR2 ");//LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "ERR2");
					  reStr[4] = Screen_Status.Com_Err_Flag + '0';
					  break;
					} 
		          }
		        }
				else
				{
				      //Screen_Status.UDisk_Flag = UDISK_END; //处理完毕
   					  ASSERT_FAILED();
					  //Clr_All_Show_Data();
					  strcpy(reStr, "ERR3");//LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "ERR3");
					  break;
				}
		    }


		CH376FileClose(FALSE);
	    
	}
	else
	{
	  ASSERT_FAILED();
	  //Clr_All_Show_Data();
	  strcpy(reStr, "ERR5");//LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "ERR5");
	}
	
UDiskProcEnd:
	
	Set_Screen_Com_Time(0); //到计时0秒后重新播放节目
	Set_RT_Show_Area(0, 0, 64, 16);
	RT_Play_Status_Enter(3);
	Clr_All_Show_Data();

	LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, reStr);
	Restore_Show_Area();//此处可以restore

	Set_UDisk_Status(UDISK_NULL);

#endif
}

#ifdef CHIP_USB_HOST
FATFS fatfs;
FIL file;

void Update_From_UDisk(void)
{
  unsigned char buf[20];
  FRESULT fRe;
  INT32U RealCount;
  INT16U len;
  INT8U Re;

	/* Initialises the File System*/
	if ( f_mount( 0, &fatfs ) != FR_OK ) 
	{
	  /* efs initialisation fails*/
	  debug("> Cannot initialize File System.\n");
	  return;
	}

	Set_UDisk_Status(UDISK_ING);

	sprintf((char *)buf, "/LEDDATA/%d.dat", Screen_Para.COM_Para.Addr);
	
	if(f_open(&file, (const XCHAR *)buf, FA_OPEN_EXISTING | FA_READ) != 0)
	{
	  if(f_open(&file, (const XCHAR *)"/LEDDATA/65535.dat", FA_OPEN_EXISTING | FA_READ) != 0)
	  {
		UDisk_Res_Flag.Var = 1;
		goto UDiskProcEnd;
	  }
	}

	while (1)
	{
	    Clr_Watch_Dog();
	    //读取字节数
	    fRe = f_read(&file, (INT8U *)RCV_DATA_BUF, FLEN + 2, &RealCount);
        
		if(fRe EQ FR_OK && RealCount EQ 0)
		{
		  //Clr_All_Show_Data();
		  //strcpy(reStr, "OK");//LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "OK");
		  UDisk_Res_Flag.Var = UDISK_RES_OK;
		  break;
		}
	    else if(RealCount != FLEN + 2)
		{
		  //Clr_All_Show_Data();
		  //strcpy(reStr, "ERR1");//LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "ERR1");
		  UDisk_Res_Flag.Var = 2;
		  break;
		}

        memcpy(&len, (INT8U *)RCV_DATA_BUF + FLEN, 2);
		if(len <= sizeof(RCV_DATA_BUF) && len > FLEN + 2)
		{
		  Clr_Watch_Dog();
		  fRe = f_read(&file, (INT8U *)RCV_DATA_BUF + FLEN + 2, len - (FLEN + 2), &RealCount);
          if(fRe EQ FR_OK && RealCount EQ len - (FLEN + 2) && Check_Frame_Format((INT8U *)RCV_DATA_BUF, len))
          {
			Clr_Watch_Dog();
		    Re = Rcv_Frame_Proc(CH_UDISK, (INT8U *)RCV_DATA_BUF, len, sizeof(RCV_DATA_BUF)); 
			
			if(Re EQ 0)
			{
			  //Screen_Status.UDisk_Flag = UDISK_END; //处理完毕
			  ASSERT_FAILED();
			  //Clr_All_Show_Data();
			  //strcpy(reStr, "ERR2");//LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "ERR2");
			  UDisk_Res_Flag.Var = 21 +  Screen_Status.Com_Err_Flag;
			  break;
			}
		}
	  }
	  else
	  {
		  ASSERT_FAILED();
		  //Clr_All_Show_Data();
		  //strcpy(reStr, "ERR3");//LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "ERR3");
		  UDisk_Res_Flag.Var = 4;
		  break;
	  }
	 }

     f_close(&file);

UDiskProcEnd:
	f_mount(0, NULL);
	Set_UDisk_Status(UDISK_END);
}
#endif
#endif

/*******************(C)COPYRIGHT 2011 STMicroelectronics *****END OF FILE******/
