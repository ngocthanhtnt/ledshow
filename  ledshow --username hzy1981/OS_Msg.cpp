#define OS_MSG_C
#include "OS_Includes.h"

#if OS_MSG_EN>0
//消息初始化,消息的ID由应用程序自己固定
//Val为消息的初始值，1表示资源被占用，0表示资源已释放
//创建成功返回1，失败返回0
OS_INT8U OS_Msg_Init(OS_INT8U ID)
{
  if(ID>=OS_EVENT_NUM)
  {
    OS_ASSERT_FAILED();
    return 0;
  }

  OS_Event[ID].Type=OS_MSG;
  
#if OS_CS_EN>0
  OS_SET_STRUCT_SUM(OS_Event[ID]);//设置校验和
#endif

  OS_SET_STRUCT_HT(OS_Event[ID]);  
  return 1; 
}

/*
//等待某消息为空,即没有消息在等待接收,Time_Out为超时时间，单位ms,0为永远等待知道消息为空，>0为超时时间
//返回0表示等待超时，1表示消息已为空
OS_INT8U OS_Msg_Wait_Free(OS_INT8U ID,OS_INT16U Time_Out)
{
  OS_INT16U Counts;
  
  if(Time_Out!=0)
  {
    OS_Core_Wait_Ms(OS_Event[ID].Rcv_Flag EQ 0,Time_Out);//等待所有任务都开始接收数据
    if(OS_Event[ID].Rcv_Flag!=0)
      return 0;
    else
      return 1;
  }
  
  Counts=0;
  while(1)
  {
    OS_Core_Wait_Sec(OS_Event[ID].Rcv_Flag EQ 0,OS_MSG_WAIT_WARN_TIME);
    if(OS_Event[ID].Rcv_Flag!=0)
    {
      Counts++;
      OS_Debug_Print("\r\nOS:Task %d wait msg %d free time out,Rcv_Flag=%x,Counts=%d",\
                         Task_Info.Cur_Task_ID,ID,OS_Event[ID].Rcv_Flag,Counts);        
    }
    else
      break;
  }
  return 1;
}

//发送某消息,马上返回,不等待其他任务接收完成,调用该函数前先调用OS_Msg_Wait_Free确保消息已经为空,因此这两个函数是成对使用的
OS_INT8U OS_Msg_Send_NoWait(OS_INT8U ID,OS_INT16U Val,void *pMsg,OS_INT8U Rcv_Flag)
{
#if OS_CS_EN>0
  if(OS_CHECK_STRUCT_SUM(OS_Event[ID]) EQ 0)
    OS_ASSERT_FAILED();
#endif
  
  if(ID>=OS_EVENT_NUM)
  {
    OS_ASSERT_FAILED();
    return 0;
  }

  if(OS_Event[ID].Type!=OS_MSG)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
  
  //判断消息是否为空，不为空则返回错误
  if(OS_Event[ID].Rcv_Flag!=0)
  {
    OS_ASSERT_FAILED();
    return 0;    
  }
  
  //将消息信息填入OS_Event中
  OS_Event[ID].Value=Val;
  OS_Event[ID].pData=pMsg;
  OS_Event[ID].Rcv_Flag=Rcv_Flag;
  
#if OS_CS_EN>0  
  OS_SET_STRUCT_SUM(OS_Event[ID]);
#endif
  
  return 1;  
}
*/

//发送消息,成功返回1，失败返回0
//ID表示消息的ID
//Val表示消息的值，用户自定义其意义
//*pMsg表示指向消息的指针
//Rcv_Flag表示接收该消息的指针,第N位为1表示第N号任务接收该消息
//Time_Out表示等待这么多毫秒，还没有任务接收消息的话，超时返回
//返回1表示消息发送成功，0表示失败
OS_INT8U OS_Msg_Send(OS_INT8U ID,OS_INT16U Val,void *pMsg,OS_INT8U Rcv_Flag,OS_INT16U Time_Out)
{
  OS_INT16U Counts;
  
  if(Time_Out!=0)
  {
    OS_Core_Wait_Ms(OS_Event[ID].Rcv_Flag EQ 0,Time_Out);//等待所有任务都开始接收数据
    if(OS_Event[ID].Rcv_Flag!=0)
      return 0;
  }
  else//无限时等待知道该消息为空
  {
    Counts=0;
    while(1)
    {
      OS_Core_Wait_Sec(OS_Event[ID].Rcv_Flag EQ 0,OS_MSG_WAIT_WARN_TIME);
      if(OS_Event[ID].Rcv_Flag!=0)
      {
        Counts++;
        OS_Debug_Print("\r\nOS:Task %d wait msg %d free time out,Rcv_Flag=%x,Counts=%d",\
                           Task_Info.Cur_Task_ID,ID,OS_Event[ID].Rcv_Flag,Counts);        
      }
      else
        break;
    }
  }
  
  //将消息信息填入OS_Event中
  OS_Event[ID].Value=Val;
  OS_Event[ID].pData=pMsg;
  OS_Event[ID].Rcv_Flag=Rcv_Flag;
  
#if OS_CS_EN>0  
  OS_SET_STRUCT_SUM(OS_Event[ID]);
#endif
  
  return 1; 
}

