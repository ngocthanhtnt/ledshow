#ifndef SHELL_H
#define SHELL_H

#undef EXT
#ifdef SHELL_C
#define EXT
#else
#define EXT extern
#endif

#define SHELL_CMD_BUF_LEN 10

typedef struct
{
  INT8U Head;
  INT8U Buf[SHELL_CMD_BUF_LEN];
  
  INT8U Posi;

  INT8U Tail;

}S_Shell_Cmd_Buf;

#ifdef SHELL_C
EXT S_Shell_Cmd_Buf _Shell_Cmd_Buf = {CHK_BYTE, {0}, 0, CHK_BYTE};
#else
EXT S_Shell_Cmd_Buf _Shell_Cmd_Buf;
#endif

#define Shell_Cmd_Buf _Shell_Cmd_Buf.Buf

EXT void Shell_Rcv_Byte(INT8U Byte);
EXT INT8U Shell_Print_Screen_Status(INT8U argc, INT8S **argv);
EXT INT8U Shell_Print_Prog_Status(INT8U argc, INT8S **argv);
EXT INT8U Shell_Bg_Print_Switch(INT8U argc, INT8S **argv);
EXT void Shell_Proc(void);
#endif

