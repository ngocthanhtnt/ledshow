#ifndef OS_MEM_H
#define OS_MEM_H

#if OS_MEM_EN>0

#undef OS_EXT
#ifndef OS_MEM_C
#define OS_EXT extern
#else
#define OS_EXT
#endif

//Mem_Block的类型定义,常用于Mem_Block的定义,头和尾采用OS_Align_Type类型
//是为了使Buf的开头处于一个对齐的位置,以便在动态内存中存放结构体等类型时不会发生成员地址不对齐等问题
//可以根据目标平台调整Head和Tail的类型
#define DECLARE_MEM_TYPE(Type,Len,Name) typedef struct{\
                                          OS_ALIGN_TYPE Head;\
                                          Type Buf[Len];\
                                          OS_ALIGN_TYPE Tail;\
                                          }Name

//描述某个Block的信息
typedef struct
{
  OS_ALIGN_TYPE *pHead; //指向缓冲区结构体的头
  OS_ALIGN_TYPE *pTail; //指向尾
  OS_INT8U *pBuf;  //指向缓冲区
  OS_INT16U Buf_Size; //缓冲区大小
}S_Mem_Block_Info;

//最多预先定义30个Block,必须先在OS_Cfg.h中定义MEM_BLOCKX_SIZE等宏
#ifdef OS_MEM_C

#ifdef MEM_BLOCK0_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK0_SIZE,S_Mem_Block0);
OS_EXT S_Mem_Block0 Mem_Block0={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK1_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK1_SIZE,S_Mem_Block1);
OS_EXT S_Mem_Block1 Mem_Block1={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK2_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK2_SIZE,S_Mem_Block2);
OS_EXT S_Mem_Block2 Mem_Block2={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK3_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK3_SIZE,S_Mem_Block3);
OS_EXT S_Mem_Block3 Mem_Block3={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK4_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK4_SIZE,S_Mem_Block4);
OS_EXT S_Mem_Block4 Mem_Block4={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK5_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK5_SIZE,S_Mem_Block5);
OS_EXT S_Mem_Block5 Mem_Block5={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK6_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK6_SIZE,S_Mem_Block6);
OS_EXT S_Mem_Block6 Mem_Block6={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK7_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK7_SIZE,S_Mem_Block7);
OS_EXT S_Mem_Block7 Mem_Block7={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK8_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK8_SIZE,S_Mem_Block8);
OS_EXT S_Mem_Block8 Mem_Block8={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK9_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK9_SIZE,S_Mem_Block9);
OS_EXT S_Mem_Block9 Mem_Block9={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK10_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK10_SIZE,S_Mem_Block10);
OS_EXT S_Mem_Block10 Mem_Block10={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK11_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK11_SIZE,S_Mem_Block11);
OS_EXT S_Mem_Block11 Mem_Block11={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK12_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK12_SIZE,S_Mem_Block12);
OS_EXT S_Mem_Block12 Mem_Block12={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK13_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK13_SIZE,S_Mem_Block13);
OS_EXT S_Mem_Block13 Mem_Block13={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK14_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK14_SIZE,S_Mem_Block14);
OS_EXT S_Mem_Block14 Mem_Block14={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK15_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK15_SIZE,S_Mem_Block15);
OS_EXT S_Mem_Block15 Mem_Block15={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK16_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK16_SIZE,S_Mem_Block16);
OS_EXT S_Mem_Block16 Mem_Block16={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK17_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK17_SIZE,S_Mem_Block17);
OS_EXT S_Mem_Block17 Mem_Block17={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK18_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK18_SIZE,S_Mem_Block18);
OS_EXT S_Mem_Block18 Mem_Block18={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK19_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK19_SIZE,S_Mem_Block19);
OS_EXT S_Mem_Block19 Mem_Block19={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK20_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK20_SIZE,S_Mem_Block20);
OS_EXT S_Mem_Block20 Mem_Block20={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK21_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK21_SIZE,S_Mem_Block21);
OS_EXT S_Mem_Block21 Mem_Block21={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK22_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK22_SIZE,S_Mem_Block22);
OS_EXT S_Mem_Block22 Mem_Block22={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK23_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK23_SIZE,S_Mem_Block23);
OS_EXT S_Mem_Block23 Mem_Block23={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK24_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK24_SIZE,S_Mem_Block24);
OS_EXT S_Mem_Block24 Mem_Block24={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK25_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK25_SIZE,S_Mem_Block25);
OS_EXT S_Mem_Block25 Mem_Block25={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK26_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK26_SIZE,S_Mem_Block26);
OS_EXT S_Mem_Block26 Mem_Block26={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK27_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK27_SIZE,S_Mem_Block27);
OS_EXT S_Mem_Block27 Mem_Block27={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK28_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK28_SIZE,S_Mem_Block28);
OS_EXT S_Mem_Block28 Mem_Block28={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK29_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK29_SIZE,S_Mem_Block29);
OS_EXT S_Mem_Block29 Mem_Block29={CHK_BYTE,{0},CHK_BYTE};
#endif
#ifdef MEM_BLOCK30_SIZE
DECLARE_MEM_TYPE(OS_INT8U,MEM_BLOCK30_SIZE,S_Mem_Block30);
OS_EXT S_Mem_Block30 Mem_Block30={CHK_BYTE,{0},CHK_BYTE};
#endif

