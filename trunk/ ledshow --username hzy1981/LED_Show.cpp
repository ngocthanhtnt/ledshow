#define LED_SHOW_C
#include "Includes.h"


/*
//获取得颜色
INT8U Get_Color()
{
  if(!(Screen_Para.Base_Para.Color <=2))
    return 0;
  else
  {
    return Screen_Para.Base_Para.Color;
  } 
}  
*/
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
  if(Area_No < MAX_AREA_NUM)
    return Prog_Para.Area[Area_No].X_Len;
  else if(Area_No EQ MAX_AREA_NUM)
    return Screen_Para.Base_Para.Width;
  else
  {
    ASSERT_FAILED();
    return 0; 
  } 
}

//获取某个分区的高度
//Area_No分区号
INT16U Get_Area_Height(INT8U Area_No)
{
  if(Area_No < MAX_AREA_NUM)
    return Prog_Para.Area[Area_No].Y_Len;
  else if(Area_No EQ MAX_AREA_NUM)
    return Screen_Para.Base_Para.Height;
  else
  {
    ASSERT_FAILED();
    return 0; 
  }  
}

//获取一个分区的像素个数,Area_No表示分区号
INT32U Get_Area_Size(INT8U Area_No)
{
  if(Area_No >= MAX_AREA_NUM)
  {
    ASSERT_FAILED();
    return 0;
  }
  
  return (INT32U)Prog_Para.Area[Area_No].X_Len * Prog_Para.Area[Area_No].Y_Len;  
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
  
  pPoint->X = Prog_Para.Area[Area_No].X;
  pPoint->Y = Prog_Para.Area[Area_No].Y;
  
  return 1;
}

