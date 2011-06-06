#define LED_SCAN_C
#include "Includes.h"

//获取第Rows行第Index个字节的移动数据对应的在屏幕数据中的坐标
//Rows表示行号，该行号对应接口中的ABCD的行号
//Cols表示宽度，595个数
//Index表示该扫描线中的第Index个字节
//*pX和*pY返回坐标
//Direct表示数据进入方向,Rows_Fold表示行折叠数，Cols_Fold表示列折数
void Get_Shift_Data(INT16U Block, INT16U Rows, INT16U BRow, INT16U Cols, INT16U Index,\
                          INT8U Direct, INT8U Rows_Fold, INT8U Cols_Fold, INT8U *pDst)
{
  INT16U Fold_Size,X,Y;
  INT8U Screen_Color_Num, *p;
  INT8U Off;

  X = Y = 0;  
  if(Direct EQ 0x01 || Direct EQ 0x03)
    Index = Cols * Rows_Fold - Index;
  
  Fold_Size = Rows_Fold*Cols_Fold;  
  if(Direct EQ 0x00 || Direct EQ 0x03)//左上进入、右下进入
  {
    X = Index / Rows_Fold  + (Index % Fold_Size) % Cols_Fold;
    Y = Block * Rows* Rows_Fold + BRow * Rows_Fold + (Index % Fold_Size) / Cols_Fold;
  }
  else if(Direct EQ 0x01 || Direct EQ 0x02) //左下进入、右上进入
  {
    X = Index / Rows_Fold + (Index % Fold_Size) % Cols_Fold;
    Y = (Block  + 1)*  Rows * Rows_Fold - BRow * Rows_Fold - (Index % Fold_Size) / Cols_Fold;    
  }
  else
    ASSERT_FAILED();
 
  Screen_Color_Num = Get_Screen_Color_Num();  

  p = Show_Data.Color_Data + (Y*Cols + X)*Screen_Color_Num;
  
  Off = 0;
  
  //获取三色数据
  //红
  if(GET_BIT(Screen_Para.Base_Para.Color, 0))
    *pDst = *(p + Off++);//Show_Data.Color_Data[Data_Index];
  else 
    *pDst = 0;
  
  //绿
  if(GET_BIT(Screen_Para.Base_Para.Color, 1))
    *(pDst + 1) = *(p + Off ++);//Show_Data.Color_Data[Data_Index];
  else 
    *(pDst + 1) = 0;
  
  //蓝
  if(GET_BIT(Screen_Para.Base_Para.Color, 2))
    *(pDst + 2) = *(p + Off ++);//Show_Data.Color_Data[Data_Index];
  else 
    *(pDst + 2) = 0;  
  //memcpy(pDst, Show_Data.Color_Data + Data_Index*Screen_Color_Num, Screen_Color_Num);
  return ;//ReIndex;
}


INT8U Get_Next_Byte_Posi(INT16U X, INT16U Y, INT16U *pX, INT16U *pY,\
                         INT8U Direct, INT8U Rows_Fold, INT8U Cols_Fold)
{
  if(Direct EQ 0x00)//左上进入
  {
    if(X % Cols_Fold EQ 0 && Y % Rows_Fold EQ 0)
    {
      *pX = X - 1;
      *pY = Y + Rows_Fold - 1;
    }
    else if(X % Cols_Fold EQ 0)
    {
      *pX = X + Cols_Fold - 1;
      *pY = Y - 1;
    }
    else
    {
       *pX = X - 1; 
       *pY = Y;
    }
  }
  else if(Direct EQ 0x01) //右上进入
  {
    if(X % Cols_Fold EQ (Cols_Fold - 1) && Y % Rows_Fold EQ 0)
    {
      *pX = X + 1;
      *pY = Y + Rows_Fold - 1;
    }
    else if(X % Cols_Fold EQ (Cols_Fold - 1))
    {
      *pX = X - (Cols_Fold - 1);
      *pY = Y - 1;
    }
    else
    {
       *pX = X + 1; 
       *pY = Y;
    }    
  }
  else if(Direct EQ 0x02) //左下进入
  {
    if(X % Cols_Fold EQ 0 && Y % Rows_Fold EQ (Rows_Fold - 1))
    {
      *pX = X - 1;
      *pY = Y - (Rows_Fold - 1);
    }
    else if(X % Cols_Fold EQ 0)
    {
      *pX = X + (Cols_Fold - 1);
      *pY = Y + 1;
    }
    else
    {
       *pX = X - 1; 
       *pY = Y;
    }     
  }
  else if(Direct EQ 0x03) //右下进入
  {
    if(X % Cols_Fold EQ (Cols_Fold - 1) && Y % Rows_Fold EQ (Rows_Fold - 1))
    {
      *pX = X + 1;
      *pY = Y - (Rows_Fold - 1);
    }
    else if(X % Cols_Fold EQ (Cols_Fold - 1))
    {
      *pX = X - (Cols_Fold - 1);
      *pY = Y + 1;
    }
    else
    {
       *pX = X + 1; 
       *pY = Y;
    }     
  }
  else
  {
    ASSERT_FAILED();
    *pX = 0;
    *pY = 0;
  }
  
  return 1;
}
                         
