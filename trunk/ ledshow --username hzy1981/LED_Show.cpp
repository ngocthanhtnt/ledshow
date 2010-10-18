#define LED_SHOW_C
#include "Includes.h"


const CNZK_Info CN_ZK[]=
{
  {0,{0},{0},{0}}
};

//每档速度的延时,单位为毫秒
const INT16U Step_Delay[]=
{
  10,
  20,
  30,
  40,
  50,
  60,
  70,
  80,
  90,
  100
};

//数据移入方式
const S_Mode_Func Mode_Func[]=
{
  {&Move_Left},//0
  {&Move_Right},//1
  {&Move_Up},//2
  {&Move_Down},//3
  {&Move_Left_Cover},//4
  {&Move_Right_Cover},//5
  {&Move_Up_Cover},//6
  {&Move_Down_Cover},//7
  {&Move_Left_Up_Cover},//8
  {&Move_Right_Up_Cover},//9
  {&Move_Left_Down_Cover},//10
  {&Move_Right_Down_Cover},//11
  {&Move_Left_Right_Open},//12
  {&Move_Up_Down_Open},//13
  {&Move_Left_Right_Close},//14
  {&Move_Up_Down_Close},//15
  
};

//获取得颜色
INT8U Get_Color()
{
  if(!(Screen_Para.Color <=2))
    return 0;
  else
  {
    return Screen_Para.Color;
  } 
}  

//获取缓冲区中第Index位的值
INT8U Get_Buf_Bit(INT8U Buf[], INT32U Buf_Size, INT32U Index)
{
  if(Index >= (INT32U)Buf_Size * 8)
  {
    ASSERT_FAILED();
    return 0;
  }
  
  return (Buf[Index >>3] & (0x01 << (Index & 0x07)))>0?1:0;
}

//设置缓冲区中第Index位的值
void Set_Buf_Bit(INT8U Buf[], INT32U Buf_Size, INT32U Index, INT8U Value)
{
  if(Index >= Buf_Size * 8)
  {
    ASSERT_FAILED();
    return;
  }
  
  if(Value EQ 0)
    Buf[Index >>3] = (Buf[Index >>3] & (~(0x01 << (Index & 0x07))));
  else
    Buf[Index >>3] = (Buf[Index >>3] | (0x01 << (Index & 0x07)));
}

//获取一个矩形数据缓冲区的某坐标点的值 
//Buf_Size为缓冲区长度,Width为矩形区域宽度
//X\Y为矩形中的坐标点
INT8U Get_Rect_Buf_Bit(INT8U Buf[], INT16U Buf_Size, INT16U Width, INT16U X, INT16U Y)
{
  INT16U Index;
  
  Index = ((Y/8 * Width) + X)*8 + Y %8;
  return Get_Buf_Bit(Buf, Buf_Size, Index);//Index;
  
}

//设置一个矩形数据缓冲区的某坐标点的值 
//Buf_Size为缓冲区长度,Width为矩形区域宽度
//X\Y为矩形中的坐标点
//Value为该点值
void Set_Rect_Buf_Bit(INT8U Buf[], INT16U Buf_Size, INT16U Width, INT16U X, INT16U Y, INT8U Value)
{
  INT16U Index;
  
  Index = ((Y/8 * Width) + X)*8 + Y %8;
  Set_Buf_Bit(Buf, Buf_Size, Index, Value);//Index;  
}

/*
//Buf到分区的映射
INT32U Buf_2_Area_Bit_Index_Map(INT32U Buf_Bit, INT8U Area_No, INT16U X, INT16U Y, INT16U X_Len, INT16U Y_Len)
{
  INT32U Index;
  INT32U X0, Y0;

  X0 = Buf_Bit % X_Len;
  Y0 = Buf_Bit / X_Len;

  Get_Area_Point_Index(Area_No, X + X0, Y + Y0);
}
*/

//复制一个Buf到分区中的一个Rect中
//pSrc是源缓冲区
//Src_Size表示源缓冲区的最大长度
//pDst表示目标显示数据区
//Area_No表示目标分区
//X,Y,X_Len,Y_Len目标缓冲中的一个Rect
void Copy_Buf_2_Area_Rect(INT8U *pSrc, INT16U Src_Size, S_Show_Data *pDst, INT8U Area_No, INT16U X, INT16U Y, INT16U X_Len, INT16U Y_Len)
{
  INT32U i,j;
  INT8U Re;

  for(i = 0; i <X_Len; i ++)
    for(j = 0; j <Y_Len; j ++)
    {
      Re = Get_Rect_Buf_Bit(pSrc, Src_Size, X_Len, i, j);
      Set_Area_Point_Data(pDst, Area_No, X + i, Y + j, Re);
    }
}

//用于分段拷贝缓冲区中数据到显示分区中
//pSrc表示源数据缓冲
//Src_Len源缓冲长度
//Src_Off表示当前复制的数据在整个矩形数据中的起始偏移
//pDst目标显示缓冲区
//Area_No目标分区号
//X,Y,X_Len,Y_Len表示目标分区中的一个矩形，复制pSrc显示数据到这个矩形中
void Copy_Buf_2_Area_Rect_0(INT8U *pSrc, INT16U Src_Len, INT16U Src_Off, \
                            S_Show_Data *pDst, INT8U Area_No, INT16U X, INT16U Y, INT16U X_Len, INT16U Y_Len)
{
  INT32U i;//j,Index;
  INT16U X0,Y0;
  INT8U Re;

  for(i = 0; i <Src_Len *8; i ++)
  {
    Re = Get_Buf_Bit(pSrc, Src_Len, i);
    X0 = (Src_Off*8 + i) % X_Len;
    Y0 = (Src_Off*8 + i) / X_Len;
    if(X0 < X_Len && Y0 < Y_Len) //X0,Y0必须在X_Len和Y_Len的范围内
      Set_Area_Point_Data(pDst, Area_No, X+X0, Y+Y0, Re);
  }
}
//复制一个分区中的矩形数据到目标缓冲区中
//pDst目标缓冲区
//Dst_Size目标缓冲区的大小
//pSrc源显示区
//源分区
//X,Y,X_Len,Y_Len表示源分区中的矩形
void Copy_Area_Rect_2_Buf(INT8U *pDst, INT16U Dst_Size, S_Show_Data *pSrc, INT8U Area_No, INT16U X, INT16U Y, INT16U X_Len, INT16U Y_Len)
{
  INT32U i,j;
  INT8U Re;


  for(i = 0; i <X_Len; i ++)
    for(j = 0; j <Y_Len; j ++)
    {
      Re = Get_Area_Point_Data(pSrc, Area_No, X + i, Y + j);
      Set_Rect_Buf_Bit(pDst, Dst_Size, X_Len, i, j, Re);
    }
}

//获取某个分区的宽度
//Area_No分区号
INT16U Get_Area_Width(INT8U Area_No)
{
  if(Area_No >= MAX_AREA_NUM)
  {
    ASSERT_FAILED();
    return 0;
  }
  
  return Program_Para.Area[Area_No].X_Len;
}

//获取某个分区的高度
//Area_No分区号
INT16U Get_Area_Height(INT8U Area_No)
{
  if(Area_No >= MAX_AREA_NUM)
  {
    ASSERT_FAILED();
    return 0;
  }
  
  return Program_Para.Area[Area_No].Y_Len;  
}

//获取一个分区的像素个数,Area_No表示分区号
INT32U Get_Area_Size(INT8U Area_No)
{
  if(Area_No >= MAX_AREA_NUM)
  {
    ASSERT_FAILED();
    return 0;
  }
  
  return (INT32U)Program_Para.Area[Area_No].X_Len * Program_Para.Area[Area_No].Y_Len;  
}

//获取分区的左上点位置
INT8U Get_Area_TopLeft(INT8U Area_No, S_Point *pPoint)
{
  if(Area_No >= MAX_AREA_NUM)
  {
    ASSERT_FAILED();
    pPoint -> X = 0;
    pPoint -> Y = 0;
    return 0;
  }
  
  pPoint->X = Program_Para.Area[Area_No].X;
  pPoint->Y = Program_Para.Area[Area_No].Y;
  
  return 1;
}

//获取区域中某点的索引
//Area_No表示分区号
//x,y表示在分区内的坐标
INT32U Get_Area_Point_Index(INT8U Area_No, INT16U X, INT16U Y)
{
  INT32U Index;
  
  if(Area_No > MAX_AREA_NUM)
  {
    ASSERT_FAILED();
    return 0;	
  }
  
  if(X >= Program_Para.Area[Area_No].X_Len ||\
     Y >= Program_Para.Area[Area_No].Y_Len)
  {
    ASSERT_FAILED();
    return 0;
  }

  X += Program_Para.Area[Area_No].X;
  Y += Program_Para.Area[Area_No].Y;
 
  if(X >= Screen_Para.Width ||\
     Y >= Screen_Para.Height)
  {
    ASSERT_FAILED();
    return 0;
  }

  Index = (((Y>>3) * Screen_Para.Width) + X)*8 + (Y & 0x07);
  return Index;
}