//获取区域中某点的索引
//Area_No表示分区号
//x,y表示在分区内的坐标
INT32U Get_Area_Point_Index(INT8U Area_No, INT16U X, INT16U Y)
{
  INT32U Index;
 /* 
  if(Area_No < MAX_AREA_NUM)
  {
    ASSERT_FAILED();
    return 0;	
  }
  
  if(X >= Prog_Para.Area[Area_No].X_Len ||\
     Y >= Prog_Para.Area[Area_No].Y_Len)
  {
    //ASSERT_FAILED();
    return 0;
  }

  X += Prog_Para.Area[Area_No].X;
  Y += Prog_Para.Area[Area_No].Y;
 
  if(X >= Screen_Para.Base_Para.Width ||\
     Y >= Screen_Para.Base_Para.Height)
  {
    ASSERT_FAILED();
    return 0;
  }

  Index = (((Y>>3) * Screen_Para.Base_Para.Width) + X)*8 + (Y & 0x07);
  return Index;
  */
  
  if(Area_No < MAX_AREA_NUM)
  {
    if(X >= Prog_Para.Area[Area_No].X_Len ||\
       Y >= Prog_Para.Area[Area_No].Y_Len)
    {
      //ASSERT_FAILED();
      return 0;
    }
  
    X += Prog_Para.Area[Area_No].X;
    Y += Prog_Para.Area[Area_No].Y;
   
    if(X >= Screen_Para.Base_Para.Width ||\
       Y >= Screen_Para.Base_Para.Height)
    {
      ASSERT_FAILED();
      return 0;
    }
  
    Index = (((Y>>3) * Screen_Para.Base_Para.Width) + X)*8 + (Y & 0x07);
    return Index; 
  }
  else if(Area_No EQ MAX_AREA_NUM) //表示整屏数据
  {
    if(X >= Screen_Para.Base_Para.Width ||\
       Y >= Screen_Para.Base_Para.Height)
    {
      ASSERT_FAILED();
      return 0;
    }
  
    Index = (((Y>>3) * Screen_Para.Base_Para.Width) + X)*8 + (Y & 0x07);
    return Index;  
  }
  else
  {
    ASSERT_FAILED();
    return 0;
  }
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

INT8U Get_Buf_Point_Data(INT8U Buf[], INT16U Buf_Len, INT8U Color, INT16U Width, INT16U X, INT16U Y)
{
  INT32U Index;

  Index = (((Y>>3) * Width) + X)*8 + (Y & 0x07);
  
 if(Color < 3 || Color EQ 4)  //0,1,2,4单色屏
    return Get_Buf_Bit(Buf, Buf_Len,Index);
  else if(Color EQ 3 || Screen_Para.Base_Para.Color EQ 5 || Color EQ 6) //双色屏
    return Get_Buf_Bit(Buf, Buf_Len, ((Index>>3)<<4) + (Index & 0x07)) +\
      (Get_Buf_Bit(Buf, Buf_Len, ((Index>>3)<<4) + 8 + (Index & 0x07))<<1);
  else if(Color EQ 7) //三色屏
    return Get_Buf_Bit(Buf, Buf_Len, (Index>>3)*24 + (Index & 0x07)) +\
      (Get_Buf_Bit(Buf, Buf_Len, (Index>>3)*24 + 8 + (Index & 0x07))<<1)+
      (Get_Buf_Bit(Buf, Buf_Len, (Index>>3)*24 + 16 + (Index & 0x07))<<2);
  else
    return 0;  
  
}

//当前节目的某点数据,第0位到第2位分别为三种颜色
//pSrc_Buf，显示数据buf
//Area_No，分区号
//x,y分区坐标
INT8U Get_Area_Point_Data(S_Show_Data *pSrc_Buf, INT8U Area_No, INT16U X, INT16U Y) //获取一个区域内一个点的数据
{
  INT32U Index;

  Index = Get_Area_Point_Index(Area_No, X, Y);
  
  if(Screen_Para.Base_Para.Color < 3 || Screen_Para.Base_Para.Color EQ 4)  //0,1,2,4单色屏
    return Get_Buf_Bit(pSrc_Buf->Color_Data, sizeof(pSrc_Buf->Color_Data),Index);
  else if(Screen_Para.Base_Para.Color EQ 3 || Screen_Para.Base_Para.Color EQ 5 || Screen_Para.Base_Para.Color EQ 6) //双色屏
    return Get_Buf_Bit(pSrc_Buf->Color_Data, sizeof(pSrc_Buf->Color_Data), ((Index>>3)<<4) + (Index & 0x07)) +\
      (Get_Buf_Bit(pSrc_Buf->Color_Data, sizeof(pSrc_Buf->Color_Data), ((Index>>3)<<4) + 8 + (Index & 0x07))<<1);
  else if(Screen_Para.Base_Para.Color EQ 7) //三色屏
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
 
  if(Screen_Para.Base_Para.Color < 3 || Screen_Para.Base_Para.Color EQ 4)  //单色屏
    return Get_Buf_Bit(pSrc_Buf->One_Color_Data.Color0, sizeof(pSrc_Buf->One_Color_Data.Color0),Index);
  else if(Screen_Para.Base_Para.Color EQ 3 || Screen_Para.Base_Para.Color EQ 5 || Screen_Para.Base_Para.Color EQ 6) //双色屏
    return Get_Buf_Bit(pSrc_Buf->Two_Color_Data.Color0, sizeof(pSrc_Buf->Two_Color_Data.Color0), Index) +\
      (Get_Buf_Bit(pSrc_Buf->Two_Color_Data.Color1, sizeof(pSrc_Buf->Two_Color_Data.Color1), Index) << 1);
  else if(Screen_Para.Base_Para.Color EQ 7) //三色屏
    return Get_Buf_Bit(pSrc_Buf->Three_Color_Data.Color0, sizeof(pSrc_Buf->Two_Color_Data.Color0), Index) + \
      (Get_Buf_Bit(pSrc_Buf->Three_Color_Data.Color1, sizeof(pSrc_Buf->Three_Color_Data.Color1), Index) << 1) +\
        (Get_Buf_Bit(pSrc_Buf->Three_Color_Data.Color2, sizeof(pSrc_Buf->Three_Color_Data.Color2), Index) << 2);
  else
    return 0;  
  
}
*/

void Set_Buf_Point_Data(INT8U Buf[], INT16U Buf_Len, INT8U Color, INT8U Width, INT16U X, INT16U Y, INT8U Value)
{
  INT32U Index;
  
  Index = (((Y>>3) * Width) + X)*8 + (Y & 0x07);
  
  if(Color < 3 || Color EQ 4)  //单色屏
    Set_Buf_Bit(Buf, Buf_Len,Index, (Value & 0x01));
  else if(Color EQ 3 || Color EQ 5 || Color EQ 6) //双色屏
  {
    Set_Buf_Bit(Buf, Buf_Len, ((Index>>3)<<4) + (Index & 0x07), (Value & 0x01));
    Set_Buf_Bit(Buf, Buf_Len, ((Index>>3)<<4) + 8+ (Index & 0x07), (Value & 0x02)>>1);
  }
  else if(Color EQ 7) //三色屏
  {
    Set_Buf_Bit(Buf, Buf_Len, (Index>>3)*24 + (Index & 0x07), (Value & 0x01));
    Set_Buf_Bit(Buf, Buf_Len, (Index>>3)*24 + 8 + (Index & 0x07), (Value & 0x02)>>1);
    Set_Buf_Bit(Buf, Buf_Len, (Index>>3)*24 + 16 + (Index & 0x07), (Value & 0x04)>>2);
  }  
}


//设置某节目区域中某点的数据,第0-2位分别表示三种颜色
//pDst_Buf，设置该显示缓冲中的点
//Area_No表示分区号
//x,y坐标位置
//Value点
void Set_Area_Point_Data(S_Show_Data *pDst_Buf, INT8U Area_No, INT16U X, INT16U Y, INT8U Value) //设置一个区域的点   
{
  INT32U Index;
  
  Index = Get_Area_Point_Index(Area_No, X, Y);
  
  if(Screen_Para.Base_Para.Color < 3 || Screen_Para.Base_Para.Color EQ 4)  //0,1,2,4单色屏
    Set_Buf_Bit(pDst_Buf->Color_Data, sizeof(pDst_Buf->Color_Data),Index, (Value & 0x01));
  else if(Screen_Para.Base_Para.Color EQ 3 || Screen_Para.Base_Para.Color EQ 5 || Screen_Para.Base_Para.Color EQ 6) //双色屏
  {
    Set_Buf_Bit(pDst_Buf->Color_Data, sizeof(pDst_Buf->Color_Data), ((Index>>3)<<4) + (Index & 0x07), (Value & 0x01));
    Set_Buf_Bit(pDst_Buf->Color_Data, sizeof(pDst_Buf->Color_Data), ((Index>>3)<<4) + 8+ (Index & 0x07), (Value & 0x02)>>1);
  }
  else if(Screen_Para.Base_Para.Color EQ 7) //三色屏
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
  else if(pPoint0->X > pPoint1->X)
  {
    return pPoint1;
  }  
  else
  {
    if(pPoint0->Y < pPoint1->Y)
        return pPoint0;
    else if(pPoint0 ->Y > pPoint1->Y)
        return pPoint1;
    else
        return pPoint0;
  }
}

//获取两个点之中的右边一个点，X座标较大的一个
S_Point * Get_Right_Point(S_Point *pPoint0, S_Point *pPoint1)
{
  if(pPoint0->X > pPoint1->X) //point0在最左边
  {
    return pPoint0;
  }
  else if(pPoint0->X < pPoint1->X)
  {
    return pPoint1;
  }
  else
  {
    if(pPoint0->Y > pPoint1->Y)
        return pPoint0;
    else if(pPoint0 ->Y < pPoint1->Y)
        return pPoint1;
    else
        return pPoint0;
  }
}

S_Point * Get_Up_Point(S_Point *pPoint0, S_Point *pPoint1)
{
  if(pPoint0->Y < pPoint1->Y) //point0在最上边
  {
    return pPoint0;
  }
  else if(pPoint0->Y > pPoint1->Y)
  {
    return pPoint1;
  }
  else
  {
      if(pPoint0->X < pPoint1->X)
          return pPoint0;
      else if(pPoint0->X > pPoint1->X)
          return pPoint1;
      else
          return pPoint0;
  }
}

//获取两个点之中的下边一个点，Y座标较大的一个
S_Point * Get_Down_Point(S_Point *pPoint0, S_Point *pPoint1)
{
  if(pPoint0->Y > pPoint1->Y) //point0在最下边
  {
    return pPoint0;
  }
  else if(pPoint0->Y < pPoint1->Y)
  {
    return pPoint1;
  }
  else
  {
      if(pPoint0->X > pPoint1->X)
          return pPoint0;
      else if(pPoint0->X < pPoint1->X)
          return pPoint1;
      else
          return pPoint0;
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

  return pMid;
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

    return pMid;
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
  INT16U Y,k;
  
  p0 = Get_Left_Point(pPoint0, pPoint1);
  p1 = Get_Right_Point(pPoint0, pPoint1);
  
  Y = p0->Y;
  if(p0->X != p1->X)
  {
      for(i = p0 -> X; i <= p1->X ; i ++)
      {
        j = GET_LINE_Y((INT32S)p0->X,(INT32S)p0->Y, (INT32S)p1->X, (INT32S)p1->Y, i);//(INT32S)pLeft->Y + (INT32S)(i - pLeft ->X)((INT32S)(pRgiht->Y) - (INT32S)(pLeft->Y))/(pRight -> X - pLeft->X) ;

//--------------
        if((INT16U)j > Y + 1)
        {
          for(k = Y + 1; k < j; k ++)
              Set_Area_Point_Data(pDst_Buf, Area_No, (INT16U)i, (INT16U)k, Value);
        }
        else if(Y > (INT16U)j + 1)
        {
            for(k = (INT16U)j + 1; k < Y; k ++)
                Set_Area_Point_Data(pDst_Buf, Area_No, (INT16U)i, (INT16U)k, Value);
        }
//----------------
        if(j < 0)
          ASSERT_FAILED();

        Set_Area_Point_Data(pDst_Buf, Area_No, (INT16U)i, (INT16U)j, Value);
        Y = j;
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
  S_Point Temp0, Temp1,Temp0_Bk,Temp1_Bk;


  pLeft = Get_Left_Point(pPoint0, pPoint1);
  pLeft = Get_Left_Point(pLeft, pPoint2);

  pRight = Get_Right_Point(pPoint0, pPoint1);
  pRight = Get_Right_Point(pRight, pPoint2);

  pMid = Get_X_Mid_Point(pPoint0, pPoint1, pPoint2);

  //Draw_Line(pDst_Buf, Area_No, pPoint0, pPoint1, Value);
  //Draw_Line(pDst_Buf, Area_No, pPoint1, pPoint2, Value);
  //Draw_Line(pDst_Buf, Area_No, pPoint2, pPoint0, Value);

  Temp0.X = pLeft -> X;  //中间的X
  Temp0_Bk.X = pLeft->X;
  Temp0_Bk.Y = pLeft->Y;

  Temp1_Bk.X = pLeft->X;
  Temp1_Bk.Y = pLeft->Y;

  do
  {
    Temp0.Y = GET_LINE_Y((INT32S)pLeft ->X, (INT32S)pLeft->Y, (INT32S)pRight->X, (INT32S)pRight->Y, (INT32S)Temp0.X);
    Temp1.X = Temp0.X;
    if(Temp1.X < pMid->X)
      Temp1.Y = GET_LINE_Y((INT32S)pLeft ->X, (INT32S)pLeft->Y, (INT32S)pMid->X, (INT32S)pMid->Y, (INT32S)Temp1.X);
    else
      Temp1.Y = GET_LINE_Y((INT32S)pRight ->X, (INT32S)pRight->Y, (INT32S)pMid->X, (INT32S)pMid->Y, (INT32S)Temp1.X);
    Draw_Line(pDst_Buf, Area_No, &Temp0, &Temp1, Value);
    Draw_Line(pDst_Buf, Area_No, &Temp0, &Temp0_Bk, Value);
    Draw_Line(pDst_Buf, Area_No, &Temp1, &Temp1_Bk, Value);

    Temp0_Bk.X = Temp0.X;
    Temp0_Bk.Y = Temp0.Y;

    Temp1_Bk.X = Temp1.X;
    Temp1_Bk.Y = Temp1.Y;
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
  pPoint1 -> X = (INT16U)((INT16S)pPoint0->X + (INT16S)Len * cos(2*PI*Angle/360) + 0.5);
  pPoint1 -> Y = (INT16U)((INT16S)pPoint0->Y - (INT16S)Len * sin(2*PI*Angle/360) + 0.5);
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


//上移
void Move_Up(INT8U Area_No)//上移动
{
  S_Point Temp;
  S_Point Temp1;
  
  //if(Prog_Status.Area_Status[Area_No].Step < 100) //是否已经移动完成100%
  {
    Temp.X = 0;//Prog_Para.Area[Area_No].X;
    Temp.Y = 0;//Prog_Para.Area[Area_No].Y;
    
    Temp1.X = 0;//Prog_Para.Area[Area_No].X;// + Step +
    Temp1.Y = (100 - Prog_Status.Area_Status[Area_No].Step) * Prog_Para.Area[Area_No].Y_Len / 100;
    
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / 100,\
      &Show_Data, &Temp1);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  } 
}

//下移
void Move_Down(INT8U Area_No)
{
  S_Point Temp;
  S_Point Temp1;
  
  //if(Prog_Status.Area_Status[Area_No].Step < 100) //是否已经移动完成100%
  {
    Temp.X = 0;//Prog_Para.Area[Area_No].X;// + Step +
    Temp.Y = (100 - Prog_Status.Area_Status[Area_No].Step) * Prog_Para.Area[Area_No].Y_Len / 100;
    
    Temp1.X = 0;//Prog_Para.Area[Area_No].X;
    Temp1.Y = 0;//Prog_Para.Area[Area_No].Y;
    
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / 100,\
      &Show_Data, &Temp1);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  } 
}

//左移
void Move_Left(INT8U Area_No)
{
  S_Point Temp;
  S_Point Temp1;
  
  //if(Prog_Status.Area_Status[Area_No].Step < 100) //是否已经移动完成100%
  {
    Temp.X = 0;//Prog_Para.Area[Area_No].X;
    Temp.Y = 0;//Prog_Para.Area[Area_No].Y;
    
    Temp1.X = (100 - Prog_Status.Area_Status[Area_No].Step) * Prog_Para.Area[Area_No].X_Len / 100;// + Step +
    Temp1.Y = 0;
    
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].X_Len / 100,Prog_Para.Area[Area_No].Y_Len, \
      &Show_Data, &Temp1);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  }   
}

//右边移
void Move_Right(INT8U Area_No)
{
  S_Point Temp;
  S_Point Temp1;
  
  //if(Prog_Status.Area_Status[Area_No].Step < 100) //是否已经移动完成100%
  {
    Temp.X = (100 - Prog_Status.Area_Status[Area_No].Step) * Prog_Para.Area[Area_No].Y_Len / 100;// + Step +
    Temp.Y = 0;
    
    Temp1.X = 0;//Prog_Para.Area[Area_No].X;
    Temp1.Y = 0;//Prog_Para.Area[Area_No].Y;
    
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp,  Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].X_Len / 100,Prog_Para.Area[Area_No].Y_Len,\
      &Show_Data, &Temp1);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  } 
}

