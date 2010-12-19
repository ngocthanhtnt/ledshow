#define TIME_SHOW_C
#include "Includes.h"


const char WeekStr[][7][15] =
{
{"星期日","星期一","星期二","星期三","星期四","星期五","星期六"},

//const char WeekStr1[][10] =
{"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday", "Saturday"},

//const char WeekStr2[][6] =
{ "Sun","Mon","Tues","Wed","Thur","Fri","Sat"},

//const char WeekStr3[][12] =
{"domenica","lunedi\’","martedi\’","mercoledi\’","giovedi\’","venerdi\’","sabato"},

//const char WeekStr4[][12] =
{"Sonntag","Montag","Dienstag","Mittwoch","Donnerstag","Freitag","Samstag"}, //德文

//const char WeekStr5[][10] =
{"dimanche","lundi","mardi","mercredi","jeudi", "vendredi","samedi"},//法文

//const char WeekStr6[][12] =
{"にちようび","げつようび","かようび","すいようび","もくようび","きんようび","どようび"}
};

const S_Format_Str DateStr[]=
{
    {"%4d年%2d月%2d日", 14}, //0-14
    {"%2d年%2d月%2d日", 12}, //1-12
    {"%2d/%2d/%4d",10},    //2-9
    {"%4d/%2d/%2d",10},    //3-9
    {"%2d-%2d-%2d",8},    //4
    {"%2d.%2d.%2d",8},    //5
    {"%2d月%2d日",8},      //6
    {"%2d.%2d.%4d", 10},   //7
    {"%4d-%2d-%2d", 10},   //8
    {"%4d", 4},            //9
    {"%2d", 2},           //10
    {"%2d",2}             //11
};

const S_Format_Str TimeStr[] =
{
    {"%2d时%2d分%2d秒", 12}, //0
    {"%2d:%2d:%2d",8},    //1
    {"%2d时%2d分", 8},      //2
    {"%2d:%2d",5},        //3
    {"%2d时",4},           //4
    {"%2d分",4},          //5
    {"%2d秒",4},          //6
    {"上午 %2d:%2d",10},    //7
    {"AM %2d:%2d", 8},    //8
    {"%2d:%2d 上午",10},    //9
    {"%2d:%2d AM",8}      //10
};

//显示日期
void Show_Date(S_Show_Data *pDst_Buf, INT8U Area_No, INT16U X, INT16U Y, S_Time *pTime, INT8U Type, INT8U Font, INT8U Color)
{
  INT16U y,m,d;

  y = pTime->Time[T_YEAR];
  m = pTime->Time[T_MONTH];
  d = pTime->Time[T_DATE];

  if(Type EQ 0)
    LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, DateStr[Type].str, y + 2000, m, d);
  else if(Type EQ 1)
    LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, DateStr[Type].str, y, m, d);
  else if(Type EQ 2)
    LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, DateStr[Type].str, m, d, y + 2000);
  else if(Type EQ 3)
    LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, DateStr[Type].str, y + 2000, m, d);
  else if(Type EQ 4)
    LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, DateStr[Type].str, y, m, d);
  else if(Type EQ 5)
    LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, DateStr[Type].str, y, m, d);
  else if(Type EQ 6)
    LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, DateStr[Type].str, m, d);
  else if(Type EQ 7)
    LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, DateStr[Type].str, m, d, y + 2000);
  else if(Type EQ 8)
    LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, DateStr[Type].str, y + 2000, m, d);
  else if(Type EQ 9)
    LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, DateStr[Type].str, y + 2000);
  else if(Type EQ 10)
    LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, DateStr[Type].str, m);
  else if(Type EQ 11)
    LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, DateStr[Type].str, d);
}

//获取日期显示的像素宽度
INT16U Get_DateStr_Pix_Width(INT8U Type, INT8U Font)
{
  return DateStr[Type].Len*Get_Font_Width(Font);
}