//位拷贝
//pSrc源缓冲区
//Src_Len源缓冲区长度
//Src_Index位拷贝的起始位置
//Bits拷贝的位数
//pDst目标缓冲区
//Dst_Index目标的起始位
//Dst_Len目标缓冲区的长度
/*
void Bits_Copy(INT8U *pSrc, INT16U Src_Len, INT32U Src_Index, INT32U Bits, \
               INT8U *pDst, INT16U Dst_Len, INT32U Dst_Index)
{
  INT32U i;
  INT8U Re;
  
  for(i = 0 ; i < Bits; i ++)
  {
    Re = Get_Buf_Bit(pSrc, Src_Len, Src_Index + i);
    Set_Buf_Bit(pDst, Dst_Len, Dst_Index + i, Re);
  }
  
}*/

//位拷贝
//pSrc源缓冲区
//Src_Len源缓冲区长度
//Src_Index位拷贝的起始位置
//Bits拷贝的位数
//pDst目标缓冲区
//Dst_Index目标的起始位
//Dst_Len目标缓冲区的长度
/*
void Copy_Bits_2_Area(INT8U *pSrc, INT16U Src_Len, INT16U Width, INT32U Bits, \
               S_Show_Data *pDst, INT8U Area_No, INT16U X, INT16U Y, INT16U X_Len, INT16U Y_Len, INT16U Dst_Index)
{
  INT32U i;
  INT8U Re;
  
  for(i = 0 ; i < Bits; i ++)
  {
    Re = Get_Rect_Buf_Bit(pSrc, Src_Len, Width, X, Y);
    Set_Area_Point_Data(pDst, Area_No, Dst_Len, Dst_Index + i, Re);
  }
  
}
*/

//当前节目的某点数据,第0位到第2位分别为三种颜色
//pSrc_Buf，显示数据buf
//Area_No，分区号
//x,y分区坐标
INT8U Get_Area_Point_Data(S_Show_Data *pSrc_Buf, INT8U Area_No, INT16U X, INT16U Y) //获取一个区域内一个点的数据
{
  INT32U Index;

  Index = Get_Area_Point_Index(Area_No, X, Y);
  
  if(Screen_Para.Color EQ 0)  //单色屏
    return Get_Buf_Bit(pSrc_Buf->Color_Data, sizeof(pSrc_Buf->Color_Data),Index);
  else if(Screen_Para.Color EQ 1) //双色屏
    return Get_Buf_Bit(pSrc_Buf->Color_Data, sizeof(pSrc_Buf->Color_Data), ((Index>>3)<<4) + (Index & 0x07)) +\
      (Get_Buf_Bit(pSrc_Buf->Color_Data, sizeof(pSrc_Buf->Color_Data), ((Index>>3)<<4) + 8 + (Index & 0x07))<<1);
  else if(Screen_Para.Color EQ 2) //三色屏
    return Get_Buf_Bit(pSrc_Buf->Color_Data, sizeof(pSrc_Buf->Color_Data), (Index>>3)*24 + (Index & 0x07)) +\
      (Get_Buf_Bit(pSrc_Buf->Color_Data, sizeof(pSrc_Buf->Color_Data), (Index>>3)*24 + 8 + (Index & 0x07))<<1)+
      (Get_Buf_Bit(pSrc_Buf->Color_Data, sizeof(pSrc_Buf->Color_Data), (Index>>3)*24 + 16 + (Index & 0x07))<<2);
  else
    return 0;
}
/*
INT8U Get_Area_Offset_Len(S_Show_Data *pBuf, INT8U Area_No, INT8U **pOff, INT16U *pLen)
{
  INT32U Index;
  
  Index = Get_Area_Point_Index(Area_No, X, Y);
 
  if(Screen_Para.Color EQ 0)  //单色屏
    return Get_Buf_Bit(pSrc_Buf->One_Color_Data.Color0, sizeof(pSrc_Buf->One_Color_Data.Color0),Index);
  else if(Screen_Para.Color EQ 1) //双色屏
    return Get_Buf_Bit(pSrc_Buf->Two_Color_Data.Color0, sizeof(pSrc_Buf->Two_Color_Data.Color0), Index) +\
      (Get_Buf_Bit(pSrc_Buf->Two_Color_Data.Color1, sizeof(pSrc_Buf->Two_Color_Data.Color1), Index) << 1);
  else if(Screen_Para.Color EQ 2) //三色屏
    return Get_Buf_Bit(pSrc_Buf->Three_Color_Data.Color0, sizeof(pSrc_Buf->Two_Color_Data.Color0), Index) + \
      (Get_Buf_Bit(pSrc_Buf->Three_Color_Data.Color1, sizeof(pSrc_Buf->Three_Color_Data.Color1), Index) << 1) +\
        (Get_Buf_Bit(pSrc_Buf->Three_Color_Data.Color2, sizeof(pSrc_Buf->Three_Color_Data.Color2), Index) << 2);
  else
    return 0;  
  
}
*/
//设置某节目区域中某点的数据,第0-2位分别表示三种颜色
//pDst_Buf，设置该显示缓冲中的点
//Area_No表示分区号
//x,y坐标位置
//Value点
void Set_Area_Point_Data(S_Show_Data *pDst_Buf, INT8U Area_No, INT16U X, INT16U Y, INT8U Value) //设置一个区域的点   
{
  INT32U Index;
  
  Index = Get_Area_Point_Index(Area_No, X, Y);
  
  if(Screen_Para.Color EQ 0)  //单色屏
    Set_Buf_Bit(pDst_Buf->Color_Data, sizeof(pDst_Buf->Color_Data),Index, (Value & 0x01));
  else if(Screen_Para.Color EQ 1) //双色屏
  {
    Set_Buf_Bit(pDst_Buf->Color_Data, sizeof(pDst_Buf->Color_Data), ((Index>>3)<<4) + (Index & 0x07), (Value & 0x01));
    Set_Buf_Bit(pDst_Buf->Color_Data, sizeof(pDst_Buf->Color_Data), ((Index>>3)<<4) + 8+ (Index & 0x07), (Value & 0x02)>>1);
  }
  else if(Screen_Para.Color EQ 2) //三色屏
  {
    Set_Buf_Bit(pDst_Buf->Color_Data, sizeof(pDst_Buf->Color_Data), (Index>>3)*24 + (Index & 0x07), (Value & 0x01));
    Set_Buf_Bit(pDst_Buf->Color_Data, sizeof(pDst_Buf->Color_Data), (Index>>3)*24 + 8 + (Index & 0x07), (Value & 0x02)>>1);
    Set_Buf_Bit(pDst_Buf->Color_Data, sizeof(pDst_Buf->Color_Data), (Index>>3)*24 + 16 + (Index & 0x07), (Value & 0x04)>>2);
  }
} 
/*
//复制一个方形区域
//pSrc_Buf 原显示数据缓冲区
//Area_No分区号
//pSrc_Point 源举行的左上点位置
//X_Len宽度,Y_Len高度
//pDst_Buf 目标显示缓冲
//pDst_Point 目标矩形的左上点位置
void Copy_Filled_Rect_Data(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pSrc_Point, INT16U X_Len, INT16U Y_Len,\
  S_Show_Data *pDst_Buf, S_Point *pDst_Point) //复制一个方形区域
{
  
}
*/
S_Point * Get_Left_Point(S_Point *pPoint0, S_Point *pPoint1)
{
  if(pPoint0->X < pPoint1->X) //point0在最左边
  {
    return pPoint0;
  }
  else
  {
    return pPoint1;
  }  
}

//获取两个点之中的右边一个点，X座标较大的一个
S_Point * Get_Right_Point(S_Point *pPoint0, S_Point *pPoint1)
{
  if(pPoint0->X > pPoint1->X) //point0在最左边
  {
    return pPoint0;
  }
  else
  {
    return pPoint1;
  }  
}

S_Point * Get_Up_Point(S_Point *pPoint0, S_Point *pPoint1)
{
  if(pPoint0->Y < pPoint1->Y) //point0在最上边
  {
    return pPoint0;
  }
  else
  {
    return pPoint1;
  }
}

//获取两个点之中的下边一个点，Y座标较大的一个
S_Point * Get_Down_Point(S_Point *pPoint0, S_Point *pPoint1)
{
  if(pPoint0->Y > pPoint1->Y) //point0在最下边
  {
    return pPoint0;
  }
  else
  {
    return pPoint1;
  }
}

