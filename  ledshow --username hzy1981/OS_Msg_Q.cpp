#define OS_MSG_Q_C
#include "OS_Includes.h"

#if OS_MSG_Q_EN>0
//初始化消息队列,消息的ID由应用程序自己固定
//pMsg_Q_Info指向一个已经初始化好的S_Msg_Q_Info类型变量，用来描述消息队列的属性。传入参数前必须已经初始化好
//pMsg_Q_Info->pMsg必须保证该值在一个对齐的位置上，最好是能被4整除
//创建成功返回1，失败返回0
OS_INT8U OS_Msg_Q_Init(OS_INT8U ID,S_Msg_Q_Info *pMsg_Q_Info)
{
  OS_INT8U i;
  S_Msg_Q_H_Info *p;
    
  if(ID>=OS_EVENT_NUM)
  {
    OS_ASSERT_FAILED();
    return 0;
  }

  /*
  //保证消息缓冲区的起始地址在一个对齐的位置
  if((OS_INT32U)pMsg_Q_Info->pMsg%4!=0)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
  */
  
  //每条消息分配的内存大小必须大于保留的大小
  if(pMsg_Q_Info->Msg_Mem_Size<=MSG_RESERVE_SIZE)
  {
    OS_ASSERT_FAILED();
    return 0;    
  }
     
  OS_Event[ID].Type=OS_MSG_Q;
  OS_Event[ID].pData=pMsg_Q_Info;
  OS_Event[ID].Rcv_Flag=pMsg_Q_Info->Msg_Rcv_Flag;
  
  OS_SET_STRUCT_HT(OS_Event[ID]); 
  
  pMsg_Q_Info->Msg_Flag=OS_MSG_Q;  
  pMsg_Q_Info->Msg_Send_Index=0;//发送索引
  for(i=0;i<OS_TASK_NUM;i++)
    pMsg_Q_Info->Msg_Rcv_Index[i]=0;//接收索引
  
  pMsg_Q_Info->Head=CHK_BYTE;//头尾置特殊字节
  pMsg_Q_Info->Tail=CHK_BYTE;

#if OS_CS_EN>0
  OS_SET_STRUCT_SUM(OS_Event[ID]);//设置校验和
  OS_Set_STRUCT_Sum(pMsg_Q_Info,sizeof(S_Msg_Q_Info),pMsg_Q_Info->CS,sizeof(pMsg_Q_Info->CS));
#endif

  //对每个消息对应的内存块进行初始化
  for(i=0;i<pMsg_Q_Info->Msg_Max_Num;i++)
  {
    p=(S_Msg_Q_H_Info *)((OS_INT8U *)pMsg_Q_Info->pMsg+(pMsg_Q_Info->Msg_Mem_Size)*i);//第i条消息对应内存块的初始位置
    p->Head=CHK_BYTE;//信息块的头和尾
    p->Tail=CHK_BYTE;
    p->Rcv_Flag=0; //接收标志，表示哪些任务接收该消息
  #if OS_CS_EN>0
    OS_Set_STRUCT_Sum(p,sizeof(S_Msg_Q_H_Info),p->CS,sizeof(p->CS));
  #endif
    *((OS_INT8U *)p+pMsg_Q_Info->Msg_Mem_Size-1)=CHK_BYTE; //整个内存块的尾 
  }
  return 1;
}

