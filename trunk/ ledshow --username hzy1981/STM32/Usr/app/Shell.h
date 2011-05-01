#ifndef SHELL_H
#define SHELL_H

#undef EXT
#ifdef SHELL_C
#define EXT
#else
#define EXT extern
#endif

//EXT INT8U Shell_Read_Mem(INT8U argc, INT8S **argv);
//EXT INT8U Shell_OS_Info(INT8U argc, INT8S **argv);

EXT INT8U Shell_Print_Screen_Status(INT8U argc, INT8S **argv);
EXT INT8U Shell_Print_Prog_Status(INT8U argc, INT8S **argv);
EXT INT8U Shell_Bg_Print_Switch(INT8U argc, INT8S **argv);
EXT void Shell_Proc(void);
#endif