S_Point * Get_X_Mid_Point(S_Point *pPoint0, S_Point *pPoint1, S_Point *pPoint2)
{
  S_Point *pLeft, *pRight, *pMid;

  pLeft = Get_Left_Point(pPoint0, pPoint1);
  pLeft = Get_Left_Point(pLeft, pPoint2);

  pRight = Get_Right_Point(pPoint0, pPoint1);
  pRight = Get_Right_Point(pRight, pPoint2);

  if(pPoint0 != pLeft && pPoint0 != pRight)
      pMid = pPoint0;
  else if(pPoint1 != pLeft && pPoint1 != pRight)
      pMid = pPoint1;
  else
      pMid = pPoint2;
}

S_Point * Get_Y_Mid_Point(S_Point *pPoint0, S_Point *pPoint1, S_Point *pPoint2)
{
    S_Point *pUp, *pDown, *pMid;

    pUp = Get_Up_Point(pPoint0, pPoint1);
    pUp = Get_Up_Point(pUp, pPoint2);

    pDown = Get_Down_Point(pPoint0, pPoint1);
    pDown = Get_Down_Point(pDown, pPoint2);

    if(pPoint0 != pUp && pPoint0 != pDown)
        pMid = pPoint0;
    else if(pPoint1 != pUp && pPoint1 != pDown)
        pMid = pPoint1;
    else
        pMid = pPoint2;
}
//复制一条线
//pSrc_Buf,源显示缓冲
//Area_No,分区号
//pPoint0, 源线的起点
//pPoint1, 源线的终点
//pDst_Buf, 目标显示缓冲
//pPoint2, 目标线的起始位置
void Copy_Line(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pPoint0, S_Point *pPoint1, \
  S_Show_Data *pDst_Buf, S_Point *pPoint2)  //复制一条线
{
  INT8U Data;
  S_Point *p0, *p1;
  INT32S i,j;
  
  p0 = Get_Left_Point(pPoint0, pPoint1);
  p1 = Get_Right_Point(pPoint0, pPoint1);
  
  if(p0 != p1) //不是在垂直的一条线上
  {
      for(i = p0 -> X; i <= p1->X ; i ++)
      {
        j = GET_LINE_Y((INT32S)p0->X,(INT32S)p0->Y, (INT32S)p1->X, (INT32S)p1->Y, i);//(INT32S)pLeft->Y + (INT32S)(i - pLeft ->X)((INT32S)(pRgiht->Y) - (INT32S)(pLeft->Y))/(pRight -> X - pLeft->X) ;

        if(j < 0)
          ASSERT_FAILED();

        Data = Get_Area_Point_Data(pSrc_Buf, Area_No, (INT16U)i, (INT16U)j);
        Set_Area_Point_Data(pDst_Buf, Area_No, (INT16U)(i + pPoint2->X - pPoint0->X), (INT16U)(j + pPoint2->Y - pPoint0->Y), Data);
      }
  }
  else
  {
      p0 = Get_Up_Point(pPoint0, pPoint1);
      p1 = Get_Down_Point(pPoint0, pPoint1);

      for(j = p0->Y; j <=p1->Y; j ++)
      {
        Data = Get_Area_Point_Data(pSrc_Buf, Area_No, p0->X, j);
        Set_Area_Point_Data(pDst_Buf, Area_No, pPoint2->X, j + pPoint2->Y - pPoint0->Y, Data);
      }
  }
}

//绘制一条线
//pDst_Buf, 目标缓冲
//Area_No, 分区号
//pPoint0, 起始点
//pPoint1, 终点
//Value, 颜色
void Draw_Line(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pPoint0, S_Point *pPoint1, INT8U Value)
{
  S_Point *p0, *p1;
  INT32S i,j;
  
  p0 = Get_Left_Point(pPoint0, pPoint1);
  p1 = Get_Right_Point(pPoint0, pPoint1);
  
  if(p0 != p1)
  {
      for(i = p0 -> X; i <= p1->X ; i ++)
      {
        j = GET_LINE_Y((INT32S)p0->X,(INT32S)p0->Y, (INT32S)p1->X, (INT32S)p1->Y, i);//(INT32S)pLeft->Y + (INT32S)(i - pLeft ->X)((INT32S)(pRgiht->Y) - (INT32S)(pLeft->Y))/(pRight -> X - pLeft->X) ;

        if(j < 0)
          ASSERT_FAILED();

        Set_Area_Point_Data(pDst_Buf, Area_No, (INT16U)i, (INT16U)j, Value);
      }
  }
  else
  {
      p0 = Get_Up_Point(pPoint0, pPoint1);
      p1 = Get_Down_Point(pPoint0, pPoint1);

      for(j = p0->Y; j <=p1->Y; j ++)
        Set_Area_Point_Data(pDst_Buf, Area_No, p0->X, j, Value);
  }

}

//复制一个三角形数据--限直角三角形
//pSrc_Buf 源显示buf
//pPoint0, pPoint1, pPoint2 表示源三角的的三个坐标点
//pDst_Buf 目标显示buf
//pPoint3 目标三角位置，对应pPoint0
void Copy_Filled_Triangle(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pPoint0, S_Point *pPoint1,S_Point *pPoint2,\
  S_Show_Data *pDst_Buf, S_Point *pPoint3)  //复制一个三角形区域

{/*
  S_Point *pLeft;  //最左边的点
  S_Point *pRight; //最右边的点
  S_Point Temp;
  S_Point Temp1;
  
  pLeft = Get_Left_Point(pPoint0, pPoint1);
  pRight = Get_Right_Point(pPoint0, pPoint1);
  
  Temp.X = pLeft -> X;  //中间的X
  
  while(Temp.X != pRight -> X)
  {
    Temp.Y = GET_LINE_Y((INT32S)pLeft ->X, (INT32S)pLeft->Y, (INT32S)pRight->X, (INT32S)pRight->Y, (INT32S)Temp.X);
    Temp1.X = (INT16U)((INT32S)Temp.X + (INT32S)(pPoint3 -> X) - (INT32S)(pPoint0 -> X));
    Temp1.Y = (INT16U)((INT32S)Temp.Y + (INT32S)(pPoint3 -> Y) - (INT32S)(pPoint0 -> Y));
    Copy_Line(pSrc_Buf, Area_No, &Temp, pPoint2, pDst_Buf, &Temp1);
    Temp.X ++;
  }
  */
  S_Point *pLeft;  //最左边的点
  S_Point *pRight; //最右边的点
  S_Point *pMid;  //中间的点
  S_Point Temp0, Temp1, Temp2;

  pLeft = Get_Left_Point(pPoint0, pPoint1);
  pLeft = Get_Left_Point(pLeft, pPoint2);

  pRight = Get_Right_Point(pPoint0, pPoint1);
  pRight = Get_Right_Point(pRight, pPoint2);

  pMid = Get_X_Mid_Point(pPoint0, pPoint1, pPoint2);

  Temp0.X = pLeft -> X;  //中间的X

  do
  {
    Temp0.Y = GET_LINE_Y((INT32S)pLeft ->X, (INT32S)pLeft->Y, (INT32S)pRight->X, (INT32S)pRight->Y, (INT32S)Temp0.X);
    Temp1.X = Temp0.X;
    if(Temp1.X < pMid->X)
      Temp1.Y = GET_LINE_Y((INT32S)pLeft ->X, (INT32S)pLeft->Y, (INT32S)pMid->X, (INT32S)pMid->Y, (INT32S)Temp1.X);
    else
      Temp1.Y = GET_LINE_Y((INT32S)pRight ->X, (INT32S)pRight->Y, (INT32S)pMid->X, (INT32S)pMid->Y, (INT32S)Temp1.X);
    //Draw_Line(pDst_Buf, Area_No, &Temp0, &Temp1, Value);
    Temp2.X = Temp0.X + pPoint3->X - pPoint0->X;
    Temp2.Y = Temp0.Y + pPoint3->Y - pPoint0->Y;

    Copy_Line(pSrc_Buf, 0, &Temp0, &Temp1, pDst_Buf, &Temp2);
    Temp0.X ++;
  }while(Temp0.X <= pRight -> X);
}

