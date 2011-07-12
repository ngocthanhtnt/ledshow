#define LED_SCAN_C
#include "Includes.h"

//此算法相当牛逼，将i数组中的8个
void transpose8(unsigned char i[8], unsigned char o[8]) { 
        unsigned long x, y, t; 

        x = (i[0] << 24) | (i[1] << 16) | (i[2] << 8) | i[3]; 
        y = (i[4] << 24) | (i[5] << 16) | (i[6] << 8) | i[7]; 

        t = (x & 0xf0f0f0f0) | ((y >> 4) & 0x0f0f0f0f); 
        y = ((x << 4) & 0xf0f0f0f0) | (y & 0x0f0f0f0f); 
        x = t; 

        t = (x ^ (x >> 14)) & 0x0000cccc; 
        x = x ^ t ^ (t << 14); 
        t = (y ^ (y >> 14)) & 0x0000cccc; 
        y = y ^ t ^ (t << 14); 

        t = (x ^ (x >> 7)) & 0x00aa00aa; 
        x = x ^ t ^ (t << 7); 
        t = (y ^ (y >> 7)) & 0x00aa00aa; 
        y = y ^ t ^ (t << 7); 

        o[7] = x >> 24; o[6] = x >> 16; o[5] = x >> 8; o[4] = x; 
        o[3] = y >> 24; o[2] = y >> 16; o[1] = y >> 8; o[0] = y; 
}

/*
//按位逆序函数
#include  "intrinsics.h" 
unsigned int __rbit(unsigned int val) 
*/
//-------------------------
void Set_Clock_Hight_Speed(void)
{
	RCC_SYSCLKConfig(RCC_SYSCLKSource_HSE); //设置外部时钟为HSE
	//_RCC_HCLKConfig(RCC_SYSCLK_Div1);   //设置AHB时钟=AHB_FREQ MHz
	RCC_PCLK1Config(H_PCLK1_DIV);   //设置APB1时钟=36 MHz(APB1时钟最大值)
	RCC_PCLK2Config(H_PCLK2_DIV);   //设置APB2时钟=72 MHz
	RCC_PLLCmd(DISABLE); //关闭PLL
	RCC_PLLConfig(RCC_PLLSource_HSE_Div1, H_HCLK_MUL); //PLL必须在其激活前完成配置（设置PLL时钟源及倍频系数）
	RCC_PLLCmd(ENABLE);
	// Wait till PLL is ready 
	while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
	{
	}
	// Select PLL as system clock source 
	RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
	// Wait till PLL is used as system clock source 
	while(RCC_GetSYSCLKSource() != 0x08)
	{
	}
}

void Set_Clock_Normal_Speed(void)
{
	RCC_SYSCLKConfig(RCC_SYSCLKSource_HSE); //设置外部时钟为HSE
	//_RCC_HCLKConfig(RCC_SYSCLK_Div1);   //设置AHB时钟=AHB_FREQ MHz
	RCC_PCLK1Config(PCLK1_DIV);   //设置APB1时钟=36 MHz(APB1时钟最大值)
	RCC_PCLK2Config(PCLK2_DIV);   //设置APB2时钟=72 MHz
	RCC_PLLCmd(DISABLE); //关闭PLL
	RCC_PLLConfig(RCC_PLLSource_HSE_Div1, HCLK_MUL); //PLL必须在其激活前完成配置（设置PLL时钟源及倍频系数）
	RCC_PLLCmd(ENABLE);
	// Wait till PLL is ready 
	while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
	{
	}
	// Select PLL as system clock source 
	RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
	// Wait till PLL is used as system clock source 
	while(RCC_GetSYSCLKSource() != 0x08)
	{
	}

}

#if BUILD_SCAN_DATA_INDEX_EN
typedef struct
{
  INT8U Head;
  INT16U Index[MAX_POINTS*2/(8*16)]; //记录第0扫描单元内的一条扫描线的所有数据偏移

  INT16U Block_Off[MAX_SCAN_BLOCK_NUM][16];
  INT8U Block_Num;
  INT8U Tail;
}S_Scan_Data_Index;

S_Scan_Data_Index Scan_Data_Index;
#endif

#pragma pack(1)
INT8U Scan_Data[MAX_SCAN_BLOCK_NUM][3] __attribute__((at(SCAN_DATA_ADDR)));
#pragma pack()

 //构建扫描单元0的所有扫描数据的索引，以字节为单位
