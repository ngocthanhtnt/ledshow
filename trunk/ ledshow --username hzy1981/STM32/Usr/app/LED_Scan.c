#define LED_SCAN_C
#include "Includes.h"

volatile INT32U test_temp = 0, test_x=0, test_y=0;

#if MAX_SCAN_BLOCK_NUM EQ 16
//此算法相当牛逼，将i数组中的8个
void transpose8(unsigned char i[8], unsigned char o[]/*, unsigned char flag*/) { 
        unsigned long x, y, t; 

        //x = (i[0] << 24) | (i[1] << 16) | (i[2] << 8) | i[3]; 
        //y = (i[4] << 24) | (i[5] << 16) | (i[6] << 8) | i[7]; 
        x = (i[7] << 24) | (i[6] << 16) | (i[5] << 8) | i[4]; 
        y = (i[3] << 24) | (i[2] << 16) | (i[1] << 8) | i[0];

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

		if(Screen_Para.Scan_Para.Data_Polarity != 1) //数据极性为低
		{
		   x = ~x;
		   y = ~y;
		}
		
		if(Screen_Para.Scan_Para.Direct > 0)
		{
          o[0] = y; o[2] = y >> 8; o[4] = y >> 16; o[6] = y >> 24; 
          o[8] = x; o[10] = x >> 8; o[12] = x >> 16; o[14] = x >> 24;    
		}
		else
		{
          o[0] = x >> 24; o[2] = x >> 16; o[4] = x >> 8; o[6] = x; 
          o[8] = y >> 24; o[10] = y >> 16; o[12] = y >> 8; o[14] = y;		
		} 

}

void transpose4(unsigned char i[8], unsigned char o[]/*, unsigned char flag*/) {

        unsigned long x, y, t; 

        //x = (i[0] << 24) | (i[1] << 16) | (i[2] << 8) | i[3]; 
        //y = (i[4] << 24) | (i[5] << 16) | (i[6] << 8) | i[7]; 
        //x = 0;//(i[7] << 24) | (i[6] << 16) | (i[5] << 8) | i[4]; 
        y = (i[3] << 24) | (i[2] << 16) | (i[1] << 8) | i[0];

        t = ((y >> 4) & 0x0f0f0f0f); 
        y = (y & 0x0f0f0f0f); 
        x = t; 

        t = (x ^ (x >> 14)) & 0x0000cccc; 
        x = x ^ t ^ (t << 14); 
        t = (y ^ (y >> 14)) & 0x0000cccc; 
        y = y ^ t ^ (t << 14); 

        t = (x ^ (x >> 7)) & 0x00aa00aa; 
        x = x ^ t ^ (t << 7); 
        t = (y ^ (y >> 7)) & 0x00aa00aa; 
        y = y ^ t ^ (t << 7); 

		if(Screen_Para.Scan_Para.Data_Polarity != 1) //数据极性为低
		{
		   x = ~x;
		   y = ~y;
		}

		if(Screen_Para.Scan_Para.Direct > 0)
		{
          o[0] = y; o[2] = y >> 8; o[4] = y >> 16; o[6] = y >> 24; 
          o[8] = x; o[10] = x >> 8; o[12] = x >> 16; o[14] = x >> 24; 
		}
		else
		{
          o[0] = x >> 24; o[2] = x >> 16; o[4] = x >> 8; o[6] = x; 
          o[8] = y >> 24; o[10] = y >> 16; o[12] = y >> 8; o[14] = y;		
		}
} 
#else
//此算法相当牛逼，将i数组中的8个
void transpose8(unsigned char i[8], unsigned char o[8]/*, unsigned char flag*/) { 
        unsigned long x, y, t; 

        //x = (i[0] << 24) | (i[1] << 16) | (i[2] << 8) | i[3]; 
        //y = (i[4] << 24) | (i[5] << 16) | (i[6] << 8) | i[7]; 
        x = (i[7] << 24) | (i[6] << 16) | (i[5] << 8) | i[4]; 
        y = (i[3] << 24) | (i[2] << 16) | (i[1] << 8) | i[0];

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

		if(Screen_Para.Scan_Para.Data_Polarity != 1) //数据极性为低
		{
		   x = ~x;
		   y = ~y;
		}
		
		if(Screen_Para.Scan_Para.Direct > 0)
		{
          o[0] = y; o[1] = y >> 8; o[2] = y >> 16; o[3] = y >> 24; 
          o[4] = x; o[5] = x >> 8; o[6] = x >> 16; o[7] = x >> 24; 
		}
		else
		{
          o[0] = x >> 24; o[1] = x >> 16; o[2] = x >> 8; o[3] = x; 
          o[4] = y >> 24; o[5] = y >> 16; o[6] = y >> 8; o[7] = y;		
		} 

}