//填充一个三角形
//pDst_Buf目标显示缓冲区
//Area_No分区号
//pPoint0,pPoint1,pPoint2 三角形的三个点
//Value,颜色
void Fill_Triangle(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pPoint0, S_Point *pPoint1,S_Point *pPoint2, INT8U Value)
{
  S_Point *pLeft;  //最左边的点
  S_Point *pRight; //最右边的点
  S_Point *pMid;  //中间的点
  S_Point Temp0, Temp1;
  
  pLeft = Get_Left_Point(pPoint0, pPoint1);
  pLeft = Get_Left_Point(pLeft, pPoint2);

  pRight = Get_Right_Point(pPoint0, pPoint1);
  pRight = Get_Right_Point(pRight, pPoint2);

  pMid = Get_X_Mid_Point(pPoint0, pPoint1, pPoint2);

  //Draw_Line(pDst_Buf, Area_No, pPoint0, pPoint1, Value);
  //Draw_Line(pDst_Buf, Area_No, pPoint1, pPoint2, Value);
  //Draw_Line(pDst_Buf, Area_No, pPoint2, pPoint0, Value);

  Temp0.X = pLeft -> X;  //中间的X
  
  do
  {
    Temp0.Y = GET_LINE_Y((INT32S)pLeft ->X, (INT32S)pLeft->Y, (INT32S)pRight->X, (INT32S)pRight->Y, (INT32S)Temp0.X);
    Temp1.X = Temp0.X;
    if(Temp1.X < pMid->X)
      Temp1.Y = GET_LINE_Y((INT32S)pLeft ->X, (INT32S)pLeft->Y, (INT32S)pMid->X, (INT32S)pMid->Y, (INT32S)Temp1.X);
    else
      Temp1.Y = GET_LINE_Y((INT32S)pRight ->X, (INT32S)pRight->Y, (INT32S)pMid->X, (INT32S)pMid->Y, (INT32S)Temp1.X);
    Draw_Line(pDst_Buf, Area_No, &Temp0, &Temp1, Value);
    Temp0.X ++;
  }while(Temp0.X <= pRight -> X);
}

//复制一个多边形
void Copy_Filled_Polygon(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pPoint0, S_Point *pPoint1,S_Point *pPoint2, S_Point *pPoint3,\
  S_Show_Data *pDst_Buf, S_Point *pPoint4)
{
  Copy_Filled_Triangle(pSrc_Buf, Area_No, pPoint0, pPoint1, pPoint2, pDst_Buf, pPoint4);
  Copy_Filled_Triangle(pSrc_Buf, Area_No, pPoint0, pPoint2, pPoint3, pDst_Buf, pPoint4);
}

//填充一个多边形
void Fill_Polygon(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pPoint0, S_Point *pPoint1,S_Point *pPoint2, S_Point *pPoint3, INT8U Value)
{
  Fill_Triangle(pDst_Buf, Area_No, pPoint0, pPoint3, pPoint2, Value);
  Fill_Triangle(pDst_Buf, Area_No, pPoint0, pPoint1, pPoint2, Value);

}

//复制一个矩形
void Copy_Filled_Rect(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pPoint0, INT16U X_Len, INT16U Y_Len,\
  S_Show_Data *pDst_Buf, S_Point *pPoint1)
{
  INT16U i,j;
  INT8U Data;
  
  for(i = 0; i < X_Len;  i++)
    for(j = 0; j < Y_Len; j++)
    {
      Data = Get_Area_Point_Data(pSrc_Buf, Area_No, pPoint0->X + i, pPoint0->Y + j);
      Set_Area_Point_Data(pDst_Buf, Area_No, pPoint1->X + i, pPoint1->Y + j, Data);
    }  
}

//填充一个矩形
void Fill_Rect(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pPoint0, INT16U X_Len, INT16U Y_Len,INT8U Value)
{
  INT16U i,j;
  //INT8U Data;
  
  for(i = 0; i < X_Len;  i++)
    for(j = 0; j < Y_Len; j++)
    {
      //Data = Get_Area_Point_Data(pSrc_Buf, Area_No, i, j); 
      Set_Area_Point_Data(pDst_Buf, Area_No, pPoint0->X + i, pPoint0->Y + j, Value);
    }
}


//填充一个圆形
//pDst_Buf, 目标显示缓冲
//Area_No, 分区号
//pCenter,圆中心点
//Radius,半径
//Value,颜色
void Fill_Round(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pCenter, INT16U Radius, INT8U Value)
{
  S_Point Up, Down;
  INT16U Temp,X;
  INT32S Temp0;
  
  X = pCenter -> X - Radius; //最左边一点的X坐标
  
  for(; X <= pCenter -> X + Radius; X ++)
  {
    Temp0 = ((INT32S)Radius * Radius - ((INT32S)X - (INT32S)pCenter->X)*((INT32S)X - (INT32S)pCenter->X));
    Temp = (INT16U)sqrt(Temp0);
    //上面一点
    Up.Y = pCenter->Y + Temp;
    Up.X = X;
    //下面一点
    if(pCenter->Y >= Temp)
      Down.Y = pCenter->Y- Temp;
    else
      Down.Y = 0;
    Down.X = X;
    Draw_Line(pDst_Buf, Area_No, &Down, &Up, Value);
  }
}

//复制一个实心圆
//pSrc_Buf,源显示缓冲
//Area_No,分区号
//pCenter0,源中心点
//Radius,半径
//pDst_Buf,目标缓冲
//pCenter,目标中心点
void Copy_Filled_Round(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pCenter0, INT16U Radius, S_Show_Data *pDst_Buf, S_Point *pCenter1)
{
  S_Point Up, Down,Temp;
  INT16U X,Temp1;
  
  X = pCenter0 -> X - Radius; //最左边一点的X坐标
  
  for(; X <= pCenter0 -> X + Radius; X ++)
  {
    Temp1 = (INT16U)sqrt((float)(Radius * Radius - (INT16U)((INT32S)X - (INT32S)pCenter0->X)*((INT32S)X - (INT32S)pCenter0->X)));
    //上面一点
    Up.Y = pCenter0->Y + Temp1;
    Up.X = X;
    //下面一点
    Down.Y = pCenter0->Y- Temp1;
    Down.X = X;
    
    Temp.X = (INT16U)((INT32S)Up.X + (INT32S)(pCenter1 -> X) - (INT32S)(pCenter0 -> X));
    Temp.Y = (INT16U)((INT32S)Up.Y + (INT32S)(pCenter1 -> Y) - (INT32S)(pCenter0 -> Y));
    
    Copy_Line(pSrc_Buf,Area_No, &Up, &Down, pDst_Buf, &Temp);
  }
}


//----------------------下面实现各种显示效果----------------------
//找到从一个点，按照Angle角度延伸Len长的一个点
//
void Get_Angle_Point(S_Point *pPoint0, INT16S Angle, INT16U Len, S_Point *pPoint1)
{
  pPoint1 -> X = (INT16U)((INT16S)pPoint0->X + (INT16S)Len * cos(2*PI*Angle/360));
  pPoint1 -> Y = (INT16U)((INT16S)pPoint0->Y - (INT16S)Len * sin(2*PI*Angle/360));
}

//pDst_Buf,显示目标缓冲区
//Area_No, 显示分区
//pCenter,时钟中心
//Angle,角度,-359->359
//Len,点数距离中心的长度
//Radius,点的半径
//Value,点的值也就是颜色
void Fill_Clock_Point(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pCenter, \
                      INT16S Angle, INT16U Len, INT16U Radius, INT8U Value)
{
   S_Point Point;
   
   Get_Angle_Point(pCenter, Angle, Len, &Point); //找到圆的中心点
   Fill_Round(pDst_Buf, Area_No, &Point, Radius, Value); //绘制一个圆
}

//绘制时钟的时钟、分钟线
//pDst_Buf,目标缓冲区
//Area_No,分区号
//pCenter时钟中心
//Angle 时钟线的角度0-359
//Len 时钟线的长度
//width 时钟线的宽度
//Value 时钟线的颜色
void Fill_Clock_Line(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pCenter, \
                     INT16S Angle, INT16U Len, INT16U Width, INT8U Value)
{
  S_Point Point0, Point1, Point2;
  
  Get_Angle_Point(pCenter, Angle, Len * 7 / 10, &Point0); //前端的顶点
  Get_Angle_Point(pCenter, Angle - 90, Width/2, &Point1);
  Get_Angle_Point(pCenter, Angle + 90, Width/2, &Point2);
  
  Fill_Triangle(pDst_Buf, Area_No, &Point0, &Point1, &Point2, Value);
  
  Get_Angle_Point(pCenter, Angle + 180, Len * 3 / 10, &Point0); //后端的顶点
  Get_Angle_Point(pCenter, Angle + 180 - 90, Width/2, &Point1);
  Get_Angle_Point(pCenter, Angle + 180 + 90, Width/2, &Point2);
  
  Fill_Triangle(pDst_Buf, Area_No, &Point0, &Point1, &Point2, Value); 
}