//上划
void Move_Up_Cover(INT8U Area_No)
{
  S_Point Temp;
  
  //if(Prog_Status.Area_Status[Area_No].Step < 100) //是否已经移动完成100%
  {
    Temp.X = 0;// + (100 - Prog_Status.Area_Status[Area_No].Step) * Prog_Para.Area[Area_No].Y_Len / 100;
    Temp.Y = (100 - Prog_Status.Area_Status[Area_No].Step) * Prog_Para.Area[Area_No].Y_Len / 100;
    
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, MOVE_STEP * Prog_Para.Area[Area_No].Y_Len / 100,\
      &Show_Data, &Temp);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  }  
}

//下划
void Move_Down_Cover(INT8U Area_No)
{
  S_Point Temp;
  
  //if(Prog_Status.Area_Status[Area_No].Step < 100) //是否已经移动完成100%
  {
    Temp.X = 0;// + Step +
    Temp.Y = Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / 100;
    
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, MOVE_STEP * Prog_Para.Area[Area_No].Y_Len / 100,\
      &Show_Data, &Temp);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  }  
}

//左划
void Move_Left_Cover(INT8U Area_No)
{
  S_Point Temp;
  
  //if(Prog_Status.Area_Status[Area_No].Step < 100) //是否已经移动完成100%
  {
    Temp.X = (100 - Prog_Status.Area_Status[Area_No].Step) * Prog_Para.Area[Area_No].X_Len / 100;// + Step +
    Temp.Y = 0;
    
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, MOVE_STEP * Prog_Para.Area[Area_No].X_Len / 100, Prog_Para.Area[Area_No].Y_Len,\
      &Show_Data, &Temp);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  }  
}