//获取星期显示的像素宽度
INT16U Get_WeekStr_Pix_Width(INT8U Type, INT8U Font, INT8U Week)
{
  return strlen(WeekStr[Type][Week])*Get_Font_Width(Font);
}

//获取时间显示的像素宽度
INT16U Get_TimeStr_Pix_Width(INT8U Type, INT8U Font)
{
  return TimeStr[Type].Len*Get_Font_Width(Font);

}

//获取某个语言的星期字符串的最大像素宽度
INT16U Get_WeekStr_Type_Max_Pix_Width(INT8U Type, INT8U Font)
{
    INT16U max = 0;

    for(int i=0; i < 7; i ++)
    {
      if(strlen(WeekStr[Type][i]) > max)
          max = strlen(WeekStr[Type][i]);
    }

    return max*Get_Font_Width(Font);
}

/*
    timeCombo->addItem(tr("12时59分59秒"));
    timeCombo->addItem(tr("12:59:59"));
    timeCombo->addItem(tr("12时59分"));
    timeCombo->addItem(tr("12:59"));
    timeCombo->addItem(tr("12时"));
    timeCombo->addItem(tr("59分"));
    timeCombo->addItem(tr("59秒"));
    timeCombo->addItem(tr("上午 8:59"));
    timeCombo->addItem(tr("AM 8:59"));
    timeCombo->addItem(tr("8:59 上午"));
    timeCombo->addItem(tr("8:59 AM"));
 */
void Show_Time(S_Show_Data *pDst_Buf, INT8U Area_No, INT16U X, INT16U Y, S_Time *pTime, INT8U Type, INT8U Font, INT8U Color)
{
    INT16U h,m,s;

    h = pTime->Time[T_HOUR];
    m = pTime->Time[T_MIN];
    s = pTime->Time[T_SEC];

    if(Type EQ 0)
      LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, TimeStr[Type].str, h, m, s);
    else if(Type EQ 1)
      LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, TimeStr[Type].str, h, m, s);
    else if(Type EQ 2)
      LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, TimeStr[Type].str, h, m);
    else if(Type EQ 3)
      LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, TimeStr[Type].str, h, m);
    else if(Type EQ 4)
      LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, TimeStr[Type].str, h);
    else if(Type EQ 5)
      LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, TimeStr[Type].str, m);
    else if(Type EQ 6)
      LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, TimeStr[Type].str, s);
    else if(Type EQ 7)
      LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, TimeStr[Type].str, h, m);
    else if(Type EQ 8)
      LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, TimeStr[Type].str, h, m);
    else if(Type EQ 9)
      LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, TimeStr[Type].str, h, m);
    else if(Type EQ 10)
      LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, TimeStr[Type].str, h, m);

}

//显示星期的字符串
void Show_Week(S_Show_Data *pDst_Buf, INT8U Area_No, INT16U X, INT16U Y, S_Time *pTime, INT8U Language, INT8U Font, INT8U Color)
{
    INT8U Week;

    Week = pTime->Time[T_WEEK];
    LED_Print(Font, Color, pDst_Buf, Area_No, X, Y, "%s", WeekStr[Language][Week]);
}

