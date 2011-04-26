#include "Includes.h"

int main(void)
{ 
  Hardware_Init();
  //while(1);
  Show_Timer_Proc();
  while(1)
  {
    Shell_Proc();
    Show_Main_Proc();
  }
  
}
