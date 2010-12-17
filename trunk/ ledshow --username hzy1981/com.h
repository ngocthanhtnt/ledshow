#ifndef COM_H
#define COM_H

//extern "c"
//{
#undef EXT
#ifdef COM_C
#define EXT
#else
#define EXT extern
#endif

#define FRAME_HEAD 0x5A
//#define FRAME_HEAD1 0xA5
#define FRAME_TAIL  0xAA

//控制码定义
#define C_SCREEN_WH   0x01 //屏幕宽高
#define C_SCREEN_ADDR 0x02 //屏幕地址
#define C_SCREEN_IP   0x03 //IP地址
#define C_SCREEN_BAUD 0x04 //通信速率
#define C_SCREEN_OC_TIME 0x05 //定时开关机时间
#define C_SCREEN_LIGNTNESS 0x06 //亮度
#define C_SCREEN_TIME 0x07 //时间
#define C_DEL_PROG    0x08 //删除节目
#define C_PROG_PROPERTY  0x09 //节目属性
#define C_PROG_DATA  0x0A //显示数据
#define C_SCREEN_INFO 0x0B //屏幕信息
#define C_UPDATE      0x0C //固件升级

#define FLEN   0x01
#define FADDR  0x03
#define FSEQ   0x05
#define FSEQ0  0x06
#define FCTRL  0x07
#define FDATA  0x09

#define F_NDATA_LEN 12 

EXT INT8U Check_Frame_Format(INT8U Frame[], INT16U Frame_Len);
EXT INT8U Para_Frame_Proc(INT16U Ctrl_Code, INT8U Data[], INT16U Len);
//}
#endif