//获取时间显示的最小宽度,分区需要有该宽度才能显示完横向上的所有数据
//Area_No为分区号
INT16U Get_Time_Min_Width(INT8U Area_No)
{
    INT16U Width = 0, Width0 = 0;
    INT8U i = 0;

    if(Prog_Status.File_Para[Area_No].Time_Para.SmLineFlag == SLINE_MODE)//单行
    {
        if(Prog_Status.File_Para[Area_No].Time_Para.Text_Width > 0)
        {
            Width = Prog_Status.File_Para[Area_No].Time_Para.Text_Width;
            i ++;
        }

        if(Prog_Status.File_Para[Area_No].Time_Para.Date_Type > 0)
        {
            Width += Get_DateStr_Pix_Width(Prog_Status.File_Para[Area_No].Time_Para.Date_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Date_Font);
            i++;
        }

        if(Prog_Status.File_Para[Area_No].Time_Para.Week_Type > 0)
        {
            Width +=Get_WeekStr_Type_Max_Pix_Width(Prog_Status.File_Para[Area_No].Time_Para.Week_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Week_Font);
            i++;
        }

        if(Prog_Status.File_Para[Area_No].Time_Para.Time_Type > 0)
        {
            Width +=Get_TimeStr_Pix_Width(Prog_Status.File_Para[Area_No].Time_Para.Time_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Time_Font);
            i++;
        }

        if(i>0)
            Width += (i- 1)*SPACE_WIDTH;
    }
    else
    {

        Width = Prog_Status.File_Para[Area_No].Time_Para.Text_Width;

        if(Prog_Status.File_Para[Area_No].Time_Para.Date_Type > 0)
        {
            Width0 = Get_DateStr_Pix_Width(Prog_Status.File_Para[Area_No].Time_Para.Date_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Date_Font);
            Width = MAX_2(Width, Width0);
        }

        if(Prog_Status.File_Para[Area_No].Time_Para.Week_Type > 0)
        {
            Width0 = Get_WeekStr_Type_Max_Pix_Width(Prog_Status.File_Para[Area_No].Time_Para.Week_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Week_Font);
            Width = MAX_2(Width, Width0);
        }

        if(Prog_Status.File_Para[Area_No].Time_Para.Time_Type > 0)
        {
            Width0 = Get_TimeStr_Pix_Width(Prog_Status.File_Para[Area_No].Time_Para.Time_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Time_Font);
            Width = MAX_2(Width, Width0);

        }

    }

    return Width;
}

//获取时间显示的最小高度,需要该高度才能显示纵向显示完所有的时间数据
//Area_No为分区号
INT16U Get_Time_Min_Height(INT8U Area_No)
{
    INT16U Height,Height0;

    if(Prog_Status.File_Para[Area_No].Time_Para.SmLineFlag == SLINE_MODE)//单行
    {
        Height = Prog_Status.File_Para[Area_No].Time_Para.Text_Height;

        if(Prog_Status.File_Para[Area_No].Time_Para.Date_Type > 0)
        {
            Height0 = Get_Font_Height(Prog_Status.File_Para[Area_No].Time_Para.Date_Font);
            Height = MAX_2(Height, Height0);
        }

        if(Prog_Status.File_Para[Area_No].Time_Para.Week_Type > 0)
        {
            Height0 = Get_Font_Height(Prog_Status.File_Para[Area_No].Time_Para.Week_Font);
            Height = MAX_2(Height, Height0);
        }

        if(Prog_Status.File_Para[Area_No].Time_Para.Time_Type > 0)
        {
            Height0 = Get_Font_Height(Prog_Status.File_Para[Area_No].Time_Para.Time_Font);
            Height = MAX_2(Height, Height0);
        }
    }
    else
    {
        Height = Prog_Status.File_Para[Area_No].Time_Para.Text_Height;

        if(Prog_Status.File_Para[Area_No].Time_Para.Date_Type > 0)
            Height += Get_Font_Height(Prog_Status.File_Para[Area_No].Time_Para.Date_Font);

        if(Prog_Status.File_Para[Area_No].Time_Para.Week_Type > 0)
            Height += Get_Font_Height(Prog_Status.File_Para[Area_No].Time_Para.Week_Font);

        if(Prog_Status.File_Para[Area_No].Time_Para.Time_Type > 0)
            Height += Get_Font_Height(Prog_Status.File_Para[Area_No].Time_Para.Time_Font);
    }

    return Height;
}