//右划
void Move_Right_Cover(INT8U Area_No)
{
  S_Point Temp;
  S_Point Temp1;
  
  //if(Prog_Status.Area_Status[Area_No].Step < 100) //是否已经移动完成100%
  {
    Temp.X = Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / 100;// + Step +
    Temp.Y = 0;
    
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp,  MOVE_STEP * Prog_Para.Area[Area_No].X_Len / 100,Prog_Para.Area[Area_No].Y_Len,\
      &Show_Data, &Temp1);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  }  
}

//左上划
void Move_Left_Up_Cover(INT8U Area_No)
{
  S_Point Left,Up,Right;
  
  //if(Prog_Status.Area_Status[Area_No].Step < 100)
  {
    Left.X = (100 - Prog_Status.Area_Status[Area_No].Step)*Prog_Para.Area[Area_No].X_Len / 100;
    Left.Y = Prog_Para.Area[Area_No].Y_Len;
    
    Up.X = Prog_Para.Area[Area_No].X_Len;
    Up.Y = (100 - Prog_Status.Area_Status[Area_No].Step)*Prog_Para.Area[Area_No].Y_Len / 100;
    
    Right.X = Prog_Para.Area[Area_No].X_Len;
    Right.Y = Prog_Para.Area[Area_No].Y_Len;
    
    Copy_Filled_Triangle(&Show_Data_Bak, Area_No, &Left, &Up, &Right, &Show_Data, &Left);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  }
}