void Build_Scan_Data_Index(void)
{
#if BUILD_SCAN_DATA_INDEX_EN
  INT16U Cols, i,j,Index;
  INT8U Color_Num;

  if(Screen_Para.Scan_Para.Rows EQ 0)
  {
	Screen_Para.Scan_Para.Rows = 16;
	SET_SUM(Screen_Para);
  }

  Color_Num = Get_Screen_Color_Num();
  //Block数可以理解为单元板纵向的个数
  Scan_Data_Index.Block_Num = Screen_Para.Base_Para.Height / (Screen_Para.Scan_Para.Rows * (Screen_Para.Scan_Para.Rows_Fold + 1)); //1.2.4.8.16扫？
 
  if(Scan_Data_Index.Block_Num > MAX_SCAN_BLOCK_NUM)
	 Scan_Data_Index.Block_Num = MAX_SCAN_BLOCK_NUM;

  Cols = Screen_Para.Base_Para.Width / 8;
  //对每个Blocks进行扫描
  //每一条扫描线需要Screen_Para.Base_Para.Width / 8 * Screen_Para.Scan_Para.Rows_Fold个字节
  for(i = 0; i < Cols * (Screen_Para.Scan_Para.Rows_Fold + 1); i ++)
  {
      Index = Get_Scan_Data(0, \
	              Screen_Para.Scan_Para.Rows, \
	              0,\
	              Cols, \
	              i, \
	              Screen_Para.Scan_Para.Direct, \
	              Screen_Para.Scan_Para.Rows_Fold, \
	              Screen_Para.Scan_Para.Cols_Fold,\
	              Scan_Data[0]);

	   if(Index < sizeof(Scan_Data_Index.Index))
		  Scan_Data_Index.Index[i] = Index;
	   else
		  ASSERT_FAILED();

   }

   for(i = 0; i < MAX_SCAN_BLOCK_NUM; i ++)
   {
      for(j = 0; j < Screen_Para.Scan_Para.Rows && j < S_NUM(Scan_Data_Index.Block_Off[0]); j ++)
	  {
	      Index = Get_Scan_Data(i, \
		              Screen_Para.Scan_Para.Rows, \
		              j,\
		              Cols, \
		              0, \
		              Screen_Para.Scan_Para.Direct, \
		              Screen_Para.Scan_Para.Rows_Fold, \
		              Screen_Para.Scan_Para.Cols_Fold,\
		              Scan_Data[0]);
	
		   //if(Index < sizeof(Scan_Data_Index.Index))
			  Scan_Data_Index.Block_Off[i][j] = Index - Scan_Data_Index.Index[0];
     }
   }
 #endif
}

