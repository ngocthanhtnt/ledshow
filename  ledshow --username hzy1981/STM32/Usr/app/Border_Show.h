#ifndef BORDER_SHOW_H
#define BORDER_SHOW_H

#if 1//BORDER_SHOW_EN > 0

#undef EXT
#ifdef BORDER_SHOW_C
#define EXT
#else
#define EXT extern
#endif

#define BORDER_STATIC 0x00 //��̬
#define BORDER_FLASH  0x01 //��˸
#define BORDER_CLKWS  0x02 //˳ʱ��
#define BORDER_CCLKWS 0x03 //��ʱ��
#define BORDER_CLKWS_FLASH  0x04 //˳ʱ����˸
#define BORDER_CCLKWS_FLASH 0x05 //��ʱ����˸

//#define MAX_SBORDER_DATA_LEN 120

//�򵥱߿����ݴ���
typedef struct
{
    INT8U Width;
    INT8U Height;
    INT8U const *Data;
}S_Simple_Border_Data;

extern const S_Simple_Border_Data Simple_Border_Data0[];

//EXT INT8U Get_Simple_Border_Data_Num(void);
EXT INT8U Get_Simple_Border_Height(INT8U Type);
EXT INT8U Get_Area_Border_Width(INT8U Area_No);
EXT INT8U Get_Area_Border_Height(INT8U Area_No);
EXT void Clr_Border(S_Show_Data *pDst, INT8U Area_No);
EXT void Restore_Border_Data(INT8U Area_No);
EXT INT8U Get_Border_Point_Data(INT8U *pData, INT8U Area_No, INT16U X, INT16U Y);
EXT void Draw_Border(S_Show_Data *pDst, INT8U Area_No, INT8U *pData, INT32U Step, INT8U Flag);
EXT void Copy_Border(INT8U Area_No, INT32U Step);
EXT void Update_Border_Data(INT8U Area_No);
EXT INT8U Get_Simple_Border_Num(INT8U Type);
EXT S_Simple_Border_Data *Get_Simple_Border_Info(INT8U Index);
EXT void Border_Show_Proc(void);
#endif

#endif
