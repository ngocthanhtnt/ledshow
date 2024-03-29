#ifndef SMS_SHOW_H
#define SMS_SHOW_H

#include "Includes.h"

#undef EXT
#ifdef SMS_SHOW_C
#define EXT
#else
#define EXT extern
#endif

#define SMS_NO_ERR          0x00
#define SMS_INDEX_ERR       0x01 //短信索引号错误
#define SMS_LEN_ERR         0x02 //短信长度错误
#define SMS_STORA_ERR       0x03 //追加索引错误
#define SMS_SUB_INDEX_ERR   0x04 //播放次数错误
#define SMS_IN_MODE_ERR     0x05 //进入特效错误
#define SMS_OUT_MODE_ERR    0x06 //退出特效错误
#define SMS_SPEED_ERR       0x07 //速度错误
#define SMS_STAY_TIME_ERR   0x08 //停留时间错误
#define SMS_FORMAT_ERR      0x09//短信格式错误
#define SMS_TIME_ERR        0x0A //时间格式错误
#define SMS_FONT_ERR        0x0B //字体错误
#define SMS_FONT_ERR1       0x0C //字体超过分区大小
#define SMS_COLOR_ERR       0x0D //颜色错误
#define SMS_TXTHEAD_ERR     0x0E //文本起始字符错误
#define SMS_SCN_BASE_ERR    0x0F //屏参不合法
#define SMS_SCN_OE_ERR      0x10 //OE极性错误
#define SMS_SCN_DE_ERR      0x11 //数据极性错误
#define SMS_SCN_SCAN_ERR    0x12 //扫描方式错误
#define SMS_SCN_COLOR_ERR   0x13 //屏幕颜色错误
#define SMS_PN_FULL_ERR     0x14 //手机号码满
#define SMS_PN_INVALID      0x15 //手机号码无权限
#define SMS_PSW_ERR         0x16 //密码错误
#define SMS_BORDER_ERR      0x17 //边框错误
#define SMS_RD_NO_ERR       0x18
#define SMS_CALL_FILE_INDEX_ERR 0x19 //预存文件序号错误
#define SMS_UNAVAIL_ERR     0x20 //非有效短信，不需应答

#define SMS_FILE_PARA_LEN 400
#define SMS_SUB_DATA_NUM 3 //短信子短信项目数
#define SMS_MAX_DATA_LEN (SMS_FILE_PARA_LEN - sizeof(S_Txt_Para))
#define SMS_SUB_DATA_LEN (SMS_MAX_DATA_LEN / SMS_SUB_DATA_NUM)//最多存放3条短信

#define SMS_PHONE_NO_LEN sizeof(S_SMS_Phone_No)

#define NULL_SMS_NO 0xFFFF

typedef struct
{
    INT8U Head;
    INT8U Flag[((MAX_SMS_NUM % 8) == 0)? (MAX_SMS_NUM / 8) : (MAX_SMS_NUM / 8 + 1)];
    INT8U CS[CS_BYTES];
    INT8U Tail;
}S_SMS_File_Flag;

typedef struct
{
    INT8U Head;
    INT8U Data[SMS_FILE_PARA_LEN]; //该数据
    INT8U Tail;
}S_SMS_Data;

typedef struct
{
    INT8U Head;
    INT16U No;
    INT8U CS[CS_BYTES];
    INT8U Tail;
}S_SMS_Cur_No;

typedef struct
{
    INT8U Head;
    char No[9][30];
	INT8U PSW[3];
    INT8U CS[CS_BYTES];
    INT8U Tail;
}S_SMS_Phone_No;

typedef struct
{
  INT8U Head;
  char Data[SMS_FILE_PARA_LEN];
  INT8U Tail;

}S_SMS_WR_Buf;

EXT S_SMS_File_Flag SMS_File_Flag;
EXT S_SMS_Phone_No SMS_Phone_No; //有效电话号码
EXT S_SMS_Cur_No SMS_Cur_No;
EXT S_SMS_Data SMS_Data;
EXT S_SMS_WR_Buf SMS_WR_Buf; //SMS读写的buf
EXT INT8U SMS_File_Play_End(void);
EXT void Clear_All_SMS(void);
EXT void Read_SMS_File_Flag(void);
EXT void Reset_Cur_SMS_File_No(void);
EXT INT16U Read_Cur_SMS_File_Para(void *pDst, void *pDst_Start, INT16U DstLen);
EXT void Find_Next_SMS_File_No(void);
EXT INT8U One_SMS_Proc(char *p, char *pReStr);//, S_Txt_Para *pPara, char *pUSC, INT16U *pIndex, INT8U *pSubIndex);
#if QT_EN == 0
EXT void smsMessageProc(SM_PARAM* pMsg, INT8U Num);
#endif
#endif
