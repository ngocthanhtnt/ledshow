#define SMS_SHOW_C
#include "Includes.h"

#if SMS_EN
void Read_SMS_File_Flag(void)
{
    INT16U Len;

    Len = Read_Storage_Data(SDI_SMS_FILE_FLAG, SMS_File_Flag.Flag, SMS_File_Flag.Flag, sizeof(SMS_File_Flag.Flag));
    if(Len EQ 0)
    {
#ifdef SDI_SMS_FILE_FLAG_BK0
        Len = Read_Storage_Data(SDI_SMS_FILE_FLAG_BK0, SMS_File_Flag.Flag, SMS_File_Flag.Flag, sizeof(SMS_File_Flag.Flag));
#endif
    }

    if(Len == 0)
    {
      memset(SMS_File_Flag.Flag, 0, sizeof(SMS_File_Flag.Flag));

      SMS_File_Flag.Flag[0] = 0x03; //测试用
    }

    SET_SUM(SMS_File_Flag);
    SET_HT(SMS_File_Flag);

    //读取有效号码
    Len = Read_Storage_Data(SDI_SMS_PHONE_NO, &SMS_Phone_No, &SMS_Phone_No, sizeof(SMS_Phone_No));
    if(Len EQ 0)
      memset(&SMS_Phone_No, 0, sizeof(SMS_Phone_No));

    SET_HT(SMS_Phone_No);
    SET_SUM(SMS_Phone_No);
}

void Write_SMS_File_Flag(void)
{
    Write_Storage_Data(SDI_SMS_FILE_FLAG, SMS_File_Flag.Flag, sizeof(SMS_File_Flag.Flag));

#ifdef SDI_SMS_FILE_FLAG_BK0
    Write_Storage_Data(SDI_SMS_FILE_FLAG_BK0, SMS_File_Flag.Flag, sizeof(SMS_File_Flag.Flag));
#endif
}

INT16U _Find_Next_SMS_File_No(void)
{
    INT16U i;
    INT16U Start_No;
    INT16U No = NULL_SMS_NO;

    if(SMS_Cur_No.No == NULL_SMS_NO)
        Start_No = 0;
    else
        Start_No = SMS_Cur_No.No + 1;

    for(i = Start_No; i < MAX_SMS_NUM; i ++)
    {
        if(Get_Buf_Bit(SMS_File_Flag.Flag, sizeof(SMS_File_Flag.Flag), i))
        {
          No = i;
          break;
        }
    }

    return No;
}

//从Cur_No下一个开始找可播放的短信节目
void Find_Next_SMS_File_No(void)
{
    INT16U No;

    No = _Find_Next_SMS_File_No();
    //if(No != NULL_SMS_NO)
    {
      SMS_Cur_No.No = No;
      SET_SUM(SMS_Cur_No);
    }
}

//重置当前sms文件编号为未播放状态
void Reset_Cur_SMS_File_No(void)
{
    SMS_Cur_No.No = NULL_SMS_NO;
    SET_HT(SMS_Cur_No);
    SET_SUM(SMS_Cur_No);
}

INT8U SMS_File_Play_End(void)
{
    //if(SMS_Cur_No.No EQ NULL_SMS_NO)
        //return 0;

    if(_Find_Next_SMS_File_No() EQ NULL_SMS_NO)
        return 1;
    else
        return 0;
}