//清除某个分区的显示
//pDst_Buf显示缓冲区
void Clear_Area_Data(S_Show_Data *pDst_Buf, INT8U Area_No)
{
  INT16U X,Y,X_Len,Y_Len;
  
  X_Len = Get_Area_Width(Area_No);
  Y_Len = Get_Area_Height(Area_No);
  
  for(X = 0; X < X_Len; X++)
    for(Y = 0; Y < Y_Len; Y++)
    {
      Set_Area_Point_Data(pDst_Buf, Area_No, X, Y, 0);
    }
  
}

//显示一个表盘
//pDst_Buf目标显示缓冲区
//Area_No 目标分区
//pClock_Para 时钟参数
void Show_Clock(S_Show_Data *pDst_Buf, INT8U Area_No, S_Time *pTime, S_Clock_Para *pClock_Para)
{
   INT16U Radius;
   INT16U Width,Height;
   S_Point Point;
   INT16S Angle;
   
   if(Area_No >= MAX_AREA_NUM)
   {
     ASSERT_FAILED();
     return;
   }
   
   Width = Get_Area_Width(Area_No);
   Height = Get_Area_Height(Area_No);
   
   Radius = ((Width < Height)? Width:Height) * 95 /100 / 2; //表盘的半径 
  
   Get_Area_TopLeft(Area_No, &Point); //分区左上位置
   //分区中心位置
   Point.X += Width/2;
   Point.Y += Height/2;
  
   //369点
   for(Angle = 0; Angle < 360; Angle = Angle + 90)
   {
     //距离中心点的角度是Angle，长度是Radius * 0.9, 该点半径为Hour369_Point_Radius,颜色为 Hour369_Point_Color
      Fill_Clock_Point(pDst_Buf, Area_No, &Point, Angle, Radius * 9 / 10, \
         pClock_Para->Hour369_Point_Radius, pClock_Para->Hour369_Point_Color);
   }
 
   //整点
   for(Angle = 0; Angle < 360; Angle = Angle + 360/12)
   {
     if(Angle % 90 == 0) //369点已经绘制过了，跳过
       continue;
     //距离中心点的角度是Angle，长度是Radius * 0.9, 该点半径为Hour369_Point_Radius,颜色为 Hour369_Point_Color
     Fill_Clock_Point(pDst_Buf, Area_No, &Point, Angle, (INT16S)(Radius * 0.9), \
         pClock_Para->Hour_Point_Radius, pClock_Para->Hour_Point_Color);
   }
   //----------至此0-11点所有的点都已经绘制完成------------
   //时钟
   Fill_Clock_Line(pDst_Buf, Area_No, &Point, 90 - 360 * (pTime->Time[T_HOUR] % 12) / 12, Radius * 8 / 10,\
                   pClock_Para->Hour_Line_Width, pClock_Para->Hour_Line_Color);  
   //分钟
   Fill_Clock_Line(pDst_Buf, Area_No, &Point, 90 - 360 * pTime->Time[T_MIN] / 60, Radius * 10 / 10,\
                   pClock_Para->Min_Line_Width, pClock_Para->Min_Line_Color);
   //秒钟
   Fill_Clock_Line(pDst_Buf, Area_No, &Point, 90 - 360 * pTime->Time[T_SEC] / 60, Radius * 12 / 10,\
                   pClock_Para->Sec_Line_Width, pClock_Para->Sec_Line_Color);   
}

//上移
void Move_Up(INT8U Area_No)//上移动
{
  S_Point Temp;
  S_Point Temp1;
  
  if(Area_Status[Area_No].Step < 100) //是否已经移动完成100%
  {
    Temp.X = 0;//Program_Para.Area[Area_No].X;
    Temp.Y = 0;//Program_Para.Area[Area_No].Y;
    
    Temp1.X = 0;//Program_Para.Area[Area_No].X;// + Step +
    Temp1.Y = (100 - Area_Status[Area_No].Step) * Program_Para.Area[Area_No].Y_Len / 100;
    
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Program_Para.Area[Area_No].X_Len, Area_Status[Area_No].Step * Program_Para.Area[Area_No].Y_Len / 100,\
      &Show_Data, &Temp1);
    Area_Status[Area_No].Step += MOVE_STEP;
  } 
}

//下移
void Move_Down(INT8U Area_No)
{
  S_Point Temp;
  S_Point Temp1;
  
  if(Area_Status[Area_No].Step < 100) //是否已经移动完成100%
  {
    Temp.X = 0;//Program_Para.Area[Area_No].X;// + Step +
    Temp.Y = (100 - Area_Status[Area_No].Step) * Program_Para.Area[Area_No].Y_Len / 100;
    
    Temp1.X = 0;//Program_Para.Area[Area_No].X;
    Temp1.Y = 0;//Program_Para.Area[Area_No].Y;
    
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Program_Para.Area[Area_No].X_Len, Area_Status[Area_No].Step * Program_Para.Area[Area_No].Y_Len / 100,\
      &Show_Data, &Temp1);
    Area_Status[Area_No].Step += MOVE_STEP;
  } 
}

//左移
void Move_Left(INT8U Area_No)
{
  S_Point Temp;
  S_Point Temp1;
  
  if(Area_Status[Area_No].Step < 100) //是否已经移动完成100%
  {
    Temp.X = 0;//Program_Para.Area[Area_No].X;
    Temp.Y = 0;//Program_Para.Area[Area_No].Y;
    
    Temp1.X = (100 - Area_Status[Area_No].Step) * Program_Para.Area[Area_No].X_Len / 100;// + Step +
    Temp1.Y = 0;
    
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Area_Status[Area_No].Step * Program_Para.Area[Area_No].X_Len / 100,Program_Para.Area[Area_No].Y_Len, \
      &Show_Data, &Temp1);
    Area_Status[Area_No].Step += MOVE_STEP;
  }   
}

//右边移
void Move_Right(INT8U Area_No)
{
  S_Point Temp;
  S_Point Temp1;
  
  if(Area_Status[Area_No].Step < 100) //是否已经移动完成100%
  {
    Temp.X = (100 - Area_Status[Area_No].Step) * Program_Para.Area[Area_No].Y_Len / 100;// + Step +
    Temp.Y = 0;
    
    Temp1.X = 0;//Program_Para.Area[Area_No].X;
    Temp1.Y = 0;//Program_Para.Area[Area_No].Y;
    
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp,  Area_Status[Area_No].Step * Program_Para.Area[Area_No].X_Len / 100,Program_Para.Area[Area_No].Y_Len,\
      &Show_Data, &Temp1);
    Area_Status[Area_No].Step += MOVE_STEP;
  } 
}

//上划
void Move_Up_Cover(INT8U Area_No)
{
  S_Point Temp;
  
  if(Area_Status[Area_No].Step < 100) //是否已经移动完成100%
  {
    Temp.X = 0;// + (100 - Area_Status[Area_No].Step) * Program_Para.Area[Area_No].Y_Len / 100;
    Temp.Y = (100 - Area_Status[Area_No].Step) * Program_Para.Area[Area_No].Y_Len / 100;
    
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Program_Para.Area[Area_No].X_Len, MOVE_STEP * Program_Para.Area[Area_No].Y_Len / 100,\
      &Show_Data, &Temp);
    Area_Status[Area_No].Step += MOVE_STEP;
  }  
}

//下划
void Move_Down_Cover(INT8U Area_No)
{
  S_Point Temp;
  
  if(Area_Status[Area_No].Step < 100) //是否已经移动完成100%
  {
    Temp.X = 0;// + Step +
    Temp.Y = Area_Status[Area_No].Step * Program_Para.Area[Area_No].Y_Len / 100;
    
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Program_Para.Area[Area_No].X_Len, MOVE_STEP * Program_Para.Area[Area_No].Y_Len / 100,\
      &Show_Data, &Temp);
    Area_Status[Area_No].Step += MOVE_STEP;
  }  
}

//左划
void Move_Left_Cover(INT8U Area_No)
{
  S_Point Temp;
  
  if(Area_Status[Area_No].Step < 100) //是否已经移动完成100%
  {
    Temp.X = (100 - Area_Status[Area_No].Step) * Program_Para.Area[Area_No].X_Len / 100;// + Step +
    Temp.Y = 0;
    
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, MOVE_STEP * Program_Para.Area[Area_No].X_Len / 100, Program_Para.Area[Area_No].Y_Len,\
      &Show_Data, &Temp);
    Area_Status[Area_No].Step += MOVE_STEP;
  }  
}

//右划
void Move_Right_Cover(INT8U Area_No)
{
  S_Point Temp;
  S_Point Temp1;
  
  if(Area_Status[Area_No].Step < 100) //是否已经移动完成100%
  {
    Temp.X = Area_Status[Area_No].Step * Program_Para.Area[Area_No].Y_Len / 100;// + Step +
    Temp.Y = 0;
    
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp,  MOVE_STEP * Program_Para.Area[Area_No].X_Len / 100,Program_Para.Area[Area_No].Y_Len,\
      &Show_Data, &Temp1);
    Area_Status[Area_No].Step += MOVE_STEP;
  }  
}

