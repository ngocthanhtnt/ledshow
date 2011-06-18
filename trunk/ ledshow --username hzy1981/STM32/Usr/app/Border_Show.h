#ifndef BORDER_SHOW_H
#define BORDER_SHOW_H

#if BORDER_SHOW_EN > 0

#undef EXT
#ifdef BORDER_SHOW_C
#define EXT
#else
#define EXT extern
#endif

#define BORDER_STATIC 0x00 //æ≤Ã¨
#define BORDER_FLASH  0x01 //…¡À∏
#define BORDER_CLKWS  0x02 //À≥ ±’Î
#define BORDER_CCLKWS 0x03 //ƒÊ ±’Î
#define BORDER_CLKWS_FLASH  0x04 //À≥ ±’Î…¡À∏
#define BORDER_CCLKWS_FLASH 0x05 //ƒÊ ±’Î…¡À∏

//ºÚµ•±ﬂøÚ ˝æ›¥¶¿Ì
typedef struct
{
    INT8U Width;
    INT8U Height;
    INT8U Data[12];
}S_Simple_Border_Data;

extern const S_Simple_Border_Data Simple_Border_Data[];

EXT INT8U Get_Simple_Border_Data_Num(void);
EXT INT8U Get_Simple_Border_Height(INT8U Type);
EXT INT8U Get_Area_Border_Width(INT8U Area_No);
EXT INT8U Get_Area_Border_Height(INT8U Area_No);
EXT void Clr_Border(S_Show_Data *pDst, INT8U Area_No, INT8U Width, INT8U Height);
EXT void Restore_Border_Data(INT8U Area_No);
EXT INT8U Get_Border_Point_Data(INT8U Area_No, INT16U X, INT16U Y);
EXT void Draw_Border(S_Show_Data *pDst, INT8U Area_No, INT8U *pData, INT8U Width, INT8U Height,  INT32U Step);
EXT void Update_Border_Data(INT8U Area_No);
#endif

#endif
