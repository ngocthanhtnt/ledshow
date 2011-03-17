#define OS_SHELL_C
#include "OS_Includes.h"

#if OS_SHELL_EN > 0

#define OS_SHELL_MAX_PARA_NUM 5 //最多支持5个命令参数
//入口参数表示是否打开
void OS_Shell_Init(OS_INT8U Bg_Print_Flag)
{
  if(Bg_Print_Flag != 0)
    OS_Shell_Status.Bg_Print_Flag = BG_PRINT_ON; //后台进程打印开启
  else
    OS_Shell_Status.Bg_Print_Flag = BG_PRINT_OFF;
  
  OS_Shell_Status.Shell_Flag = SHELL_OUT; //初始状态不在Shell中
  OS_Shell_Status.Shell_Task_ID = 0; //shell运行的任务ID
  OS_SET_STRUCT_HT(OS_Shell_Status);
}

//检查当前是否在后台状态运行，返回1表示是，0表示不是
//该函数内部不能有可能引起断言的或者直接调试输出的函数,否则可能嵌套
OS_INT8U OS_Check_Bg_Status(void)
{
  OS_INT8U Task_ID;
  
  Task_ID = Task_Info.Cur_Task_ID;//OS_Get_Cur_Task_ID();
  
  if(OS_Shell_Status.Shell_Flag EQ SHELL_IN &&\
     OS_Shell_Status.Shell_Task_ID EQ Task_ID)
    return 0;
  else
    return 1;
}

//检查后台打印是否开启，返回0表示关闭，1表示打开
//该函数内部不能有可能引起断言的或者直接调试输出的函数,否则可能嵌套
OS_INT8U OS_Check_Bg_Print_En(void)
{
  if(OS_Shell_Status.Bg_Print_Flag EQ BG_PRINT_OFF)
    return 0;
  else
    return 1;
}

//设置后台打印标志，0表示关闭后台打印，只保留shell的打印，1表示打开后台打印
void OS_Set_Bg_Print_Flag(OS_INT8U Flag)
{
  if(Flag EQ 0)
    OS_Shell_Status.Bg_Print_Flag = BG_PRINT_OFF;
  else
    OS_Shell_Status.Bg_Print_Flag = BG_PRINT_ON;
}

//命令分析
OS_INT8U OS_Cmd_Analys(CONST S_OS_Shell_Cmd Shell_Cmd[], OS_INT8U Num, OS_INT8S Cmd[], OS_INT8U Len)
{
  OS_INT8U i, j, Re;
  OS_INT8S *(Argv[OS_SHELL_MAX_PARA_NUM]);
  OS_INT8U Argc, Cmd_Len;
  
  Cmd_Len = 0;
  for(i = 0; i < Len; i ++)
  {
    if(Cmd[i] EQ '\r')//找到回车符,说明已经输入了一条完整命令
    {
      Cmd[i] = '\0';
      Cmd_Len = i; //记录命令长度
      break;
    }
    else if(Cmd[i] EQ ' ') //空格全部替换成'\0'
      Cmd[i] = '\0';
  }
  
  if(i EQ Len) //没有找到命令
    return 0;

  OS_Shell_Status.Shell_Flag = SHELL_IN; //进入shell状态
  OS_Shell_Status.Shell_Task_ID = OS_Get_Cur_Task_ID(); //当前运行shell任务的ID
  
  if(Cmd_Len EQ 0) //全部输入的是空格或者回车
  {
    OS_Debug_Print("\nOS_Shell:"); //提示输入新的命令
    OS_Shell_Status.Shell_Flag = SHELL_OUT; //退出shell状态
    return 1;
  }
  
  Re = OS_CHECK_STRUCT_HT(OS_Shell_Status); //检查壳状态的头尾信息
  if(Re EQ 0)
    OS_ASSERT_FAILED();
  
  for(i = 0; i < Num; i ++)
  {
    if(strcmp(Shell_Cmd[i].pName, Cmd) != 0)
      continue;
    
    j = (OS_INT8U)strlen(Cmd);
    Argc = 0;
    while(j < Cmd_Len)
    {
      if(Cmd[j] EQ '\0' && Cmd[j + 1] != '\0') //前一个是空格，后一个非空格，说明是一个新参数
      {
        if(Argc < OS_SHELL_MAX_PARA_NUM)
        {
          Argv[Argc] = &Cmd[j + 1];
          Argc++;
        }
        else
        {
          OS_ASSERT_FAILED();
          break;
        }
      }
      
      j++;
    }

    OS_Debug_Print("\n");    
    (*Shell_Cmd[i].pCmdFunc)(Argc,Argv); 
    OS_Debug_Print("\r\n");    
    break;  
  }
  
  if(i EQ Num)
    OS_Debug_Print("\r\nCmd Error!\r\n");
  
  OS_Debug_Print("\r\nOS_Shell:"); //提示输入新的命令
  OS_Shell_Status.Shell_Flag = SHELL_OUT; //退出shell状态 
  return 1;
}
#endif

#undef OS_SHELL_C