//左上划
void Move_Left_Up_Cover(INT8U Area_No)
{
  S_Point Left,Up,Right;
  
  if(Area_Status[Area_No].Step < 100)
  {
    Left.X = (100 - Area_Status[Area_No].Step)*Program_Para.Area[Area_No].X_Len / 100;
    Left.Y = Program_Para.Area[Area_No].Y_Len;
    
    Up.X = Program_Para.Area[Area_No].X_Len;
    Up.Y = (100 - Area_Status[Area_No].Step)*Program_Para.Area[Area_No].Y_Len / 100;
    
    Right.X = Program_Para.Area[Area_No].X_Len;
    Right.Y = Program_Para.Area[Area_No].Y_Len;
    
    Copy_Filled_Triangle(&Show_Data_Bak, Area_No, &Left, &Up, &Right, &Show_Data, &Left);
    Area_Status[Area_No].Step += MOVE_STEP;
  }
}

//右上划
void Move_Right_Up_Cover(INT8U Area_No)
{
  S_Point Left,Up,Right;
  
  if(Area_Status[Area_No].Step < 100)
  {
    Left.X = 0;//Program_Para.Area[Area_No].X;
    Left.Y = Program_Para.Area[Area_No].Y_Len;
    
    Right.X = Area_Status[Area_No].Step * Program_Para.Area[Area_No].X_Len / 100;
    Right.Y = Program_Para.Area[Area_No].Y_Len;
    
    Up.X = 0;//Program_Para.Area[Area_No].X;
    Up.Y = (100 - Area_Status[Area_No].Step)*Program_Para.Area[Area_No].Y_Len / 100;
    
    Copy_Filled_Triangle(&Show_Data_Bak, Area_No, &Left, &Up, &Right, &Show_Data, &Left);
    Area_Status[Area_No].Step += MOVE_STEP;
  }
  
}

//左下划
void Move_Left_Down_Cover(INT8U Area_No)
{
  S_Point Left,Up,Right;
  
  if(Area_Status[Area_No].Step < 100)
  {
    Left.X = (100 - Area_Status[Area_No].Step)*Program_Para.Area[Area_No].X_Len / 100; 
    Left.Y = 0;
    
    Right.X = Program_Para.Area[Area_No].X_Len;
    Right.Y = Area_Status[Area_No].Step * Program_Para.Area[Area_No].Y_Len / 100;
    
    Up.X = Program_Para.Area[Area_No].X_Len;
    Up.Y = 0;
    
    Copy_Filled_Triangle(&Show_Data_Bak, Area_No, &Left, &Up, &Right, &Show_Data, &Left);
    Area_Status[Area_No].Step += MOVE_STEP;
  }  
}

//右下划
void Move_Right_Down_Cover(INT8U Area_No)
{
  S_Point Left,Up,Right;
  
  if(Area_Status[Area_No].Step < 100)
  {
    Left.X = 0;// + (100 - Area_Status[Area_No].Step)*Program_Para.Area[Area_No].X_Len / 100; 
    Left.Y = Area_Status[Area_No].Step * Program_Para.Area[Area_No].Y_Len / 100;
    
    Right.X = Area_Status[Area_No].Step * Program_Para.Area[Area_No].Y_Len / 100;
    Right.Y = 0;// + Area_Status[Area_No].Step * Program_Para.Area[Area_No].Y_Len / 100;
    
    Up.X = 0;// + Program_Para.Area[Area_No].X_Len;
    Up.Y = 0;
    
    Copy_Filled_Triangle(&Show_Data_Bak, Area_No, &Left, &Up, &Right, &Show_Data, &Left);
    Area_Status[Area_No].Step += MOVE_STEP;
  }  
}

//上下拉帘
void Move_Up_Down_Open(INT8U Area_No)
{
  S_Point Temp;
  
  if(Area_Status[Area_No].Step < 100)
  {
    Temp.X = 0;
    Temp.Y = (100 - Area_Status[Area_No].Step)*Program_Para.Area[Area_No].Y_Len / 200; 
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Program_Para.Area[Area_No].X_Len, Area_Status[Area_No].Step * Program_Para.Area[Area_No].Y_Len / 100, &Show_Data, &Temp);
    Area_Status[Area_No].Step += MOVE_STEP;
  }
  
}

//上下合帘
void Move_Up_Down_Close(INT8U Area_No)
{
  S_Point Temp;
  
  if(Area_Status[Area_No].Step < 100)
  {
    Temp.X = 0;
    Temp.Y = 0;// + Area_Status[Area_No].Step * Program_Para.Area[Area_No].Y_Len / 200; 
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Program_Para.Area[Area_No].X_Len, Area_Status[Area_No].Step * Program_Para.Area[Area_No].Y_Len / 200, &Show_Data, &Temp);
    
    Temp.X = 0;
    Temp.Y = Program_Para.Area[Area_No].Y_Len - Area_Status[Area_No].Step * Program_Para.Area[Area_No].Y_Len / 200; 
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Program_Para.Area[Area_No].X_Len, Area_Status[Area_No].Step * Program_Para.Area[Area_No].Y_Len / 200, &Show_Data, &Temp);
    Area_Status[Area_No].Step += MOVE_STEP;
  }  
}

//左右开帘
void Move_Left_Right_Open(INT8U Area_No)
{
  S_Point Temp;
  
  if(Area_Status[Area_No].Step < 100)
  {
    Temp.X = (100 - Area_Status[Area_No].Step)*Program_Para.Area[Area_No].X_Len / 200;
    Temp.Y = 0; 
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp,  Area_Status[Area_No].Step * Program_Para.Area[Area_No].X_Len / 100, Program_Para.Area[Area_No].Y_Len, &Show_Data, &Temp);
    Area_Status[Area_No].Step += MOVE_STEP;
  }
  
}

//左右合帘
void Move_Left_Right_Close(INT8U Area_No)
{
  S_Point Temp;
  
  if(Area_Status[Area_No].Step < 100)
  {
    Temp.X = 0;
    Temp.Y = 0;// + Area_Status[Area_No].Step * Program_Para.Area[Area_No].Y_Len / 200; 
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Area_Status[Area_No].Step * Program_Para.Area[Area_No].X_Len / 200, Program_Para.Area[Area_No].Y_Len,  &Show_Data, &Temp);
    
    Temp.X = Program_Para.Area[Area_No].X_Len - Area_Status[Area_No].Step * Program_Para.Area[Area_No].X_Len / 200;
    Temp.Y = 0; 
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Area_Status[Area_No].Step * Program_Para.Area[Area_No].X_Len / 200, Program_Para.Area[Area_No].Y_Len, &Show_Data, &Temp);
    Area_Status[Area_No].Step += MOVE_STEP;
  }  
}




//获取某个窗口区域某个步进的停留时间
INT8U Get_Area_Step_Delay(INT8U Area_No)
{
  INT8U Step;
  
  if(Area_No >= MAX_AREA_NUM)
  {
    ASSERT_FAILED();
    return Step_Delay[0];
  }
  
  Step = File_Para[Area_No].Pic_Para.In_Speed; //引入速度
  if(Step >= sizeof(Step_Delay)/sizeof(Step_Delay))
    Step = sizeof(Step_Delay)/sizeof(Step_Delay);
  
  return Step_Delay[Step];
}

//获取文件的停留时间,单位为ms
//原参数最高为表示单位，0为s，1为ms
INT32U Get_File_Stay_Time(INT8U Area_No)
{
  if((File_Para[Area_No].Pic_Para.Stay_Time & 0x8000) > 0)
    return (INT32U)(File_Para[Area_No].Pic_Para.Stay_Time & 0x7FFF);
  else
    return (INT32U)File_Para[Area_No].Pic_Para.Stay_Time * 1000;
}

//设置文件的停留时间
void Set_File_Stay_Time(INT8U Area_No, INT16U ms)
{
  File_Para[Area_No].Pic_Para.Stay_Time = ms;
  File_Para[Area_No].Pic_Para.Stay_Time = File_Para[Area_No].Pic_Para.Stay_Time | 0x80;
}

