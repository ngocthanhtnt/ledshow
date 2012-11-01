#include "Includes.h"
#if TXT_SHOW_EN

#define CHK_ASC(X) ((X>0xA0)?0:1)


typedef struct
{
    INT8U Head;
    INT8U Chr[2]; //读取的字符
    INT8U Data[64*64 / 8];
    INT8U Tail;
}S_Font_Data;

S_Font_Data Font_Data;
/*
0x0D（asc码是13） 指的是“回车”   \r是把光标置于本行行首

0x0A（asc码是10） 指的是“换行”    \n是把光标置于下一行的同一列

0x0D + 0x0A        回车换行          \r\n把光标置于下一行行首
*/
//画一个字符
//pDst目标缓冲区
//Area_No表示分区号
//X,Y表示位置
//CharOff表示显示某个字符的起始位置偏移，从左到右数
//Data表示需要显示的数据
//pointFlag表示是否只读取某点,0表示读取整屏,>0表示读取某点
void Draw_Txt_Chr(S_Show_Data *pDst, INT8U Area_No, INT16U X, INT16U Y, INT8U Color, INT8U CharOff, INT8U FontSize, INT8U Data[],\
                  INT8U pointFlag, INT16U X0, INT16U Y0)
{
    //每个汉字，占两个字节, 取其区位号
    INT8U FontWidth,FontHeight,i,j,Re,RD_Flag = 0;
    INT32U offset, len, Width;
    FILE *file;

    if(CHK_ASC(Data[0]) EQ 0) //中文
    {
      FontWidth = GET_HZ_FONT_WIDTH(FontSize);
      FontHeight = GET_HZ_FONT_HEIGHT(FontSize);
      len = GET_HZ_FONT_BYTES(FontSize);
      offset = (94*(Data[0] - 0xa0 -1)+(Data[1] - 0xa0 -1)) * len; //得到偏移位置

      //前一个读取的字符和当前一致则不需要读取了
      if(Font_Data.Chr[0] != Data[0] || Font_Data.Chr[1] != Data[1])
      {
        Font_Data.Chr[0] = Data[0];
        Font_Data.Chr[1] = Data[1];
        RD_Flag = 1;
      }
    }
    else //英文
    {
      FontWidth = GET_ASC_FONT_WIDTH(FontSize);
      FontHeight = GET_ASC_FONT_HEIGHT(FontSize);
      len = GET_ASC_FONT_BYTES(FontSize);
      offset = Data[0] * len;

      if(Font_Data.Chr[0] != Data[0])
      {
        Font_Data.Chr[0] = Data[0];
        //Font_Data.Chr[1] = 0;
        RD_Flag = 1;
      }
    }

    if(pointFlag)//读取某点数据
    {
      if(!(X0 >= X && X0 <X + FontWidth - CharOff &&
         Y0 >= Y && Y0 <Y + FontHeight))
          return;
    }

    Width = len * 8 / FontHeight ; //字库占用的宽度，并不是字体的宽度

    if(RD_Flag)
    {
        file = getFontFile(FontSize, (CHK_ASC(Data[0]))?0:1);
        fseek(file, offset, SEEK_SET);
        fread(Font_Data.Data, len , 1, file); //读取数据长度
    }

    //复制字体到显示缓冲区
    if(pointFlag)
    {
        for(i = CharOff; i < FontWidth; i ++)
          for(j = 0; j < FontHeight; j ++)
          {
            if(X + i - CharOff == X0 && Y + j == Y0)
            {
                Re = Get_Rect_Buf_Bit(Font_Data.Data, len, Width, ((i >>3) << 3) + (7 - (i % 8)), j);
                if(Re)
                  Set_Area_Point_Data(pDst, Area_No, X + i - CharOff, Y + j, Color);
            }
        }
     }
    else
    {
        for(i = CharOff; i < FontWidth; i ++)
          for(j = 0; j < FontHeight; j ++)
          {
            Re = Get_Rect_Buf_Bit(Font_Data.Data, len, Width, ((i >>3) << 3) + (7 - (i % 8)), j);
            if(Re)
              Set_Area_Point_Data(pDst, Area_No, X + i - CharOff, Y + j, Color);
          }
    }
}

