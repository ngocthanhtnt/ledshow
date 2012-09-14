#define NET_PROC_C
#include "Includes.h"

#if NET_EN
void Net_Init(void)
{
  Unselect_SPI_Device();
  init_TcpNet ();
}

void Net_Proc(void)
{
  static INT32U ms100Timer = 0xFFFFFFFF;

  if(ms100Timer != Pub_Timer.Ms100)
  {
    ms100Timer = Pub_Timer.Ms100;
    timer_tick();		  
  }

  Unselect_SPI_Device();								//Provide timer tick
  main_TcpNet ();								//Call the TCPnet library
}
#endif