/*
1，简化发送：
  格式：*#1A  nnn 内容
  *#1A :  固定存在
  nnn   :  代表信息ID，有效范围为000 – 999，长3位
  内容  :  要显示的内容，最长63个字符
//读取当前短信文件，转换为S_Txt_Para类型参数

2，普通发送：
格式：*#1B  nnn  I  J   K   L  内容
*#1B ：固定存在
nnn  ：信息ID
I     ： 追加总数，默认填0
J    ： 显示特技， 0 – 9  （参照附表）
K    ： 速度，0-9数字越大越慢
L    ：停留时间，0-9
内容 ： 要显示的内容，最长58个字符

例：*#1B0010821这里是第001条信息，特技=下雨，速度=2，停留时间=1

二，  格式详细说明
1，“*#1”：此为固定存在，每条合法的指令必须以这3个字母开头，否则被丢弃
2，“信息ID”  ：有效范围000-399，最多可存400条信息，播放时从小到大轮流播放
3，“追加总数”：0=不追加。1-2代表信息需要追加1或2次才完整。A/B 代表时间信息
4，“显示特技”  ：有效范围:  数字0-9，小写字母a-z，大写字母A-I，具体含义请参照
附表
5，“速度”  ：0-9-Z，数字越大越慢
6，“停留时间”  ：0-9-X，0-9 代表0-9 秒，A=10秒，B=15秒，C=20秒以此类推(字母从10秒开始，每个递增5秒)，最大为X。

三，  其他指令格式
删除一条信息：
*#1(固定3字) + GDEL(固定4字)  + 信息ID(3字)

删除全部信息：
*#1(固定3字) + HALL(固定4字)  + 999(固定3字)

校时：
*#1(固定3字) + ITIM(固定4字)  + 年月日时分秒星期（15字）
-- 如：201107181301385 代表2011年7月18日13时01分38秒星期五

屏参设置：
*#1(固定3字) + LSET(固定4字) + 屏宽点数(4字) + ‘x’(小写,固定存在) + 屏
高点数(3字) + ‘,’(固定存在) + 颜色类型(1字) + 数据极性(1字) + OE极
性(1字) + 扫描方式(2字) + 行顺序(1字)

扫描方式含义：00=16扫(室内常规)，41=4扫(P10单红常规)

例：*#1LSET0128x016,101410  设置为8字条屏(128点*16点)，P10单红扫描方式(4.1)，
数据极性=0，OE极性=1

  例：*#1LSET0128x016,200000 设置为8字条屏，室内16扫，数据和OE均为低

四，  指令返回
1， 本节内容仅规定了指令返回的格式，但是收到指令后，是否回复短信，取决于回显
等级。（注意：如果是用串口发送指令，则会一直返回，而忽略回显等级）
2， 如果收到无法识别的短信，则自动丢弃，不返回任何内容。
3， 指令返回内容代表的含义参见下表
返回内容  可能的原因
OK  指令执行成功

E002  无法识别，或不支持的指令
E004  指令参数错误，即指令格式完全正确，但是参数属于协议规定外的字符。
（如更新信息时，输入的ID 大于400）
E005  指令参数无法识别，如该出现数字的地方，出现字母等
E007  设置屏参时，宽度超出最大范围。
E008  设置屏参时，高度超出最大范围。
E009  设置屏参时，总点数超过控制卡所支持的最大点数。
E010  指令长度异常，如本来总长度应该是10个字符，却输入了9个或11个。
E110  追加信息时，顺序错误，或出现没有原始信息直接追加的情况。
*/
INT16U Read_Cur_SMS_File_Para(void *pDst, void *pDst_Start, INT16U DstLen)
{
  S_Txt_Para *pPara;
  INT8U subIndex, i, Num0 = 1, Num1;
  INT16U index;

  Find_Next_SMS_File_No();

  if(SMS_Cur_No.No EQ NULL_SMS_NO) //已经播放到最后一个了，再重头开始查找
  {
      Find_Next_SMS_File_No();
      if(SMS_Cur_No.No EQ NULL_SMS_NO)
        return 0;
  }
/*
  if(Read_Storage_Data(SDI_SMS_FILE_PARA + SMS_Cur_No.No, Pub_Buf, Pub_Buf, sizeof(Pub_Buf)))
  {

  }
  */
  pPara = (S_Txt_Para *)pDst;

  pPara->Flag = SHOW_TXT;
  pPara->Border_Check = 0;
  pPara->Color = 0x01;
  pPara->In_Mode = 0x06;
  pPara->In_Speed = 0x01;
  pPara->Stay_Time = 2;//10s
  pPara->Out_Mode = 0x07;
  pPara->Out_Speed = 0x01;
  pPara->SNum = 0x01;

  pPara->Font_Size = 0x00;
  pPara->Len = 0x05;


  if(SMS_Cur_No.No EQ 0)
  {

  pPara->SMS_Txt_Flag = TXT_SMS_NORMAL;
  }
  else if(SMS_Cur_No.No EQ 1)
  {
  pPara->SMS_Txt_Flag = TXT_SMS_BK_FILE;
  pPara->SMS_File_No = 0x00;
  }

  //memcpy(pDst, pDst + 1 ,sizeof(S_Txt_Para) - CHK_BYTE_LEN);

  strcpy((char *)SMS_Data.Data, (char *)"你好啊哈哈，很好啊，你个笨蛋");


  One_SMS_Proc((char *)"+P0002AB0901#ijk你是个大笨蛋，你有毛病吧，哈哈哈哈，大,国家");//, (S_Txt_Para *)pDst, (char *)SMS_Data.Data, &index, &subIndex);

  //------自适应字体大小---------
  if(((S_Txt_Para *)pDst)->SMS_Fix_Font_Flag EQ 0) //没有固定字体大小
  {
      for(i = 0; i < GET_FONT_NUM() - 1; i ++)
      {
        pPara->Font_Size = i; //16*16字体

        if(GET_HZ_FONT_WIDTH(i) <= Get_Area_Width(0) && GET_HZ_FONT_HEIGHT(i) <= Get_Area_Height(0))
        {
          Num0 = Read_Txt_Show_Data(&Show_Data, 0, pPara, SMS_Data.Data, sizeof(SMS_Data.Data), 0, RD_TXT_NODATA_FLAG, 0, 0);

          if(GET_HZ_FONT_WIDTH(i+1) <= Get_Area_Width(0) && GET_HZ_FONT_HEIGHT(i+1) <= Get_Area_Height(0))
          {
            pPara->Font_Size++;
            Num1 = Read_Txt_Show_Data(&Show_Data, 0, pPara, SMS_Data.Data, sizeof(SMS_Data.Data), 0, RD_TXT_NODATA_FLAG, 0, 0);
            if(Num0 < Num1) //两个字体屏幕数不一致
            {
              pPara->Font_Size--;
              break;
            }
          }
        }
       }

       pPara->SNum = Num0;

  }

  //pPara->Font_Size = 2;
  SET_SUM((*pPara));
  return sizeof(S_Txt_Para);
}