void transpose4(unsigned char i[8], unsigned char o[8]/*, unsigned char flag*/) {

        unsigned long x, y, t; 

        //x = (i[0] << 24) | (i[1] << 16) | (i[2] << 8) | i[3]; 
        //y = (i[4] << 24) | (i[5] << 16) | (i[6] << 8) | i[7]; 
        //x = 0;//(i[7] << 24) | (i[6] << 16) | (i[5] << 8) | i[4]; 
        y = (i[3] << 24) | (i[2] << 16) | (i[1] << 8) | i[0];

        t = ((y >> 4) & 0x0f0f0f0f); 
        y = (y & 0x0f0f0f0f); 
        x = t; 

        t = (x ^ (x >> 14)) & 0x0000cccc; 
        x = x ^ t ^ (t << 14); 
        t = (y ^ (y >> 14)) & 0x0000cccc; 
        y = y ^ t ^ (t << 14); 

        t = (x ^ (x >> 7)) & 0x00aa00aa; 
        x = x ^ t ^ (t << 7); 
        t = (y ^ (y >> 7)) & 0x00aa00aa; 
        y = y ^ t ^ (t << 7); 

		if(Screen_Para.Scan_Para.Data_Polarity != 1) //数据极性为低
		{
		   x = ~x;
		   y = ~y;
		}

		if(Screen_Para.Scan_Para.Direct > 0)
		{
          o[0] = y; o[1] = y >> 8; o[2] = y >> 16; o[3] = y >> 24; 
          o[4] = x; o[5] = x >> 8; o[6] = x >> 16; o[7] = x >> 24; 
		}
		else
		{
          o[0] = x >> 24; o[1] = x >> 16; o[2] = x >> 8; o[3] = x; 
          o[4] = y >> 24; o[5] = y >> 16; o[6] = y >> 8; o[7] = y;		
		} 
}
#endif

/*
//按位逆序函数
#include  "intrinsics.h" 
unsigned int __rbit(unsigned int val) 
*/
//-------------------------
/*
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
 */
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
  INT16U Index[MAX_SCAN_WIDTH]; //记录第0扫描单元内的一条扫描线的所有数据偏移

  INT16U Block_Off[MAX_SCAN_BLOCK_NUM][16];
  INT8U Block_Num;
  INT8U Tail;
}S_Scan_Data_Index;

