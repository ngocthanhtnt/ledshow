#define LED_SHOW_C
#include "Includes.h"

#define SNOW_RATIO 4 //飘雪的数据比例
//#define TENSILE_STEP 10//Tensile
//#define COMPRESSION_RATIO
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
  
  //Index = ((Y/8 * Width) + X)*8 + Y %8;
  Index = GET_POINT_INDEX(Width,X,Y);
  return Get_Buf_Bit(Buf, Buf_Size, Index);//Index;
  
}

//设置一个矩形数据缓冲区的某坐标点的值 
//Buf_Size为缓冲区长度,Width为矩形区域宽度
//X\Y为矩形中的坐标点
//Value为该点值
void Set_Rect_Buf_Bit(INT8U Buf[], INT16U Buf_Size, INT16U Width, INT16U X, INT16U Y, INT8U Value)
{
  INT16U Index;
  
  //Index = ((Y/8 * Width) + X)*8 + Y %8;
  Index = GET_POINT_INDEX(Width,X,Y);
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
  INT16U Row_Points;

  Row_Points = ((X_Len % 8) EQ 0)?X_Len:((X_Len / 8 + 1)*8);
  
  if(Row_Points EQ 0)
    return;
  
  for(i = 0; i <Src_Len *8; i ++)
  {
    Re = Get_Buf_Bit(pSrc, Src_Len, i);

    X0 = (Src_Off*8 + i) % Row_Points;
    Y0 = (Src_Off*8 + i) / Row_Points;

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
  
    //Index = (((Y>>3) * Screen_Para.Base_Para.Width) + X)*8 + (Y & 0x07);
    Index = GET_POINT_INDEX(Screen_Para.Base_Para.Width,X,Y);
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
  
    //Index = (((Y>>3) * Screen_Para.Base_Para.Width) + X)*8 + (Y & 0x07);
    Index = GET_POINT_INDEX(Screen_Para.Base_Para.Width,X,Y);
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

  //Index = (((Y>>3) * Width) + X)*8 + (Y & 0x07);
 Index = GET_POINT_INDEX(Width,X,Y);
 
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
 
#if 0  
 if(Color < 3)// || Color EQ 4)  //0,1,2,4单色屏
    return Get_Buf_Bit(Buf, Buf_Len,Index);
  else if(Color EQ 3)// || Screen_Para.Base_Para.Color EQ 5 || Color EQ 6) //双色屏
    return Get_Buf_Bit(Buf, Buf_Len, ((Index>>3)<<4) + (Index & 0x07)) +\
      (Get_Buf_Bit(Buf, Buf_Len, ((Index>>3)<<4) + 8 + (Index & 0x07))<<1);
  else
    return 0;  
#endif  
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
  
#if 0  
  if(Screen_Para.Base_Para.Color < 3)// || Screen_Para.Base_Para.Color EQ 4)  //0,1,2,4单色屏
    return Get_Buf_Bit(pSrc_Buf->Color_Data, sizeof(pSrc_Buf->Color_Data),Index);
  else if(Screen_Para.Base_Para.Color EQ 3)// || Screen_Para.Base_Para.Color EQ 5 || Screen_Para.Base_Para.Color EQ 6) //双色屏
    return Get_Buf_Bit(pSrc_Buf->Color_Data, sizeof(pSrc_Buf->Color_Data), ((Index>>3)<<4) + (Index & 0x07)) +\
      (Get_Buf_Bit(pSrc_Buf->Color_Data, sizeof(pSrc_Buf->Color_Data), ((Index>>3)<<4) + 8 + (Index & 0x07))<<1);
  else
    return 0;  
#endif
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
  
  //Index = (((Y>>3) * Width) + X)*8 + (Y & 0x07);
  Index = GET_POINT_INDEX(Width,X,Y);
  
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

#if 0  
  if(Color < 3)// || Color EQ 4)  //单色屏
    Set_Buf_Bit(Buf, Buf_Len,Index, (Value & 0x01));
  else if(Color EQ 3)// || Color EQ 5 || Color EQ 6) //双色屏
  {
    Set_Buf_Bit(Buf, Buf_Len, ((Index>>3)<<4) + (Index & 0x07), (Value & 0x01));
    Set_Buf_Bit(Buf, Buf_Len, ((Index>>3)<<4) + 8+ (Index & 0x07), (Value & 0x02)>>1);
  }
#endif
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
 
#if 0  
  if(Screen_Para.Base_Para.Color < 3)// || Screen_Para.Base_Para.Color EQ 4)  //0,1,2,4单色屏
    Set_Buf_Bit(pDst_Buf->Color_Data, sizeof(pDst_Buf->Color_Data),Index, (Value & 0x01));
  else if(Screen_Para.Base_Para.Color EQ 3)// || Screen_Para.Base_Para.Color EQ 5 || Screen_Para.Base_Para.Color EQ 6) //双色屏
  {
    Set_Buf_Bit(pDst_Buf->Color_Data, sizeof(pDst_Buf->Color_Data), ((Index>>3)<<4) + (Index & 0x07), (Value & 0x01));
    Set_Buf_Bit(pDst_Buf->Color_Data, sizeof(pDst_Buf->Color_Data), ((Index>>3)<<4) + 8+ (Index & 0x07), (Value & 0x02)>>1);
  }
#endif  
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
{/*
  INT8U Data;
  S_Point *p0, *p1;
  INT32S i,j;
  
  p0 = Get_Left_Point(pPoint0, pPoint1);
  p1 = Get_Right_Point(pPoint0, pPoint1);
  
  if(p0->X != p1->X) //不是在垂直的一条线上
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
  */
    S_Point *p0, *p1;//, *p2;
    INT32S i,j;
    INT16U Y,k;
    INT8U Value;
    INT16S Xdiff,Ydiff;

    p0 = Get_Left_Point(pPoint0, pPoint1);
    p1 = Get_Right_Point(pPoint0, pPoint1);
    //p2 = pPoint2;

    Xdiff = (INT16S)pPoint2->X - (INT16S)pPoint0->X;
    Ydiff = (INT16S)pPoint2->Y - (INT16S)pPoint0->Y;

    Y = p0->Y;
    if(p0->X != p1->X)
    {
        for(i = p0 -> X; i <= p1->X ; i ++)
        {
          j = GET_LINE_Y((INT32S)p0->X,(INT32S)p0->Y, (INT32S)p1->X, (INT32S)p1->Y, i);//(INT32S)pLeft->Y + (INT32S)(i - pLeft ->X)((INT32S)(pRgiht->Y) - (INT32S)(pLeft->Y))/(pRight -> X - pLeft->X) ;
          if(j < 0)
            ASSERT_FAILED();

          if((INT16U)j > Y + 1)
          {
            for(k = Y + 1; k < j; k ++)
            {
                Value = Get_Area_Point_Data(pSrc_Buf, Area_No, (INT16U)i, (INT16U)k);
                Set_Area_Point_Data(pDst_Buf, Area_No, (INT16U)i + Xdiff, (INT16U)k + Ydiff, Value);
            }
          }
          else if(Y > (INT16U)j + 1)
          {
              for(k = (INT16U)j + 1; k < Y; k ++)
              {
                  Value = Get_Area_Point_Data(pSrc_Buf, Area_No, (INT16U)i, (INT16U)k);
                  Set_Area_Point_Data(pDst_Buf, Area_No, (INT16U)i + Xdiff, (INT16U)k + Ydiff, Value);
              }
          }
          else
          {
             Value = Get_Area_Point_Data(pSrc_Buf, Area_No, (INT16U)i, (INT16U)j);
             Set_Area_Point_Data(pDst_Buf, Area_No, (INT16U)i + Xdiff, (INT16U)j + Ydiff, Value);
          }
          Y = j;
       }
    }
    else
    {
        p0 = Get_Up_Point(pPoint0, pPoint1);
        p1 = Get_Down_Point(pPoint0, pPoint1);

        for(j = p0->Y; j <=p1->Y; j ++)
        {
          Value = Get_Area_Point_Data(pSrc_Buf, Area_No, (INT16U)p0->X, (INT16U)j);
          Set_Area_Point_Data(pDst_Buf, Area_No, p0->X + Xdiff, j + Ydiff, Value);
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

        if(j < 0)
          ASSERT_FAILED();
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
        else
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

{
    S_Point *pLeft;  //最左边的点
    S_Point *pRight; //最右边的点
    S_Point *pMid;  //中间的点
    S_Point Temp0, Temp1, Temp2;//,Temp0_Bk,Temp1_Bk;


    pLeft = Get_Left_Point(pPoint0, pPoint1);
    pLeft = Get_Left_Point(pLeft, pPoint2);

    pRight = Get_Right_Point(pPoint0, pPoint1);
    pRight = Get_Right_Point(pRight, pPoint2);

    pMid = Get_X_Mid_Point(pPoint0, pPoint1, pPoint2);

    //Draw_Line(pDst_Buf, Area_No, pPoint0, pPoint1, Value);
    //Draw_Line(pDst_Buf, Area_No, pPoint1, pPoint2, Value);
    //Draw_Line(pDst_Buf, Area_No, pPoint2, pPoint0, Value);

    Temp0.X = pLeft -> X;  //中间的X
    //Temp0_Bk.X = pLeft->X;
    //Temp0_Bk.Y = pLeft->Y;

    //Temp1_Bk.X = pLeft->X;
    //Temp1_Bk.Y = pLeft->Y;

    Temp2.X = pLeft->X + pPoint3->X - pPoint0->X;
    Temp2.Y = pLeft->Y + pPoint3->Y - pPoint0->Y;
    Copy_Line(pSrc_Buf, Area_No, pLeft, pRight, pDst_Buf, &Temp2);
/*
    Copy_Line(pSrc_Buf, Area_No, pLeft, pMid, pDst_Buf, &Temp2);
    Temp2.X = pMid->X + pPoint3->X - pPoint0->X;
    Temp2.Y = pMid->Y + pPoint3->Y - pPoint0->Y;
    Copy_Line(pSrc_Buf, Area_No, pRight, pMid, pDst_Buf, &Temp2);
*/
    while(Temp0.X <= pRight -> X)
    {
      Temp0.Y = GET_LINE_Y((INT32S)pLeft ->X, (INT32S)pLeft->Y, (INT32S)pRight->X, (INT32S)pRight->Y, (INT32S)Temp0.X);
      Temp1.X = Temp0.X;
      if(Temp1.X < pMid->X)
        Temp1.Y = GET_LINE_Y((INT32S)pLeft ->X, (INT32S)pLeft->Y, (INT32S)pMid->X, (INT32S)pMid->Y, (INT32S)Temp1.X);
      else
        Temp1.Y = GET_LINE_Y((INT32S)pRight ->X, (INT32S)pRight->Y, (INT32S)pMid->X, (INT32S)pMid->Y, (INT32S)Temp1.X);


      Temp2.X = Temp0.X + pPoint3->X - pPoint0->X;
      Temp2.Y = Temp0.Y + pPoint3->Y - pPoint0->Y;
      Copy_Line(pSrc_Buf, Area_No, &Temp0, &Temp1, pDst_Buf, &Temp2);
/*
      Copy_Line(pSrc_Buf, Area_No, &Temp0, &Temp0_Bk, pDst_Buf, &Temp2);
      Temp2.X = Temp1.X + pPoint3->X - pPoint0->X;
      Temp2.Y = Temp1.Y + pPoint3->Y - pPoint0->Y;
      Copy_Line(pSrc_Buf, Area_No, &Temp1, &Temp1_Bk, pDst_Buf, &Temp2);

      Temp0_Bk.X = Temp0.X;
      Temp0_Bk.Y = Temp0.Y;

      Temp1_Bk.X = Temp1.X;
      Temp1_Bk.Y = Temp1.Y;
 */
      Temp0.X ++;
    }//while(Temp0.X < pRight -> X);
/*
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

    Temp2.X = pLeft->X + pPoint3->X - pPoint0->X;
    Temp2.Y = pLeft->Y + pPoint3->Y - pPoint0->Y;
    Copy_Line(pSrc_Buf, Area_No, pLeft, pRight, pDst_Buf, &Temp2);

    while(Temp0.X <= pRight -> X)
    {
      Temp0.Y = GET_LINE_Y((INT32S)pLeft ->X, (INT32S)pLeft->Y, (INT32S)pRight->X, (INT32S)pRight->Y, (INT32S)Temp0.X);

      //Draw_Line(pDst_Buf, Area_No, &Temp0, &Temp1, Value);
      Temp2.X = Temp0.X + pPoint3->X - pPoint0->X;
      Temp2.Y = Temp0.Y + pPoint3->Y - pPoint0->Y;

      Copy_Line(pSrc_Buf, Area_No, &Temp0, pMid, pDst_Buf, &Temp2);
      Temp0.X ++;
    }//while(Temp0.X < pRight -> X);
    */
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
  S_Point Temp0, Temp1;//,Temp0_Bk,Temp1_Bk;


  pLeft = Get_Left_Point(pPoint0, pPoint1);
  pLeft = Get_Left_Point(pLeft, pPoint2);

  pRight = Get_Right_Point(pPoint0, pPoint1);
  pRight = Get_Right_Point(pRight, pPoint2);

  pMid = Get_X_Mid_Point(pPoint0, pPoint1, pPoint2);

  //Draw_Line(pDst_Buf, Area_No, pPoint0, pPoint1, Value);
  //Draw_Line(pDst_Buf, Area_No, pPoint1, pPoint2, Value);
  //Draw_Line(pDst_Buf, Area_No, pPoint2, pPoint0, Value);

  Temp0.X = pLeft -> X;  //中间的X
  //Temp0_Bk.X = pLeft->X;
  //Temp0_Bk.Y = pLeft->Y;

  //Temp1_Bk.X = pLeft->X;
  //Temp1_Bk.Y = pLeft->Y;

  Draw_Line(pDst_Buf, Area_No, pLeft, pRight, Value);
  //Draw_Line(pDst_Buf, Area_No, pLeft, pMid, Value);
  //Draw_Line(pDst_Buf, Area_No, pRight,pMid,  Value);

  while(Temp0.X <= pRight -> X)
  {
    Temp0.Y = GET_LINE_Y((INT32S)pLeft ->X, (INT32S)pLeft->Y, (INT32S)pRight->X, (INT32S)pRight->Y, (INT32S)Temp0.X);
    Temp1.X = Temp0.X;
    if(Temp1.X < pMid->X)
      Temp1.Y = GET_LINE_Y((INT32S)pLeft ->X, (INT32S)pLeft->Y, (INT32S)pMid->X, (INT32S)pMid->Y, (INT32S)Temp1.X);
    else
      Temp1.Y = GET_LINE_Y((INT32S)pRight ->X, (INT32S)pRight->Y, (INT32S)pMid->X, (INT32S)pMid->Y, (INT32S)Temp1.X);

    Draw_Line(pDst_Buf, Area_No, &Temp0, &Temp1, Value);
/*
    Draw_Line(pDst_Buf, Area_No, &Temp0, &Temp0_Bk, Value);
    Draw_Line(pDst_Buf, Area_No, &Temp1, &Temp1_Bk, Value);

    Temp0_Bk.X = Temp0.X;
    Temp0_Bk.Y = Temp0.Y;

    Temp1_Bk.X = Temp1.X;
    Temp1_Bk.Y = Temp1.Y;
*/
    Temp0.X ++;
  }//while(Temp0.X < pRight -> X);

/*
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

  Draw_Line(pDst_Buf, Area_No, pLeft, pRight, Value);
  //Draw_Line(pDst_Buf, Area_No, pLeft, pMid, Value);
  //Draw_Line(pDst_Buf, Area_No, pMid, pRight, Value);
  while(Temp0.X <= pRight -> X)
  {
    Temp0.Y = GET_LINE_Y((INT32S)pLeft ->X, (INT32S)pLeft->Y, (INT32S)pRight->X, (INT32S)pRight->Y, (INT32S)Temp0.X);

    //Draw_Line(pDst_Buf, Area_No, &Temp0, &Temp1, Value);
    //Temp2.X = Temp0.X + pPoint3->X - pPoint0->X;
    //Temp2.Y = Temp0.Y + pPoint3->Y - pPoint0->Y;

    Draw_Line(pDst_Buf, Area_No, &Temp0, pMid, Value);
    Temp0.X ++;
  }//while(Temp0.X < pRight -> X);
*/
}

//复制一个多边形
void Copy_Filled_Polygon(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pPoint0, INT8U Point_Num,\
  S_Show_Data *pDst_Buf, S_Point *pPoint1)
{
    INT8U i;

    for(i = 1; i < Point_Num - 1; i ++)
    {
      Copy_Filled_Triangle(pSrc_Buf, Area_No, pPoint0, pPoint0 + i, pPoint0 + 1 + i, pDst_Buf, pPoint1);
      //Copy_Filled_Triangle(pSrc_Buf, Area_No, pPoint0, pPoint2, pPoint3, pDst_Buf, pPoint4);
    }
}

//填充一个多边形
void Fill_Polygon(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pPoint0, INT8U Point_Num, INT8U Value)
{
    INT8U i;

    for(i = 1; i < Point_Num - 1; i ++)
    {
      Fill_Triangle(pDst_Buf, Area_No, pPoint0, pPoint0 + i, pPoint0 + 1 + i, Value);
      //Copy_Filled_Triangle(pSrc_Buf, Area_No, pPoint0, pPoint2, pPoint3, pDst_Buf, pPoint4);
    }

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
/*
//复制一个拉伸的矩形框，Stretch_X_Len表示复制后在目标显示缓冲中宽度，Stretch_Y_Len表示目标缓冲中的高度,Stretch_Direct表示拉伸的方向,0表示横向，1表示纵向
//pPoint1表示在目标中的
void Copy_Filled_Stretch_Rect(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pPoint0, INT16S Stretch_X_Len, INT16Ss Stretch_Y_Len, INT8U Stretch_Direct, \
                              S_Show_Data *pDst_Buf, S_Point *pPoint1)
{
    INT16U Stretch_Len, Y_Len, i;
    S_Point Temp0,Temp1,Temp2;

    Temp0.X = pPoint0->X;
    Temp0.Y = pPoint0->Y;

    Temp1.X = Temp0.X;
    Temp1.Y = Temp0.Y;



    Len = 0;
   if(Stretch_Direct EQ 0) //横向
    {
       Temp1.X = Temp0.X;

       if(Stretch_Y_Len > 0) //复制改点的下部分
         Temp1.Y = Temp0.Y + Stretch_Y_Len;
       else
       {
         if(Temp0.Y > Stretch_Y_Len)
             Temp1.Y = Temp0.Y - Stretch_Y_Len;
         else
             Temp1.Y = 0;
       }

       if(Stretch_X_Len > 0)
           Stretch_Len = Stretch_X_Len;
       else
           Stretch_Len = 0 - Stretch_X_Len;

       while(Len <= Stretch_Len)
       {
           for(i = 0; i < 3; i ++)
           {
             Len ++;
             Copy_Line(pSrc_Buf, Area_No, &Temp0, &Temp1, pDst_Buf, &Temp2);

             if(Stretch_X_Len >0)
                 Temp2.X ++;
             else
                 Temp2.X --;
           \}


           if(Stretch_X_Len >0)
               Temp0.X ++;
           else
               Temp0.X --;
       }
   }
}
*/
//反向复制一个矩形
void Rev_Copy_Filled_Rect(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pPoint0, INT16U X_Len, INT16U Y_Len,\
  S_Show_Data *pDst_Buf, S_Point *pPoint1)
{
  //INT16U i,j;
  INT32S i,j;
  INT8U Data;
  
  for(i = 0; i < X_Len;  i++)
    for(j = 0; j < Y_Len; j++)
    {
      Data = Get_Area_Point_Data(pSrc_Buf, Area_No, pPoint0->X + (X_Len - 1 - i), pPoint0->Y + (Y_Len - 1 -j));
      Set_Area_Point_Data(pDst_Buf, Area_No, pPoint1->X + (X_Len - 1 - i), pPoint1->Y + (Y_Len - 1 -j), Data);
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
  
  X = pCenter -> X - Radius + 1; //最左边一点的X坐标
  
  for(; X < pCenter -> X + Radius; X ++)
  {
    Temp0 = ((INT32S)Radius * Radius - ((INT32S)X - (INT32S)pCenter->X)*((INT32S)X - (INT32S)pCenter->X));
    Temp = (INT16U)sqrt(Temp0);//Sqrt(Temp0);
    //下面一点
    Up.Y = pCenter->Y + Temp - 1;
    Up.X = X;
    //上面一点
    if(pCenter->Y >= Temp )
      Down.Y = pCenter->Y- Temp + 1;
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
  
  X = pCenter0 -> X - Radius + 1; //最左边一点的X坐标
  
  for(; X < pCenter0 -> X + Radius; X ++)
  {
    Temp1 = (INT16U)sqrt((float)(Radius * Radius - (INT16U)((INT32S)X - (INT32S)pCenter0->X)*((INT32S)X - (INT32S)pCenter0->X)));
    //下面一点
    Up.Y = pCenter0->Y + Temp1 - 1;
    Up.X = X;
    //上面一点
    Down.Y = pCenter0->Y- Temp1 + 1;
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
    INT16S Temp;
    double Re;

    if(Len >=1)
    {
      Re = (Len-1) * cos(2*PI*Angle/360) + 0.5;
      Temp = ((INT16S)pPoint0->X + Re);// + 0.5);
      pPoint1->X = Temp>0?(INT16U)Temp:0;

      Re = (Len-1) * sin(2*PI*Angle/360) - 0.5;
      Temp = (INT16U)((INT16S)pPoint0->Y - Re);// - 0.5);
      pPoint1->Y = Temp>0?(INT16U)Temp:0;
    }
    else
    {
      pPoint1 -> X = pPoint0 -> X;
      pPoint1 -> Y = pPoint0 -> Y;
    }
}

//pDst_Buf,显示目标缓冲区
//Area_No, 显示分区
//pCenter,时钟中心
//Angle,角度,-359->359
//Len,点数距离中心的长度
//Radius,点的半径
//Value,点的值也就是颜色
void Fill_Clock_Point(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pCenter, \
                      INT16S Angle, INT16U Len, INT16U Radius, INT8U Style, INT8U Value)
{
   S_Point Point[5];
   
   Get_Angle_Point(pCenter, Angle, Len, &Point[0]); //找到圆的中心点

   if(Style EQ 0) //圆形
     Fill_Round(pDst_Buf, Area_No, &Point[0], Radius, Value); //绘制一个圆
   else if(Style EQ 1) //方形
   {
     Point[0].X = Point[0].X - Radius + 1;
     Point[0].Y = Point[0].Y - Radius + 1;
     if(Radius > 0)
       Fill_Rect(pDst_Buf, Area_No, &Point[0], Radius*2-1, Radius*2-1, Value);
   }
   else if(Style EQ 2) //线型
   {
    if(Radius > 0)
    {
        Get_Angle_Point(pCenter, Angle, Len * 8 / 10, &Point[0]); //前端的顶点
        Get_Angle_Point(&Point[0], Angle - 90, Radius, &Point[1]);
        Get_Angle_Point(&Point[0], Angle + 90, Radius, &Point[4]);

        Get_Angle_Point(pCenter, Angle, Len + Radius/2, &Point[0]); //前端的顶点
        Get_Angle_Point(&Point[0], Angle - 90, Radius, &Point[2]);
        Get_Angle_Point(&Point[0], Angle + 90, Radius, &Point[3]);

        Fill_Polygon(pDst_Buf, Area_No, &Point[1], 4, Value);
    }
   }
   else if(Style EQ 3) //数字
   {
     Point[0].X = Point[0].X - Get_Font_Width(FONT0)/2;
     Point[0].Y = Point[0].Y - Get_Font_Height(FONT0)/2;;

     LED_Print(FONT0, Value, pDst_Buf, Area_No, Point[0].X, Point[0].Y, "%d", ((360 - Angle)/(360/12) + 3) % 12);
       //Fill_Rect(pDst_Buf, Area_No, &Point, Radius*2, Radius*2, Value);

   }
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
  
  if(Width EQ 0)
      return;

  Get_Angle_Point(pCenter, Angle, Len * 7 / 10, &Point0); //前端的顶点
  Get_Angle_Point(pCenter, Angle - 90, Width, &Point1);
  Get_Angle_Point(pCenter, Angle + 90, Width, &Point2);
  
  Fill_Triangle(pDst_Buf, Area_No, &Point1, &Point2, &Point0, Value);
  
  Get_Angle_Point(pCenter, Angle + 180, Len * 3 / 10, &Point0); //后端的顶点
  //Get_Angle_Point(pCenter, Angle + 180 - 90, Width, &Point1);
  //Get_Angle_Point(pCenter, Angle + 180 + 90, Width, &Point2);
  
  Fill_Triangle(pDst_Buf, Area_No, &Point1, &Point2, &Point0, Value);
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

void Move_Up(INT8U Area_No)
{
  S_Point Temp;
  S_Point Temp1;
  
  Temp.X = 0;//Prog_Para.Area[Area_No].X;
  Temp.Y = 0;//Prog_Para.Area[Area_No].Y;
  
  Temp1.X = 0;//Prog_Para.Area[Area_No].X;// + Step +
  Temp1.Y = Prog_Para.Area[Area_No].Y_Len - Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step;
  //备份区数据拷贝到显示区
  Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step,\
    &Show_Data, &Temp1);
  
}

//连续上移
void Move_Up_Continuous(INT8U Area_No)//上移动
{
  S_Point Temp;
  S_Point Temp1;
  
  INT16U Step_Len;


    Step_Len = Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step - (Prog_Status.Area_Status[Area_No].Step - MOVE_STEP) * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step;


    Temp.X = 0;
    Temp.Y = Step_Len;//MOVE_STEP * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step;

    Temp1.X = 0;//Prog_Para.Area[Area_No].X;
    Temp1.Y = 0;//Prog_Para.Area[Area_No].Y;
    //显示区数据上移
    if(Prog_Status.Area_Status[Area_No].Step + MOVE_STEP <= Prog_Status.Area_Status[Area_No].Max_Step)
      Copy_Filled_Rect(&Show_Data, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, Prog_Para.Area[Area_No].Y_Len - (Prog_Status.Area_Status[Area_No].Step - MOVE_STEP) * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step,\
                       &Show_Data, &Temp1);

    Move_Up(Area_No);
  //}
}

void Move_Down(INT8U Area_No)
{
  S_Point Temp;
  S_Point Temp1; 
  
  Temp.X = 0;//Prog_Para.Area[Area_No].X;// + Step +
  Temp.Y = Prog_Para.Area[Area_No].Y_Len - Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step;
  
  Temp1.X = 0;//Prog_Para.Area[Area_No].X;
  Temp1.Y = 0;//Prog_Para.Area[Area_No].Y;
  
  Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step,\
    &Show_Data, &Temp1);
  
}

//连续下移
void Move_Down_Continuous(INT8U Area_No)
{
  S_Point Temp;
  S_Point Temp1;

  //if(Prog_Status.Area_Status[Area_No].Step < Prog_Status.Area_Status[Area_No].Max_Step) //是否已经移动完成Prog_Status.Area_Status[Area_No].Max_Step%
  {
    Temp.X = 0;
    Temp.Y = (Prog_Status.Area_Status[Area_No].Step - MOVE_STEP) * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step;
    
    Temp1.X = 0;
    Temp1.Y = Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step;
      
    //显示区数据下移
    if(Prog_Status.Area_Status[Area_No].Step + MOVE_STEP <= Prog_Status.Area_Status[Area_No].Max_Step)
      Rev_Copy_Filled_Rect(&Show_Data, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, Prog_Para.Area[Area_No].Y_Len - (Prog_Status.Area_Status[Area_No].Step - MOVE_STEP) * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step,\
                       &Show_Data, &Temp1);
 
    Move_Down(Area_No);
  } 
}

//左移
void Move_Left(INT8U Area_No)
{
  S_Point Temp;
  S_Point Temp1;
  INT16U Moved_Len;

  Temp.X = 0;//Prog_Para.Area[Area_No].X;
  Temp.Y = 0;//Prog_Para.Area[Area_No].Y;
  
  Moved_Len = Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].X_Len / Prog_Status.Area_Status[Area_No].Max_Step;
  Temp1.X = Prog_Para.Area[Area_No].X_Len - Moved_Len;// + Step +
  Temp1.Y = 0;
  
  Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Moved_Len,Prog_Para.Area[Area_No].Y_Len, \
    &Show_Data, &Temp1);
   
}

void Move_Show_RightNow(INT8U Area_No)
{
    S_Point Temp;

    Temp.X = 0;
    Temp.Y = 0;
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, Prog_Para.Area[Area_No].Y_Len,\
                     &Show_Data, &Temp);

}

//连续左移
void Move_Left_Continuous(INT8U Area_No)
{
  S_Point Temp;
  S_Point Temp1;
  INT16U Step_Len;


  Step_Len = Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].X_Len / Prog_Status.Area_Status[Area_No].Max_Step - (Prog_Status.Area_Status[Area_No].Step - MOVE_STEP) * Prog_Para.Area[Area_No].X_Len / Prog_Status.Area_Status[Area_No].Max_Step;

  Temp.X = Step_Len;
  Temp.Y = 0; 

  Temp1.X = 0;//Prog_Para.Area[Area_No].X;
  Temp1.Y = 0;//Prog_Para.Area[Area_No].Y;   
  //显示区数据左移
  if(Prog_Status.Area_Status[Area_No].Step + MOVE_STEP <= Prog_Status.Area_Status[Area_No].Max_Step)
    Copy_Filled_Rect(&Show_Data, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len - (Prog_Status.Area_Status[Area_No].Step - MOVE_STEP) * Prog_Para.Area[Area_No].X_Len / Prog_Status.Area_Status[Area_No].Max_Step, Prog_Para.Area[Area_No].Y_Len,\
                     &Show_Data, &Temp1);  
  
  Move_Left(Area_No);   
}

//右移
void Move_Right(INT8U Area_No)
{
  S_Point Temp;
  S_Point Temp1;
  INT16U Moved_Len;

  Moved_Len = Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].X_Len / Prog_Status.Area_Status[Area_No].Max_Step;
  Temp.X = Prog_Para.Area[Area_No].X_Len - Moved_Len;//(Prog_Status.Area_Status[Area_No].Max_Step - Prog_Status.Area_Status[Area_No].Step) * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step;// + Step +
  Temp.Y = 0;
  
  Temp1.X = 0;//Prog_Para.Area[Area_No].X;
  Temp1.Y = 0;//Prog_Para.Area[Area_No].Y;
  
  Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp,  Moved_Len,Prog_Para.Area[Area_No].Y_Len,\
    &Show_Data, &Temp1);

}

//连续右移
void Move_Right_Continuous(INT8U Area_No)
{
  S_Point Temp;
  S_Point Temp1;
  INT16U Step_Len;

  Temp.X = (Prog_Status.Area_Status[Area_No].Step -MOVE_STEP) * Prog_Para.Area[Area_No].X_Len / Prog_Status.Area_Status[Area_No].Max_Step;
  Temp.Y = 0; 

  Step_Len = Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].X_Len / Prog_Status.Area_Status[Area_No].Max_Step - (Prog_Status.Area_Status[Area_No].Step - MOVE_STEP) * Prog_Para.Area[Area_No].X_Len / Prog_Status.Area_Status[Area_No].Max_Step;
  Temp1.X = Temp.X + Step_Len;//(Prog_Status.Area_Status[Area_No].Step + MOVE_STEP) * Prog_Para.Area[Area_No].X_Len / Prog_Status.Area_Status[Area_No].Max_Step;;
  Temp1.Y = 0;  
    
  //显示区数据右移
  if(Prog_Status.Area_Status[Area_No].Step + MOVE_STEP <= Prog_Status.Area_Status[Area_No].Max_Step)
    Rev_Copy_Filled_Rect(&Show_Data, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len - Temp.X, Prog_Para.Area[Area_No].Y_Len,\
                     &Show_Data, &Temp1);
    
  Move_Right(Area_No);
}

//上覆盖
void Move_Up_Cover(INT8U Area_No)
{
  S_Point Temp;
  
  //if(Prog_Status.Area_Status[Area_No].Step < Prog_Status.Area_Status[Area_No].Max_Step) //是否已经移动完成Prog_Status.Area_Status[Area_No].Max_Step%
  {
    Temp.X = 0;// + (Prog_Status.Area_Status[Area_No].Max_Step - Prog_Status.Area_Status[Area_No].Step) * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step;
    Temp.Y = Prog_Para.Area[Area_No].Y_Len - Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step;
    
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step,\
      &Show_Data, &Temp);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  }  
}