//申请消息开始,成功返回1，失败返回0或者不返回,该函数必须和OS_Msg_Rcv_End成对使用
//在OS_Msg_Rcv_Start和OS_Msg_Rcv_End两个函数运行过程中,消息发送函数不能再往这个消息上ID上发消息
//从而保护该消息不会被新消息覆盖
OS_INT8U OS_Msg_Rcv_Start(OS_INT8U ID,OS_INT16U *pVal,OS_INT8U **ppMsg,OS_INT8U Time_Out)
{
  OS_INT16U Counts;
  
#if OS_CS_EN>0
  if(OS_CHECK_STRUCT_SUM(OS_Event[ID]) EQ 0)
    OS_ASSERT_FAILED();
#endif
  
  if(ID>=OS_EVENT_NUM)
  {
    OS_ASSERT_FAILED();
    return 0;
  }

  if(OS_Event[ID].Type!=OS_MSG)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
  
  if(Time_Out!=0)
  {
    OS_Core_Wait_Ms(OS_GET_BIT(OS_Event[ID].Rcv_Flag,Task_Info.Cur_Task_ID),Time_Out); 
    if(OS_GET_BIT(OS_Event[ID].Rcv_Flag,Task_Info.Cur_Task_ID) EQ 0)//还是没数据
      return 0;
  }
  else//无限时等待直到有消息需要接收
  {
    Counts=0;
    while(1)
    {
      OS_Core_Wait_Sec(OS_GET_BIT(OS_Event[ID].Rcv_Flag,Task_Info.Cur_Task_ID),OS_MSG_WAIT_WARN_TIME);
      if(OS_GET_BIT(OS_Event[ID].Rcv_Flag,Task_Info.Cur_Task_ID) EQ 0)
      {
        Counts++;
        OS_Debug_Print("\r\nOS:Task %d rcv msg %d start wait time out, Counts=%d",\
                          Task_Info.Cur_Task_ID,ID,Counts);        
      }
      else
        break;
    }
  }
  
  *ppMsg=(OS_INT8U *)OS_Event[ID].pData;//返回消息数据起始地址
  *pVal=OS_Event[ID].Value; //返回消息数值
  
#if OS_CS_EN>0
  OS_SET_STRUCT_SUM(OS_Event[ID]);
#endif   
  
  return 1;  
}

//申请消息结束,成功返回1，失败返回0或者不返回 
//在申请信号量的OS_Msg_Rcv_Flag()和OS_Msg_Proc_Flag()两个函数调用之间，OS_Msg_Send()函数是挂起不会返回的
//因此要注意这两个函数调用期间时间不要太长
//返回1表示成功，0表示失败
OS_INT8U OS_Msg_Rcv_End(OS_INT8U ID)
{
#if OS_CS_EN>0
  if(OS_CHECK_STRUCT_SUM(OS_Event[ID]) EQ 0)
    OS_ASSERT_FAILED();
#endif
  
  if(ID>=OS_EVENT_NUM)
  {
    OS_ASSERT_FAILED();
    return 0;
  }

  if(OS_Event[ID].Type!=OS_MSG)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
  
  if(OS_GET_BIT(OS_Event[ID].Rcv_Flag,Task_Info.Cur_Task_ID) EQ 0)
  {
    OS_ASSERT_FAILED();
    OS_Debug_Print("\r\nOS:Task %d rcv msg %d end error,no message in the MSG box",Task_Info.Cur_Task_ID,ID);
  }
  
  OS_CLR_BIT(OS_Event[ID].Rcv_Flag,Task_Info.Cur_Task_ID);//消息接收完成
   
#if OS_CS_EN>0
  OS_SET_STRUCT_SUM(OS_Event[ID]);
#endif 
  
   return 1;  
}

//打印消息的相关信息
void OS_Msg_Info_Print(void)
{
  OS_INT8U i;
  
  OS_Debug_Print("\r\nOS:Msg Use Info:");
  
  for(i=0;i<OS_EVENT_NUM;i++)
  {
    if(OS_Event[i].Type!=OS_MSG)
      continue;

    OS_Debug_Print("\r\n  Msg %d Rcv_Flag=0x%x, Val=0x%x",i,OS_Event[i].Rcv_Flag,OS_Event[i].Value);
  }
}
#endif

#undef OS_MSG_C