//发送消息到某个消息队列上,注意:消息的长度不能超过该消息队列的最大消息长度,如果消息队列
OS_INT8U OS_Msg_Q_Send(OS_INT8U ID,void *pMsg,OS_INT16U Msg_Len,OS_INT16U Time_Out)
{
  S_Msg_Q_Info *pMsg_Q;
  S_Msg_Q_H_Info *pMsg_H;
  OS_INT32U Counts;

#if OS_CS_EN>0
  if(OS_CHECK_STRUCT_SUM(OS_Event[ID]) EQ 0)
    OS_ASSERT_FAILED();
#endif
  
  if(OS_Event[ID].Type!=OS_MSG_Q)
  {
    OS_ASSERT_FAILED();
    return 0; 
  }
  
  //pMsg_Q指向该消息队列的控制信息块
  pMsg_Q=(S_Msg_Q_Info *)OS_Event[ID].pData;
  
  if(pMsg_Q->Head!=CHK_BYTE || pMsg_Q->Tail!=CHK_BYTE)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
  
#if OS_CS_EN>0
  if(OS_Check_STRUCT_Sum(pMsg_Q,sizeof(S_Msg_Q_Info),pMsg_Q->CS,sizeof(pMsg_Q->CS)) EQ 0)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
#endif
  
  //pMsg_H指向消息所在内存块的头位置
  pMsg_H=(S_Msg_Q_H_Info *)((OS_INT8U *)(pMsg_Q->pMsg)+(pMsg_Q->Msg_Mem_Size)*(pMsg_Q->Msg_Send_Index));
  
  //检查消息内存块头信息的头尾校验
  if(pMsg_H->Head!=CHK_BYTE || pMsg_H->Tail!=CHK_BYTE)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
  
  //检查消息内存块头信息的校验和
#if OS_CS_EN>0
  if(OS_Check_STRUCT_Sum(pMsg_H,sizeof(S_Msg_Q_H_Info),pMsg_H->CS,sizeof(pMsg_H->CS)) EQ 0)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
#endif

  //检查消息内存块尾
  if(*((OS_INT8U *)pMsg_H+pMsg_Q->Msg_Mem_Size-1)!=CHK_BYTE)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
  
  //检查消息长度是否超？
  if((Msg_Len+sizeof(S_Msg_Q_H_Info)+1)>pMsg_Q->Msg_Mem_Size)
  {
    OS_ASSERT_FAILED();
    return 0;
  }

  if(Time_Out!=0)
  {
    OS_Core_Wait_Ms(pMsg_H->Rcv_Flag EQ 0,Time_Out);//等待当前写消息的位置为空
    if(pMsg_H->Rcv_Flag!=0)
      return 0;
  }
  else//无限时等待当前写消息的位置为空
  {
    Counts=0;
    //目前该索引对应的消息是否为空？为空才能忘这个内存块填消息
    while(1)
    {
      OS_Core_Wait_Sec(pMsg_H->Rcv_Flag EQ 0,OS_MSG_Q_WAIT_WARN_TIME);
      if(pMsg_H->Rcv_Flag!=0)
      {
        Counts++;
        OS_Debug_Print("\r\nOS:Task %d send Msg_Q wait %d free time out,Rcv_Flag=%x,Counts=%d",\
                           Task_Info.Cur_Task_ID,ID,pMsg_H->Rcv_Flag,Counts); 
      }
      else
        break;
    }
  }
  
  //填充本条消息的内容
  pMsg_H->Rcv_Flag=pMsg_Q->Msg_Rcv_Flag;//发送给哪些任务?
  pMsg_H->Msg_Len=Msg_Len;
  //复制消息内容
  OS_memcpy((OS_INT8U *)pMsg_H+sizeof(S_Msg_Q_H_Info),pMsg,Msg_Len,\
            (OS_INT8U *)pMsg_H+sizeof(S_Msg_Q_H_Info),pMsg_Q->Msg_Mem_Size-sizeof(S_Msg_Q_H_Info)-1);
  
  //计算下条消息的写索引
  pMsg_Q->Msg_Send_Index++;
  if(pMsg_Q->Msg_Send_Index>=pMsg_Q->Msg_Max_Num)
    pMsg_Q->Msg_Send_Index=0;
  
#if OS_CS_EN>0
  OS_Set_STRUCT_Sum(pMsg_H,sizeof(S_Msg_Q_H_Info),pMsg_H->CS,sizeof(pMsg_H->CS));
  OS_Set_STRUCT_Sum(pMsg_Q,sizeof(S_Msg_Q_Info),pMsg_Q->CS,sizeof(pMsg_Q->CS));  
#endif 
  
  return 1;    
}