//下覆盖
void Move_Down_Cover(INT8U Area_No)
{
  S_Point Temp;
  
  //if(Prog_Status.Area_Status[Area_No].Step < Prog_Status.Area_Status[Area_No].Max_Step) //是否已经移动完成Prog_Status.Area_Status[Area_No].Max_Step%
  {
    Temp.X = 0;// + Step +
    Temp.Y = 0;//;
    
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step,\
      &Show_Data, &Temp);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  }  
}

//左覆盖
void Move_Left_Cover(INT8U Area_No)
{
  S_Point Temp;
  
  //if(Prog_Status.Area_Status[Area_No].Step < Prog_Status.Area_Status[Area_No].Max_Step) //是否已经移动完成Prog_Status.Area_Status[Area_No].Max_Step%
  {
    Temp.X = Prog_Para.Area[Area_No].X_Len - Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].X_Len / Prog_Status.Area_Status[Area_No].Max_Step;// + Step +
    Temp.Y = 0;
    
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].X_Len / Prog_Status.Area_Status[Area_No].Max_Step, Prog_Para.Area[Area_No].Y_Len,\
      &Show_Data, &Temp);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  }  
}

//右覆盖
void Move_Right_Cover(INT8U Area_No)
{
  S_Point Temp;
  //S_Point Temp1;
  
  //if(Prog_Status.Area_Status[Area_No].Step < Prog_Status.Area_Status[Area_No].Max_Step) //是否已经移动完成Prog_Status.Area_Status[Area_No].Max_Step%
  {
    Temp.X = 0;//Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step;// + Step +
    Temp.Y = 0;
    
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].X_Len / Prog_Status.Area_Status[Area_No].Max_Step, Prog_Para.Area[Area_No].Y_Len,\
      &Show_Data, &Temp);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  }  
}