//显示某个分区数据--->每10ms调用该函数，实现动画或移动等
//调用此函数前，显示数据已经读取在Show_Data_Bak中，同时Area_Status和Program_Para等信息已经保存好
void Update_Pic_Data(INT8U Area_No)
{
  INT8U In_Mode;
  //还在移动状态
  if(Area_Status[Area_No].Step < 100)
  {
    if(Area_Status[Area_No].Step_Timer < Get_Area_Step_Delay(Area_No))
      Area_Status[Area_No].Step_Timer += MOVE_STEP_TIMER;
    else
    {
      In_Mode = File_Para[Area_No].Pic_Para.In_Mode;
      (*(Mode_Func[In_Mode].Func))(Area_No);//执行移动操作
    }
  }
  else if(Area_Status[Area_No].Stay_Time <= Get_File_Stay_Time(Area_No)) //停留时间未到
  {
    Area_Status[Area_No].Stay_Time += MOVE_STEP_TIMER;
  }
}

//更新表盘数据
void Update_Clock_Data(INT8U Area_No)
{
  S_Point Point;
  INT16U X_Len, Y_Len;
  
  Show_Clock(&Show_Data, Area_No, &Cur_Time, &File_Para[Area_No].Clock_Para);
  //Index = Get_Area_Point_Index(Area_No, 0, 0);
  //Bits_Copy(Show_Data_Bak.Color_Data, sizeof(Show_Data_Bak.Color_Data), Index, ;
  //Copy_Buf_2_Area_Rect();
  Point.X = File_Para[Area_No].Clock_Para.Bk_X;
  Point.Y = File_Para[Area_No].Clock_Para.Bk_Y;
  X_Len = File_Para[Area_No].Clock_Para.Bk_Width;
  Y_Len = File_Para[Area_No].Clock_Para.Bk_Height;
  
  Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Point, X_Len, Y_Len, &Show_Data, &Point);
}

//更新定时器数据
void Update_Timer_Data(INT8U Area_No)
{
  
  
}

//更新时间数据
void Update_Time_Data(INT8U Area_No)
{
  
  
}

//更新温度数据
void Update_Temp_Data(INT8U Area_No)
{
  
  
}

//每隔MOVE_STEP_TIMER ms调用该函数,实现移动显示等效果
void Update_Show_Data()
{
  INT8U i;
  //static S_Int8U Ms10_Timer
  for(i = 0; i < Program_Para.Area_Num && i < MAX_AREA_NUM; i ++)
  {
    if(File_Para[i].Pic_Para.Flag EQ SHOW_PIC)
      Update_Pic_Data(i);
    else if(File_Para[i].Pic_Para.Flag EQ SHOW_CLOCK)
      Update_Clock_Data(i);
    else if(File_Para[i].Pic_Para.Flag EQ SHOW_TIMER)
      Update_Timer_Data(i);
    else if(File_Para[i].Pic_Para.Flag EQ SHOW_TIME)
      Update_Time_Data(i);
    else if(File_Para[i].Pic_Para.Flag EQ SHOW_TEMP)
      Update_Temp_Data(i);
  }
}

//读取一屏显示数据
//prog节目号
//area分区号
INT8S Update_Show_Data_Bak(INT8U Prog_No, INT8U Area_No)
{
  INT8S Re;
  INT8U Seq;
  char File_Name[MAX_FILE_NAME_SIZE];
  FILE_T File;
  INT16U Ctrl_Code;
  INT32S Len, Len0;
  INT32U Dst_Index, Size;
  INT16U X,Y,X_Len,Y_Len;

  Re = AREA_OK;
  //Read_Para();
  Get_Program_Data_File_Name(Prog_No, Area_No, File_Name); //获取该分区的显示文件

  File = File_Open(File_Name, FILE_R); //Read_

  Len = File_Read_One_Frame(File, Area_Status[Area_No].File_Offset, &Seq, &Ctrl_Code, Pub_Buf, Pub_Buf, sizeof(Pub_Buf));
  if(Len EQ FILE_END) //文件结束--从头开始重新
  {
    Area_Status[Area_No].File_Offset = 0;
    Area_Status[Area_No].File_Type = 0;
    Len = File_Read_One_Frame(File, Area_Status[Area_No].File_Offset, &Seq, &Ctrl_Code, Pub_Buf, Pub_Buf, sizeof(Pub_Buf));
  }

  if(Seq EQ 0)//---必须是第一帧,先将显示相关参数复制到File_Para结构体中
  {
    Area_Status[Area_No].File_Offset += Len;

    if(Len > (sizeof(S_Pic_Para) - 2)) //第一帧
    {
      Len0 = 0;

      Dst_Index = Get_Area_Point_Index(Area_No, 0, 0);
      Size = 0;
      Area_Status[Area_No].File_Type = Pub_Buf[0];

      if(Pub_Buf[0] EQ SHOW_PIC) //图文
      {
        Len0 =  sizeof(File_Para[Area_No].Pic_Para) - 2;
        mem_cpy(&File_Para[Area_No].Pic_Para.Flag, Pub_Buf, Len0, &File_Para[Area_No].Pic_Para, sizeof(File_Para[Area_No].Pic_Para));
        X = 0;
        Y = 0;
        X_Len = Program_Para.Area[Area_No].X_Len;
        Y_Len = Program_Para.Area[Area_No].Y_Len;
      }
      else if(Pub_Buf[0] EQ SHOW_CLOCK)//表盘
      {
        Len0 =  sizeof(File_Para[Area_No].Clock_Para) - 2;
        mem_cpy(&File_Para[Area_No].Clock_Para.Flag, Pub_Buf, Len0, &File_Para[Area_No].Clock_Para, sizeof(File_Para[Area_No].Clock_Para));

        X = File_Para[Area_No].Clock_Para.Bk_X;
        Y = File_Para[Area_No].Clock_Para.Bk_Y;
        X_Len = File_Para[Area_No].Clock_Para.Bk_Width;
        Y_Len = File_Para[Area_No].Clock_Para.Bk_Height;
      }
      else if(Pub_Buf[0] EQ SHOW_TIME)//时间
      {
        Len0 =  sizeof(File_Para[Area_No].Time_Para) - 2;
        mem_cpy(&File_Para[Area_No].Time_Para.Flag, Pub_Buf, Len0, &File_Para[Area_No].Time_Para, sizeof(File_Para[Area_No].Time_Para));

        X = File_Para[Area_No].Clock_Para.Bk_X;
        Y = File_Para[Area_No].Clock_Para.Bk_Y;
        X_Len = File_Para[Area_No].Clock_Para.Bk_Width;
        Y_Len = File_Para[Area_No].Clock_Para.Bk_Height;
      }
      else if(Pub_Buf[0] EQ SHOW_TIMER)//定时器
      {
        Len0 =  sizeof(File_Para[Area_No].Timer_Para) - 2;
        mem_cpy(&File_Para[Area_No].Timer_Para.Flag, Pub_Buf, Len0, &File_Para[Area_No].Timer_Para, sizeof(File_Para[Area_No].Timer_Para));

        X = File_Para[Area_No].Clock_Para.Bk_X;
        Y = File_Para[Area_No].Clock_Para.Bk_Y;
        X_Len = File_Para[Area_No].Clock_Para.Bk_Width;
        Y_Len = File_Para[Area_No].Clock_Para.Bk_Height;
      }
      else if(Pub_Buf[0] EQ SHOW_TEMP)//温度
      {
        Len0 =  sizeof(File_Para[Area_No].Temp_Para) - 2;
        mem_cpy(&File_Para[Area_No].Temp_Para.Flag, Pub_Buf, Len0, &File_Para[Area_No].Temp_Para, sizeof(File_Para[Area_No].Temp_Para));

        X = File_Para[Area_No].Clock_Para.Bk_X;
        Y = File_Para[Area_No].Clock_Para.Bk_Y;
        X_Len = File_Para[Area_No].Clock_Para.Bk_Width;
        Y_Len = File_Para[Area_No].Clock_Para.Bk_Height;
      }

      //Bits_Copy(Pub_Buf, sizeof(Pub_Buf), 0, (Len - Len0)* 8, Show_Data.Color_Data + Dst_Index, sizeof(Show_Data.Color_Data), Dst_Index);
      Copy_Buf_2_Area_Rect_0(Pub_Buf, Len - Len0, 0, &Show_Data_Bak, Area_No, X, Y, X_Len, Y_Len);
      Dst_Index += (Len - Len0)*8;
      Size += (Len - Len0);
    }
  }
  else
  {
    ASSERT_FAILED();
    return 0;
  }

  if((Ctrl_Code & 0x10) == 0x10) //有后续帧
  {
    STOP_SHOW_TIMER_INT; //关闭显示中断

    do
    { //继续读下一帧
      Len = File_Read_One_Frame(File, Area_Status[Area_No].File_Offset, &Seq, &Ctrl_Code, Pub_Buf, Pub_Buf, sizeof(Pub_Buf)); //读取一帧

      if(Len > 0) //正常读出一帧
      {
        if((Size + Len) * 8 > Get_Area_Size(Area_No)) //超过了分区的范围！
        {
          ASSERT_FAILED();
          break;
        }

        //位复制
        Copy_Buf_2_Area_Rect_0(Pub_Buf, Len - Len0, Size, &Show_Data_Bak, Area_No, X, Y, X_Len, Y_Len);
        //Bits_Copy(Pub_Buf, sizeof(Pub_Buf), 0, Len * 8, Show_Data.Color_Data + Dst_Index, sizeof(Show_Data.Color_Data), Dst_Index);
        Dst_Index += Len*8;
        Size += Len;
        //修改读文件偏移
        Area_Status[Area_No].File_Offset += Len;

        if((Ctrl_Code & 0x10) != 0x10) //没有后续帧则退出
          break;
      }
      else //读不出一条完整的帧数据了，认为该分区所有数据结束了
      {
        Area_Status[Area_No].File_Offset = 0;
        Re = AREA_END;
        break;
      }
    }while(1); //是同一屏数据,有后续帧表示---一个完整的屏数据用一帧传输，数据太大则拆帧

    START_SHOW_TIMER_INT; //打开显示中断
  }

  File_Close(File); //关闭

  return 1;
}


