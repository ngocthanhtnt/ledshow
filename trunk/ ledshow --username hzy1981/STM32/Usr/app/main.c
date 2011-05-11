#include "Includes.h"

int main(void)
{ 
  Hardware_Init();

  Para_Init(); //参数初始化

  Com_Init(); //初始化串口

#if UDISK_EN  
  UDisk_Init(); //U盘初始化
#endif

#if NET_EN
  Net_Init(); //网络初始化
#endif

  Self_Test(); //自检操作
  
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