//将Block的信息定义到 Mem_Block_Info中,排列方式应该从小到大排
CONST S_Mem_Block_Info Mem_Block_Info[]=
{
#ifdef MEM_BLOCK0_SIZE  
  {&Mem_Block0.Head,&Mem_Block0.Tail,Mem_Block0.Buf,sizeof(Mem_Block0.Buf)},
#endif  
#ifdef MEM_BLOCK1_SIZE
  {&Mem_Block1.Head,&Mem_Block1.Tail,Mem_Block1.Buf,sizeof(Mem_Block1.Buf)},
#endif
#ifdef MEM_BLOCK2_SIZE
  {&Mem_Block2.Head,&Mem_Block2.Tail,Mem_Block2.Buf,sizeof(Mem_Block2.Buf)},
#endif
#ifdef MEM_BLOCK3_SIZE
  {&Mem_Block3.Head,&Mem_Block3.Tail,Mem_Block3.Buf,sizeof(Mem_Block3.Buf)},
#endif
#ifdef MEM_BLOCK4_SIZE
  {&Mem_Block4.Head,&Mem_Block4.Tail,Mem_Block4.Buf,sizeof(Mem_Block4.Buf)},
#endif
#ifdef MEM_BLOCK5_SIZE
  {&Mem_Block5.Head,&Mem_Block5.Tail,Mem_Block5.Buf,sizeof(Mem_Block5.Buf)},
#endif
#ifdef MEM_BLOCK6_SIZE
  {&Mem_Block6.Head,&Mem_Block6.Tail,Mem_Block6.Buf,sizeof(Mem_Block6.Buf)},
#endif
#ifdef MEM_BLOCK7_SIZE
  {&Mem_Block7.Head,&Mem_Block7.Tail,Mem_Block7.Buf,sizeof(Mem_Block7.Buf)},
#endif
#ifdef MEM_BLOCK8_SIZE
  {&Mem_Block8.Head,&Mem_Block8.Tail,Mem_Block8.Buf,sizeof(Mem_Block8.Buf)},
#endif
#ifdef MEM_BLOCK9_SIZE
  {&Mem_Block9.Head,&Mem_Block9.Tail,Mem_Block9.Buf,sizeof(Mem_Block9.Buf)},
#endif
#ifdef MEM_BLOCK10_SIZE
  {&Mem_Block10.Head,&Mem_Block10.Tail,Mem_Block10.Buf,sizeof(Mem_Block10.Buf)},
#endif
#ifdef MEM_BLOCK11_SIZE
  {&Mem_Block11.Head,&Mem_Block11.Tail,Mem_Block11.Buf,sizeof(Mem_Block11.Buf)},
#endif
#ifdef MEM_BLOCK12_SIZE
  {&Mem_Block12.Head,&Mem_Block12.Tail,Mem_Block12.Buf,sizeof(Mem_Block12.Buf)},
#endif
#ifdef MEM_BLOCK13_SIZE
  {&Mem_Block13.Head,&Mem_Block13.Tail,Mem_Block13.Buf,sizeof(Mem_Block13.Buf)},
#endif
#ifdef MEM_BLOCK14_SIZE
  {&Mem_Block14.Head,&Mem_Block14.Tail,Mem_Block14.Buf,sizeof(Mem_Block14.Buf)},
#endif
#ifdef MEM_BLOCK15_SIZE
  {&Mem_Block15.Head,&Mem_Block15.Tail,Mem_Block15.Buf,sizeof(Mem_Block15.Buf)},
#endif
#ifdef MEM_BLOCK16_SIZE
  {&Mem_Block16.Head,&Mem_Block16.Tail,Mem_Block16.Buf,sizeof(Mem_Block16.Buf)},
#endif
#ifdef MEM_BLOCK17_SIZE
  {&Mem_Block17.Head,&Mem_Block17.Tail,Mem_Block17.Buf,sizeof(Mem_Block17.Buf)},
#endif
#ifdef MEM_BLOCK18_SIZE
  {&Mem_Block18.Head,&Mem_Block18.Tail,Mem_Block18.Buf,sizeof(Mem_Block18.Buf)},
#endif
#ifdef MEM_BLOCK19_SIZE
  {&Mem_Block19.Head,&Mem_Block19.Tail,Mem_Block19.Buf,sizeof(Mem_Block19.Buf)},
#endif
#ifdef MEM_BLOCK20_SIZE
  {&Mem_Block20.Head,&Mem_Block20.Tail,Mem_Block20.Buf,sizeof(Mem_Block20.Buf)},
#endif
#ifdef MEM_BLOCK21_SIZE
  {&Mem_Block21.Head,&Mem_Block21.Tail,Mem_Block21.Buf,sizeof(Mem_Block21.Buf)},
#endif
#ifdef MEM_BLOCK22_SIZE
  {&Mem_Block22.Head,&Mem_Block22.Tail,Mem_Block22.Buf,sizeof(Mem_Block22.Buf)},
#endif
#ifdef MEM_BLOCK23_SIZE
  {&Mem_Block23.Head,&Mem_Block23.Tail,Mem_Block23.Buf,sizeof(Mem_Block23.Buf)},
#endif
#ifdef MEM_BLOCK24_SIZE
  {&Mem_Block24.Head,&Mem_Block24.Tail,Mem_Block24.Buf,sizeof(Mem_Block24.Buf)},
#endif
#ifdef MEM_BLOCK25_SIZE
  {&Mem_Block25.Head,&Mem_Block25.Tail,Mem_Block25.Buf,sizeof(Mem_Block25.Buf)},
#endif
#ifdef MEM_BLOCK26_SIZE
  {&Mem_Block26.Head,&Mem_Block26.Tail,Mem_Block26.Buf,sizeof(Mem_Block26.Buf)},
#endif
#ifdef MEM_BLOCK27_SIZE
  {&Mem_Block27.Head,&Mem_Block27.Tail,Mem_Block27.Buf,sizeof(Mem_Block27.Buf)},
#endif
#ifdef MEM_BLOCK28_SIZE
  {&Mem_Block28.Head,&Mem_Block28.Tail,Mem_Block28.Buf,sizeof(Mem_Block28.Buf)},
#endif
#ifdef MEM_BLOCK29_SIZE
  {&Mem_Block29.Head,&Mem_Block29.Tail,Mem_Block29.Buf,sizeof(Mem_Block29.Buf)},
#endif
#ifdef MEM_BLOCK30_SIZE
  {&Mem_Block30.Head,&Mem_Block30.Tail,Mem_Block30.Buf,sizeof(Mem_Block30.Buf)}
#endif
};

