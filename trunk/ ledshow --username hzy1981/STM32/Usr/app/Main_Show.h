#ifndef MAIN_SHOW_H
#define MAIN_SHOW_H

#undef EXT
#ifdef MAIN_SHOW_C
#define EXT
#else
#define EXT extern
#endif

#include "LED_Cfg.h"

#define NEW_FLAG 0x0A

#define DATA_ERR 0x0A
#define DATA_OK  0x05
#define DATA_READ 0x06

#define PREVIEW_SCREEN 0x00 //预览屏幕
#define PREVIEW_PROG 0x01 //预览节目

#define FAC_TEST 0x00 //工厂状态测试
#define CMD_TEST 0x01 //命令状态测试

#define MAX_ROWS_FOLD 4
#define MAX_COLS_FOLD 4

typedef struct
{
  INT8U Head;

  S_Prog_Para Prog_Para;
  S_Int8U Prog_Para_No;
  S_Int8U Prog_Para_Flag; //参数读出标志

  S_Prog_Block_Index Block_Index;
  S_Int8U Block_Index_Flag; //Block_Index标志

  U_File_Para File_Para[MAX_AREA_NUM]; //文件参数
  S_Int8U Para_Prog_No[MAX_AREA_NUM];
  S_Int8U Para_File_No[MAX_AREA_NUM];
  S_Int8U File_Para_Ok_Flag[MAX_AREA_NUM];
  S_Int8U File_Para_Read_Flag[MAX_AREA_NUM];

  S_Show_Data Show_Data;
  S_Int8U Data_Prog_No[MAX_AREA_NUM];
  S_Int8U Data_File_No[MAX_AREA_NUM];
  S_Int16U Data_SCN_No[MAX_AREA_NUM];
  S_Int16U Data_X[MAX_AREA_NUM];
  S_Int16U Data_Y[MAX_AREA_NUM];
  S_Int16U Data_Width[MAX_AREA_NUM];
  S_Int16U Data_Height[MAX_AREA_NUM];
  S_Int8U Data_Ok_Flag[MAX_AREA_NUM];
  S_Int8U Data_Read_Flag[MAX_AREA_NUM];

  INT8U CS[CS_BYTES];

  INT8U Tail;
}S_Prep_Data;

typedef struct
{
  INT8U Head;
  INT8U Area_Num;
  INT16U X;
  INT16U Y;
  INT16U X_Len;
  INT16U Y_Len;

  INT16U Screen_Width;
  INT16U Screen_Height;
  INT8U Screen_Color;

  INT8U Open_Flag;
  INT8U Tail;
}S_RT_Show_Para;
/*
  if((Prog_Status.File_Para[Area_No].Pic_Para.Stay_Time & 0x8000) > 0)
    return (INT32U)(Prog_Status.File_Para[Area_No].Pic_Para.Stay_Time & 0x7FFF);
  else
    return (INT32U)Prog_Status.File_Para[Area_No].Pic_Para.Stay_Time * 1000;
*/

#define CONVERT_TIME(X) (((X) & 0x8000)?((X) & 0x7FFF):(X) * 1000)

EXT INT8U Preview_Prog_No;
EXT INT8U Preview_Mode;

#if DATA_PREP_EN
EXT S_Prep_Data Prep_Data;
#endif

EXT S_RT_Show_Para RT_Show_Para;

EXT INT32U Get_Area_In_Step_Delay(INT8U Area_No);
EXT INT32U Get_Area_Out_Step_Delay(INT8U Area_No);
EXT INT32U Get_File_Stay_Time(INT8U Area_No);
//EXT INT32U Get_File_Out_Time(INT8U Area_No);
EXT void Set_File_Stay_Time(INT8U Area_No, INT16U ms);
EXT void Update_Show_Data(void);
EXT INT8U Check_Prog_Play_Time(void);
EXT INT8U Update_XXX_Data(S_Show_Data *pDst, INT8U Area_No);
EXT INT8U Update_Show_Data_Bak(INT8U Prog_No, INT8U Area_No);
EXT INT8U Check_Update_Show_Data_Bak(void);
EXT INT8U Check_Prog_End(void);
EXT void Check_Show_Data_Para(void);
EXT void Calc_Prog_Play_Counts(void);
EXT void Show_Timer_Proc(void);
EXT void Show_Main_Proc(void);
EXT void Para_Init(void);
EXT void Para_Show(void);
EXT void Prog_Status_Init(void);
EXT void Set_RT_Show_Area(INT16U Width, INT16U Height);
EXT void Restore_Show_Area(void);
EXT void RT_Play_Status_Enter(INT16U Sec);
EXT void RT_Play_Status_Exit(void);
EXT void Print_Cur_Time(void);
EXT void Self_Test(INT8U Mode);
EXT void Fac_Status_Self_Test(void);
#endif