S_Scan_Data_Index Scan_Data_Index;
#endif

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
      Index = Get_Scan_Data_Index(0, i);

	   if(Index < sizeof(Scan_Data_Index.Index))
		  Scan_Data_Index.Index[i] = Index;
	   else
		  ASSERT_FAILED();

   }

   for(i = 0; i < MAX_SCAN_BLOCK_NUM; i ++)
   {
      for(j = 0; j < Screen_Para.Scan_Para.Rows && j < S_NUM(Scan_Data_Index.Block_Off[0]); j ++)
	  {
	      Index = Get_Scan_Data_Index(i, \
		              Screen_Para.Scan_Para.Rows, \
		              j,\
		              Cols, \
		              0, \
		              Screen_Para.Scan_Para.Direct, \
		              Screen_Para.Scan_Para.Rows_Fold, \
		              Screen_Para.Scan_Para.Cols_Fold);
	
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
    TIM4->CCR3 = TIM4->ARR * Duty / 100;
  else
    TIM4->CCR3 = TIM4->ARR * (100 - Duty) / 100;
}

//获取第Rows行第Index个字节的移动数据对应的在屏幕数据中的坐标
//Block表示扫描块的块号
//Rows表示行号，该行号对应接口中的ABCD的行号,几分之几扫?
//BRow表示该块号内的第几条扫描线
//Cols表示宽度，595个数,实际为屏幕宽度/8
//Index表示该扫描线中的第Index个字节
//*pX和*pY返回坐标
//Direct表示数据进入方向,Rows_Fold表示行折叠数，Cols_Fold表示列折数
INT16U Get_Scan_Data_Index(INT16U Block, INT16U Index)
{
  INT32U Fold_Size,X,Y;
  INT32U Temp;
  INT8U Rows_Fold, Cols_Fold;//,Rows;
  INT16U Cols;
  INT8U Direct;

  if(Screen_Para.Scan_Para.Direct < 2) //从左边进入，则索引应该转换
    Index = Screen_Status.Block_Cols - 1 - Index; //Index从0开始计数
				  
  if(Screen_Para.Scan_Para.Rows_Fold EQ 0 ||\
     Screen_Para.Scan_Para.Cols_Fold EQ 0) //没有打折的现象
  {	
      //return ((Block * Screen_Status.Block_Cols + Screen_Status.Scan_Row) * Screen_Status.Block_Cols + Index)*Screen_Status.Color_Num;
      X = Index;
	   //每个Block对应的屏幕上的行数是 Rows*Rows_Fold
	   //BRow表示第几条扫描线,每条扫描线对应到屏幕上的有Rows_Fold行
	  Y = Block*Screen_Status.Rows_X_RowsFold + Screen_Status.BRow_X_RowsFold;//(Block * Rows + BRow) * Rows_Fold;//Block * Rows* Rows_Fold + BRow * Rows_Fold;//
      return (Y*Screen_Status.Block_Cols + X)*Screen_Status.Color_Num;//ReIndex;
  }	
  else
  {
	  Cols = Screen_Status.Block_Cols;
	
	  //Rows = Screen_Para.Scan_Para.Rows;
	  Rows_Fold = Screen_Para.Scan_Para.Rows_Fold + 1;
	  Cols_Fold = Screen_Para.Scan_Para.Cols_Fold;
	  Direct = Screen_Para.Scan_Para.Direct;
     
	  Fold_Size = Screen_Status.Fold_Size;//Rows_Fold*Cols_Fold;  
	  if(Direct EQ 0x00 || Direct EQ 0x02)//左上进入、右上进入
	  {

	    Temp = Index % Fold_Size; 
	    X = Index / Fold_Size * Cols_Fold + Temp % Cols_Fold;
	    //每个Block对应的屏幕上的行数是 Rows*Rows_Fold
	    //BRow表示第几条扫描线,每条扫描线对应到屏幕上的有Rows_Fold行
	    Y = Block*Screen_Status.Rows_X_RowsFold + Screen_Status.BRow_X_RowsFold + Temp / Cols_Fold; //(Block * Rows + BRow) * Rows_Fold + Temp / Cols_Fold;//Block * Rows* Rows_Fold + BRow * Rows_Fold + (Index % Fold_Size) / Cols_Fold;
 
	  }
	  else if(Direct EQ 0x01 || Direct EQ 0x03) //左下进入、右下进入
	  {
	    Temp = Index % Fold_Size; 
	    X = Index / Fold_Size * Cols_Fold + Temp % Cols_Fold;
	    //每个Block对应的屏幕上的行数是 Rows*Rows_Fold
	    //BRow表示第几条扫描线,每条扫描线对应到屏幕上的有Rows_Fold行
	    Y = Block*Screen_Status.Rows_X_RowsFold + Screen_Status.BRow_X_RowsFold + Temp / Cols_Fold + Rows_Fold - Temp / Cols_Fold - 1; 
	  }
	  else
	  {
	    ASSERT_FAILED();
        return 0;
	  }

      return (Y*Cols + X)*Screen_Status.Color_Num;//ReIndex;
   }

}

#if SCAN_DATA_MODE EQ SCAN_SOFT_MODE1
void Get_Scan_Data(INT16U Blocks, INT16U Col)
{
    INT16U Index,i;
	INT32U Temp;
	INT16U Cols;
	INT8U *p;
	

	Index = Get_Scan_Data_Index(0, Col); //先计算第0个block的对应索引，后面的block都是加一个同样的值
    
	//Cols = Screen_Para.Base_Para.Width / 8;
    for(i = 0; i < Blocks && i < MAX_SCAN_BLOCK_NUM; i ++)
    {
        //获取该扫描线上的所有字节并输出
        //Index = Get_Scan_Data_Index(i, Col);

	   //test_temp = Index;
	    p = Show_Data.Color_Data + Index;
	  
		//Off = 0;
		//获取三色数据
		//红
		if(GET_BIT(Screen_Para.Base_Para.Color, 0))
		  Scan_Data[0][i] = 0xFF - *p;//Show_Data.Color_Data[Data_Index];
		else 
		  Scan_Data[0][i] = 0xFF;
		
		//绿
		if(GET_BIT(Screen_Para.Base_Para.Color, 1))
		  Scan_Data[1][i] = 0xFF - *(p +1);//Show_Data.Color_Data[Data_Index];
		else 
		  Scan_Data[1][i] = 0xFF;
/*		
		//蓝
		if(GET_BIT(Screen_Para.Base_Para.Color, 2))
		  Scan_Data[2][i] = 0xFF - *(p + Off ++);//Show_Data.Color_Data[Data_Index];
		else 
		  Scan_Data[2][i] = 0xFF; 
*/		
		
		if(Screen_Para.Scan_Para.Direct < 0x02)// EQ 0x00 || Screen_Para.Scan_Para.Direct EQ 0x01)//左边进入位序应该反
		{
			Temp = __RBIT(Scan_Data[0][i]);
			Scan_Data[0][i] = *((INT8U *)&Temp + 3);
			Temp = __RBIT(Scan_Data[1][i]);
			Scan_Data[1][i] = *((INT8U *)&Temp + 3);
			//Temp = __RBIT(Scan_Data[2][i]);
			//Scan_Data[2][i] = *((INT8U *)&Temp + 3);
		}

		Index += Screen_Status.Block_Bytes;
    }

}
#elif SCAN_DATA_MODE EQ SCAN_SOFT_MODE0
void Get_Scan_Data(INT16U Blocks, INT16U Col)
{
    INT16U i;
	INT32S Index;
	//INT16U Addr;
	//INT32U Temp;
	//INT16U Cols;
	

	Index = Screen_Status.Block0_Index + Screen_Status.ScanRow_X_BlockCols;//Screen_Status.Scan_Row * Screen_Para.Base_Para.Width / 8 * Screen_Status.Color_Num;//Get_Scan_Data_Index(0, Col); //先计算第0个block的对应索引，后面的block都是加一个同样的值
   
    if(Screen_Para.Scan_Para.RG_Reverse EQ 1) //红绿反向
	{
 		if(Screen_Status.Color_Num < 2)
		{
			for(i = 0; i < Blocks; i ++)
			{
				Scan_Data[1][i] = Show_Data.Color_Data[Index];//Show_Data.Color_Data[Data_Index];
				Index += Screen_Status.Block_Bytes;
			}
		}
		else
		{
			for(i = 0; i < Blocks; i ++)
			{
	     		Scan_Data[1][i] = Show_Data.Color_Data[Index];//Show_Data.Color_Data[Data_Index]; 		    
				Scan_Data[0][i] = Show_Data.Color_Data[Index + 1];//Show_Data.Color_Data[Data_Index];
				Index += Screen_Status.Block_Bytes;
			}
		}
	}
	else
	{
		if(Screen_Status.Color_Num < 2)
		{
			for(i = 0; i < Blocks; i ++)
			{
				Scan_Data[0][i] = Show_Data.Color_Data[Index];//Show_Data.Color_Data[Data_Index];
				Index += Screen_Status.Block_Bytes;
			}
		}
		else
		{
			for(i = 0; i < Blocks; i ++)
			{
	     		Scan_Data[0][i] = Show_Data.Color_Data[Index];//Show_Data.Color_Data[Data_Index]; 		    
				Scan_Data[1][i] = Show_Data.Color_Data[Index + 1];//Show_Data.Color_Data[Data_Index];
				Index += Screen_Status.Block_Bytes;
			}
	
		}
	}

    //if(Screen_Para.Scan_Para.Direct < 2) //从左边进入，则索引应该转换
      Screen_Status.Block0_Index += Screen_Status.Block_Data_Off[Col % Screen_Status.Fold_Size];
//	else
//	  Screen_Status.Block0_Index - Screen_Status.Block_Data_Off[Col % Screen_Status.Fold_Size];
  	//Screen_Status.Block0_Index = Screen_Status.Block0_Index + Screen_Status.Block_Data_Off[Col % Screen_Status.Fold_Size]; 
}
#endif 
  
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
  
  if(Screen_Para.Scan_Para._138Check != 1) //0表示有138译码器
  {  
    SET_A((Row & 0x01));
    SET_B(((Row & 0x02) >> 1));
    SET_C(((Row & 0x04) >> 2));
    SET_D(((Row & 0x08) >> 3));
  }
  else //没有138译码器的情况下
  {
    SET_A(0);
    SET_B(0);
    SET_C(0);
    SET_D(0);

	if(Row EQ 0)
	  SET_A(1);
	else if(Row EQ 1)
	  SET_B(1);
    else if(Row EQ 2)
	  SET_C(1);
	else if(Row EQ 3)
	  SET_D(1);
  }
}

