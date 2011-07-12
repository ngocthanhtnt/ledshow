#include "Includes.h"

 void test()
 {
        int i; 
        unsigned char t1[8]={0x24,0x21,0xf0,0x7f,0x80,0x37,0xff,0x1f}; 
        unsigned char t2[8]; 

        transpose8(t1, t2);  

		for(i = 0; i < 8; i	++)
		  printf("%d = %x", i, t2[i]);

 }

int main(void)
{ 
  Hardware_Init();

  test();

  RST_Periph();

  Para_Init(); //参数初始化

  Com_Init(); //初始化串口

#if UDISK_EN  
  UDisk_Init(); //U盘初始化
#endif

#if NET_EN
  Net_Init(); //网络初始化
#endif

  DS1302_Init(); //启动后1s再初始化DS1302，手册要求

  Fac_Status_Self_Test(); //自检操作
  
  Para_Show(); //上电参数显示

  while(1)
  {
#if SHELL_EN
    Shell_Proc();
#endif

    Show_Main_Proc();

#if UDISK_EN
    UDisk_Proc(); //u盘处理
#endif
#if NET_EN
	Net_Proc();
#endif
  }
  
}
