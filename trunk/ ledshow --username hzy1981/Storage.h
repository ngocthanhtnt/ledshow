#ifndef STORAGE_H
#define STORAGE_H

#define STORA_DI INT32U

#define NULL_1BYTE  0xFF
#define NULL_2BYTES 0xFFFF
#define NULL_4BYTES 0xFFFFFFFF

#define MEM_WR_NUM 3

typedef struct
{
    INT8U MemID;
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

EXT INT16U Read_Multi_Storage_Data(STORA_DI SDI, INT16U Num, void *pDst, void *pDst_Start, INT16U DstLen);

#endif