INT16S Get_Data_Index(INT16U X, INT16U Y)
{

  return Y*Screen_Para.Base_Para.Width / 8 + X;
}

//计算一个扫描块内数据的偏移
void Calc_Block_Data_Addr_Off(void)
{
   INT8U i;
   INT16U Size;

   Size = Screen_Status.Fold_Size;//(Screen_Para.Scan_Para.Rows_Fold + 1) * Screen_Para.Scan_Para.Cols_Fold;
   
   if(Screen_Para.Scan_Para.Rows_Fold EQ 0 || Screen_Para.Scan_Para.Cols_Fold EQ 0)
   {
       Size = 1;
  	   for(i = 0; i < Size; i ++)
	   {
	     if(Screen_Para.Scan_Para.Direct > 1)
		   Screen_Status.Block_Data_Off[i] = Screen_Status.Color_Num;
	     else
		   Screen_Status.Block_Data_Off[i] = -Screen_Status.Color_Num;
	   }

	   Screen_Status.Block0_Index = 0;

	   if(Screen_Para.Scan_Para.Direct > 1)
	     Screen_Status.Block0_Index = 0;
	   else
	     Screen_Status.Block0_Index = (Screen_Para.Base_Para.Width / 8 - 1) * Screen_Status.Color_Num;

	   return;
   } 

   if(Screen_Para.Scan_Para.Direct EQ 0x00) //左上入
   {
 	   for(i = 0; i < Size && i < sizeof(Screen_Status.Block_Data_Off); i ++)
	   {
	      if(i EQ Size - 1)
		    Screen_Status.Block_Data_Off[i] = Get_Data_Index(0, Screen_Para.Scan_Para.Rows_Fold * Screen_Para.Scan_Para.Rows) - \
			                                  Get_Data_Index(1, 0);
		  else if((i % Screen_Para.Scan_Para.Cols_Fold) EQ Screen_Para.Scan_Para.Cols_Fold - 1)
		    Screen_Status.Block_Data_Off[i] = Get_Data_Index(Screen_Para.Scan_Para.Cols_Fold - 1, 0) - Get_Data_Index(0, Screen_Para.Scan_Para.Rows);
	      else
		    Screen_Status.Block_Data_Off[i] = -1;

		  Screen_Status.Block_Data_Off[i] = Screen_Status.Block_Data_Off[i] * Screen_Status.Color_Num;
	   }

	   Screen_Status.Block0_Index = ((Screen_Para.Scan_Para.Rows_Fold * Screen_Para.Scan_Para.Rows  + 1)* Screen_Para.Base_Para.Width / 8 - 1)* Screen_Status.Color_Num;

   }
   else if(Screen_Para.Scan_Para.Direct EQ 0x01) //左下入
   {
 	   for(i = 0; i < Size; i ++)
	   {
	      if(i EQ Size - 1)
		    Screen_Status.Block_Data_Off[i] = Get_Data_Index(0, 0) -\
			                                  Get_Data_Index(1, Screen_Para.Scan_Para.Rows_Fold * Screen_Para.Scan_Para.Rows);			                                  
		  else if((i % Screen_Para.Scan_Para.Cols_Fold) EQ Screen_Para.Scan_Para.Cols_Fold - 1)
		    Screen_Status.Block_Data_Off[i] = Get_Data_Index(Screen_Para.Scan_Para.Cols_Fold - 1, Screen_Para.Scan_Para.Rows) - Get_Data_Index(0, 0);
	      else
		    Screen_Status.Block_Data_Off[i] = -1;

	      Screen_Status.Block_Data_Off[i] = Screen_Status.Block_Data_Off[i] * Screen_Status.Color_Num;
	   }

	   Screen_Status.Block0_Index = (Screen_Para.Base_Para.Width / 8 - 1) * Screen_Status.Color_Num;
   }
   else if(Screen_Para.Scan_Para.Direct EQ 0x02) //右上入
   {
	   for(i = 0; i < Size; i ++)
	   {
	      if(i EQ Size - 1)
		    Screen_Status.Block_Data_Off[i] = Get_Data_Index(1, Screen_Para.Scan_Para.Rows_Fold * Screen_Para.Scan_Para.Rows) - \
			                                  Get_Data_Index(0, 0);
		  else if((i % Screen_Para.Scan_Para.Cols_Fold) EQ Screen_Para.Scan_Para.Cols_Fold - 1)
		    Screen_Status.Block_Data_Off[i] = Get_Data_Index(0, 0) - Get_Data_Index(Screen_Para.Scan_Para.Cols_Fold - 1, Screen_Para.Scan_Para.Rows);
	      else
		    Screen_Status.Block_Data_Off[i] = 1;

		  Screen_Status.Block_Data_Off[i] = Screen_Status.Block_Data_Off[i] * Screen_Status.Color_Num;
	   }

	   Screen_Status.Block0_Index = Screen_Para.Scan_Para.Rows_Fold * Screen_Para.Scan_Para.Rows * Screen_Para.Base_Para.Width / 8 * Screen_Status.Color_Num;

   }
   else	//右下入
   {
	   for(i = 0; i < Size; i ++)
	   {
	      if(i EQ Size - 1)
		    Screen_Status.Block_Data_Off[i] = Get_Data_Index(1, 0) - \
			                                  Get_Data_Index(0, Screen_Para.Scan_Para.Rows_Fold * Screen_Para.Scan_Para.Rows);
		  else if((i % Screen_Para.Scan_Para.Cols_Fold) EQ Screen_Para.Scan_Para.Cols_Fold - 1)
		    Screen_Status.Block_Data_Off[i] = Get_Data_Index(0, Screen_Para.Scan_Para.Rows) - Get_Data_Index(Screen_Para.Scan_Para.Cols_Fold - 1, 0);
	      else
		    Screen_Status.Block_Data_Off[i] = 1;

	      Screen_Status.Block_Data_Off[i] = Screen_Status.Block_Data_Off[i] * Screen_Status.Color_Num;
	   }

	   Screen_Status.Block0_Index = 0;
  }
}
/*
void Clr_Cur_Scan_Row(void)
{
  INT16U Cols, i,j;
  INT8U Data;

  Cols = (Screen_Para.Base_Para.Width / 8)* (Screen_Para.Scan_Para.Rows_Fold + 1);

  if(Screen_Para.Scan_Para.Data_Polarity EQ 0)
    Data = 0xFF;
  else
    Data = 0;
    
  //对每个Blocks进行扫描
  //每一条扫描线需要Screen_Para.Base_Para.Width / 8 * Screen_Para.Scan_Para.Rows_Fold个字节
  for(i = 0; i < Cols ; i ++)
  {
      //Get_Scan_Data(Blocks, i);

#if MAX_SCAN_BLOCK_NUM EQ 4//A型卡最多4条扫描线
	  for(j = 0; j < 8; j ++)
	  {
	    nop();
	    SET_CLK_LOW();
        GPIOB->ODR = Data;//Temp | Scan_Data[0][j]; //输出R1-R4,G1-G4
		SET_CLK_HIGH();
	   }
#elif MAX_SCAN_BLOCK_NUM EQ 8
;
#elif MAX_SCAN_BLOCK_NUM EQ 16


	  for(j = 0; j < 8; j ++)
	  {
		GPIOD->ODR = Data;//(GPIOD->ODR & 0xFF00) | Scan_Data[0][j]; //输出R1-R8
		SET_CLK_LOW();

		GPIOE->ODR = Data;//(GPIOE->ODR & 0xFF00) | Scan_Data[1][j]; //输出G1-G8
		SET_CLK_HIGH();
	   }
	
#else
#error "MAX_SCAN_BLOCK_NUM error"
#endif

   }

    SET_LAT(0); //锁存信号输出
	nop();
	nop();
    SET_LAT(1); //锁存信号输出
}
*/                      
//调用该函数每次扫描一行
//每中断一次调用一次该函数
//SPI频率2.5M比较合适
void LED_Scan_One_Row(void)
{
  INT16U i,j,k,Cols;
  INT16U Blocks;
  INT8U *pDst;
  static INT32U Flag = 0;
  //INT8U Direct;
//  INT8U Color_Num;
  
  //Delay_us(500);
  //return;
  if(Flag EQ 0xA5) //防止重复进入
    return;
 
  Flag = 0xA5;

  if(Screen_Status.Time_OC_Flag EQ CLOSE_FLAG ||\
     Screen_Status.Manual_OC_Flag EQ CLOSE_FLAG ||\
	 Screen_Status.Com_Time > 0 ||\
	 Chk_UDisk_Processing()) //关机状态，不显示,或当前在通信状态也不显示
	 {
	 Flag = 0;
    return;
	}
 
    //GPIO_SetBits(GPIOB,GPIO_Pin_9); //测试输出


  if(Screen_Para.Scan_Para.Rows EQ 0)
  {
	Screen_Para.Scan_Para.Rows = 16;
	SET_SUM(Screen_Para);
  }

  Screen_Status.Color_Num = Get_Screen_Color_Num();
  Screen_Status.Block_Cols = (Screen_Para.Base_Para.Width / 8)* (Screen_Para.Scan_Para.Rows_Fold + 1);//Screen_Para.Base_Para.Width / 8;	//一条扫描线的长度，此处待修改
  Screen_Status.Fold_Size = Screen_Para.Scan_Para.Cols_Fold * (Screen_Para.Scan_Para.Rows_Fold + 1);

  if(Screen_Status.Fold_Size EQ 0)
    Screen_Status.Fold_Size = 1;

  Screen_Status.BRow_X_RowsFold = Screen_Status.Scan_Row * (Screen_Para.Scan_Para.Rows_Fold + 1);
  Screen_Status.Rows_X_RowsFold = Screen_Para.Scan_Para.Rows * (Screen_Para.Scan_Para.Rows_Fold + 1); 
  Screen_Status.Block_Bytes = (Screen_Para.Scan_Para.Rows_Fold + 1) * Screen_Para.Scan_Para.Rows * Screen_Para.Base_Para.Width / 8 * Screen_Status.Color_Num; //每个扫描单元的字节数
  Screen_Status.ScanRow_X_BlockCols	= Screen_Status.Color_Num * Screen_Status.Scan_Row * Screen_Para.Base_Para.Width / 8; 
  //Block数可以理解为单元板纵向的个数

  Blocks = Screen_Para.Base_Para.Height / (Screen_Para.Scan_Para.Rows * (Screen_Para.Scan_Para.Rows_Fold + 1)); //1.2.4.8.16扫？
	
  if(Blocks > MAX_SCAN_BLOCK_NUM)
	Blocks = MAX_SCAN_BLOCK_NUM;

  Cols = Screen_Status.Block_Cols;

  Calc_Block_Data_Addr_Off();

  //Direct = (Screen_Para.Scan_Para.Direct < 2)?0:1; //左入为0，数据反向，右入为1，数据维持

 // if(Screen_Para.Scan_Para.Data_Polarity EQ 0)
   // memset(Scan_Data0, 0xFF, sizeof(Scan_Data));
 // else
    memset(Scan_Data0, 0x00, sizeof(Scan_Data0));

#if SCAN_DATA_MODE EQ SCAN_SOFT_MODE0

  //对每个Blocks进行扫描
  //每一条扫描线需要Screen_Para.Base_Para.Width / 8 * Screen_Para.Scan_Para.Rows_Fold个字节
  for(i = 0; i < Cols ; i ++)
  {
      //GPIO_SetBits(GPIOB,GPIO_Pin_9); //测试输出
      Get_Scan_Data(Blocks, i);

	  if(i & 0x01)
	    pDst = &Scan_Data0[0][0];
	  else
	    pDst = &Scan_Data1[0][0];
 
#if MAX_SCAN_BLOCK_NUM EQ 4//A型卡最多4条扫描线
      transpose8(&Scan_Data[0][0], pDst/*, Direct*/);	//R1-R4,G1-G4

	  Temp = (GPIOB->ODR & 0xFF00) ;
	  for(j = 0; j < 8; j ++)
	  {
	    nop();
	    SET_CLK_LOW();
        GPIOB->ODR = Temp | Scan_Data[0][j]; //输出R1-R4,G1-G4
		SET_CLK_HIGH();
	   }
#elif MAX_SCAN_BLOCK_NUM EQ 8
;
#elif MAX_SCAN_BLOCK_NUM EQ 16

	    if(Blocks <= 4)
		   transpose4(&Scan_Data[0][0], pDst/*, Direct*/);	//R1-R4
 		else
		{
			transpose8(&Scan_Data[0][0], pDst/*, Direct*/);	//R1-R8
			if(Blocks > 8)
			{
			   if(Blocks <= 12)
			     transpose4(&Scan_Data[0][8], pDst + 1/*, Direct*/); //R9-R16
			   else
			     transpose8(&Scan_Data[0][8], pDst + 1/*, Direct*/); //R9-R16
			}
		}

		if(Screen_Status.Color_Num > 1)
		{
	      if(Blocks <= 4)
		    transpose4(&Scan_Data[1][0], pDst + MAX_SCAN_BLOCK_NUM/*, Direct*/);	//R1-R8
		  else
		  {
		    transpose8(&Scan_Data[1][0], pDst + MAX_SCAN_BLOCK_NUM/*, Direct*/); //G1-G8
  			if(Blocks > 8)
			{
			    if(Blocks <= 12)
				  transpose4(&Scan_Data[1][8], pDst + MAX_SCAN_BLOCK_NUM + 1/*, Direct*/);	//R1-R8
				else
			      transpose8(&Scan_Data[1][8], pDst + MAX_SCAN_BLOCK_NUM + 1/*, Direct*/); //R9-R16
			}
		  }
		}

		for(k = 0; k < 8; k ++)
		{
			GPIOA->BRR = GPIO_Pin_1;
			GPIOD->ODR = Scan_Data[0][k];//(GPIOD->ODR & 0xFF00) | Scan_Data[0][j]; //输出R1-R8
			GPIOA->BSRR = GPIO_Pin_1;
		}
		/*
	   Scan_Data0[0][0] = 0x5A;
	   Scan_Data0[0][1] = 0x00;
	   Scan_Data0[0][2] = 0x5B;
	   Scan_Data0[0][3] = 0x00;

	   Scan_Data0[1][0] = 0xA5;
	   Scan_Data0[1][1] = 0x00;
	   Scan_Data0[1][2] = 0xA6;
	   Scan_Data0[1][3] = 0x00;
		*/
		GPIO_ResetBits(GPIOB,GPIO_Pin_9); //测试输出
		while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET); //等待上次发送完成
//应该不需要换地址，因为只要DMA速度比数据生成速度快，就不存在追赶上的问题。如果慢就可能发生。新生成的数据覆盖即将输出的数据的问题
 
		DMA1_Channel5->CCR &= (uint16_t)(~DMA_CCR1_EN); //关闭DMA通道
		DMA1_Channel5->CMAR = (uint32_t)pDst;//pDMA_InitStruct->DMA_MemoryBaseAddr;
	    DMA1_Channel5->CCR |= DMA_CCR1_EN; //打开DMA通道

 		DMA1_Channel7->CCR &= (uint16_t)(~DMA_CCR1_EN);
		DMA1_Channel7->CMAR = (uint32_t)(pDst + MAX_SCAN_BLOCK_NUM);
		DMA1_Channel7->CCR |= DMA_CCR1_EN;

		//SPI_I2S_SendData(SPI2, 0);
	   //GPIO_ResetBits(GPIOB,GPIO_Pin_9); //测试输出 

#else
#error "MAX_SCAN_BLOCK_NUM error"
#endif

   }
