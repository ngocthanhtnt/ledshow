#ifndef MAIN_SHOW_H
#define MAIN_SHOW_H

#undef EXT
#ifdef MAIN_SHOW_C
#define EXT
#else
#define EXT extern
#endif



EXT INT8U Get_Area_Step_Delay(INT8U Area_No);
EXT INT32U Get_File_Stay_Time(INT8U Area_No);
EXT void Set_File_Stay_Time(INT8U Area_No, INT16U ms);
EXT void Update_Show_Data();
EXT INT8U Check_Prog_Play_Time();
EXT INT8U Update_XXX_Data_Bak(INT8U Area_No);
EXT INT8U Update_Show_Data_Bak(INT8U Prog_No, INT8U Area_No);
EXT INT8U Check_Update_Show_Data_Bak();
EXT void Show_Timer_Proc();
EXT void Show_Main_Proc();
#endif