void Set_OE_Duty_Polarity(INT8U Duty, INT8U Polarity)
{
  if(Duty > 100)
  {
    Duty = 100;
    ASSERT_FAILED();
  }

  if(Polarity EQ 0)
    TIM3->CCR3 = TIM3->ARR * Duty / 100;
  else
    TIM3->CCR3 = TIM3->ARR * (100 - Duty) / 100;
}
//获取第Rows行第Index个字节的移动数据对应的在屏幕数据中的坐标
//Block表示扫描块的块号
//Rows表示行号，该行号对应接口中的ABCD的行号,几分之几扫?
//BRow表示该块号内的第几条扫描线
//Cols表示宽度，595个数,实际为屏幕宽度/8
//Index表示该扫描线中的第Index个字节
//*pX和*pY返回坐标
//Direct表示数据进入方向,Rows_Fold表示行折叠数，Cols_Fold表示列折数
INT16U Get_Scan_Data(INT16U Block, INT16U Rows, INT16U BRow, INT16U Cols, INT16U Index,\
                          INT8U Direct, INT8U Rows_Fold, INT8U Cols_Fold, INT8U *pDst)
{
  INT16U Fold_Size,X,Y;
  INT8U Screen_Color_Num, *p;
  INT8U Off;
  //INT16U Cols;
  
  X = Y = 0; 

  Rows_Fold ++;

  if(Direct EQ 0x00 || Direct EQ 0x01) //从左边进入，则索引应该转换
    Index = Cols - 1 - Index; //Index从0开始计数
		  
  if(Rows_Fold EQ 0 || Cols_Fold EQ 0) //没有打折的现象
  {
      X = Index;
	   //每个Block对应的屏幕上的行数是 Rows*Rows_Fold
	   //BRow表示第几条扫描线,每条扫描线对应到屏幕上的有Rows_Fold行
	  Y = Block * Rows* Rows_Fold + BRow * Rows_Fold;// + (Index % Fold_Size) / Cols_Fold;
  }
  else
  { 
	  Fold_Size = Rows_Fold*Cols_Fold;  
	  if(Direct EQ 0x00 || Direct EQ 0x02)//左上进入、右上进入
	  {
	    X = Index / Fold_Size * Cols_Fold + (Index % Fold_Size) % Cols_Fold;
	    //每个Block对应的屏幕上的行数是 Rows*Rows_Fold
	    //BRow表示第几条扫描线,每条扫描线对应到屏幕上的有Rows_Fold行
	    Y = Block * Rows* Rows_Fold + BRow * Rows_Fold + (Index % Fold_Size) / Cols_Fold;
	  }
	  else if(Direct EQ 0x01 || Direct EQ 0x03) //左下进入、右下进入
	  {
	    X = Index / Fold_Size * Cols_Fold + (Index % Fold_Size) % Cols_Fold;
	    //每个Block对应的屏幕上的行数是 Rows*Rows_Fold
	    //BRow表示第几条扫描线,每条扫描线对应到屏幕上的有Rows_Fold行
	    Y = Block * Rows* Rows_Fold + (BRow + 1) * Rows_Fold - (Index % Fold_Size) / Cols_Fold - 1;//Y = (Block  + 1)*  Rows * Rows_Fold - BRow * Rows_Fold - (Index % Rows_Fold);//(Index % Fold_Size) / Cols_Fold;    
	  }
	  else
	    ASSERT_FAILED();
   }
  Screen_Color_Num = Get_Screen_Color_Num();  

  p = Show_Data.Color_Data + (Y*Cols + X)*Screen_Color_Num;
  
  Off = 0;
  
  //获取三色数据
  //红
  if(GET_BIT(Screen_Para.Base_Para.Color, 0))
    *pDst = 0xFF - *(p + Off++);//Show_Data.Color_Data[Data_Index];
  else 
    *pDst = 0xFF;
  
  //绿
  if(GET_BIT(Screen_Para.Base_Para.Color, 1))
    *(pDst + 1) = 0xFF - *(p + Off ++);//Show_Data.Color_Data[Data_Index];
  else 
    *(pDst + 1) = 0xFF;
  
  //蓝
  if(GET_BIT(Screen_Para.Base_Para.Color, 2))
    *(pDst + 2) = 0xFF - *(p + Off ++);//Show_Data.Color_Data[Data_Index];
  else 
    *(pDst + 2) = 0xFF;  
  //memcpy(pDst, Show_Data.Color_Data + Data_Index*Screen_Color_Num, Screen_Color_Num);
  return (Y*Cols + X)*Screen_Color_Num;//ReIndex;
}
 //获取扫描数据
void Get_Scan_Data0(INT8U Row, INT16U Col)
{
#if BUILD_SCAN_DATA_INDEX_EN
  INT16U i;
  INT8U *p;

  p = (INT8U *)Show_Data.Color_Data;
  for(i = 0; i < Scan_Data_Index.Block_Num && i < MAX_SCAN_BLOCK_NUM; i ++)
  {
    Scan_Data[i][0] = 0xFF - *(p + Scan_Data_Index.Index[Col] +  Scan_Data_Index.Block_Off[i][Row]);
	Scan_Data[i][1] = 0xFF - *(p + Scan_Data_Index.Index[Col] +  Scan_Data_Index.Block_Off[i][Row] + 1);
	Scan_Data[i][2] = 0xFF - *(p + Scan_Data_Index.Index[Col] +  Scan_Data_Index.Block_Off[i][Row] + 2);
  }
#endif
}

  
 //设置块行号
