#define UDISK_PROC_C
#include "Includes.h"

void UDisk_Init(void)
{
  INT8U i=mInitCH376Host();
}

void UDisk_Proc(void)
{
    INT16U RealCount,i;
	unsigned char buf[10];

	if(CH376DiskConnect()==USB_INT_SUCCESS)
	{
	    SPI_CH376_Init();  //重新初始化SPI口

		if(CH376DiskMount()==USB_INT_SUCCESS)
		{
			strcpy((char *)buf, "\CH376.TXT" );
			if(CH376FileOpen(buf)==USB_INT_SUCCESS)
			{
				for(i=0;i<30;i++)
					buf[i]=0;
				CH376ByteRead( buf, 30, &RealCount );

			}
		}
	}

}