//计算Txt出现的幕数
//Data字符串
//FontSize,字体大小
INT16U Calc_Txt_SNum(INT16U Area_Width, INT16U Area_Height, INT8U Data[], INT16U Data_Len, INT8U FontSize, INT8U Flag)
{
    //INT16U Area_Width, Area_Height;
    INT16U Width = 0, LineNo = 0, ScnNo = 0, i = 0, CharWidth,LineNum;
    INT8U CharOff = 0; //字符内偏移

    //Area_Width = Get_Area_Width(Area_No);
    //Area_Height = Get_Area_Height(Area_No);

    LineNum = Area_Height / FontSize;

    while(i < Data_Len && Data[i] != 0)
    {
       if(CHK_ASC(Data[i]) EQ 0)//中文
         CharWidth = FontSize;
       else//英文
       {
         CharWidth = 0;

         if(Data[i] EQ '\r')
         {
             Width = 0;
             i++;
             continue;
         }
         else if(Data[i] EQ '\n')
         {
             Width = 0;
             LineNo ++;

             if(LineNo >= LineNum)
             {
                 LineNo = 0;
                 ScnNo++;
             }

             i++;
             continue;
         }
         else
           CharWidth = FontSize / 2;

       }

       //判断是否需要换行和换屏
       if(Width + CharWidth > Area_Width)
       {
           if(LineNum > 1 || Flag > 0) //多行或者自动排版标志>0都需要自动排版
           {
             CharOff = 0;//Width + CharWidth - Area_Width;
             LineNo ++;
           }
           else //单行而且不需要自动排版
           {
             CharOff = Width + CharWidth - Area_Width;
             LineNo ++;

             //if(ScnNo EQ SCN_No) //当前字符在当前字幕
               //Draw_Txt_Chr(pDst, Area_No, Width, LineNo * FontSize, Color, 0, FontSize, &Data[i]); //显示字符左半边
           }

           Width = 0;

           if(LineNo >= LineNum)
           {
               LineNo = 0;
               ScnNo++;
           }
       }

       Width += (CharWidth > CharOff)? (CharWidth - CharOff):0;
       CharOff = 0;

       if(CHK_ASC(Data[i]) EQ 0)//中文
         i += 2;
       else//英文
         i ++;

    }

    return ScnNo + 1;

}

//读取Txt显示数据
//Area_No分区号
//data需要显示的字符串
//dataLen表示缓冲区长度
//FontSize字体大小
//SCN_No屏幕编号
//Flag表示，0表示自动换行切换，1表示不自动换行（左连移等需要）
//pointFlag表示是否只读取某点,0表示读取整屏,>0表示读取某点
INT16U Read_Txt_Show_Data(S_Show_Data *pDst, INT8U Area_No, U_File_Para *pPara, INT8U Data[], INT16U Data_Len, INT8U SCN_No,\
                          INT8U pointFlag, INT16U X, INT16U Y)
{
  INT8U FontHeight,Color,Flag;
  INT16U Area_Width, Area_Height,LineSpace = 0;
  INT16U Width = 0, LineNo = 0, ScnNo = 0, i = 0, CharWidth,LineNum;
  INT8U CharOff = 0; //字符内偏移

  Area_Width = Get_Area_Width(Area_No);
  Area_Height = Get_Area_Height(Area_No);

  FontHeight = GET_HZ_FONT_HEIGHT(pPara->Txt_Para.Font_Size);
  Color = pPara->Txt_Para.Color;
  Flag = (Prog_Status.File_Para[Area_No].Pic_Para.In_Mode EQ 1)?1:0; //连续左移需要

  LineNum = Area_Height / FontHeight;
  LineSpace = (Area_Height - LineNum * FontHeight) / (LineNum + 1);

  while(i < Data_Len && Data[i] != 0)
  {
     if(CHK_ASC(Data[i]) EQ 0)//中文
       CharWidth = GET_HZ_FONT_WIDTH(pPara->Txt_Para.Font_Size);//FontSize;
     else//英文
     {
       CharWidth = 0;

       if(Data[i] EQ '\r')
       {
           Width = 0;
           i++;
           continue;
       }
       else if(Data[i] EQ '\n')
       {
           Width = 0;
           LineNo ++;

           if(LineNo >= LineNum)
           {
               LineNo = 0;
               ScnNo++;
           }

           i++;
           continue;
       }
       else
         CharWidth = GET_ASC_FONT_WIDTH(pPara->Txt_Para.Font_Size);;

     }

     //判断是否需要换行和换屏
     if(Width + CharWidth > Area_Width)
     {
         if(LineNum > 1 || Flag > 0) //多行或者自动排版标志>0都需要自动排版
         {
           CharOff = 0;//Width + CharWidth - Area_Width;
           LineNo ++;
         }
         else //单行而且不需要自动排版
         {
           CharOff = Width + CharWidth - Area_Width;

           if(ScnNo EQ SCN_No) //当前字符在当前字幕
             Draw_Txt_Chr(pDst, Area_No, Width, LineNo * FontHeight + (LineNo + 1) * LineSpace, Color, 0, pPara->Txt_Para.Font_Size, &Data[i], \
                          pointFlag, X, Y); //显示字符左半边

           LineNo ++;
         }

         Width = 0;

         if(LineNo >= LineNum)
         {
             LineNo = 0;
             ScnNo++;
         }
     }


     if(ScnNo EQ SCN_No) //当前字符在当前字幕
     {
       Draw_Txt_Chr(pDst, Area_No, Width, LineNo * FontHeight + (LineNo + 1) * LineSpace, Color, CharOff, pPara->Txt_Para.Font_Size, &Data[i],\
                    pointFlag, X, Y); //显示字符左半边
     }

     Width += (CharWidth > CharOff)? (CharWidth - CharOff):0;
     CharOff = 0;

     if(CHK_ASC(Data[i]) EQ 0)//中文
       i += 2;
     else//英文
       i ++;

  }

  //设置屏幕数
  if(pPara->Txt_Para.SNum != ScnNo + 1)
  {
    pPara->Txt_Para.SNum = ScnNo + 1;
    SET_SUM((pPara->Txt_Para));
  }

  return ScnNo + 1;
}
#endif