INT16U Str_2_Int(char *p, INT8U Len)
{
    INT8U i;
    INT16U re = 0;

    for(i = 0; i < Len; i ++)
    {
        re = re * 10;
        re += p[i] - '0';
    }

    return re;
}

INT8U Chk_Int_Str(char *p, INT8U Len)
{
    INT8U i;

    for(i = 0; i < Len; i ++)
    {
        if(!(p[i] >= '0' && p[i] <= '9'))
            return 0;
    }
    return 1;
}

//检查电话号码是否可接收
INT8U Chk_PH_No(char No[])
{
  INT8U i;
  INT8U num = 0;

  for(i = 0; i < S_NUM(SMS_Phone_No.No); i ++)
  {
    if(strlen(SMS_Phone_No.No[i]) != 0)
        num ++;

    if(strstr(No, SMS_Phone_No.No[i]) != '\0')
        break;
  }

  if(num EQ 0 || i < S_NUM(SMS_Phone_No.No))
      return 1;
  else
      return 0;

}

//处理一条短信数据
INT8U One_SMS_Proc(char *p)
{
  int index,temp,i;
  INT8U Rows,TxtOff;
  INT8U SubIndex;
  S_Scan_Para Scan_Para = {0};
  S_Screen_Base_Para Base_Para = {0};
  S_Time tempTime;
  INT16U scanMode;
  S_Txt_Para *pPara;


  pPara = (S_Txt_Para *)SMS_WR_Buf.Data;
  pPara->SMS_Fix_Font_Flag = 0;
  pPara->Color = Screen_Para.Base_Para.Color;

  if(p[0] EQ '+' || p[0] EQ '*') //'+'表示不需应答，'*'表示需要应答
  {
    if(p[1] EQ '#') //简单方式
      {
        if(Chk_Int_Str(&p[2], 3) EQ 0)
            return SMS_INDEX_ERR;

        index = Str_2_Int(&p[2], 3);

        if(index > MAX_SMS_NUM)
            return SMS_INDEX_ERR;

        //*pIndex = (INT16U)index;
        //*pSubIndex = 0;

        if(strlen(&p[5]) >= SMS_MAX_DATA_LEN)
            return SMS_LEN_ERR;

        pPara->In_Mode = 0x01;
        pPara->Out_Mode = 0x01;
        pPara->Play_Counts = 0x01;
        pPara->Stay_Time = 10;

        //strcpy(pUSC, &p[4]);
		memset(SMS_WR_Buf.Data, 0, sizeof(SMS_WR_Buf.Data));
		memcpy(SMS_WR_Buf.Data, pPara, sizeof(S_Txt_Para));
		
		
		mem_cpy(SMS_WR_Buf.Data + sizeof(S_Txt_Para), &p[5],strlen(&p[5]),\
		      SMS_WR_Buf.Data,sizeof(SMS_WR_Buf.Data));
		Write_Storage_Data(SDI_SMS_FILE_PARA + index, SMS_WR_Buf.Data, SMS_FILE_PARA_LEN);

		//修改并保存SMS_File_Flag
		Set_Buf_Bit(SMS_File_Flag.Flag, sizeof(SMS_File_Flag.Flag), index, 1);
		SET_SUM(SMS_File_Flag);
        Write_SMS_File_Flag();

		return SMS_NO_ERR;
      }
      else if(p[1] EQ 'P') //+T0002AB09
      {
          if(Chk_Int_Str(&p[2], 3) EQ 0) //序号错误
              return SMS_INDEX_ERR;

           index = Str_2_Int(&p[2], 3);

           if(index > MAX_SMS_NUM)
               return SMS_INDEX_ERR;

           //*pIndex = (INT16U)index;

           //---播放次数------------
           if(!(p[5] >= '0' && p[5] <= '2'))
               return SMS_PLAY_COUNTS_ERR;

           SubIndex = (p[5] - '0'); //追加次数
           //*pSubIndex = SubIndex;

           TxtOff = 11;

           if(SubIndex EQ 0) //==0的时候才更新节目参数
           {
               //----进入方式----
               if(!((p[6] >= '0' && p[6] <= '9') ||\
                    (p[6] >= 'A' && p[6] <= 'Z') ||\
                    (p[6] >= 'a' && p[6] <= 'z')))
                   return SMS_IN_MODE_ERR;

               if(p[6] >= '0' && p[6] <= '9')
                   temp = p[6] - '0';
               else if(p[6] >= 'A' && p[6] <= 'Z')
                   temp = 10 + p[6] - 'A';
               else
                   temp = 10 + 26 + p[6] - 'a';

               pPara->In_Mode = (INT8U)temp;

               //----退出方式----
               if(!((p[7] >= '0' && p[7] <= '9') ||\
                    (p[7] >= 'A' && p[7] <= 'Z') ||\
                    (p[7] >= 'a' && p[7] <= 'z')))
                   return SMS_OUT_MODE_ERR;

               if(p[7] >= '0' && p[7] <= '9')
                   temp = p[7] - '0';
               else if(p[7] >= 'A' && p[7] <= 'Z')
                   temp = 10 + p[7] - 'A';
               else
                   temp = 10 + 26 + p[7] - 'a';

               pPara->Out_Mode = (INT8U)temp;

               //---速度-----------
               if(!(p[8] >= '0' && p[8] <= '9'))
                 return SMS_SPEED_ERR;

               pPara->In_Speed = p[8] - '0';
               pPara->Out_Speed = p[8] - '0';

               //停留时间
               if(!(p[9] >= '0' && p[9] <= '9'))
                 return SMS_STAY_TIME_ERR;

               pPara->Stay_Time = p[9] - '0';

               if(p[10] != '#')
               {
                   //字体
                   if(!(p[10] >= '0' && p[10] <= '2'))
                     return SMS_FONT_ERR;

                   pPara->Font_Size = p[10] - '0';

                   //颜色
                   if(!(p[11] >= '0' && p[11] <= '3'))
                     return SMS_COLOR_ERR;

                   pPara->Color = p[11] - '0';
                   if(pPara->Color EQ 0)
                       pPara->Color = 1;

                   if((pPara->Color & Screen_Para.Base_Para.Color) EQ 0)
                       return SMS_COLOR_ERR;

                   if(p[12] != '#')
                       return SMS_TXTHEAD_ERR;

                   pPara->SMS_Fix_Font_Flag = 1;

                   TxtOff = 13;
               }
               else
                 TxtOff = 11;

               pPara->Play_Counts = 1;

               SET_SUM(*pPara);
          }
          else
           {
              if(p[10] != '#')
                  return SMS_TXTHEAD_ERR;

              TxtOff = 11;
          }

          if(strlen(&p[TxtOff]) >= SMS_MAX_DATA_LEN)
            return SMS_LEN_ERR;

          if(SubIndex EQ 0)
		  {
            memset(SMS_WR_Buf.Data, 0, sizeof(SMS_WR_Buf.Data));
		    memcpy(SMS_WR_Buf.Data, pPara, sizeof(S_Txt_Para));
		  }
		  else
		  {
		    if(Read_Storage_Data(SDI_SMS_FILE_PARA + index, SMS_WR_Buf.Data, SMS_WR_Buf.Data, sizeof(SMS_WR_Buf.Data)) > 0)
			  return SMS_STORA_ERR;
		  }
		  
	      mem_cpy(SMS_WR_Buf.Data + sizeof(S_Txt_Para) + SubIndex * SMS_SUB_DATA_LEN,&p[TxtOff],strlen(&p[TxtOff]),\
		          SMS_WR_Buf.Data,sizeof(SMS_WR_Buf.Data));
		  Write_Storage_Data(SDI_SMS_FILE_PARA + index, SMS_WR_Buf.Data, SMS_FILE_PARA_LEN);
 
	 	  //修改并保存SMS_File_Flag
		  Set_Buf_Bit(SMS_File_Flag.Flag, sizeof(SMS_File_Flag.Flag), index, 1);
		  SET_SUM(SMS_File_Flag);
	      Write_SMS_File_Flag();
		           
		  return SMS_NO_ERR;
      }
      else if(p[1] EQ 'T' && p[2] EQ 'I' && p[3] EQ 'M') //校时
      {
          if(Chk_Int_Str(&p[4], 15) EQ 0)
              return SMS_TIME_ERR;

          tempTime.Time[T_YEAR] = (INT8U)Str_2_Int(&p[4], 2); //年
          tempTime.Time[T_MONTH] = (INT8U)Str_2_Int(&p[6], 2);//月
          tempTime.Time[T_DATE] = (INT8U)Str_2_Int(&p[8], 2); //日
          tempTime.Time[T_HOUR] = (INT8U)Str_2_Int(&p[10], 2); //时
          tempTime.Time[T_MIN] = (INT8U)Str_2_Int(&p[12], 2); //分
          tempTime.Time[T_SEC] = (INT8U)Str_2_Int(&p[14], 2); //秒
          tempTime.Time[T_WEEK] = (INT8U)Str_2_Int(&p[16], 1); //星期

          SET_HT(tempTime);
          SET_SUM(tempTime);

          if(Chk_Time(&tempTime) EQ 0)
              return SMS_TIME_ERR;

          Set_Cur_Time(tempTime.Time);
          return SMS_NO_ERR;
      }
      else if(p[1] EQ 'S' && p[2] EQ 'C' && p[3] EQ 'N') //设置屏幕参数
      {
        //屏幕宽度
          if(Chk_Int_Str(&p[4], 4) EQ 0)
              return SMS_FORMAT_ERR;

           Base_Para.Width = Str_2_Int(&p[4], 4);

           if(p[8] EQ 'x' || p[8] EQ 'X')
             return SMS_FORMAT_ERR;

           //高度
           if(Chk_Int_Str(&p[9], 3) EQ 0)
             return SMS_FORMAT_ERR;

           Base_Para.Height = Str_2_Int(&p[9], 3); //高度

           if(p[12] != ',')
               return SMS_FORMAT_ERR;

           //颜色
           if(p[13] EQ '0' || p[13] EQ '1')
               Base_Para.Color = 0x01;
           else if(p[13] EQ '2')
               Base_Para.Color = 0x02;
           else if(p[12] EQ '3')
               Base_Para.Color = 0x03;
           else
               return SMS_COLOR_ERR;

           if(Check_Screen_Base_Para(&Base_Para) EQ 0)
             return SMS_SCN_BASE_ERR;

           //数据极性
           if(p[14] EQ 0)
               Scan_Para.Data_Polarity = 0x00;
           else if(p[14] EQ 1)
               Scan_Para.Data_Polarity = 0x01;
           else
               return SMS_SCN_DE_ERR;

           //OE极性
           if(p[15] EQ 0)
               Scan_Para.OE_Polarity = 0x00;
           else if(p[15] EQ 1)
               Scan_Para.OE_Polarity = 0x01;
           else
               return SMS_SCN_OE_ERR;

           //扫描方式
           if(Chk_Int_Str(&p[17], 4) > 0)
               scanMode = Str_2_Int(&p[17], 4);
		   else
		      return SMS_SCN_SCAN_ERR;

           Scan_Para.Direct = (scanMode%1000) / 100;
           Scan_Para.Cols_Fold = (scanMode %100) / 10;
           Scan_Para.Rows_Fold = (scanMode %10);
           Rows = (scanMode % 10000) / 1000;

           if(Rows EQ 0)
             Scan_Para.Rows = 16;
           else if(Rows EQ 1)
             Scan_Para.Rows = 8;
           else if(Rows EQ 2)
             Scan_Para.Rows = 4;
           else if(Rows EQ 3)
             Scan_Para.Rows = 2;
           else if(Rows EQ 4)
             Scan_Para.Rows = 1;
           else
             Scan_Para.Rows = 16;

           memcpy(&Screen_Para.Base_Para, &Base_Para, sizeof(Base_Para));
           //memcpy(&Screen_Para.Scan_Para, &Scan_Para, sizeof(Scan_Para));
		   Screen_Para.Scan_Para.Data_Polarity = Scan_Para.Data_Polarity;
		   Screen_Para.Scan_Para.OE_Polarity = Scan_Para.OE_Polarity;
		   Screen_Para.Scan_Para.Direct = Scan_Para.Direct;
           Screen_Para.Scan_Para.Cols_Fold = Scan_Para.Cols_Fold;
           Screen_Para.Scan_Para.Rows_Fold = Scan_Para.Rows_Fold;
		   Screen_Para.Scan_Para.Rows = Scan_Para.Rows;
           SET_SUM(Screen_Para);

           Write_Screen_Para();

           return SMS_NO_ERR;

      }
      else if(p[1] EQ 'P' && p[2] EQ 'N')//接收过滤短信号码
      {
          if(p[3] EQ 0) //清除所有号码
          {
              memset(SMS_Phone_No.No, 0, sizeof(SMS_Phone_No));
              SET_SUM(SMS_Phone_No);

              Write_Storage_Data(SDI_SMS_PHONE_NO, &SMS_Phone_No, sizeof(SMS_Phone_No));
          }
          else
          {
             if(strlen(&p[3]) >= sizeof(SMS_Phone_No.No[0]))
                 return SMS_FORMAT_ERR;

             //寻找一个空闲位置存储号码
             for(i = 0; i < (int)S_NUM(SMS_Phone_No.No); i ++)
             {
                 if(strlen(SMS_Phone_No.No[i]) EQ 0)
                 {
                     strcpy(SMS_Phone_No.No[i], &p[3]);
                     SET_SUM(SMS_Phone_No);

                     Write_Storage_Data(SDI_SMS_PHONE_NO, &SMS_Phone_No, sizeof(SMS_Phone_No));
                     break;
                 }
             }

             if(i EQ S_NUM(SMS_Phone_No.No))
                 return SMS_PN_FULL_ERR; //没有空闲位置了
          }

          return SMS_NO_ERR;
      }
      else if(p[1] EQ 'D' && p[2] EQ 'E' && p[3] EQ 'L') //删除短信
      {
          if(p[4] EQ '9' && p[5] EQ '9' && p[6] EQ '9') //删除所有短信
          {
              memset(SMS_File_Flag.Flag, 0, sizeof(SMS_File_Flag.Flag));
              SET_SUM(SMS_File_Flag);

              Write_SMS_File_Flag();
              return SMS_NO_ERR;
          }
          else if(Chk_Int_Str(&p[4], 3))
          {
              index = Str_2_Int(&p[4], 3);
              if(index > MAX_SMS_NUM)
                  return SMS_INDEX_ERR;

              Set_Buf_Bit(SMS_File_Flag.Flag, sizeof(SMS_File_Flag.Flag), index, 0);
              SET_SUM(SMS_File_Flag);

              Write_SMS_File_Flag();
              return SMS_NO_ERR;
         }
         else
             return SMS_FORMAT_ERR;
      }
      
	  return SMS_FORMAT_ERR;
  }
  else
    return SMS_UNAVAIL_ERR;


}