#define OS_MEM_BLOCK_NUM (sizeof(Mem_Block_Info)/sizeof(Mem_Block_Info[0]))

//定义一个内存的使用信息
typedef struct
{
  OS_INT8U Head;

  OS_INT8U Task_ID;   //占有该内存的任务 
  OS_INT8U Use_Flag;  //该内存块是否被占用
  
  OS_INT8U Tail;
}S_Mem_Block_Use_Info;

//定义所有内存块的使用信息
typedef struct
{
  OS_INT8U Head;//头
  
  S_Mem_Block_Use_Info Block_Use_Info[OS_MEM_BLOCK_NUM];
  //以下用于统计内存块使用情况
  OS_INT8U Block_Counts;    //当前已经使用的Block数
  OS_INT8U Block_Counts_Max; //最大Block使用数
  OS_INT16U Max_Time; //最长占用时间
 
#if OS_CS_EN>0
  OS_INT8U CS[OS_CS_BYTES];
#endif
  
  OS_INT16U Use_Time[OS_MEM_BLOCK_NUM];//占有时间,ms为单位,需要频繁修改，所以不放入CS计算范围  
  
  OS_INT8U Tail; //尾
}S_Mem_Info;

OS_EXT volatile S_Mem_Info Mem_Info;
#endif

OS_EXT void OS_Mem_Init(void);
OS_EXT void *OS_malloc(OS_INT16U Size);
OS_EXT void OS_free(void *p);
OS_EXT void OS_Mem_Block_Check(OS_INT8U Index);
OS_EXT void OS_Mem_Check(void);
OS_EXT void OS_Mem_Use_Time_Stat(OS_INT16U Ms);
OS_EXT void OS_Mem_Info_Print(void);
#endif

#endif