//左上覆盖
void Move_Left_Up_Cover(INT8U Area_No)
{
  S_Point Point[6];
  INT8U i = 0;
  INT16U Area_Width, Area_Height,Step_Len;

  Area_Width = Get_Area_Width(Area_No);
  Area_Height = Get_Area_Height(Area_No);
  Step_Len = (Area_Width + Area_Height) * Prog_Status.Area_Status[Area_No].Step / Prog_Status.Area_Status[Area_No].Max_Step;

  //Step_Len = Area_Width + Area_Height;

  if(Step_Len > Area_Height)
  {
    Point[i].X = Area_Width + Area_Height - Step_Len;
    Point[i].Y = 0;
    i ++;

    Point[i].X = Area_Width;
    Point[i].Y = 0;
    i ++;
  }
  else
  {
    Point[i].X = Area_Width;
    Point[i].Y = Area_Height - Step_Len;
    i ++;
  }

  Point[i].X = Area_Width;
  Point[i].Y = Area_Height;
  i++;

  if(Step_Len < Area_Width)
  {
    Point[i].X = Area_Width - Step_Len;
    Point[i].Y = Area_Height;
    i ++;
  }
  else
  {
    Point[i].X = 0;//Area_Width - Step_Len;
    Point[i].Y = Area_Height;
    i ++;

    Point[i].X = 0;//Area_Width - Step_Len;
    Point[i].Y = Area_Height + Area_Width - Step_Len;
    i ++;
  }

  //i = 3;
  Copy_Filled_Polygon(&Show_Data_Bak, Area_No, &Point[0], i, &Show_Data, &Point[0]);

}

