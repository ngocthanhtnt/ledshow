#ifndef STORAGE_H
#define STORAGE_H

#undef EXT
#ifdef STORAGE_C
#define EXT
#else
#define EXT extern
#endif

#define TEST_DATA_LEN 4 //测试数据长度

#define STORA_DI INT16U

#define NULL_1BYTE  0xFF
#define NULL_2BYTES 0xFFFF
#define NULL_4BYTES 0xFFFFFFFF

#define MEM_WR_NUM 3

#define SDI_SCREEN_PARA     0x000 //屏幕参数
#define SDI_SCREEN_PARA_BK0 0x001
#define SDI_SCREEN_PARA_BK1 0x002
#define SDI_SCREEN_PARA_BK2 0x003

#define SDI_ENCRYPTION_DATA  0x04 //加密数据及3个备份
#define SDI_ENCRYPTION_DATA0 0x05
#define SDI_ENCRYPTION_DATA1 0x06
#define SDI_ENCRYPTION_DATA2 0x07

#define SDI_MAC_PARA	    0x008
#define SDI_MAC_PARA_BK0	0x009
#define SDI_MAC_PARA_BK1   	0x00A
#define SDI_MAC_PARA_BK2	0x00B

#define SDI_CUR_BLOCK_INDEX     0x0010
#define SDI_CUR_BLOCK_INDEX_BK0 0x0011
#define SDI_CUR_BLOCK_INDEX_BK1 0x0012

#define SDI_TEST_DATA   0x0020 //测试数据

#define SDI_PROG_PARA       0x100 //编程参数--后续有MAX_PROG_NUM个
#define SDI_PROG_PARA_BK0   0x200 //备份0
#define SDI_PROG_PARA_BK1   0x300 //备份1

#define SDI_PROG_BORDER     0x400
#define SDI_PROG_BORDER_BK0 0x500
#define SDI_PROG_BORDER_BK1 0x600

#define SDI_PROG_NUM	    0x700 //节目个数
#define SDI_PROG_NUM_BK0    0x800
#define SDI_PROG_NUM_BK1    0x900

#define SDI_PROG_BLOCK_INDEX     0x1000
#define SDI_PROG_BLOCK_INDEX_BK0 0x2000
#define SDI_PROG_BLOCK_INDEX_BK1 0x3000

#define SDI_FILE_PARA     0x4000 //文件参数
#define SDI_FILE_PARA_BK0 0x6000 //文件参数备份

#define SDI_FILE_BORDER     0x7000
#define SDI_FILE_BORDER_BK0 0x9000

#define SDI_SHOW_DATA     0xA000 //显示数据



typedef struct
{
    //INT8U MemID;
    //INT8U Stora_Property;//存储属性,0表示标识符是自定义的，1表示标识符与协议兼容
    STORA_DI SDI; 
    //参数标识,与DLT645兼容，同时可扩充。
    //INT8U RW_Flag;
    //参数读写标志，宏READ表示可读，宏WRITE 表示可写,READ|WRITE表示可读可写
    //INT8U PSW_Flag;
    //参数密码等级标志,PSW_N表示在N级密码以上才可修改该参数(N=0,1,2)
    //INT8U Imp_Flag;
    //重要等级标志 宏IMP_FACTORY_PARA表示最重要 IMP_CUR_DATA->IMP5重要性依次递减
    INT16U Len; //数据或参数长度
    //可否考虑加读写错误次数？这样可加强IMP不同的参数的容错能力。
    INT32U Num;
    //类似于此项的个数
}S_Data_Para_Storage_Info;


EXT void Check_Storage_Size(void);
//EXT INT8U Check_SuperPSW_Jump();
//EXT INT8U Check_Imp_Flag(INT8U Imp_Flag);
//EXT INT8U Get_Storage_Data_ImpFlag(STORA_DI SDI);
EXT INT32U Get_Storage_Data_Off(STORA_DI SDI);
EXT INT16U Get_Storage_Data_Len(STORA_DI SDI);
//EXT INT32U Get_Imp_Data_Size(INT8U Imp_Flag);
//EXT INT32U Get_Imp_Mem_Size(INT8U Imp_Flag);
//EXT INT8U Read_Imp_Data(INT8U Imp_Flag, INT32U Offset, void* pDst, INT16U RD_Len, void* pDst_Start, INT16U DstLen);
//EXT INT8U Write_Imp_Data(INT8U Imp_Flag, INT32U Offset, void* pSrc, INT16U SrcLen);

EXT INT16U Read_Storage_Data_Fix_Len(STORA_DI SDI, INT16U Offset, INT16U Len, void* pDst, void* pDst_Start, INT16U DstLen);
EXT INT8U Write_Storage_Data_Fix_Len(STORA_DI SDI, INT16U Offset, void* pSrc, INT16U SrcLen);

EXT INT16U Read_Storage_Data(STORA_DI SDI, void* pDst, void* pDst_Start, INT16U DstLen);
EXT INT8U Write_Storage_Data(STORA_DI SDI, void* pSrc, INT16U SrcLen);

EXT INT16U Read_Storage_Data_NoCS(STORA_DI SDI, INT16U Offset, INT16U Len, void* pDst, void* pDst_Start, INT16U DstLen);
EXT INT16U Read_Multi_Storage_Data(STORA_DI SDI, INT16U Num, void *pDst, void *pDst_Start, INT16U DstLen);

#endif
