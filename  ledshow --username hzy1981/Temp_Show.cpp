#define TEMP_SHOW_C
#include "Includes.h"

#if TEMP_SHOW_EN
//#define TEMP_STR_MAX_WIDTH 250

//温度>=0是使用以下格式字符串
const S_Format_Str TempStr0[]=
{
    {"温度 %2d.%d℃", 11},
    {"温度 %2d℃", 9}, 
    {" %2d.%d℃", 7}, 
    {" %2d℃",5}

};

//当温度<0时候，使用以下格式字符串
const S_Format_Str TempStr1[]=
{
    {"温度-%2d.%d℃", 11},
    {"温度-%2d℃", 9}, 
    {"-%2d.%d℃", 7}, 
    {"-%2d℃",5}

};

//获取温度显示的像素宽度
INT16U Get_TempStr_Pix_Width(INT8U Type, INT8U Font)
{
  if(Type < S_NUM(TempStr0)) //TempStr0和TempStr1的宽度是一样的
   return TempStr0[Type].Len*Get_Font_Width(Font);
  else
    return 0;
}

//显示温度的最小
INT16U Get_Temp_Min_Width(INT8U Area_No)
{
    INT16U StrWidth;
    //INT8U Font,Type;
    StrWidth = Get_TempStr_Pix_Width(Prog_Status.File_Para[Area_No].Temp_Para.Temp_Type, \
                                     Prog_Status.File_Para[Area_No].Temp_Para.Temp_Font);


    if(Prog_Status.File_Para[Area_No].Temp_Para.Text_Width)
      return Prog_Status.File_Para[Area_No].Temp_Para.Text_Width + SPACE_WIDTH + StrWidth;
    else
      return StrWidth;
}

//显示定时信息的最小高度
INT16U Get_Temp_Min_Height(INT8U Area_No)
{
    INT16U StrHeight;
    //INT16U Height;

    StrHeight = Get_Font_Height(Prog_Status.File_Para[Area_No].Temp_Para.Temp_Font);

    if(Prog_Status.File_Para[Area_No].Temp_Para.Text_Height > StrHeight)
        return Prog_Status.File_Para[Area_No].Temp_Para.Text_Height;
    else
        return StrHeight;
}
//显示温度
//pDst_Buf目标显示缓冲
//Area_No分区
//X、Y为显示坐标
//Temp为温度，小数为1位
//
void Show_Temp(S_Show_Data *pDst_Buf, INT8U Area_No, INT16U X, INT16U Y, INT16S Temp, INT8U Type, INT8U Font, INT8U Color)
{
    char const *p;
    INT8U d; //i为整数部分，d为小数部分
    INT8U i;
    //INT16U uTemp;
    
    if(Temp >= 0)
    {
      if(Type >= S_NUM(TempStr0))
        return;
     
      p = TempStr0[Type].str;
      d = Temp % 10;
      i = Temp / 10;
    }
    else
    {
      if(Type >= S_NUM(TempStr1))
        return;
      
      p = TempStr1[Type].str;
      d = (0 - Temp)% 10;
      i = (0 - Temp)/ 10;
    }
    
    if(Type EQ 0 || Type EQ 2)
      LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, p, i,d);
    else if(Type EQ 1 || Type EQ 3)
      LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, p, i);
}

//更新温度数据
void Update_Temp_Data(S_Show_Data *pDst, INT8U Area_No)
{
    S_Point P0;
    INT16U Width,Height;
    INT16U Min_Width;//, Min_Height;
    INT16S Temp;

    Width = Get_Area_Width(Area_No);
    Height = Get_Area_Height(Area_No);

    Min_Width = Get_Temp_Min_Width(Area_No);
    //Min_Height = Get_Temp_Min_Height(Area_No);
 
    if(Width > Min_Width)
      P0.X = (Width - Min_Width) / 2;
    else
      P0.X = 0;
/*
    if(Height > Prog_Status.File_Para[Area_No].Temp_Para.Text_Height)
      P0.Y = (Height - Prog_Status.File_Para[Area_No].Temp_Para.Text_Height)/2;
    else
      P0.Y = 0;//(Height - Prog_Status.File_Para[Area_No].Temp_Para.Text_Height)/2;
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Status.File_Para[Area_No].Temp_Para.Text_Width, Prog_Status.File_Para[Area_No].Temp_Para.Text_Height, &Show_Data, &P0);//&Point);
*/

    P0.X = P0.X + Prog_Status.File_Para[Area_No].Temp_Para.Text_Width;
    if(Prog_Status.File_Para[Area_No].Temp_Para.Text_Width)
      P0.X += SPACE_WIDTH;//Get_Font_Width(Prog_Status.File_Para[Area_No].Temp_Para.);

    if(Height > Get_Font_Height(Prog_Status.File_Para[Area_No].Temp_Para.Temp_Font))
      P0.Y = (Height - Get_Font_Height(Prog_Status.File_Para[Area_No].Temp_Para.Temp_Font))/2;
    else
      P0.Y = 0;

    Temp = Get_Cur_Temp(); //--获取当前温度
    Show_Temp(pDst, Area_No, P0.X, P0.Y, Temp, \
               Prog_Status.File_Para[Area_No].Temp_Para.Temp_Type, Prog_Status.File_Para[Area_No].Temp_Para.Temp_Font,Prog_Status.File_Para[Area_No].Temp_Para.Temp_Color);

      
    //Prog_Status.Area_Status[Area_No].Step = 100; //一步显示到位，直接100%
}
#endif
