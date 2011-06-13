#define LED_SCAN_C
#include "Includes.h"

//获取第Rows行第Index个字节的移动数据对应的在屏幕数据中的坐标
//Block表示扫描块的块号
//Rows表示行号，该行号对应接口中的ABCD的行号,几分之几扫?
//BRow表示该块号内的第几条扫描线
//Cols表示宽度，595个数,实际为屏幕宽度/8
//Index表示该扫描线中的第Index个字节
//*pX和*pY返回坐标
//Direct表示数据进入方向,Rows_Fold表示行折叠数，Cols_Fold表示列折数
void Get_Shift_Data(INT16U Block, INT16U Rows, INT16U BRow, INT16U Cols, INT16U Index,\
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
  else if(Direct EQ 0x01) //左下进入
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
  else if(Direct EQ 0x02) //右上进入
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
  INT16U i,j,k,m,Cols;
  INT16U Blocks;
  //INT32U Row_Freq;
  
  if(Screen_Status.Open_Flag EQ 0) //关机状态，不显示
    return;

  if(Screen_Para.Scan_Para.Rows EQ 0)
  {
	Screen_Para.Scan_Para.Rows = 16;
	SET_SUM(Screen_Para);
  }

  //Block数可以理解为单元板纵向的个数
  Blocks = Screen_Para.Base_Para.Height / (Screen_Para.Scan_Para.Rows * (Screen_Para.Scan_Para.Rows_Fold + 1)); //1.2.4.8.16扫？
 
  if(Blocks > MAX_SCAN_BLOCK_NUM)
	 Blocks = MAX_SCAN_BLOCK_NUM;

  Cols = Screen_Para.Base_Para.Width / 8;
  //对每个Blocks进行扫描
  //每一条扫描线需要Screen_Para.Base_Para.Width / 8 * Screen_Para.Scan_Para.Rows_Fold个字节
  for(i = 0; i < Cols * (Screen_Para.Scan_Para.Rows_Fold + 1); i ++)
  {
    //对每个Block的每条扫描线同时输出一个字节
    for(j = 0; j < Blocks; j++)
    {
    //获取该扫描线上的所有字节并输出
      Get_Shift_Data(j, \
              Screen_Para.Scan_Para.Rows, \
              Screen_Status.Scan_Row,\
              Cols, \
              i, \
              Screen_Para.Scan_Para.Direct, \
              Screen_Para.Scan_Para.Rows_Fold, \
              Screen_Para.Scan_Para.Cols_Fold,\
              Screen_Status.Scan_Data[j]);

	  Screen_Status.Scan_Data[j][0] = 0xFF - Screen_Status.Scan_Data[j][0];
	  Screen_Status.Scan_Data[j][1] = 0xFF - Screen_Status.Scan_Data[j][1];
	  Screen_Status.Scan_Data[j][2] = 0xFF - Screen_Status.Scan_Data[j][2];
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
    /*
	 //Set_Block_OE_En(0); //关闭使能 
    SET_LAT(0); //锁存信号输出
    SET_LAT(1); //锁存信号输出

	//Screen_Status.Scan_Row = 2;
    Set_Block_Row(Screen_Status.Scan_Row);
    Screen_Status.Scan_Row++;
    if(Screen_Status.Scan_Row >= Screen_Para.Scan_Para.Rows)
      Screen_Status.Scan_Row = 0;

	//Set_Block_OE_En(1); //重新打开使能
	*/
  }
  
  //for(i = 0; i < Cols * (Screen_Para.Scan_Para.Rows_Fold + 1); i ++)
  {  
     //行消隐时间
    Set_Block_OE_En(0); //关闭使能
    //Delay_us(Screen_Para.Scan_Para.Line_Hide); //行消隐时间
    
	//GPIO_ResetBits(GPIOB,GPIO_Pin_0);
    SET_LAT(0); //锁存信号输出
    SET_LAT(1); //锁存信号输出
    
    Set_Block_Row(Screen_Status.Scan_Row);
    Screen_Status.Scan_Row++;
    if(Screen_Status.Scan_Row >= Screen_Para.Scan_Para.Rows)
      Screen_Status.Scan_Row = 0;
  
	//GPIO_ResetBits(GPIOB,GPIO_Pin_0);
    Set_Block_OE_En(1); //重新打开使能
    
    //行扫描的频率等于屏扫描频率*扫描行数
    //Row_Freq = (INT32U)Screen_Para.Scan_Para.Screen_Freq*Screen_Para.Scan_Para.Rows; //行扫描的频率
    //Reset_Scan_Timer(Row_Freq); 
	}
	
}