#elif SCAN_DATA_MODE EQ SCAN_SOFT_MODE1

    for(i = 0; i < Cols ; i ++)
    {
        Get_Scan_Data(Blocks, i);
		
		if(Blocks <= 8)
		{
			if(Screen_Status.Color_Num < 2)
			{	
				for(j = 0; j < 8; j ++)
				{
					SET_CLK_LOW();
					GPIOD->ODR = Scan_Data[0][j];//(GPIOD->ODR & 0xFF00) | Scan_Data[0][j]; //输出R1-R8
					SET_CLK_HIGH();
				}
			}
			else
			{
 				for(j = 0; j < 8; j ++)
				{
					GPIOD->ODR = Scan_Data[0][j];//(GPIOD->ODR & 0xFF00) | Scan_Data[0][j]; //输出R1-R8
					SET_CLK_LOW();
					GPIOE->ODR = Scan_Data[1][j];//(GPIOD->ODR & 0xFF00) | Scan_Data[0][j]; //输出R1-R8
					SET_CLK_HIGH();
				}
			}
		}
		else
		{
			if(Screen_Status.Color_Num < 2)
			{	
				for(j = 0; j < 8; j ++)
				{
					Temp = Scan_Data[0][j] + (Scan_Data[0][8 + j]<<8);
					SET_CLK_LOW();
					GPIOD->ODR = Temp;//(GPIOD->ODR & 0xFF00) | Scan_Data[0][j]; //输出R1-R8
					SET_CLK_HIGH();
				}
			}
			else
			{
 				for(j = 0; j < 8; j ++)
				{
					GPIOD->ODR = Scan_Data[0][j] + (Scan_Data[0][8 + j]<<8);//(GPIOD->ODR & 0xFF00) | Scan_Data[0][j]; //输出R1-R8
					SET_CLK_LOW();

					GPIOE->ODR = Scan_Data[1][j] + (Scan_Data[1][8 + j]<<8);//(GPIOD->ODR & 0xFF00) | Scan_Data[0][j]; //输出R1-R8
					SET_CLK_HIGH();
				}
			}

		}
	}