#if QT_EN == 0
//收到消息处理
void smsMessageProc(SM_PARAM* pMsg, INT8U Num)
{
  INT8U i;
  INT8U re;

  for(i = 0; i < 1; i ++)
  {
    re = One_SMS_Proc(pMsg[i].TP_UD);
	
	if(pMsg[i].TP_UD[0] EQ '*') //需要应答
	{
	   if(re EQ SMS_NO_ERR)
	   	 strcpy(SMS_WR_Buf.Data, "OK");//"OK,设置成功,原始信息:"); 											   
	   else
	   	 sprintf(SMS_WR_Buf.Data, "ERR %d", re);//"Err %d,设置失败,原始信息:", re);

	   //strcpy(SMS_WR_Buf.Data, "你好");//"OK,设置成功,原始信息:");
	   /*
	   mem_cpy(SMS_WR_Buf.Data + strlen(SMS_WR_Buf.Data), pMsg[i].TP_UD, sizeof(pMsg[i].TP_UD),\
	           SMS_WR_Buf.Data, sizeof(SMS_WR_Buf.Data));
	*/		  
	   mem_cpy(pMsg[i].TP_UD, SMS_WR_Buf.Data, sizeof(pMsg[i].TP_UD),\
	           pMsg[i].TP_UD, sizeof(pMsg[i].TP_UD)); 
	   
	   gsmSendMessage(&(pMsg[i]));
	}
  }

}
#endif
#endif

