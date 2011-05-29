#ifndef DS1302_H
#define DS1302_H

#undef EXT
#ifdef DS1302_C
#define EXT
#else
#define EXT extern
#endif

/*DSCK -PA4 DAT PA5 RST DAT*/
#define ds1302Clk GPIO_Pin_5   //与时钟线相连的芯片的管脚
#define ds1302Data GPIO_Pin_7   //与数据线相连的芯片的管脚
#define ds1302Rst GPIO_Pin_8   //与复位端相连的芯片的管脚

//配置完毕，然后实现的代码就很简单了，从现成的代码移植过来。

#define WrEnDisCmd  0x8e  //写允许/禁止指令代码
#define WrEnDat     0x00 //写允许数据
#define WrDisDat    0x80 //写禁止数据
#define OscEnDisCmd 0x80 //振荡器允许/禁止指令代码
#define OscEnDat    0x00 //振荡器允许数据
#define OscDisDat   0x80 //振荡器禁止数据
#define WrMulti     0xbe //写入多个字节的指令代码
#define WrSingle    0x84 //写入单个字节的指令代码
#define RdMulti     0xbf //读出多个字节的指令代码

EXT INT8U _Get_Cur_Time(INT8U Time[]);
EXT INT8U Set_Cur_Time(INT8U Time[]);
EXT void SPI_DS1302_Init(void);
EXT void DS1302_Init(void);
#endif