//右上覆盖
void Move_Right_Up_Cover(INT8U Area_No)
{
    S_Point Point[6];
    INT8U i = 0;
    INT16U Area_Width, Area_Height,Step_Len;

    Area_Width = Get_Area_Width(Area_No);
    Area_Height = Get_Area_Height(Area_No);
    Step_Len = (Area_Width + Area_Height) * Prog_Status.Area_Status[Area_No].Step / Prog_Status.Area_Status[Area_No].Max_Step;

    //Step_Len = Area_Width + Area_Height;
    Point[i].X = 0;
    Point[i].Y = Area_Height;
    i ++;

    if(Step_Len < Area_Height)
    {
      Point[i].X = 0;
      Point[i].Y = Area_Height - Step_Len;
      i++;
    }
    else//if(Step_Len >= Area_Height)
    {
      Point[i].X = 0;
      Point[i].Y = 0;
      i++;

      Point[i].X = Step_Len - Area_Height;
      Point[i].Y = 0;
      i ++;
    }

    if(Step_Len >= Area_Width)
    {
        Point[i].X = Area_Width;
        Point[i].Y = Area_Width + Area_Height - Step_Len;
        i ++;

        Point[i].X = Area_Width;
        Point[i].Y = Area_Height;
        i ++;
    }
    else
    {
        Point[i].X = Step_Len;
        Point[i].Y = Area_Height;
        i ++;
    }

    //i = 3;
    Copy_Filled_Polygon(&Show_Data_Bak, Area_No, &Point[0], i, &Show_Data, &Point[0]);

  
}

//左下覆盖
void Move_Left_Down_Cover(INT8U Area_No)
{
    S_Point Point[6];
    INT8U i = 0;
    INT16U Area_Width, Area_Height,Step_Len;

    Area_Width = Get_Area_Width(Area_No);
    Area_Height = Get_Area_Height(Area_No);
    Step_Len = (Area_Width + Area_Height) * Prog_Status.Area_Status[Area_No].Step / Prog_Status.Area_Status[Area_No].Max_Step;

    //Step_Len = (Area_Width + Area_Height) * 30 / Prog_Status.Area_Status[Area_No].Max_Step;
    Point[i].X = Area_Width;
    Point[i].Y = 0;
    i ++;

    if(Step_Len < Area_Height)
    {
      Point[i].X = Area_Width;
      Point[i].Y = Step_Len;
      i++;
    }
    else//if(Step_Len >= Area_Height)
    {
      Point[i].X = Area_Width;
      Point[i].Y = Area_Height;
      i++;

      Point[i].X = Area_Width + Area_Height - Step_Len;
      Point[i].Y = Area_Height;
      i ++;
    }

    if(Step_Len >= Area_Width)
    {
        Point[i].X = 0;//Area_Width - 1;
        Point[i].Y = Step_Len - Area_Width;
        i ++;

        Point[i].X = 0;//Area_Width - 1;
        Point[i].Y = 0;//Area_Height - 1;
        i ++;
    }
    else
    {
        Point[i].X = Area_Width - Step_Len;
        Point[i].Y = 0;//Area_Height - 1;
        i ++;
    }

    //i = 3;
    Copy_Filled_Polygon(&Show_Data_Bak, Area_No, &Point[0], i, &Show_Data, &Point[0]);

}

//右下覆盖
void Move_Right_Down_Cover(INT8U Area_No)
{
    S_Point Point[6];
    INT8U i = 0;
    INT16U Area_Width, Area_Height,Step_Len;

    Area_Width = Get_Area_Width(Area_No);
    Area_Height = Get_Area_Height(Area_No);
    Step_Len = (Area_Width + Area_Height) * Prog_Status.Area_Status[Area_No].Step / Prog_Status.Area_Status[Area_No].Max_Step;

    //Step_Len = (Area_Width + Area_Height) * 30 / Prog_Status.Area_Status[Area_No].Max_Step;
    Point[i].X = 0;
    Point[i].Y = 0;
    i ++;

    if(Step_Len < Area_Width)
    {
      Point[i].X = Step_Len;
      Point[i].Y = 0;
      i++;
    }
    else//if(Step_Len >= Area_Height)
    {
      Point[i].X = Area_Width;
      Point[i].Y = 0;
      i ++;

      Point[i].X = Area_Width;
      Point[i].Y = Step_Len - Area_Width;
      i++;
    }

    if(Step_Len >= Area_Height)
    {
        Point[i].X = Step_Len - Area_Height;//Area_Width - 1;
        Point[i].Y = Area_Height;
        i ++;

        Point[i].X = 0;//Area_Width - 1;
        Point[i].Y = Area_Height;//Area_Height - 1;
        i ++;
    }
    else
    {
        Point[i].X = 0;
        Point[i].Y = Step_Len;//Area_Height - 1;
        i ++;
    }

    //i = 3;
    Copy_Filled_Polygon(&Show_Data_Bak, Area_No, &Point[0], i, &Show_Data, &Point[0]);
}

//上下拉帘
void Move_Up_Down_Open(INT8U Area_No)
{
  S_Point Temp;
  
  //if(Prog_Status.Area_Status[Area_No].Step < Prog_Status.Area_Status[Area_No].Max_Step)
  {
    Temp.X = 0;
    Temp.Y = (Prog_Status.Area_Status[Area_No].Max_Step - Prog_Status.Area_Status[Area_No].Step)*Prog_Para.Area[Area_No].Y_Len / (Prog_Status.Area_Status[Area_No].Max_Step*2);
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step, &Show_Data, &Temp);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  }
  
}

//上下合帘
void Move_Up_Down_Close(INT8U Area_No)
{
  S_Point Temp;
  
  //if(Prog_Status.Area_Status[Area_No].Step < Prog_Status.Area_Status[Area_No].Max_Step)
  {
    Temp.X = 0;
    Temp.Y = 0;// + Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / (Prog_Status.Area_Status[Area_No].Max_Step*2);
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / (Prog_Status.Area_Status[Area_No].Max_Step*2), &Show_Data, &Temp);
    
    Temp.X = 0;
    Temp.Y = Prog_Para.Area[Area_No].Y_Len - 1 - Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / (Prog_Status.Area_Status[Area_No].Max_Step*2);
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / (Prog_Status.Area_Status[Area_No].Max_Step*2), &Show_Data, &Temp);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  }  
}

//左右开帘
void Move_Left_Right_Open(INT8U Area_No)
{
  S_Point Temp;
  
  //if(Prog_Status.Area_Status[Area_No].Step < Prog_Status.Area_Status[Area_No].Max_Step)
  {
    Temp.X = (Prog_Status.Area_Status[Area_No].Max_Step - Prog_Status.Area_Status[Area_No].Step)*Prog_Para.Area[Area_No].X_Len / (Prog_Status.Area_Status[Area_No].Max_Step*2);
    Temp.Y = 0; 
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp,  Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].X_Len / Prog_Status.Area_Status[Area_No].Max_Step, Prog_Para.Area[Area_No].Y_Len, &Show_Data, &Temp);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  }
  
}

//左右合帘
void Move_Left_Right_Close(INT8U Area_No)
{
  S_Point Temp;
  
  //if(Prog_Status.Area_Status[Area_No].Step < Prog_Status.Area_Status[Area_No].Max_Step)
  {
    Temp.X = 0;
    Temp.Y = 0;// + Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / (Prog_Status.Area_Status[Area_No].Max_Step*2);
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Status.Area_Status[Area_No].Step * (Prog_Para.Area[Area_No].X_Len) / (Prog_Status.Area_Status[Area_No].Max_Step*2), Prog_Para.Area[Area_No].Y_Len,  &Show_Data, &Temp);
    
    Temp.X = Prog_Para.Area[Area_No].X_Len - 1 - Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].X_Len / (Prog_Status.Area_Status[Area_No].Max_Step*2);
    Temp.Y = 0; 
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Status.Area_Status[Area_No].Step * (Prog_Para.Area[Area_No].X_Len)/ (Prog_Status.Area_Status[Area_No].Max_Step*2), Prog_Para.Area[Area_No].Y_Len, &Show_Data, &Temp);
    //Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
  }  
}