#endif
	 //此处是硬件扫描方式代码

  //return;	 
	//关闭OE使能
	Set_OE_Duty_Polarity(0, Screen_Para.Scan_Para.OE_Polarity);

	if(Screen_Para.Scan_Para.Line_Hide > 0)
	  Delay_us(Screen_Para.Scan_Para.Line_Hide*10); //行消隐时间
    Delay_us(20);

    SET_LAT(0); //锁存信号输出
	nop();
	nop();
    SET_LAT(1); //锁存信号输出
    
    Set_Block_Row(Screen_Status.Scan_Row);
    Screen_Status.Scan_Row++;
    if(Screen_Status.Scan_Row >= Screen_Para.Scan_Para.Rows)
      Screen_Status.Scan_Row = 0;
	
	//重新打开OE
	Set_OE_Duty_Polarity(50, Screen_Para.Scan_Para.OE_Polarity);
	//_USART_Cmd(USART1, DISABLE);
    //Set_Clock_Normal_Speed();
	//_USART_Cmd(USART1, ENABLE); 
	//USART_Clar
    GPIO_ResetBits(GPIOB,GPIO_Pin_9); //测试输出
	Flag = 0; 
}

void LED_Scan_Screen(void)
{
  INT8U i;

  for(i = 0; i < 15; i ++)
    LED_Scan_One_Row();

}