//检测更新显示备份区数据
INT8S Check_Update_Show_Data_Bak()
{
  INT8U i, Re;
  INT32U Area_End_Flag = 0;
  INT8U All_End_Flag = 1; //有一个分区没有结束则将其置0
  
  for(i = 0; i < Program_Para.Area_Num && i < MAX_AREA_NUM; i ++)
  {
    //目前显示的步进已经到100%并且目前停留时间已经达到文件的停留时间，则认为该屏已经显示完毕，切换到下屏
    if(Get_File_Stay_Time(i) < MIN_STAY_TIME)
      Set_File_Stay_Time(i, MIN_STAY_TIME);
    
    //Step>=100表示整个移动过程完成，Stay_Time>=表示停留时间到，则需更新为下一屏数据
    if(Area_Status[i].Step >= 100 && Area_Status[i].Stay_Time >= Get_File_Stay_Time(i))
    {
      Re = Update_Show_Data_Bak(Program_Para.Program_No, i);// == FILE_END)
      if(Re EQ AREA_END) //分区完成
      {
        SET_BIT(Area_End_Flag, i); //第i分区节目播放完成
        if(i + 1 EQ Program_Para.Main_Area_No)
          return PROG_END;
      }
      else
        All_End_Flag = 0; //有一个分区没有结束则清楚该标志
    }
  }
  
  if(All_End_Flag EQ 1) //所有分区都结束了
    return PROG_END;
  else
    return PROG_OK;
}

INT8U Get_Bit(INT8U *p,INT16U X_Size,INT16U X,INT16U Y)
{
  if((*(p+(Y/8)*(X_Size)+X))&(0x01<<(Y%8)))
    return 0x01;
  else
    return 0x00;
  
}

void Show_Char(INT16U Unicode,INT8U Area_No, INT16U X,INT16U Y,INT8U Size_Flag)
{
  INT16U i,j,k;
  INT8U Bit,X_Size,Y_Size;
  //S_Point Point;
  
  for(i=0;i<sizeof(CN_ZK)/sizeof(CN_ZK[0]);i++)
  {
    if(CN_ZK[i].Unicode==Unicode)
    {     
      if(Size_Flag EQ FONT_SIZE16)
      {
        X_Size=16;
        Y_Size=16;
      }
      else if(Size_Flag EQ FONT_SIZE24)
      {
        X_Size=24;
        Y_Size=24;          
      }
      else
      {
        X_Size=48;
        Y_Size=48;
      }
      
      if(Unicode < 0xA0A0) //英文宽度-1
      {
        X_Size=X_Size / 2;           
      }//
      
      for(j=0;j<X_Size;j++)
        for(k=0;k<Y_Size;k++)
        {
          if(Size_Flag EQ 0)            
            Bit=Get_Bit((INT8U *)CN_ZK[i].CN16_Dot,X_Size,j,k);
          else if(Size_Flag EQ 1)
            Bit=Get_Bit((INT8U *)CN_ZK[i].CN24_Dot,X_Size,j,k);
          else
            Bit=Get_Bit((INT8U *)CN_ZK[i].CN36_Dot,X_Size,j,k);
          
          Set_Area_Point_Data(&Show_Data_Bak, Area_No, X + j, Y +k, Bit);          
        }
    }   
  }
}

//根据format和ap参数表输出调试信息
void LED_Printf(INT8U Area_No, INT16U X, INT16U Y, INT8U Size_Flag, const INT8S *format, va_list ap)
{
  
  static const INT8S Chr[]="0123456789ABCDEF";
  
  static const INT32U Oct[12]=
  {
    01,010,0100,01000,010000,0100000,01000000,010000000,
    0100000000,01000000000,010000000000,010000000000,
  }; //八进制
  static const INT32U Dec[11]=
  {
    1,10,100,1000,10000,100000,1000000,
    10000000,100000000,1000000000,1000000000,
  }; //十进制
  static const INT32U Hex[8]=
  {
    0x1,0x10,0x100,0x1000,0x10000,
    0x100000,0x1000000,0x10000000,
  }; //十六进制
  
  INT8U LintFlag;
  INT32U const *p;
  INT8S *pSrc;
  
  unsigned long int uParaValue;//无符号数
  long int sParaValue;//有符号数
  
  INT8U c;
  INT8U i,Width,Len;
  
  for(;;)    //遍历整个参数表
  {
    while((c=*format++)!='%')//%符号之前全是字符串
    {
      if(!c)
        return;
      Show_Char(Area_No, X, Y,c,Size_Flag);
    }
    
    c=*format++;
    //非数值类型处理
    switch(c)
    {
    case 'c':
      c = va_arg(ap, int);
      Show_Char(Area_No, X, Y,c,Size_Flag);
      break;
    case 's':
      pSrc= va_arg(ap,INT8S *);
      while((c = *pSrc++)!=0)
        Show_Char(Area_No, X, Y,c,Size_Flag);
      break;
    default:
      break;
    }
    
    //数值类型处理
    if(c>='1' && c<='9')
    {
      Width=c-'0';
      c=*format++;
    }
    else
      Width=1;//至少打印一个字符
    
    if(c EQ 'l' || c EQ 'L')//是否是一个长整形?
    {
      LintFlag=1;
      c=*format++;
    }
    else
      LintFlag=0;
    
    switch(c)//打印数据类型
    {
    case 'o':
      p=Oct;
      Len=12;
      break;
    case 'd':
    case 'u':
      p=Dec;
      Len=11;
      break;
    case 'x':
      p=Hex;
      Len=8;
      break;
      
    default:
      continue;
    }
    
    //获取参数数值
    if(c EQ 'd')//有符号数
    {
      if(LintFlag)//长整型
        sParaValue=va_arg(ap,long int);
      else
        sParaValue=va_arg(ap,int);
      
      if(sParaValue<0)
      {
        Show_Char(Area_No, X, Y, '-',Size_Flag);
        sParaValue=0-sParaValue;
      }
      uParaValue=(unsigned long int)sParaValue;//赋值到uParaValue,统一计算
    }
    else//无符号数
    {
      if(LintFlag)//长整型
        uParaValue=va_arg(ap,unsigned long int);
      else
        uParaValue=va_arg(ap,INT16U);  
    }
    
    //计算数据本身的长度
    for(i=0;i<Len;i++)
    {
      if(uParaValue<*(p+i))
        break;
    }
    
    if(Width<i)//i表示数据本身长度，Width表示需要打印的长度
      Width=i;
    
    //分别打印每个字符
    i=0;//表示是否已经找到了一个非0位
    for(;Width!=0;Width--)
    {
      c=(INT8U)(uParaValue/(*(p+Width-1)));
      uParaValue=uParaValue%(*(p+Width-1));
      //前面的0全部打成空格
      
      if(c EQ 0 && i EQ 0 && Width>1)//该位为0，且之前的位也都为0,且不是最后一位(数值本身为0)
        c='0';//c=' ';----修改为填0
      else
      {
        i=1;//表示已经有一个非0位了
        c=Chr[c];
      }
      Show_Char(Area_No, X, Y,c,Size_Flag);
    }
  }
}

//每隔MOVE_STEP_TIMER ms 调用该函数，实现移动效果
void Show_Timer_Proc()
{
  Update_Show_Data(); //更新显示数据
  
}

//显示相关处理
void Show_Main_Proc()
{
  //Check_Update_Program_Para(); //检查是否需要更新节目
  Check_Update_Show_Data_Bak(); //检查是否需要更新显示备份区数据
  //Check_Update_Show_Data(); //检查是否更新显示区数据
  
}