//判断三个点是否在一条直线上，同时pPoint1和pPoint2在pPoint0的同一侧
INT8U Check_Point_One_Line(S_Point *pPoint0, S_Point *pPoint1, S_Point *pPoint2)
{
    if(pPoint0->X != pPoint1->X && pPoint0->X != pPoint2->X)
    {
      if(((float)pPoint0->Y - (float)pPoint1->Y)/((float)pPoint0->X - (float)pPoint1->X) <=\
         ((float)pPoint0->Y - (float)pPoint2->Y)/((float)pPoint0->X - (float)pPoint2->X)) //斜率相等
        {
          if(((INT16S)pPoint0->X - (INT16S)pPoint1->X)*((INT16S)pPoint0->X - (INT16S)pPoint2->X) > 0)
              return 1;
          else
              return 0;
        }
        else
            return 0;
    }
    else
    {
        if(pPoint0->X EQ pPoint1->X && pPoint0->X EQ pPoint2->X)
        {
            if(((INT16S)pPoint0->Y - (INT16S)pPoint1->Y)*((INT16S)pPoint0->Y - (INT16S)pPoint2->Y) > 0)
               return 1;
            else
               return 0;
        }
        else
            return 0;
    }
}

//顺时针旋转
void Move_Spin_CW(INT8U Area_No)
{
   //INT16U X,Y;
   //INT16U Arg;
   INT16U Area_Width, Area_Height;
   S_Point Point[8];//,CPoint;
   INT8U i = 0;
   INT16U Len;

   Area_Width = Get_Area_Width(Area_No);
   Area_Height = Get_Area_Height(Area_No);

   Len = (Area_Width + Area_Height)*2 * Prog_Status.Area_Status[Area_No].Step/Prog_Status.Area_Status[Area_No].Max_Step;

   Point[i].X = Area_Width / 2;
   Point[i].Y = Area_Height / 2;
   i++;

   Point[i].X = Area_Width ;
   Point[i].Y = Area_Height / 2;
   i++;

   Point[i].X = Area_Width ;
   Point[i].Y = Area_Height / 2 + Len;

   //Get_Angle_Point(&Point[0], 360 - Arg, (Area_Width>Area_Height?Area_Height:Area_Width)/2, &CPoint);

   if(Len > Area_Height / 2)
   {
     Point[i].X = Area_Width;
     Point[i].Y = Area_Height;
     i++;

     Point[i].X = Area_Width + Area_Height / 2 -Len;
     Point[i].Y = Area_Height;
   }

   if(Len > Area_Height / 2 + Area_Width)
   {
     Point[i].X = 0;
     Point[i].Y = Area_Height;
     i++;

     Point[i].X = 0;
     Point[i].Y = Area_Height / 2 + Area_Width + Area_Height - Len;
   }

   if(Len > Area_Height / 2 + Area_Width + Area_Height)
   {
     Point[i].X = 0;
     Point[i].Y = 0;
     i++;

     Point[i].X = Len - (Area_Height / 2 + Area_Width + Area_Height);
     Point[i].Y = 0;
   }

   if(Len > Area_Height / 2 + Area_Width + Area_Height + Area_Width)
   {
     Point[i].X = Area_Width;
     Point[i].Y = 0;
     i ++;

     Point[i].X = Area_Width;
     Point[i].Y = Len - (Area_Height / 2 + Area_Width + Area_Height + Area_Width);
   }

   i++;
   Copy_Filled_Polygon(&Show_Data_Bak, Area_No, &Point[0], i, &Show_Data, &Point[0]);

   return;
}

//逆时针旋转
void Move_Spin_CCW(INT8U Area_No)
{
    //INT16U X;//,Y;
    //INT16U Arg;
    INT16U Area_Width, Area_Height;
    S_Point Point[8];//,CPoint;
    INT8U i = 0;
    INT16U Len;

    Area_Width = Get_Area_Width(Area_No);
    Area_Height = Get_Area_Height(Area_No);

    Len = (Area_Width + Area_Height)*2 * Prog_Status.Area_Status[Area_No].Step/Prog_Status.Area_Status[Area_No].Max_Step;

    Point[i].X = Area_Width / 2;
    Point[i].Y = Area_Height / 2;
    i++;

    Point[i].X = Area_Width;
    Point[i].Y = Area_Height / 2;
    i++;

    Point[i].X = Area_Width;
    Point[i].Y = Area_Height / 2 - Len;

    //Get_Angle_Point(&Point[0], 360 - Arg, (Area_Width>Area_Height?Area_Height:Area_Width)/2, &CPoint);

    if(Len > Area_Height / 2)
    {
      Point[i].X = Area_Width;
      Point[i].Y = 0;
      i++;

      Point[i].X = Area_Width + Area_Height / 2 -Len;
      Point[i].Y = 0;
    }

    if(Len > Area_Height / 2 + Area_Width)
    {
      Point[i].X = 0;
      Point[i].Y = 0;
      i++;

      Point[i].X = 0;
      Point[i].Y = Len - (Area_Height / 2 + Area_Width);
    }

    if(Len > Area_Height / 2 + Area_Width + Area_Height)
    {
      Point[i].X = 0;
      Point[i].Y = Area_Height;
      i++;

      Point[i].X = Len - (Area_Height / 2 + Area_Width + Area_Height);
      Point[i].Y = Area_Height;
    }

    if(Len > Area_Height / 2 + Area_Width + Area_Height + Area_Width)
    {
      Point[i].X = Area_Width;
      Point[i].Y = Area_Height;
      i ++;

      Point[i].X = Area_Width;
      Point[i].Y = Area_Height -(Len - (Area_Height / 2 + Area_Width + Area_Height + Area_Width));
    }

    i++;
    Copy_Filled_Polygon(&Show_Data_Bak, Area_No, &Point[0], i, &Show_Data, &Point[0]);

    return;
}

void Copy_Snow_Rect(S_Show_Data *pSrc, INT8U Area_No, S_Point *pPoint0, INT16U X_Len, INT16U Y_Len, \
                    S_Show_Data *pDst, S_Point *pPoint1)
{
  INT16U i,j,k;
  INT16U x, y;
  INT8U Re;

  for(i = 0;i < X_Len; i ++)
    for(j = 0; j < Y_Len; j++)
      {
        Re = Get_Area_Point_Data(pSrc, Area_No, pPoint0->X + i, pPoint0->Y + j);

        y = pPoint1->Y + j * SNOW_RATIO;
        x = pPoint0->X + i;

        if((x % 8) EQ 0)
            y +=8;
        else if((x % 8) EQ 1)
            y +=4;
        else if((x % 8) EQ 2)
            y +=1;
        else if((x % 8) EQ 3)
            y +=7;
        else if((x % 8) EQ 4)
            y +=5;
        else if((x % 8) EQ 5)
            y +=2;
        else if((x % 8) EQ 6)
            y +=6;
        else if((x % 8) EQ 7)
            y +=0;

        Set_Area_Point_Data(pDst, Area_No, pPoint1->X + i, y,Re);

        for(k = 1; k < SNOW_RATIO; k++)
          Set_Area_Point_Data(pDst, Area_No, pPoint1->X + i, pPoint1->Y + j * SNOW_RATIO + k, 0);

  }
}

//向上飘雪
void Move_Up_Snow(INT8U Area_No)
{
    INT16U Step_Len,Y_Len;
    S_Point P0,P1;

    //下降还没有到底的时间段
    if(Prog_Status.Area_Status[Area_No].Step <= (Prog_Status.Area_Status[Area_No].Max_Step / SNOW_RATIO))
    {
        //y = (height - y0)
        Step_Len = Prog_Para.Area[Area_No].Y_Len * Prog_Status.Area_Status[Area_No].Step / Prog_Status.Area_Status[Area_No].Max_Step;
        P0.X = 0;
        P0.Y = 0;//Prog_Para.Area[Area_No].Y_Len - Step_Len;

        P1.X = 0;
        P1.Y = Prog_Para.Area[Area_No].Y_Len - Step_Len * SNOW_RATIO;
        Copy_Snow_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Para.Area[Area_No].X_Len, Step_Len, &Show_Data,&P1);
    }
    else
    {/*
        Step_Len = Prog_Para.Area[Area_No].Y_Len * ((Prog_Status.Area_Status[Area_No].Step - (Prog_Status.Area_Status[Area_No].Max_Step / SNOW_RATIO)))*SNOW_RATIO/(SNOW_RATIO - 1)/ Prog_Status.Area_Status[Area_No].Max_Step;
        P0.X = 0;
        P0.Y = 0;//Prog_Para.Area[Area_No].Y_Len - Step_Len;

        Copy_Filled_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Para.Area[Area_No].X_Len, Step_Len, &Show_Data,&P0);

        //Step_Len = (Prog_Para.Area[Area_No].Y_Len - Step_Len)/ SNOW_RATIO;
        P0.Y = Step_Len;//P0.Y - P0.Y / SNOW_RATIO;

        Step_Len = (Prog_Para.Area[Area_No].Y_Len - Step_Len) / SNOW_RATIO;
        //P1.X = 0;
        //P1.Y = 0;
        Copy_Snow_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Para.Area[Area_No].X_Len, Step_Len, &Show_Data,&P0);
*/
//------------
        Step_Len = Prog_Para.Area[Area_No].Y_Len * ((Prog_Status.Area_Status[Area_No].Step - (Prog_Status.Area_Status[Area_No].Max_Step / SNOW_RATIO)))*SNOW_RATIO/(SNOW_RATIO - 1)/ Prog_Status.Area_Status[Area_No].Max_Step;

        P0.X = 0;
        P0.Y = Step_Len;//(Prog_Para.Area[Area_No].Y_Len - Step_Len) - (Prog_Para.Area[Area_No].Y_Len - Step_Len) / SNOW_RATIO;

        P1.X = 0;
        P1.Y = Step_Len;
        Y_Len = (Prog_Para.Area[Area_No].Y_Len - Step_Len) / SNOW_RATIO;
        Copy_Snow_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Para.Area[Area_No].X_Len, Y_Len, &Show_Data,&P1);

        P0.X = 0;
        P0.Y = 0;
        Y_Len = Step_Len;// / SNOW_RATIO;

        Copy_Filled_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Para.Area[Area_No].X_Len, Y_Len, &Show_Data,&P0);


        //------------
    }

}