void Set_Block_Row(INT8U Row)
{
  //Row = Screen_Status.Scan_Row;
  if(Screen_Para.Scan_Para.Rows EQ 0)
  {
    Screen_Para.Scan_Para.Rows = 16;
	SET_SUM(Screen_Para);
  }

  Row = (INT8U)(((INT8S)Screen_Status.Scan_Row + Screen_Para.Scan_Para.Line_Order) % Screen_Para.Scan_Para.Rows);
    
  SET_A((Row & 0x01));
  SET_B(((Row & 0x02) >> 1));
  SET_C(((Row & 0x04) >> 2));
  SET_D(((Row & 0x08) >> 3));
}

                       
//调用该函数每次扫描一行
//每中断一次调用一次该函数
void LED_Scan_One_Row(void)
{
  INT16U i,j,Cols;
  INT16U Blocks;
  INT8U Color_Num;
  
  if(Screen_Status.Time_OC_Flag EQ CLOSE_FLAG ||\
     Screen_Status.Manual_OC_Flag EQ CLOSE_FLAG ||\
	 Screen_Status.Com_Time > 0 ||\
	 Chk_UDisk_Processing()) //关机状态，不显示,或当前在通信状态也不显示
    return;
 

  //Set_Clock_Hight_Speed(); //设置为高速运行模式
  if(Screen_Para.Scan_Para.Rows EQ 0)
  {
	Screen_Para.Scan_Para.Rows = 16;
	SET_SUM(Screen_Para);
  }

  Color_Num = Get_Screen_Color_Num();
  //Block数可以理解为单元板纵向的个数
  Blocks = Screen_Para.Base_Para.Height / (Screen_Para.Scan_Para.Rows * (Screen_Para.Scan_Para.Rows_Fold + 1)); //1.2.4.8.16扫？
 
  if(Blocks > MAX_SCAN_BLOCK_NUM)
	 Blocks = MAX_SCAN_BLOCK_NUM;

  Cols = Screen_Para.Base_Para.Width / 8;
  //对每个Blocks进行扫描
  //每一条扫描线需要Screen_Para.Base_Para.Width / 8 * Screen_Para.Scan_Para.Rows_Fold个字节
  for(i = 0; i < Cols * (Screen_Para.Scan_Para.Rows_Fold + 1); i ++)
  {
#if BUILD_SCAN_DATA_INDEX_EN
  	Get_Scan_Data0(Screen_Status.Scan_Row, i);	
#else
    //对每个Block的每条扫描线同时输出一个字节
    for(j = 0; j < Blocks; j++)
    {
    //获取该扫描线上的所有字节并输出
      Get_Scan_Data(j, \
              Screen_Para.Scan_Para.Rows, \
              Screen_Status.Scan_Row,\
              Cols, \
              i, \
              Screen_Para.Scan_Para.Direct, \
              Screen_Para.Scan_Para.Rows_Fold, \
              Screen_Para.Scan_Para.Cols_Fold,\
              Scan_Data[j]);
    }
#endif	

#if SCAN_DATA_MODE EQ 0    
    //对所有的block输出一个字节
    //如果是从左向右，应该先输出高位再输出低位
    if(Screen_Para.Scan_Para.Direct EQ 0x00 || Screen_Para.Scan_Para.Direct EQ 0x01)
    {
	 if(Color_Num EQ 1)
	 {  
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,7); 
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,6);
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,5);
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,4);
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,3);
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,2);
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,1); 
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,0);
	  }
	  else if(Color_Num EQ 2)
	  {
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,7); 
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,6);
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,5);
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,4);
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,3);
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,2);
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,1); 
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,0);
	  }	
	  else
	  {
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,7); 
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,6);
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,5);
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,4);
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,3);
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,2);
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,1); 
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,0);	  
	  }   
     }
     else //如果从右往左输出应该先输出低位
     {
	 
	 if(Color_Num EQ 1)
	 {  
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,0); 
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,1);
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,2);
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,3);
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,4);
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,5);
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,6); 
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,7);
	  }
	  else if(Color_Num EQ 2)
	  {
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,0); 
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,1);
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,2);
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,3);
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,4);
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,5);
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,6); 
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,7);
	  }
	  else
	  {
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,0); 
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,1);
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,2);
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,3);
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,4);
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,5);
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,6); 
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,7);
	  }
	       
     }
	}
#else
	 //此处是硬件扫描方式代码
#endif	 
	//关闭OE使能
	Set_OE_Duty_Polarity(0, Screen_Para.Scan_Para.OE_Polarity);

	if(Screen_Para.Scan_Para.Line_Hide > 0)
	  Delay_us(Screen_Para.Scan_Para.Line_Hide*10); //行消隐时间
    Delay_us(20);
    SET_LAT(0); //锁存信号输出
    SET_LAT(1); //锁存信号输出
    
    Set_Block_Row(Screen_Status.Scan_Row);
    Screen_Status.Scan_Row++;
    if(Screen_Status.Scan_Row >= Screen_Para.Scan_Para.Rows)
      Screen_Status.Scan_Row = 0;
	
	//重新打开OE
	Set_OE_Duty_Polarity(100, Screen_Para.Scan_Para.OE_Polarity);
	//_USART_Cmd(USART1, DISABLE);
    //Set_Clock_Normal_Speed();
	//_USART_Cmd(USART1, ENABLE); 
	//USART_Clar
   
}
