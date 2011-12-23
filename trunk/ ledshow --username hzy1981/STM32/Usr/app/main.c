#include "Includes.h"

#define MAIN_STACK_SIZE 300
 
 void test()
 {
        int i; 
        unsigned char t1[18]={0x24,0x21,0xf0,0x7f,0x80,0x37,0xff,0x1f}; 
        unsigned char t2[18];//0xEA,0xE8,0xE9,0xC8,0xEC,0x6F,0x4C,0x54 

	    transpose8(t1, t2/*, 1*/);
        transpose4(t1, t2/*, 1*/);  
		//juzhen(t1, t2, 0);
		for(i = 0; i < 8; i	++)
		  printf("%d = %x", i, t2[i]);

 }

typedef struct
{
  INT8U Head;

  INT32U Stack[MAIN_STACK_SIZE];	//人工堆栈
  INT16U Left;

  INT8U Tail;
}S_Stack;


S_Stack Main_Stack = {CHK_BYTE, {0}, 0, CHK_BYTE};

//检测系统堆栈剩余情况
void Chk_Main_Stack(void)
{
  INT16U i = 0;
  static INT8U Min = 0xFF;

  if(CHK_HT(Main_Stack) EQ 0)
  {
    ASSERT_FAILED();
  }

  //每分钟打印一次堆栈大小
  if(Min != Cur_Time.Time[T_MIN])
  {
    Min = Cur_Time.Time[T_MIN]; 
	  
	while(Main_Stack.Stack[i] EQ 0)
	{ 
	i ++;
	}
	
	Main_Stack.Left = i*4;

    debug("stack left %d", Main_Stack.Left);
  }

}

int main(void)
{
  __set_MSP((INT32U)(&Main_Stack.Stack[MAIN_STACK_SIZE - 1])); //修改为人工堆栈方式

  Ram_Init();
  Hardware_Init();



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

  //Fac_Status_Self_Test(); //自检操作
  
  Para_Show(); //上电参数显示

  SET_STATUS_LED_ON(); //打开LED状态灯

  while(1)
  {
    Screen_Test(); //屏幕检测

	Self_Test(); //硬件自检

#if SHELL_EN
    Shell_Proc();
#endif

#if UDISK_EN
    UDisk_Proc(); //u盘处理
#endif

    Show_Main_Proc();


#if NET_EN
	Net_Proc();
#endif

    Chk_Main_Stack();
  }
  
}