//向下飘雪
void Move_Down_Snow(INT8U Area_No)
{
    INT16U Step_Len,Y_Len;
    S_Point P0,P1;

    //下降还没有到底的时间段
    if(Prog_Status.Area_Status[Area_No].Step <= (Prog_Status.Area_Status[Area_No].Max_Step / SNOW_RATIO))
    {
        //y = (height - y0)
        Step_Len = Prog_Para.Area[Area_No].Y_Len * Prog_Status.Area_Status[Area_No].Step / Prog_Status.Area_Status[Area_No].Max_Step;
        P0.X = 0;
        P0.Y = Prog_Para.Area[Area_No].Y_Len - Step_Len;

        P1.X = 0;
        P1.Y = 0;
        Copy_Snow_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Para.Area[Area_No].X_Len, Step_Len, &Show_Data,&P1);
    }
    else
    {
        Step_Len = Prog_Para.Area[Area_No].Y_Len * ((Prog_Status.Area_Status[Area_No].Step - (Prog_Status.Area_Status[Area_No].Max_Step / SNOW_RATIO)))*SNOW_RATIO/(SNOW_RATIO - 1)/ Prog_Status.Area_Status[Area_No].Max_Step;

        P0.X = 0;
        Y_Len = (Prog_Para.Area[Area_No].Y_Len - Step_Len) / SNOW_RATIO;
        P0.Y = (Prog_Para.Area[Area_No].Y_Len - Step_Len) - (Prog_Para.Area[Area_No].Y_Len - Step_Len) / SNOW_RATIO;

        P1.X = 0;
        P1.Y = 0;
        Copy_Snow_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Para.Area[Area_No].X_Len, Y_Len, &Show_Data,&P1);

        P0.X = 0;
        P0.Y = Prog_Para.Area[Area_No].Y_Len - Step_Len;

        Copy_Filled_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Para.Area[Area_No].X_Len, Step_Len, &Show_Data,&P0);


    }

}

INT16U Get_TENSILE_STEP(INT16U Len)
{
  if(Len > 1000)
    return 200;
  else if(Len > 800)
    return 160;
  else if(Len > 600)
    return 120;
  else if(Len > 400)
    return 80;
  else if(Len > 200)
    return 40;
  else if(Len > 100)
    return 16;
  else
    return 8;

/*
    INT16U Re;

    if(Len > 100)
    {
    Re = Len / 10;
    if(Re < 5)
        Re = 5;
    }
    else
        Re = 10;
    return Re;
    */
}

//复制横向的压缩窗口
void Copy_Compresssion_H_Rect(S_Show_Data *pSrc, INT8U Area_No, S_Point *pPoint0, INT16U X_Len, INT16U Y_Len, \
                              S_Show_Data *pDst, S_Point *pPoint1, INT16U Ratio, INT8U Direct)
{

    INT16U i;//, j;
    S_Point P0, P1,P2;
    INT16U TENSILE_STEP;
    //INT16U Temp;

    if(Ratio EQ 0)
        return;

    TENSILE_STEP = Get_TENSILE_STEP(Prog_Para.Area[Area_No].X_Len);//Prog_Para.Area[Area_No].X_Len);

    Ratio = TENSILE_STEP * Ratio / Prog_Status.Area_Status[Area_No].Max_Step;//100;//每10个里点亮几个;

    if(Direct EQ 0)
    {
        for(i = 0; i < X_Len; i ++)
        {
          if((i % TENSILE_STEP) < Ratio)
          {
              P0.X = pPoint0->X + i;
              P0.Y = pPoint0->Y;

              P1.X = pPoint0->X + i;
              P1.Y = pPoint0->Y + Y_Len - 1;

              P2.X = pPoint1->X + (i / TENSILE_STEP)*Ratio + (i % TENSILE_STEP);
              P2.Y = pPoint1->Y;
              Copy_Line(pSrc, Area_No, &P0, &P1, pDst, &P2);
           }
         }
    }
    else
    {
        //Clear_Area_Data(pDst, Area_No);
        for(i = 0; i < X_Len; i ++)
        {
          if(((X_Len - 1- i) % TENSILE_STEP) < Ratio)
          {
              P0.X = pPoint0->X + (X_Len - 1- i);
              P0.Y = pPoint0->Y;

              P1.X = pPoint0->X + (X_Len - 1- i);
              P1.Y = pPoint0->Y + Y_Len - 1;

              P2.X = pPoint1->X + X_Len - ((i / TENSILE_STEP)*Ratio + (i % TENSILE_STEP));
              P2.Y = pPoint1->Y;
              Copy_Line(pSrc, Area_No, &P0, &P1, pDst, &P2);
           }
         }
   }
}

//复制纵向的压缩窗口
void Copy_Compresssion_V_Rect(S_Show_Data *pSrc, INT8U Area_No, S_Point *pPoint0, INT16U X_Len, INT16U Y_Len, \
                              S_Show_Data *pDst, S_Point *pPoint1, INT16U Ratio, INT8U Direct)
{
    INT16U i;
    S_Point P0, P1,P2;
    INT16U TENSILE_STEP;

    if(Ratio EQ 0)
        return;

    TENSILE_STEP = Get_TENSILE_STEP(Prog_Para.Area[Area_No].Y_Len);

    Ratio = Ratio * TENSILE_STEP / (Prog_Status.Area_Status[Area_No].Max_Step);//100;//每10个里点亮几个;
    for(i = 0; i < Y_Len; i ++)
        //for(j = 0; j < Y_Len; j ++)
        {
        if((Direct EQ 0 && (i % TENSILE_STEP) < Ratio) ||\
           (Direct EQ 1 && (i % TENSILE_STEP) >= (TENSILE_STEP - Ratio)))
        {
              P0.X = pPoint0->X;// + i;
              P0.Y = pPoint0->Y + i;

              P1.X = pPoint0->X + X_Len - 1;
              P1.Y = pPoint0->Y + i;

              P2.X = pPoint1->X;
              P2.Y = pPoint1->Y + (i / TENSILE_STEP)*Ratio + (i % TENSILE_STEP);

              Copy_Line(pSrc, Area_No, &P0, &P1, pDst, &P2);
          }
    }
}

//左拉伸
void Move_Left_Tensile(INT8U Area_No)
{
    S_Point P0;

    P0.X = 0;
    P0.Y = 0;
    Copy_Compresssion_H_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Para.Area[Area_No].X_Len, Prog_Para.Area[Area_No].Y_Len,\
                             &Show_Data, &P0, Prog_Status.Area_Status[Area_No].Step, 0);
}

//右拉伸
void Move_Right_Tensile(INT8U Area_No)
{
    S_Point P0,P1;

    P0.X = 0;
    P0.Y = 0;

    P1.X = Prog_Para.Area[Area_No].X_Len - Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].X_Len / Prog_Status.Area_Status[Area_No].Max_Step;
    P1.Y = 0;
    Copy_Compresssion_H_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Para.Area[Area_No].X_Len, Prog_Para.Area[Area_No].Y_Len,\
                             &Show_Data, &P1, Prog_Status.Area_Status[Area_No].Step, 1);

}

//上拉伸
void Move_Up_Tensile(INT8U Area_No)
{
    S_Point P0;

    P0.X = 0;
    P0.Y = 0;
    Copy_Compresssion_V_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Para.Area[Area_No].X_Len, Prog_Para.Area[Area_No].Y_Len,\
                             &Show_Data, &P0, Prog_Status.Area_Status[Area_No].Step, 0);

}

//下拉伸
void Move_Down_Tensile(INT8U Area_No)
{
    S_Point P0,P1;

    P0.X = 0;
    P0.Y = 0;

    P1.X = 0;
    P1.Y = Prog_Para.Area[Area_No].Y_Len - Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step;
    Copy_Compresssion_V_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Para.Area[Area_No].X_Len, Prog_Para.Area[Area_No].Y_Len,\
                             &Show_Data, &P1, Prog_Status.Area_Status[Area_No].Step, 1);

}

//垂直拉伸
void Move_Vertical_Tensile(INT8U Area_No)
{
    S_Point P0,P1;
    INT16U Step;
    INT16U TENSILE_STEP;

    TENSILE_STEP = Get_TENSILE_STEP(Prog_Para.Area[Area_No].Y_Len);

    if(Prog_Status.Area_Status[Area_No].Step < Prog_Status.Area_Status[Area_No].Max_Step)
      Step = Prog_Status.Area_Status[Area_No].Step / (Prog_Status.Area_Status[Area_No].Max_Step / TENSILE_STEP) *(Prog_Status.Area_Status[Area_No].Max_Step / TENSILE_STEP);
    else
      Step = Prog_Status.Area_Status[Area_No].Step;

    P0.X = 0;
    P0.Y = 0;

    P1.X = 0;
    P1.Y = Prog_Para.Area[Area_No].Y_Len - Step * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step;
    P1.Y = P1.Y / 2;
    Copy_Compresssion_V_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Para.Area[Area_No].X_Len, Prog_Para.Area[Area_No].Y_Len / 2,\
                             &Show_Data, &P1, Step, 0);

    P0.X = 0;
    P0.Y = Prog_Para.Area[Area_No].Y_Len / 2;

    P1.X = 0;
    P1.Y = Prog_Para.Area[Area_No].Y_Len / 2;//Prog_Para.Area[Area_No].Y_Len - Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step;
    //P1.Y = P1.Y / 2;
    Copy_Compresssion_V_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Para.Area[Area_No].X_Len, Prog_Para.Area[Area_No].Y_Len / 2,\
                             &Show_Data, &P1, Step, 0);

}

//水平拉伸
void Move_Horizontal_Tensile(INT8U Area_No)
{
    S_Point P0,P1;
    INT16U Step;
    INT16U TENSILE_STEP;

    TENSILE_STEP = Get_TENSILE_STEP(Prog_Para.Area[Area_No].X_Len);

    if(Prog_Status.Area_Status[Area_No].Step < Prog_Status.Area_Status[Area_No].Max_Step)
      Step = Prog_Status.Area_Status[Area_No].Step / (Prog_Status.Area_Status[Area_No].Max_Step / TENSILE_STEP) *(Prog_Status.Area_Status[Area_No].Max_Step / TENSILE_STEP);
    else
      Step = Prog_Status.Area_Status[Area_No].Step;
    P0.X = 0;
    P0.Y = 0;

    P1.X = Prog_Para.Area[Area_No].X_Len - Step * Prog_Para.Area[Area_No].X_Len / Prog_Status.Area_Status[Area_No].Max_Step;
    P1.Y = 0;
    P1.X = P1.X / 2;
    Copy_Compresssion_H_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Para.Area[Area_No].X_Len / 2, Prog_Para.Area[Area_No].Y_Len,\
                             &Show_Data, &P1, Step, 0);

    P0.X = Prog_Para.Area[Area_No].X_Len / 2;
    P0.Y = 0;

    P1.X = Prog_Para.Area[Area_No].X_Len / 2;
    P1.Y = 0;//Prog_Para.Area[Area_No].Y_Len - Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step;
    //P1.Y = P1.Y / 2;
    Copy_Compresssion_H_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Para.Area[Area_No].X_Len / 2, Prog_Para.Area[Area_No].Y_Len,\
                             &Show_Data, &P1, Step, 0);
}

//闪烁
void Move_Flash(INT8U Area_No)
{
   S_Point P0;

   P0.X = 0;
   P0.Y = 0;

   if((Prog_Status.Area_Status[Area_No].Step / (Prog_Status.Area_Status[Area_No].Max_Step/10)) % 2 EQ 0)
    {
      Copy_Filled_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Para.Area[Area_No].X_Len, Prog_Para.Area[Area_No].Y_Len,\
                       &Show_Data, &P0);
   }
   else
       Clear_Area_Data(&Show_Data, Area_No);
}