//调用该函数每次扫描一行
//每中断一次调用一次该函数
void LED_Scan_One_Row(void)
{
  INT16U i,j,k,m;
  INT16U Blocks;
  INT32U Row_Freq;
  
  if(Screen_Status.Open_Flag EQ 0) //关机状态，不显示
    return;

  if(Screen_Para.Scan_Para.Rows EQ 0)
  {
	Screen_Para.Scan_Para.Rows = 1;
	SET_SUM(Screen_Para);
  }

  if(Screen_Para.Scan_Para.Rows_Fold EQ 0)
  {
	Screen_Para.Scan_Para.Rows_Fold = 1;
	SET_SUM(Screen_Para);
  }

  //Block数可以理解为单元板纵向的个数
  Blocks = Screen_Para.Base_Para.Height / (Screen_Para.Scan_Para.Rows * Screen_Para.Scan_Para.Rows_Fold); //1.2.4.8.16扫？
 
  if(Blocks > MAX_SCAN_BLOCK_NUM)
	 Blocks = MAX_SCAN_BLOCK_NUM;

  //对每个Blocks进行扫描
  //每一条扫描线需要Screen_Para.Base_Para.Width / 8 * Screen_Para.Scan_Para.Rows_Fold个字节
  for(i = 0; i < Screen_Para.Base_Para.Width / 8 * Screen_Para.Scan_Para.Rows_Fold; i ++)
  {
    //对每个Block的每条扫描线同时输出一个字节
    for(j = 0; j < Blocks; j++)
    {
    //获取该扫描线上的所有字节并输出
      Get_Shift_Data(j, \
              Screen_Para.Scan_Para.Rows, \
              Screen_Status.Scan_Row,\
              Screen_Para.Base_Para.Width, \
              i, \
              Screen_Para.Scan_Para.Direct, \
              Screen_Para.Scan_Para.Rows_Fold, \
              Screen_Para.Scan_Para.Cols_Fold,\
              Screen_Status.Scan_Data[j]);
    }
    
    //对所有的block输出一个字节
    //如果是从左向右，应该先输出高位再输出低位
    if(Screen_Para.Scan_Para.Direct EQ 0x00 || Screen_Para.Scan_Para.Direct EQ 0x01)
    {
      for(j = 0; j < 8 ; j++)
      {
	    m = 7 - j;
        //Set_Shift_Bit_Clk(0); //移位数据时钟为0
        SET_CLK(0);

        for(k = 0; k < Blocks; k++)
        {/*
          Set_Shift_Bit(k, 0, GET_BIT(Screen_Status.Scan_Data[k][0], 7-j));//红色 Rk
          Set_Shift_Bit(k, 1, GET_BIT(Screen_Status.Scan_Data[k][1], 7-j));//绿色 Gk
          Set_Shift_Bit(k, 2, GET_BIT(Screen_Status.Scan_Data[k][2], 7-j));//蓝色 Bk
		*/
		 SET_SHIFT_BIT(k, Screen_Status.Scan_Data[k], m); 
		}
        
        //Set_Shift_Bit_Clk(1); //移位时钟置1
		SET_CLK(1);
      } 
    }
    else //如果从右往左输出应该先输出低位
    {
      for(j = 0; j < 8 ; j++)
      {
        //Set_Shift_Bit_Clk(0); //移位数据时钟为0
		SET_CLK(0);
        
        for(k = 0; k < Blocks; k++)
        {/*
          Set_Shift_Bit(k, 0, GET_BIT(Screen_Status.Scan_Data[k][0], j));//红色
          Set_Shift_Bit(k, 1, GET_BIT(Screen_Status.Scan_Data[k][1], j));//绿色
          Set_Shift_Bit(k, 2, GET_BIT(Screen_Status.Scan_Data[k][2], j));//蓝色
          */
		  SET_SHIFT_BIT(k, Screen_Status.Scan_Data[k], j);
		}
        
        //Set_Shift_Bit_Clk(1); //移位时钟置1
		SET_CLK(1);
      }      
    }
    
    //行消隐时间
    Set_Block_OE_En(0); //关闭使能
    Delay_us(Screen_Para.Scan_Para.Line_Hide); //行消隐时间
    
    SET_LAT(0); //锁存信号输出
    SET_LAT(1); //锁存信号输出
    
    Set_Block_Row(Screen_Status.Scan_Row);
    Screen_Status.Scan_Row++;
    if(Screen_Status.Scan_Row >= Screen_Para.Scan_Para.Rows)
      Screen_Status.Scan_Row = 0;
  
    Set_Block_OE_En(1); //重新打开使能
    
    //行扫描的频率等于屏扫描频率*扫描行数
    //Row_Freq = (INT32U)Screen_Para.Scan_Para.Screen_Freq*Screen_Para.Scan_Para.Rows; //行扫描的频率
    //Reset_Scan_Timer(Row_Freq);
  }
  

/*  
  Shift_Bytes = (INT16U)Screen_Para.Scan_Para.Rows_Fold*Screen_Para.Base_Para.Width/8;
  Block_Num = (INT16U)Scan_Para.Base_Para.Height/Screen_Para.Scan_Para.Rows_Fold;
  
  for(i = 0; i < Shift_Bytes; i ++)
  {
   SHIFT_CLK_0;
   
   SHIFT_CLK_1;
  }
  
*/  
  
  
  
}
