#define NOISE_SHOW_C
#include "Includes.h"

#if NOISE_SHOW_EN
//#define NOISE_STR_MAX_WIDTH 250

//噪音>=0是使用以下格式字符串
const S_Format_Str NoiseStr0[]=
{
    //{"噪音 %2d.%ddB", 11},
    {"噪音 %2ddB", 9},
    {"%2ddB", 4}
};


//获取噪音显示的像素宽度
INT16U Get_NoiseStr_Pix_Width(INT8U Type, INT8U Font)
{
  if(Type < S_NUM(NoiseStr0)) //NoiseStr0和NoiseStr1的宽度是一样的
   return NoiseStr0[Type].Len*Get_Font_Width(Font);
  else
    return 0;
}

//显示噪音的最小
INT16U Get_Noise_Min_Width(INT8U Area_No)
{
    INT16U StrWidth;
    //INT8U Font,Type;
    StrWidth = Get_NoiseStr_Pix_Width(Prog_Status.File_Para[Area_No].Noise_Para.Noise_Type, \
                                     Prog_Status.File_Para[Area_No].Noise_Para.Noise_Font);


    return Prog_Status.File_Para[Area_No].Noise_Para.Text_Width + SPACE_WIDTH + StrWidth;

}

//显示定时信息的最小高度
INT16U Get_Noise_Min_Height(INT8U Area_No)
{
    INT16U StrHeight;
    //INT16U Height;

    StrHeight = Get_Font_Height(Prog_Status.File_Para[Area_No].Noise_Para.Noise_Font);

    if(Prog_Status.File_Para[Area_No].Noise_Para.Text_Height > StrHeight)
        return Prog_Status.File_Para[Area_No].Noise_Para.Text_Height;
    else
        return StrHeight;
}
//显示噪音
//pDst_Buf目标显示缓冲
//Area_No分区
//X、Y为显示坐标
//Noise为噪音，小数为1位
//
void Show_Noise(S_Show_Data *pDst_Buf, INT8U Area_No, INT16U X, INT16U Y, INT16U Noise, INT8U Type, INT8U Font, INT8U Color)
{
    char const *p;
    INT8U d; //i为整数部分，d为小数部分
    INT8U i;
    //INT16U uNoise;    
    if(Type >= S_NUM(NoiseStr0))
      return;
    
    p = NoiseStr0[Type].str;
    d = Noise % 10;
    i = Noise / 10;
    
    //if(Type EQ 0)
      //LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, p, i,d);
    //else
      LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, p, i);
}

//更新噪音数据
void Update_Noise_Data(S_Show_Data *pDst, INT8U Area_No)
{
    S_Point P0;
    INT16U Width,Height;
    INT16U Min_Width;//, Min_Height;
    INT16S Noise;

    Width = Get_Area_Width(Area_No);
    Height = Get_Area_Height(Area_No);

    Min_Width = Get_Noise_Min_Width(Area_No);
    //Min_Height = Get_Noise_Min_Height(Area_No);
 
    if(Width > Min_Width)
      P0.X = (Width - Min_Width) / 2;
    else
      P0.X = 0;
/*
    if(Height > Prog_Status.File_Para[Area_No].Noise_Para.Text_Height)
      P0.Y = (Height - Prog_Status.File_Para[Area_No].Noise_Para.Text_Height)/2;
    else
      P0.Y = 0;//(Height - Prog_Status.File_Para[Area_No].Noise_Para.Text_Height)/2;
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Status.File_Para[Area_No].Noise_Para.Text_Width, Prog_Status.File_Para[Area_No].Noise_Para.Text_Height, &Show_Data, &P0);//&Point);
*/

    P0.X = P0.X + Prog_Status.File_Para[Area_No].Noise_Para.Text_Width;
    if(P0.X > 0)
      P0.X += SPACE_WIDTH;//Get_Font_Width(Prog_Status.File_Para[Area_No].Noise_Para.);

    if(Height > Get_Font_Height(Prog_Status.File_Para[Area_No].Noise_Para.Noise_Font))
      P0.Y = (Height - Get_Font_Height(Prog_Status.File_Para[Area_No].Noise_Para.Noise_Font))/2;
    else
      P0.Y = 0;

    Noise = Get_Cur_Noise(); //--获取当前噪音
    Show_Noise(pDst, Area_No, P0.X, P0.Y, Noise, \
               Prog_Status.File_Para[Area_No].Noise_Para.Noise_Type, Prog_Status.File_Para[Area_No].Noise_Para.Noise_Font,Prog_Status.File_Para[Area_No].Noise_Para.Noise_Color);

      
    //Prog_Status.Area_Status[Area_No].Step = 100; //一步显示到位，直接100%
}
#endif
