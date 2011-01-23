#ifndef MAIN_SHOW_H
#define MAIN_SHOW_H

#undef EXT
#ifdef MAIN_SHOW_C
#define EXT
#else
#define EXT extern
#endif

#define NEW_FLAG 0x0A
/*
  if((Prog_Status.File_Para[Area_No].Pic_Para.Stay_Time & 0x8000) > 0)
    return (INT32U)(Prog_Status.File_Para[Area_No].Pic_Para.Stay_Time & 0x7FFF);
  else
    return (INT32U)Prog_Status.File_Para[Area_No].Pic_Para.Stay_Time * 1000;
*/

#define CONVERT_TIME(X) (((X) & 0x8000)?((X) & 0x7FFF):(X) * 1000)

EXT INT32U Get_Area_In_Step_Delay(INT8U Area_No);
EXT INT32U Get_Area_Out_Step_Delay(INT8U Area_No);
EXT INT32U Get_File_Stay_Time(INT8U Area_No);
EXT INT32U Get_File_Out_Time(INT8U Area_No);
EXT void Set_File_Stay_Time(INT8U Area_No, INT16U ms);
EXT void Update_Show_Data();
EXT INT8U Check_Prog_Play_Time();
EXT INT8U Update_XXX_Data_Bak(INT8U Area_No);
EXT INT8U Update_Show_Data_Bak(INT8U Prog_No, INT8U Area_No);
EXT INT8U Check_Update_Show_Data_Bak();
EXT void Show_Timer_Proc();
EXT void Show_Main_Proc();
EXT void Show_Init();
#endif
