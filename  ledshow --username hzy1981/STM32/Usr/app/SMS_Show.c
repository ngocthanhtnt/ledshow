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

  pPara->Txt_Flag = TXT_SMS_NORMAL;
  }
  else if(SMS_Cur_No.No EQ 1)
  {
  pPara->Txt_Flag = TXT_SMS_BK_FILE;
  pPara->File_No = 0x00;
  }

  //memcpy(pDst, pDst + 1 ,sizeof(S_Txt_Para) - CHK_BYTE_LEN);

  strcpy((char *)SMS_Data.Data, (char *)"你好啊哈哈，很好啊，你个笨蛋");

  return sizeof(S_Txt_Para);
  //pPara->
}

#endif