//上镭射
void Move_Up_Laser(INT8U Area_No)
{
    S_Point Temp,Temp1;
    INT8U Re;
    INT16U i;


    Clear_Area_Data(&Show_Data, Area_No);
    Temp.X = 0;// + (Prog_Status.Area_Status[Area_No].Max_Step - Prog_Status.Area_Status[Area_No].Step) * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step;
    Temp.Y = Prog_Para.Area[Area_No].Y_Len - Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step;

    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step,\
                     &Show_Data, &Temp);


    for(i = 0; i < Prog_Para.Area[Area_No].X_Len; i ++)
    {
       Re = Get_Area_Point_Data(&Show_Data_Bak, Area_No, i, Temp.Y);
       if(Re)// && (i % 2))
       {
           Temp1.X = i;
           Temp1.Y = 0;

           Temp.X = i;
           Draw_Line(&Show_Data, Area_No, &Temp, &Temp1,Re);
       }
    }
}

//下镭射
void Move_Down_Laser(INT8U Area_No)
{
    S_Point Temp,Temp1;
    INT8U Re;
    INT16U i;

    Clear_Area_Data(&Show_Data, Area_No);

    Temp.X = 0;// + Step +
    Temp.Y = 0;//;

    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step,\
                     &Show_Data, &Temp);

    Temp.Y = Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step;
    for(i = 0; i < Prog_Para.Area[Area_No].X_Len; i ++)
    {
       //Temp.Y = i;
       Re = Get_Area_Point_Data(&Show_Data_Bak, Area_No, i, Temp.Y);
       if(Re)// && (i % 2))
       {
           Temp1.X = i;
           Temp1.Y = Prog_Para.Area[Area_No].Y_Len - 1;

           Temp.X = i;
           Draw_Line(&Show_Data, Area_No, &Temp, &Temp1,Re);
       }
    }

}

//左镭射
void Move_Left_Laser(INT8U Area_No)
{
    INT8U Re;
    S_Point Temp,Temp1;
    INT16U i;

    Clear_Area_Data(&Show_Data, Area_No);
    Temp.X = Prog_Para.Area[Area_No].X_Len - Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].X_Len / Prog_Status.Area_Status[Area_No].Max_Step;// + Step +
    Temp.Y = 0;

    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].X_Len / Prog_Status.Area_Status[Area_No].Max_Step, Prog_Para.Area[Area_No].Y_Len,\
      &Show_Data, &Temp);

    for(i = 0; i < Prog_Para.Area[Area_No].Y_Len; i ++)
    {
       Re = Get_Area_Point_Data(&Show_Data_Bak, Area_No, Temp.X, i);
       if(Re)// && (i % 2))
       {
           Temp1.X = 0;
           Temp1.Y = i;

           Temp.Y = i;
           Draw_Line(&Show_Data, Area_No, &Temp, &Temp1,Re);
       }
    }
}

//右镭射
void Move_Right_Laser(INT8U Area_No)
{
    S_Point Temp;
    INT8U Re;
    INT16U i;
    S_Point Temp1;


    Clear_Area_Data(&Show_Data, Area_No);
    Temp.X = 0;//Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step;// + Step +
    Temp.Y = 0;

    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].X_Len / Prog_Status.Area_Status[Area_No].Max_Step, Prog_Para.Area[Area_No].Y_Len,\
    &Show_Data, &Temp);

    Temp.X = Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].X_Len / Prog_Status.Area_Status[Area_No].Max_Step;
    for(i = 0; i < Prog_Para.Area[Area_No].Y_Len; i ++)
    {
       //Temp.Y = i;
       Re = Get_Area_Point_Data(&Show_Data_Bak, Area_No, Temp.X, i);
       if(Re)// && (i % 2))
       {
           Temp1.X = Prog_Para.Area[Area_No].X_Len - 1;
           Temp1.Y = i;

           Temp.Y = i;
           Draw_Line(&Show_Data, Area_No, &Temp, &Temp1,Re);
       }
    }
}

//左移弹出
void Move_Left_Stretch(INT8U Area_No)
{
    S_Point Temp;
    S_Point Temp1;
    INT16U Step;
    INT16U Moved_Len;

    if(Prog_Status.Area_Status[Area_No].Step < Prog_Status.Area_Status[Area_No].Max_Step / 3)
    {
        Temp.X = 0;//Prog_Para.Area[Area_No].X;
        Temp.Y = 0;//Prog_Para.Area[Area_No].Y;

        Step = Prog_Status.Area_Status[Area_No].Step * 3;
        Moved_Len =  Step * Prog_Para.Area[Area_No].X_Len / Prog_Status.Area_Status[Area_No].Max_Step;
        Temp1.X = Prog_Para.Area[Area_No].X_Len - Moved_Len;// + Step +
        Temp1.Y = 0;

        Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Moved_Len,Prog_Para.Area[Area_No].Y_Len, \
          &Show_Data, &Temp1);
   }
   else if(Prog_Status.Area_Status[Area_No].Step < Prog_Status.Area_Status[Area_No].Max_Step*2 / 3)
   {
       Clear_Area_Data(&Show_Data, Area_No);
       Temp.X = 0;
       Temp.Y = 0;
       Step = (Prog_Status.Area_Status[Area_No].Max_Step - (Prog_Status.Area_Status[Area_No].Step  * 3- Prog_Status.Area_Status[Area_No].Max_Step));
       Copy_Compresssion_H_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, Prog_Para.Area[Area_No].Y_Len,\
                                &Show_Data, &Temp, Step, 0);

   }
   else
   {
       Temp.X = 0;
       Temp.Y = 0;
       Step = (Prog_Status.Area_Status[Area_No].Step*3 - Prog_Status.Area_Status[Area_No].Max_Step * 2);
       Copy_Compresssion_H_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, Prog_Para.Area[Area_No].Y_Len,\
                                &Show_Data, &Temp, Step, 0);

   }
 }

//右移弹出
void Move_Right_Stretch(INT8U Area_No)
{

}

//上移弹出
void Move_Up_Stretch(INT8U Area_No)
{
    S_Point Temp;
    S_Point Temp1;
    INT16U Step;
    INT16U Moved_Len;

    if(Prog_Status.Area_Status[Area_No].Step < Prog_Status.Area_Status[Area_No].Max_Step / 3)
    {
        Temp.X = 0;//Prog_Para.Area[Area_No].X;
        Temp.Y = 0;//Prog_Para.Area[Area_No].Y;

        Step = Prog_Status.Area_Status[Area_No].Step * 3;
        Moved_Len =  Step * Prog_Para.Area[Area_No].Y_Len / Prog_Status.Area_Status[Area_No].Max_Step;
        Temp1.X = 0;// + Step +
        Temp1.Y = Prog_Para.Area[Area_No].Y_Len - Moved_Len;;

        Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, Moved_Len, \
          &Show_Data, &Temp1);
   }
   else if(Prog_Status.Area_Status[Area_No].Step < Prog_Status.Area_Status[Area_No].Max_Step*2 / 3)
   {
       Clear_Area_Data(&Show_Data, Area_No);
       Temp.X = 0;
       Temp.Y = 0;
       Step = (Prog_Status.Area_Status[Area_No].Max_Step - (Prog_Status.Area_Status[Area_No].Step*3 - Prog_Status.Area_Status[Area_No].Max_Step));
       Copy_Compresssion_V_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, Prog_Para.Area[Area_No].Y_Len,\
                                &Show_Data, &Temp, Step, 0);

   }
   else
   {
       Temp.X = 0;
       Temp.Y = 0;
       Step = (Prog_Status.Area_Status[Area_No].Step * 3 - Prog_Status.Area_Status[Area_No].Max_Step * 2) ;
       Copy_Compresssion_V_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Para.Area[Area_No].X_Len, Prog_Para.Area[Area_No].Y_Len,\
                                &Show_Data, &Temp, Step, 0);

   }
}

void Move_Down_Stretch(INT8U Area_No)
{

}

void Move_Up_Left(INT8U Area_No)
{

}

//水平百叶窗
void Move_Horizontal_Window(INT8U Area_No)
{
  INT16U i;
  S_Point P0;
  INT16U Width,Num;
  //INT32U Step;

  Width = WIN_LEAF_WIDTH;
  Num = Prog_Para.Area[Area_No].X_Len / Width;
  if(Num EQ 0)
      Num = 1;

  for(i = 0; i < Num ; i++)
  {
     P0.X = (INT16U)i * Width;//Prog_Para.Area[Area_No].Y_Len / 20;
     P0.Y = 0;
     Copy_Filled_Rect(&Show_Data_Bak, Area_No, &P0, Width * Prog_Status.Area_Status[Area_No].Step / Prog_Status.Area_Status[Area_No].Max_Step, Prog_Para.Area[Area_No].Y_Len, &Show_Data, &P0);
  }

}

//垂直百叶窗
void Move_Vertical_Window(INT8U Area_No)
{
    INT16U i;
    S_Point P0;
    INT16U Width,Num;
    //INT32U Step;

    Width = WIN_LEAF_WIDTH;
    Num = Prog_Para.Area[Area_No].Y_Len / Width;
    if(Num EQ 0)
        Num = 1;

    for(i = 0; i < Num ; i++)
    {
       P0.X = 0;//Prog_Para.Area[Area_No].Y_Len / 20;
       P0.Y = (INT16U)i * Width;
       Copy_Filled_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Para.Area[Area_No].X_Len, Width * Prog_Status.Area_Status[Area_No].Step / Prog_Status.Area_Status[Area_No].Max_Step, &Show_Data, &P0);
    }
}

//左压缩
void Move_Left_Compress(INT8U Area_No)
{
  INT16U i,j;
  S_Point P0,P1,P2;
  INT16U Step;

  Step = 10 - Prog_Status.Area_Status[Area_No].Step / (Prog_Status.Area_Status[Area_No].Max_Step / 10);
  Step++;
  if(Step EQ 0)
      return;

  //Clear_Area_Data(&Show_Data, Area_No);
  for(i = 0; i < Prog_Para.Area[Area_No].X_Len / Step; i ++)
  {
      P0.X = i;
      P0.Y = 0;

      P1.X = i;
      P1.Y = Prog_Para.Area[Area_No].Y_Len - 1;

      for(j = 0; j < Step; j++)
      {
          P2.X = i *Step + j;
          P2.Y = 0;
          Copy_Line(&Show_Data_Bak, Area_No, &P0, &P1, &Show_Data, &P2);

      }
  }
  /*
    INT16U i,j;
    S_Point P0,P1,P2;
    INT16U Step;

    Step = Prog_Status.Area_Status[Area_No].Step;
    if(Step EQ 0)
        Step = 1;

    //Clear_Area_Data(&Show_Data, Area_No);
    j = 0;
    i = 0;
    while(j < Prog_Para.Area[Area_No].X_Len)
    {
        P0.X = i;
        P0.Y = 0;

        P1.X = i;
        P1.Y = Prog_Para.Area[Area_No].Y_Len - 1;

        P2.X = j;
        P2.Y = Prog_Para.Area[Area_No].Y_Len - 1;

        Copy_Line(&Show_Data_Bak, Area_No, &P0, &P1, &Show_Data, &P2);

        if(i % Step EQ 0)
        {
            P2.X = j + 1;
            P2.Y = Prog_Para.Area[Area_No].Y_Len - 1;
            Copy_Line(&Show_Data_Bak, Area_No, &P0, &P1, &Show_Data, &P2);
            j++;
        }

        i++;
        j++;
    }*/
}