//右上划
void Move_Right_Up_Cover(INT8U Area_No)
{
  S_Point Left,Up,Right;
  
  //if(Prog_Status.Area_Status[Area_No].Step < 100)
  {
    Left.X = 0;//Prog_Para.Area[Area_No].X;
    Left.Y = Prog_Para.Area[Area_No].Y_Len;
    
    Right.X = Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].X_Len / 100;
    Right.Y = Prog_Para.Area[Area_No].Y_Len;
    
    Up.X = 0;//Prog_Para.Area[Area_No].X;
    Up.Y = (100 - Prog_Status.Area_Status[Area_No].Step)*Prog_Para.Area[Area_No].Y_Len / 100;
    
    Copy_Filled_Triangle(&Show_Data_Bak, Area_No, &Left, &Up, &Right, &Show_Data, &Left);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  }
  
}

//左下划
void Move_Left_Down_Cover(INT8U Area_No)
{
  S_Point Left,Up,Right;
  
  //if(Prog_Status.Area_Status[Area_No].Step < 100)
  {
    Left.X = (100 - Prog_Status.Area_Status[Area_No].Step)*Prog_Para.Area[Area_No].X_Len / 100;
    Left.Y = 0;
    
    Right.X = Prog_Para.Area[Area_No].X_Len;
    Right.Y = Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / 100;
    
    Up.X = Prog_Para.Area[Area_No].X_Len;
    Up.Y = 0;
    
    Copy_Filled_Triangle(&Show_Data_Bak, Area_No, &Left, &Up, &Right, &Show_Data, &Left);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  }  
}

