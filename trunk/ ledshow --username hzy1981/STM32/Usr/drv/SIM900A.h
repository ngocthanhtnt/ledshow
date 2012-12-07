#ifndef SIM900A_H
#define SIM900A_H

#undef EXT
#ifdef SIM900A_C
#define EXT
#else
#define EXT extern
#endif

typedef struct
{
  INT8U Head;
  char Data[1500];
  INT8U Tail;
}S_GPRS_Buf;

EXT S_GPRS_Buf GPRS_Buf;

EXT void ModuleInit(void);
EXT INT8U GsmInit(void);
EXT INT16U ReadComm(char *pDst, INT16U Len);
EXT INT16U WriteComm(char *pDst, INT16U Len);
EXT INT8U ATSend(char *p);
EXT INT8U ATSendResponse(char *pSrc, char *pRes, INT16U ms);
EXT INT8U GetResponse(char *p, INT16U ms);
EXT void ClrComm(void);
#endif
