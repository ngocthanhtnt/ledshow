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

/*
  if((Prog_Status.File_Para[Area_No].Pic_Para.Stay_Time & 0x8000) > 0)
    return (INT32U)(Prog_Status.File_Para[Area_No].Pic_Para.Stay_Time & 0x7FFF);
  else
    return (INT32U)Prog_Status.File_Para[Area_No].Pic_Para.Stay_Time * 1000;
*/

#define CONVERT_TIME(X) (((X) & 0x8000)?((X) & 0x7FFF):(X) * 1000)

EXT INT8U Preview_Prog_No;

#if DATA_PREP_EN
EXT S_Prep_Data Prep_Data;
#endif

EXT INT32U Get_Area_In_Step_Delay(INT8U Area_No);
EXT INT32U Get_Area_Out_Step_Delay(INT8U Area_No);
EXT INT32U Get_File_Stay_Time(INT8U Area_No);
EXT INT32U Get_File_Out_Time(INT8U Area_No);
EXT void Set_File_Stay_Time(INT8U Area_No, INT16U ms);
EXT void Update_Show_Data();
EXT INT8U Check_Prog_Play_Time();
EXT INT8U Update_XXX_Data(S_Show_Data *pDst, INT8U Area_No);
EXT INT8U Update_Show_Data_Bak(INT8U Prog_No, INT8U Area_No);
EXT INT8U Check_Update_Show_Data_Bak();
EXT INT8U Check_Prog_End();
EXT void Check_Show_Data_Para();
EXT void Check_Prog_Play_Counts();
EXT void Show_Timer_Proc();
EXT void Show_Main_Proc();
EXT void Show_Init();
EXT void Prog_Status_Init();
#endif