//右下划
void Move_Right_Down_Cover(INT8U Area_No)
{
  S_Point Left,Up,Right;
  
  //if(Prog_Status.Area_Status[Area_No].Step < 100)
  {
    Left.X = 0;// + (100 - Prog_Status.Area_Status[Area_No].Step)*Prog_Para.Area[Area_No].X_Len / 100;
    Left.Y = Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / 100;
    
    Right.X = Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / 100;
    Right.Y = 0;// + Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / 100;
    
    Up.X = 0;// + Prog_Para.Area[Area_No].X_Len;
    Up.Y = 0;
    
    Copy_Filled_Triangle(&Show_Data_Bak, Area_No, &Left, &Up, &Right, &Show_Data, &Left);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  }  
}

//上下拉帘
void Move_Up_Down_Open(INT8U Area_No)
{
  S_Point Temp;
  
  //if(Prog_Status.Area_Status[Area_No].Step < 100)
  {
    Temp.X = 0;
    Temp.Y = (100 - Prog_Status.Area_Status[Area_No].Step)*Prog_Para.Area[Area_No].Y_Len / 200;
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / 100, &Show_Data, &Temp);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  }
  
}

//上下合帘
void Move_Up_Down_Close(INT8U Area_No)
{
  S_Point Temp;
  
  //if(Prog_Status.Area_Status[Area_No].Step < 100)
  {
    Temp.X = 0;
    Temp.Y = 0;// + Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / 200;
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / 200, &Show_Data, &Temp);
    
    Temp.X = 0;
    Temp.Y = Prog_Para.Area[Area_No].Y_Len - Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / 200;
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / 200, &Show_Data, &Temp);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  }  
}

