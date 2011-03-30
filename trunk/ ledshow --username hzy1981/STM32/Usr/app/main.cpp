#include "Includes.h"

int main()
{
  Show_Timer_Proc();
  while(1)
  {
    Shell_Proc();
    Show_Main_Proc();
  }
}
