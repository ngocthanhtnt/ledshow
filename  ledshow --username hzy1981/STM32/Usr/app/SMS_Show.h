#ifndef SMS_SHOW_H
#define SMS_SHOW_H

#include "Includes.h"

#undef EXT
#ifdef SMS_SHOW_C
#define EXT
#else
#define EXT extern
#endif

#define SMS_FILE_PARA_LEN 200
#define NULL_SMS_NO 0xFFFF

typedef struct
{
    INT8U Head;
    INT8U Flag[MAX_SMS_NUM / 8];
    INT8U CS[CS_BYTES];
    INT8U Tail;
}S_SMS_File_Flag;

typedef struct
{
    INT8U Head;
    INT8U Data[200];
    INT8U Tail;
}S_SMS_Data;

typedef struct
{
    INT8U Head;
    INT16U No;
    INT8U CS[CS_BYTES];
    INT8U Tail;
}S_SMS_Cur_No;

EXT S_SMS_File_Flag SMS_File_Flag;
EXT S_SMS_Cur_No SMS_Cur_No;
EXT S_SMS_Data SMS_Data;
EXT INT8U SMS_File_Play_End(void);
EXT void Read_SMS_File_Flag(void);
EXT void Reset_Cur_SMS_File_No(void);
EXT INT16U Read_Cur_SMS_File_Para(void *pDst, void *pDst_Start, INT16U DstLen);
EXT void Find_Next_SMS_File_No(void);
#endif