//左右开帘
void Move_Left_Right_Open(INT8U Area_No)
{
  S_Point Temp;
  
  //if(Prog_Status.Area_Status[Area_No].Step < 100)
  {
    Temp.X = (100 - Prog_Status.Area_Status[Area_No].Step)*Prog_Para.Area[Area_No].X_Len / 200;
    Temp.Y = 0; 
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp,  Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].X_Len / 100, Prog_Para.Area[Area_No].Y_Len, &Show_Data, &Temp);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  }
  
}

//左右合帘
void Move_Left_Right_Close(INT8U Area_No)
{
  S_Point Temp;
  
  //if(Prog_Status.Area_Status[Area_No].Step < 100)
  {
    Temp.X = 0;
    Temp.Y = 0;// + Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / 200;
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].X_Len / 200, Prog_Para.Area[Area_No].Y_Len,  &Show_Data, &Temp);
    
    Temp.X = Prog_Para.Area[Area_No].X_Len - Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].X_Len / 200;
    Temp.Y = 0; 
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].X_Len / 200, Prog_Para.Area[Area_No].Y_Len, &Show_Data, &Temp);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  }  
}
/*
    dateCombo->addItem(tr("2000年12月30日"));
    dateCombo->addItem(tr("00年12月30日"));
    dateCombo->addItem(tr("12/30/2000"));
    dateCombo->addItem(tr("2000/12/30"));
    dateCombo->addItem(tr("00-12-30"));
    dateCombo->addItem(tr("00.12.30"));
    dateCombo->addItem(tr("12月30"));
    dateCombo->addItem(tr("12.30.2000"));
    dateCombo->addItem(tr("2000-12-30"));
    dateCombo->addItem(tr("2000"));
    dateCombo->addItem(tr("12"));
    dateCombo->addItem(tr("30"));
 */
/*
//获取日期字符串的宽度
INT16U Get_DateStr_Width(INT8U Font, INT8U Type)
{
    INT8U chrNum;

    chrNum = 0;
    if(Type EQ 0)
        chrNum = 14;
    else if(Type EQ 1)
        chrNum = 12;
    else if(Type EQ 2)
        chrNum = 8;
    else if(Type EQ 3)
        chrNum = 8;
    else if(Type EQ 4)
        chrNum = 8;
    else if(Type EQ 5)
        chrNum = 8;
    else if(Type EQ 6)
        chrNum = 8;
    else if(Type EQ 7)
        chrNum = 10;
    else if(Type EQ 8)
        chrNum = 10;
    else if(Type EQ 9)
        chrNum = 4;
    else if(Type EQ 10)
        chrNum = 2;
    else if(Type EQ 11)
        chrNum = 2;
    else
        ASSERT_FAILED();

    return chrNum * Get_Font_Width(Font);
}

//显示星期
INT16U Get_WeekStr_Width(INT8U Font, INT8U Language, INT8U Week)
{
  return strlen(WeekStr[Language][Week])*Get_Font_Width(Font);
}
*/



//显示某个分区数据--->每10ms调用该函数，实现动画或移动等
//调用此函数前，显示数据已经读取在Show_Data_Bak中，同时Prog_Status.Area_Status和Program_Para等信息已经保存好