//等待某消息为空,即没有消息在等待接收,Time_Out为超时时间，单位ms,0为永远等待知道消息为空，>0为超时时间
//返回0表示等待超时，1表示消息已为空
OS_INT16U OS_Msg_Q_Rcv_Start(OS_INT8U ID,OS_INT8U **ppMsg,OS_INT16U Time_Out)
{
  S_Msg_Q_Info *pMsg_Q;
  S_Msg_Q_H_Info *pMsg_H;
  OS_INT32U Counts;

#if OS_CS_EN>0
  if(OS_CHECK_STRUCT_SUM(OS_Event[ID]) EQ 0)
    OS_ASSERT_FAILED();
#endif
  
  if(OS_Event[ID].Type!=OS_MSG_Q)
  {
    OS_ASSERT_FAILED();
    return 0; 
  }
  
  //pMsg_Q指向该消息队列的控制信息块
  pMsg_Q=(S_Msg_Q_Info *)OS_Event[ID].pData;

  if(pMsg_Q->Head!=CHK_BYTE || pMsg_Q->Tail!=CHK_BYTE)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
  
#if OS_CS_EN>0
  if(OS_Check_STRUCT_Sum(pMsg_Q,sizeof(S_Msg_Q_Info),pMsg_Q->CS,sizeof(pMsg_Q->CS)) EQ 0)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
#endif
  
  //pMsg_H指向消息的头位置
  pMsg_H=(S_Msg_Q_H_Info *)((OS_INT8U *)(pMsg_Q->pMsg)+(pMsg_Q->Msg_Mem_Size)*(pMsg_Q->Msg_Rcv_Index[Task_Info.Cur_Task_ID]));

  //消息信息块的头和尾正确?
  if(pMsg_H->Head!=CHK_BYTE || pMsg_H->Tail!=CHK_BYTE)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
  
#if OS_CS_EN>0
  if(OS_Check_STRUCT_Sum(pMsg_H,sizeof(S_Msg_Q_H_Info),pMsg_H->CS,sizeof(pMsg_H->CS)) EQ 0)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
#endif
 
  //消息长度正确?
  if((pMsg_H->Msg_Len+sizeof(S_Msg_Q_H_Info)+1)>pMsg_Q->Msg_Mem_Size)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
  
  //消息内存块的尾正确？ 
  if(*((OS_INT8U *)pMsg_H+pMsg_Q->Msg_Mem_Size-1)!=CHK_BYTE)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
  
  if(Time_Out!=0)
  {
    OS_Core_Wait_Ms(OS_GET_BIT(pMsg_H->Rcv_Flag,Task_Info.Cur_Task_ID),Time_Out);//等待当前任务有数据需要接收
    if(OS_GET_BIT(pMsg_H->Rcv_Flag,Task_Info.Cur_Task_ID) EQ 0)
      return 0;
  }
  else//无限时等待，直到有数据需要接收
  {
    Counts=0;  
    //Time_Out EQ 0的情况下，无限等待消息
    while(1)
    {
      OS_Core_Wait_Sec(OS_GET_BIT(pMsg_H->Rcv_Flag,Task_Info.Cur_Task_ID),OS_MSG_Q_WAIT_WARN_TIME);//等待所有任务都开始接收数据
      if(OS_GET_BIT(pMsg_H->Rcv_Flag,Task_Info.Cur_Task_ID) EQ 0)
      {
        Counts++;
        OS_Debug_Print("\r\nOS:Task:%d rcv Msg_Q %d wait time out,Counts=%d",Task_Info.Cur_Task_ID,ID,Counts);
      }
      else
        break;
    }
  }

  /*
  OS_CLR_BIT(pMsg_H->Rcv_Flag,Task_Info.Cur_Task_ID);
  pMsg_Q->Msg_Rcv_Index[Task_Info.Cur_Task_ID]++;
  
#if OS_CS_EN>0
  OS_Set_STRUCT_Sum(pMsg_H,sizeof(S_Msg_Q_H_Info),pMsg_H->CS,sizeof(pMsg_H->CS));
  OS_Set_STRUCT_Sum(pMsg_Q,sizeof(S_Msg_Q_Info),pMsg_Q->CS,sizeof(pMsg_Q->CS));  
#endif
  */
  *ppMsg=(OS_INT8U *)pMsg_H+sizeof(S_Msg_Q_H_Info);
  return pMsg_H->Msg_Len;  
}

