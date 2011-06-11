#define SHELL_C
#include "Includes.h"

//#define MAX_RD_MEM_LEN 300
//#define MAX_CMD_LEN  50

//#define SHELL_DATA_BUF_LEN 100  

//读取物理存储器函数
//extern INT8U Read_PHY_Mem_Drv(INT8U MemNo,INT32U Offset,INT8U *pDst,INT16U RD_Len, INT8U *pDst_Start, INT16U DstLen);

CONST S_OS_Shell_Cmd Shell_Cmd[] =
{
  {/*.pName = */"echo", /*.pCmdFunc = */&Shell_Bg_Print_Switch},
  {/*.pName = */"ps", /*.pCmdFunc = */&Shell_Print_Prog_Status},
  {/*.pName = */"ss", /*.pCmdFunc = */&Shell_Print_Screen_Status},
  //{.pName = "mem", .pCmdFunc = &Shell_Read_Mem},
  //{.pName = "osinfo", .pCmdFunc = &Shell_OS_Info}
};

//后台打印开关echo 0表示关后台打印,echo 1表示打开后台打印，echo ?表示后台打印开关状态
INT8U Shell_Bg_Print_Switch(INT8U argc, INT8S **argv)
{
  if(*(argv[0]) EQ '0')
     OS_Set_Bg_Print_Flag(0);
  else if(*(argv[0]) EQ '1')
     OS_Set_Bg_Print_Flag(1);
  else if(*(argv[0]) EQ '?')
  {
    debug("echo status %s",\
      (OS_Check_Bg_Print_En() > 0)?"On":"Off"); 
  }
  else
  {
    debug("Cmd format error!"); 
  }
  return 1;
}
/*
//打印操作系统信息
INT8U Shell_OS_Info(INT8U argc, INT8S **argv)
{
  OS_Info_Print();
  return 1;
}
*/
//打印数据
/*
void Shell_Print_Data(INT32U Addr, INT8U *p, INT16U Len)
{
  INT16U i;
  
  for(i = 0; i < Len && i < MAX_RD_MEM_LEN; i ++)
  {
    if((i % 16) EQ 0)
      OS_Debug_Print("\r\n%8lx:", Addr + i);
    
    if(*p < 0x10)
      OS_Debug_Print("0");
    OS_Debug_Print("%x ",*p);
    p ++;
  }  
  
}

//通过shell读取内存和rom数据,argv[0]表示内存ID，0表示ram，0以上表示rom
//argv[1]表示地址
//argv[2]表示长度
INT8U Shell_Read_Mem(INT8U argc, INT8S **argv)
{
  INT32U Mem_No, Addr, Len;
  INT8U *p, Re;
  
  if(argc != 3)
  {
    OS_Debug_Print("Cmd format error!");
    return 0;
  }
  
  Mem_No = atoi(argv[0]);
  Addr = atol(argv[1]);
  Len = atol(argv[2]);
  
  OS_Debug_Print("\r\nMem_No:%lu, Addr:%lu, Len:%lu\r\n", Mem_No, Addr, Len);

  if(Len > MAX_RD_MEM_LEN)
    Len = MAX_RD_MEM_LEN;
    
  if(Mem_No EQ 0)
    p = (INT8U *)Addr;
  else
  {
    Re = Read_PHY_Mem_Drv(Mem_No - 1, Addr, (INT8U *)Shell_Data_Buf, Len, (INT8U *)Shell_Data_Buf, SHELL_DATA_BUF_LEN);
    if(Re EQ 0)
      Len = 0;
    
    p = (INT8U *)Shell_Data_Buf;
  }
  
  Shell_Print_Data(Addr, p, Len);
  
  return 1;
}
*/
/*
//定义节目状态
typedef struct
{
  INT8U Head;
  
  INT8U Prog_No; //当前节目号
  INT32U Time; //已经播放时长
  INT16U Counts; //已经播放次数

  INT8U Play_Flag; //是否播放标志--主要用于与中断显示同步
  
  S_Border_Status Border_Status;
  U_File_Para File_Para[MAX_AREA_NUM]; //每个分区的当前文件参数
  S_Area_Status Area_Status[MAX_AREA_NUM]; //每个分区的状态 
  S_Prog_Block_Index Block_Index; //当前节目的索引

  INT8U CS[CS_BYTES];
  INT8U Tail;
}S_Prog_Status;

typedef struct
{
  INT8U Head;
  INT8U Lightness;
  INT8U Open_Flag;
  INT8U CS[CS_BYTES];
  INT8U Tail;  
}S_Screen_Status;
*/
INT8U Shell_Print_Screen_Status(INT8U argc, INT8S **argv)
{
 
  debug("screen status, lightness = %d, oc_flag = %d",\
        Screen_Status.Lightness, Screen_Status.Open_Flag);
  
  return 1;
}
/*
  INT8U Flag; //标志
  INT8U Prog_No; //节目号
  INT8U Area_No; //分区号
  INT8U File_No; //文件号
  INT8U In_Mode; //引入方式
  INT8U In_Speed; //进入速度
  INT8U Add_Mode; //追加方式
  INT16U Stay_Time; //停留时间，最高位为单位，0表示s，1表示ms
  INT8U Out_Mode; //引出方式	
  INT8U Color; //颜色
  INT16U SNum; //分屏个数
*/
INT8U Shell_Print_Prog_Status(INT8U argc, INT8S **argv)
{
  INT8U i;
  
  debug("cur prog %d, play time = %d, counts = %d, play_flag = %d",\
         Prog_Status.Play_Status.Prog_No, Prog_Status.Play_Status.Time, Prog_Status.Play_Status.Counts);
  
  debug("prog border step = %d, timer = %d", \
         Prog_Status.Border_Status[0].Step, Prog_Status.Border_Status[0].Timer);
  
  debug("area num = %d", Prog_Para.Area_Num);

  for(i = 0; i < Prog_Para.Area_Num; i ++)
  {
    debug("area_no = %d, file para:", i);
    debug("flag = %d, prog_no = %d, area_no = %d, file_no = %d", \
          Prog_Status.File_Para[i].Pic_Para.Flag,\
          Prog_Status.File_Para[i].Pic_Para.Prog_No,\
          Prog_Status.File_Para[i].Pic_Para.Area_No,\
          Prog_Status.File_Para[i].Pic_Para.File_No);
    debug("in_mode = %d, In_Speed = %d, add_mode = %d, stay_time = %d, out_mode = %d, Out_Speed = %d, snum = %d",
          Prog_Status.File_Para[i].Pic_Para.In_Mode,\
          Prog_Status.File_Para[i].Pic_Para.In_Speed,\
          Prog_Status.File_Para[i].Pic_Para.Add_Mode,\
          Prog_Status.File_Para[i].Pic_Para.Stay_Time,\
          Prog_Status.File_Para[i].Pic_Para.Out_Mode,\
          Prog_Status.File_Para[i].Pic_Para.Out_Speed,\
          Prog_Status.File_Para[i].Pic_Para.SNum);  
  }
  
  return 1;
}

void Shell_Rcv_Byte(INT8U Byte)
{
  if(_Shell_Cmd_Buf.Posi >= SHELL_CMD_BUF_LEN)
    _Shell_Cmd_Buf.Posi = 0;

  _Shell_Cmd_Buf.Buf[_Shell_Cmd_Buf.Posi] = Byte;
}

void Shell_Proc(void)
{
  INT8U Re;
  
  Re = OS_Cmd_Analys(Shell_Cmd, S_NUM(Shell_Cmd), (INT8S *)Shell_Cmd_Buf, SHELL_CMD_BUF_LEN);
  if(Re EQ 1)
  {
    _Shell_Cmd_Buf.Posi = 0;
    mem_set((INT8S *)Shell_Cmd_Buf, 0, SHELL_CMD_BUF_LEN, (INT8S *)Shell_Cmd_Buf, SHELL_CMD_BUF_LEN);
  }
}
#undef APP_SHELL_C