//右压缩
void Move_Right_Compress(INT8U Area_No)
{

}

//上压缩
void Move_Up_Compress(INT8U Area_No)
{
    INT16U i,j;
    S_Point P0,P1,P2;
    INT16U Step;

    Step = 10 - Prog_Status.Area_Status[Area_No].Step / (Prog_Status.Area_Status[Area_No].Max_Step / 10);
    Step++;
    if(Step EQ 0)
        return;

    //Clear_Area_Data(&Show_Data, Area_No);
    for(i = 0; i < Prog_Para.Area[Area_No].Y_Len / Step; i ++)
    {
        P0.X = 0;
        P0.Y = i;

        P1.X = Prog_Para.Area[Area_No].X_Len - 1;
        P1.Y = i;

        for(j = 0; j < Step; j++)
        {
            P2.X = 0;
            P2.Y = i *Step + j;
            Copy_Line(&Show_Data_Bak, Area_No, &P0, &P1, &Show_Data, &P2);

        }
    }
}

//下压缩
void Move_Down_Compress(INT8U Area_No)
{

}

//左压缩
void Move_Left_Compress_0(INT8U Area_No)
{
  INT16U i,j;
  S_Point P0,P1,P2;
  INT16U Step;

  /*
  //-------------------
  S_Point Temp;


    Temp.X = 0;//Prog_Para.Area[Area_No].X_Len - Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].X_Len / Prog_Status.Area_Status[Area_No].Max_Step;// + Step +
    Temp.Y = 0;

    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, Prog_Status.Area_Status[Area_No].Step * Prog_Para.Area[Area_No].X_Len / Prog_Status.Area_Status[Area_No].Max_Step, Prog_Para.Area[Area_No].Y_Len,\
      &Show_Data, &Temp);

    for(i = 0; i < )
//--------------------------------------
*/
  Step = 10 - Prog_Status.Area_Status[Area_No].Step / (Prog_Status.Area_Status[Area_No].Max_Step / 10);
  Step++;
  if(Step EQ 0)
      return;


  //Clear_Area_Data(&Show_Data, Area_No);
  for(i = 0; i < Prog_Para.Area[Area_No].X_Len / Step; i ++)
  {
      P0.X = i;
      P0.Y = 0;

      P1.X = i;
      P1.Y = Prog_Para.Area[Area_No].Y_Len - 1;

      for(j = 0; j < Step; j++)
      {
          P2.X = i *Step + j;
          P2.Y = 0;
          Copy_Line(&Show_Data_Bak, Area_No, &P0, &P1, &Show_Data, &P2);

      }
  }
  /*
    INT16U i,j;
    S_Point P0,P1,P2;
    INT16U Step;

    Step = Prog_Status.Area_Status[Area_No].Step;
    if(Step EQ 0)
        Step = 1;

    //Clear_Area_Data(&Show_Data, Area_No);
    j = 0;
    i = 0;
    while(j < Prog_Para.Area[Area_No].X_Len)
    {
        P0.X = i;
        P0.Y = 0;

        P1.X = i;
        P1.Y = Prog_Para.Area[Area_No].Y_Len - 1;

        P2.X = j;
        P2.Y = Prog_Para.Area[Area_No].Y_Len - 1;

        Copy_Line(&Show_Data_Bak, Area_No, &P0, &P1, &Show_Data, &P2);

        if(i % Step EQ 0)
        {
            P2.X = j + 1;
            P2.Y = Prog_Para.Area[Area_No].Y_Len - 1;
            Copy_Line(&Show_Data_Bak, Area_No, &P0, &P1, &Show_Data, &P2);
            j++;
        }

        i++;
        j++;
    }*/
}

//逐点淡入
void Move_Fade_In(INT8U Area_No)
{
    INT8U Re;
    INT16U i,j;
    INT16U Step;
    //const INT8U data[20] = {1,17,3,9,19,0,15,10,7, 6,18, 2,12,4,8,14,11,13,16,5};

    Step =  Prog_Status.Area_Status[Area_No].Step *20/ Prog_Status.Area_Status[Area_No].Max_Step;
    Step = 20 - Step;
    if(Step == 0)
       Step = 1;

    for(i = 0; i < Prog_Para.Area[Area_No].X_Len; i ++)
        for(j = 0; j < Prog_Para.Area[Area_No].Y_Len; j++)
        {
          if(i % Step < 2 && j % Step < 2)
          //if(i % 20 EQ data[Step] && j %20 EQ 19 - data[Step])
          {
             Re = Get_Area_Point_Data(&Show_Data_Bak, Area_No, i, j);
             Set_Area_Point_Data(&Show_Data, Area_No, i, j, Re);
          }
    }
}

//左上引入
void Move_Left_Up_In(INT8U Area_No)
{
  S_Point Temp,Temp0;
  INT16U X_Off,Y_Off;
  static INT16U OldX = 0xFFFF,OldY = 0xFFFF;


  X_Off = (INT16U)((float)Prog_Para.Area[Area_No].X_Len * Prog_Status.Area_Status[Area_No].Step/ Prog_Status.Area_Status[Area_No].Max_Step + 0.5);
  Y_Off = (INT16U)((float)Prog_Para.Area[Area_No].Y_Len * Prog_Status.Area_Status[Area_No].Step/ Prog_Status.Area_Status[Area_No].Max_Step + 0.5);

  Temp.X = Prog_Para.Area[Area_No].X_Len - X_Off;
  Temp.Y = Prog_Para.Area[Area_No].Y_Len - Y_Off;

  Temp0.X = 0;
  Temp0.Y = 0;

  if(OldX != Temp.X && OldY != Temp.Y)
  {
    OldX = Temp.X;
    OldY = Temp.Y;
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, X_Off, Y_Off, &Show_Data, &Temp0);
  }

}

//右上引入
void Move_Right_Up_In(INT8U Area_No)
{
    S_Point Temp,Temp0;
    INT16U X_Off,Y_Off;
    static INT16U OldX = 0xFFFF,OldY = 0xFFFF;


    X_Off = (INT16U)((float)Prog_Para.Area[Area_No].X_Len * Prog_Status.Area_Status[Area_No].Step/ Prog_Status.Area_Status[Area_No].Max_Step + 0.5);
    Y_Off = (INT16U)((float)Prog_Para.Area[Area_No].Y_Len * Prog_Status.Area_Status[Area_No].Step/ Prog_Status.Area_Status[Area_No].Max_Step + 0.5);

    Temp.X = 0;//Prog_Para.Area[Area_No].X_Len - 1;// X_Off;
    Temp.Y = Prog_Para.Area[Area_No].Y_Len - Y_Off;

    Temp0.X = Prog_Para.Area[Area_No].X_Len - X_Off;
    Temp0.Y = 0;//Prog_Para.Area[Area_No].Y_Len - Y_Off;

    if(OldX != Temp0.X && OldY != Temp.Y)
    {
      OldX = Temp0.X;
      OldY = Temp.Y;
      Copy_Filled_Rect(&Show_Data_Bak, Area_No, &Temp, X_Off, Y_Off, &Show_Data, &Temp0);
    }

}

//左下引入
void Move_Left_Down_In(INT8U Area_No)
{

}

//右下引入
void Mofe_Right_Down_In(INT8U Area_No)
{

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

#define Put_Char(c) Buf[j++] = c
//根据format和ap参数表输出调试信息
void vsPrintf(char Buf[], CONST INT8S *format, va_list ap)
{

  INT8U j = 0;
  static const INT8S Chr[] = "0123456789ABCDEF";

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
      Put_Char(c);
    }

    c=*format++;
    //非数值类型处理
    switch(c)
    {
      case 'c':
        c = va_arg(ap, int);
        Put_Char(c);
        break;
      case 's':
        pSrc= va_arg(ap,INT8S *);
        while((c = *pSrc++)!=0)
          Put_Char(c);
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

    if(c=='l' || c=='L')//是否是一个长整形?
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
    if(c=='d')//有符号数
    {
      if(LintFlag)//长整型
        sParaValue=va_arg(ap,long int);
      else
        sParaValue=va_arg(ap,int);

      if(sParaValue<0)
      {
        Put_Char('-');
        sParaValue=0-sParaValue;
      }
      uParaValue=(unsigned long int)sParaValue;//赋值到uParaValue,统一计算
    }
    else//无符号数
    {
      if(LintFlag)//长整型
        uParaValue=va_arg(ap,unsigned long int);
      else
        uParaValue=va_arg(ap,int);
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

      if(c==0 && i==0 && Width>1)//该位为0，且之前的位也都为0,且不是最后一位(数值本身为0)
        c='0';
      else
      {
        i=1;//表示已经有一个非0位了
        c=Chr[c];
      }
      Put_Char(c);
    }
  }
}

//Disp_Flag,1表示反显，0表示正显
  void Show_String(INT8U Str[], INT8U Font, INT8U Color, S_Show_Data *pData, INT8U Area_No, INT16U X,INT16U Y)
  {
    INT8U i;
    INT8U FontWidth;
    INT16U Unicode;
    //INT8U X_Bak;

    FontWidth = Get_Font_Width(Font)*2;


    i=0;
    //X_Bak = X;
    while(Str[i]!=0)
    {
      if(Str[i]>=0xA0)
      {
        Unicode=((INT16U)Str[i])*256+(INT16U)Str[i+1];
        Show_Char(Unicode, Font, Color, pData, Area_No, X, Y);
        X+=FontWidth;
        i=i+2;
      }
      else
      {
        if(Str[i]=='\r')
        {
          X=0;//X_Bak;
          i++;
        }
        else if(Str[i]=='\n')
        {
          Y+=FontWidth;
          i++;
        }
        else
        {
        Show_Char(Str[i], Font, Color, pData, Area_No, X, Y);
        X+=FontWidth / 2;
        i=i+1;
        }
      }
    }
  }

//根据format和ap参数表输出调试信息
INT16U LED_Print(INT8U Font, INT8U Color, S_Show_Data *pData, INT8U Area_No, INT16U X, INT16U Y, const INT8S *format,...)
{

	va_list ap;
	
	memset(Print_Buf, 0, sizeof(Print_Buf));
	va_start(ap,format);
        vsPrintf((char *)Print_Buf, format, ap);
	
	if(pData != (S_Show_Data *)0)
	  Show_String(Print_Buf, Font, Color, pData,  Area_No, X, Y);
	va_end(ap);
	
	return strlen((char *)Print_Buf)*Get_Font_Width(Font);
}

//实时显示某个数据在
INT16U RT_LED_Print(INT8U Font, INT8U Color, INT16U X, INT16U Y, INT16U Sec, const INT8S *format,...)
{
  va_list ap;

  Set_RT_Show_Area(Screen_Para.Base_Para.Width, Screen_Para.Base_Para.Height);
  RT_Play_Status_Enter(Sec);

  memset(Print_Buf, 0, sizeof(Print_Buf));

  va_start(ap,format);
  vsPrintf((char *)Print_Buf, format, ap);

  Show_String(Print_Buf, Font, Color, &Show_Data,  0, X, Y);
  
  va_end(ap);

  return strlen((char *)Print_Buf)*Get_Font_Width(Font);

}