//等待某消息为空,即没有消息在等待接收,Time_Out为超时时间，单位ms,0为永远等待知道消息为空，>0为超时时间
//返回0表示等待超时，1表示消息已为空
OS_INT16U OS_Msg_Q_Rcv_End(OS_INT8U ID)
{
  S_Msg_Q_Info *pMsg_Q;
  S_Msg_Q_H_Info *pMsg_H;

#if OS_CS_EN>0
  if(OS_CHECK_STRUCT_SUM(OS_Event[ID]) EQ 0)
    OS_ASSERT_FAILED();
#endif
  
  if(OS_Event[ID].Type!=OS_MSG_Q)
  {
    OS_ASSERT_FAILED();
    return 0; 
  }
  
   //pMsg_Q指向该消息队列的控制信息块
  pMsg_Q=(S_Msg_Q_Info *)OS_Event[ID].pData;

  if(pMsg_Q->Head!=CHK_BYTE || pMsg_Q->Tail!=CHK_BYTE)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
  
#if OS_CS_EN>0
  if(OS_Check_STRUCT_Sum(pMsg_Q,sizeof(S_Msg_Q_Info),pMsg_Q->CS,sizeof(pMsg_Q->CS)) EQ 0)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
#endif

 //pMsg_H指向消息的头位置
  pMsg_H=(S_Msg_Q_H_Info *)((OS_INT8U *)(pMsg_Q->pMsg)+(pMsg_Q->Msg_Mem_Size)*(pMsg_Q->Msg_Rcv_Index[Task_Info.Cur_Task_ID]));

  if(pMsg_H->Head!=CHK_BYTE || pMsg_H->Tail!=CHK_BYTE)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
    
#if OS_CS_EN>0
  if(OS_Check_STRUCT_Sum(pMsg_H,sizeof(S_Msg_Q_H_Info),pMsg_H->CS,sizeof(pMsg_H->CS)) EQ 0)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
#endif

  if((pMsg_H->Msg_Len+sizeof(S_Msg_Q_H_Info)+1)>pMsg_Q->Msg_Mem_Size)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
    
  if(*((OS_INT8U *)pMsg_H+pMsg_Q->Msg_Mem_Size-1)!=CHK_BYTE)
  {
    OS_ASSERT_FAILED();
    return 0;
  }

  OS_CLR_BIT(pMsg_H->Rcv_Flag,Task_Info.Cur_Task_ID);//清接收标志，表示任务已经接收到消息
  pMsg_Q->Msg_Rcv_Index[Task_Info.Cur_Task_ID]++;//需要接收的下条消息的索引
  if(pMsg_Q->Msg_Rcv_Index[Task_Info.Cur_Task_ID]>=pMsg_Q->Msg_Max_Num)
    pMsg_Q->Msg_Rcv_Index[Task_Info.Cur_Task_ID]=0;
  
#if OS_CS_EN>0
  OS_Set_STRUCT_Sum(pMsg_H,sizeof(S_Msg_Q_H_Info),pMsg_H->CS,sizeof(pMsg_H->CS));
  OS_Set_STRUCT_Sum(pMsg_Q,sizeof(S_Msg_Q_Info),pMsg_Q->CS,sizeof(pMsg_Q->CS));  
#endif
  
  return 1;
}

//打印消息队列的相关信息
void OS_Msg_Q_Info_Print(void)
{
  OS_INT8U i,j;
  S_Msg_Q_Info *pMsg_Q;
  
  OS_Debug_Print("\r\nOS:Msg_Q Use Info:");
  
  for(i=0;i<OS_EVENT_NUM;i++)
  {
    if(OS_Event[i].Type!=OS_MSG_Q)
      continue;
  
    pMsg_Q=(S_Msg_Q_Info *)OS_Event[i].pData;
    OS_Debug_Print("\r\n  Msg_Q %d Rcv_Fag=0x%x, Send_Index=%d, Rcv_Index:",i,pMsg_Q->Msg_Rcv_Flag,pMsg_Q->Msg_Send_Index);
    for(j=0;j<OS_TASK_NUM;j++)
    {
      if(GET_BIT(pMsg_Q->Msg_Rcv_Flag,j) EQ 1)
      {
        OS_Debug_Print("\r\n  Task:%d Rcv_Inex=%d",j,pMsg_Q->Msg_Rcv_Index[j]); 
      }
    }
  }
}
#endif
#undef OS_MSG_Q_C