//更新时间数据
void Update_Time_Data(INT8U Area_No)
{
  INT16U X, Y;
  S_Point P0;
  INT16U Width,Height;
  INT16U Min_Width, Min_Height;

  Width = Get_Area_Width(Area_No);
  Height = Get_Area_Height(Area_No);

  Min_Width = Get_Time_Min_Width(Area_No);
  Min_Height = Get_Time_Min_Height(Area_No);

  if(Prog_Status.File_Para[Area_No].Time_Para.SmLineFlag == SLINE_MODE)//单行
  {
    if(Width > Min_Width)
    {
      P0.X = (Width - Min_Width) / 2;
    }
    else
    {
      P0.X = 0;
    }

    if(Height > Prog_Status.File_Para[Area_No].Time_Para.Text_Height)
      P0.Y = (Height - Prog_Status.File_Para[Area_No].Time_Para.Text_Height)/2;
    else
      P0.Y = 0;//(Height - Prog_Status.File_Para[Area_No].Time_Para.Text_Height)/2;
    Copy_Filled_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Status.File_Para[Area_No].Time_Para.Text_Width, Prog_Status.File_Para[Area_No].Time_Para.Text_Height, &Show_Data, &P0);//&Point);

    X = P0.X + Prog_Status.File_Para[Area_No].Time_Para.Text_Width;
    if(X > 0)
      X += SPACE_WIDTH;//Get_Font_Width(Prog_Status.File_Para[Area_No].Time_Para.);
    else
      X = 0;


    if(Prog_Status.File_Para[Area_No].Time_Para.Date_Type > 0)//需要显示日期?
    {
        P0.X = X;
        if(Height > Get_Font_Height(Prog_Status.File_Para[Area_No].Time_Para.Date_Font))
          P0.Y = (Height - Get_Font_Height(Prog_Status.File_Para[Area_No].Time_Para.Date_Font))/2;
        else
          P0.Y = 0;

        Show_Date(&Show_Data, Area_No, P0.X, P0.Y, &Cur_Time, \
                  Prog_Status.File_Para[Area_No].Time_Para.Date_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Date_Font, Prog_Status.File_Para[Area_No].Time_Para.Date_Color);

        X +=  SPACE_WIDTH + Get_DateStr_Pix_Width(Prog_Status.File_Para[Area_No].Time_Para.Date_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Date_Font);
    }

    if(Prog_Status.File_Para[Area_No].Time_Para.Week_Type > 0)//需要星期?
    {
        P0.X = X;
        if(Height > Get_Font_Height(Prog_Status.File_Para[Area_No].Time_Para.Week_Font))
          P0.Y = (Height - Get_Font_Height(Prog_Status.File_Para[Area_No].Time_Para.Week_Font))/2;
        else
          P0.Y = 0;

        Show_Week(&Show_Data, Area_No, P0.X, P0.Y, &Cur_Time, \
                  Prog_Status.File_Para[Area_No].Time_Para.Week_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Week_Font, Prog_Status.File_Para[Area_No].Time_Para.Week_Color);

        X += SPACE_WIDTH + Get_WeekStr_Type_Max_Pix_Width(Prog_Status.File_Para[Area_No].Time_Para.Week_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Week_Font);
    }

    if(Prog_Status.File_Para[Area_No].Time_Para.Time_Type > 0)//需要时间?
    {
        P0.X = X;
        if(Height > Get_Font_Height(Prog_Status.File_Para[Area_No].Time_Para.Time_Font))
          P0.Y = (Height - Get_Font_Height(Prog_Status.File_Para[Area_No].Time_Para.Time_Font))/2;
        else
          P0.Y = 0;

        Show_Time(&Show_Data, Area_No, P0.X, P0.Y, &Cur_Time, \
                  Prog_Status.File_Para[Area_No].Time_Para.Time_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Time_Font, Prog_Status.File_Para[Area_No].Time_Para.Time_Color);

        X += SPACE_WIDTH + Get_TimeStr_Pix_Width(Prog_Status.File_Para[Area_No].Time_Para.Time_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Time_Font);
    }
  }
  else //多行
  {
      if(Height > Min_Height)
      {
        P0.Y = (Height - Min_Height) / 2;
      }
      else
      {
        P0.Y = 0;
      }

      if(Width > Prog_Status.File_Para[Area_No].Time_Para.Text_Width)
        P0.X = (Width - Prog_Status.File_Para[Area_No].Time_Para.Text_Width)/2;
      else
        P0.X = 0;//(Height - Prog_Status.File_Para[Area_No].Time_Para.Text_Height)/2;
      Copy_Filled_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Status.File_Para[Area_No].Time_Para.Text_Width, Prog_Status.File_Para[Area_No].Time_Para.Text_Height, &Show_Data, &P0);//&Point);

      Y = P0.Y + Prog_Status.File_Para[Area_No].Time_Para.Text_Height;

      if(Prog_Status.File_Para[Area_No].Time_Para.Date_Type > 0)//需要显示日期?
      {
          P0.Y = Y;
          if(Width > Get_DateStr_Pix_Width(Prog_Status.File_Para[Area_No].Time_Para.Date_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Date_Font))
            P0.X = (Width - Get_DateStr_Pix_Width(Prog_Status.File_Para[Area_No].Time_Para.Date_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Date_Font))/2;
          else
            P0.X = 0;

          Show_Date(&Show_Data, Area_No, P0.X, P0.Y, &Cur_Time, \
                    Prog_Status.File_Para[Area_No].Time_Para.Date_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Date_Font, Prog_Status.File_Para[Area_No].Time_Para.Date_Color);

          Y += Get_Font_Height(Prog_Status.File_Para[Area_No].Time_Para.Date_Font);//Get_DateStr_Pix_Width(Prog_Status.File_Para[Area_No].Time_Para.Date_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Date_Font);
      }

      if(Prog_Status.File_Para[Area_No].Time_Para.Week_Type > 0)//需要星期?
      {
          P0.Y = Y;
          if(Width > Get_WeekStr_Pix_Width(Prog_Status.File_Para[Area_No].Time_Para.Week_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Week_Font, Cur_Time.Time[T_WEEK]))
            P0.X = (Width - Get_WeekStr_Pix_Width(Prog_Status.File_Para[Area_No].Time_Para.Week_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Week_Font, Cur_Time.Time[T_WEEK]))/2;
          else
            P0.X = 0;

          Show_Week(&Show_Data, Area_No, P0.X, P0.Y, &Cur_Time, \
                    Prog_Status.File_Para[Area_No].Time_Para.Week_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Week_Font, Prog_Status.File_Para[Area_No].Time_Para.Week_Color);

          Y += Get_Font_Height(Prog_Status.File_Para[Area_No].Time_Para.Week_Font);//SPACE_WIDTH + Get_WeekStr_Type_Max_Pix_Width(Prog_Status.File_Para[Area_No].Time_Para.Week_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Week_Font);
      }

      if(Prog_Status.File_Para[Area_No].Time_Para.Time_Type > 0)//需要时间?
      {
          P0.Y = Y;
          if(Width > Get_TimeStr_Pix_Width(Prog_Status.File_Para[Area_No].Time_Para.Time_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Time_Font))
            P0.X = (Width - Get_TimeStr_Pix_Width(Prog_Status.File_Para[Area_No].Time_Para.Time_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Time_Font))/2;
          else
            P0.X = 0;

          Show_Time(&Show_Data, Area_No, P0.X, P0.Y, &Cur_Time, \
                    Prog_Status.File_Para[Area_No].Time_Para.Time_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Time_Font, Prog_Status.File_Para[Area_No].Time_Para.Time_Color);

          //X += SPACE_WIDTH + Get_TimeStr_Pix_Width(Prog_Status.File_Para[Area_No].Time_Para.Time_Type - 1, Prog_Status.File_Para[Area_No].Time_Para.Time_Font);
      }
  }
}
