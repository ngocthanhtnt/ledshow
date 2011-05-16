#define UDISK_PROC_C
#include "Includes.h"

void UDisk_Init(void)
{
  INT8U i=mInitCH376Host();
}


 //char *itoa(int value,char *string,int radix)

void UDisk_Proc(void)
{
    static S_Int8U Flag = {CHK_BYTE, 0, CHK_BYTE};
    INT8U Re,Re1;
    INT16U RealCount,i,len;
	unsigned char buf[30];

	if(CH376DiskConnect()==USB_INT_SUCCESS) //是否有U盘插入
	{
	    if(Flag.Var EQ 1)
		  return;

		Flag.Var = 1; //当前U盘已经处理过了
	    SPI_CH376_Init();  //重新初始化SPI口

		if(CH376DiskMount()==USB_INT_SUCCESS) //磁盘就绪?
		{
			//strcpy((char *)buf, "\\led_data\\");
			//itoa(Screen_Para.COM_Para.Addr, buf + 10, 10); //文件名是板地址,找不到文件则以广播地址读
			sprintf(buf, "\\led_data\\%d.dat");
			if(CH376FileOpen(buf)!=USB_INT_SUCCESS)
			{
			  sprintf(buf, "\\led_data\\65536.dat");

			  if(CH376FileOpen(buf)!=USB_INT_SUCCESS) //找不到文件则以广播地址读
			  {
			    RT_LED_Print(FONT0, 0x01, 0, 0, 3, "err0");
			    return;
			  }
			}

 			while(1)
			{
				CH376ByteRead(Screen_Status.Rcv_Data, FLEN + 2, &RealCount );
				if(RealCount != FLEN + 2)
				{
				  RT_LED_Print(FONT0, 0x01, 0, 0, 3, "err1");
				  return;
				}

                memcpy(&len, Screen_Status.Rcv_Data + FLEN, 2);
				if(len <= sizeof(Screen_Status.Rcv_Data) && len > FLEN + 2)
				{
				  CH376ByteRead(Screen_Status.Rcv_Data + FLEN + 2, len - (FLEN + 2), &RealCount );
		          if(RealCount EQ len - (FLEN + 2) && Check_Frame_Format((INT8U *)Screen_Status.Rcv_Data, len))
		          {
				    Re1 = Rcv_Frame_Proc(CH_UDISK, Screen_Status.Rcv_Data, len); 
                    if(Re1 EQ 0)
					{
					  ASSERT_FAILED();
					  RT_LED_Print(FONT0, 0x01, 0, 0, 3, "err2");
					  return;
					} 
		          }
		        }
				else
				{
   					  ASSERT_FAILED();
					  RT_LED_Print(FONT0, 0x01, 0, 0, 3, "err3");
					  return;
				}
		    }
	     }
	}
	else
	{
	  Flag.Var = 0;
	}

}
