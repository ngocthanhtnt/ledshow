#define DS1302_C
#include "Includes.h"

/*
void Dataout_init(void) 
{ 
GPIO_InitTypeDef GPIO_InitStructure; 
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 
//PB14  CE     PB12 SCLK 
GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_13; 
GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_Out_PP; 
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
GPIO_Init(GPIOB, &GPIO_InitStructure); 
} 
void Datain_init(void) 
{ 
GPIO_InitTypeDef GPIO_InitStructure; 
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 
GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_13; 
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
GPIO_Init(GPIOB, &GPIO_InitStructure); 
} 

*/
void SPI_DS1302_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure = {0};

  SPI_Cmd(SPI1, ENABLE);
/* PA 4,6,为输出*/
  GPIO_InitStructure.GPIO_Pin =  ds1302Clk | ds1302Rst | ds1302Data;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
}

//设置数据io口为输入口
void Set_DataIO_Input(void)
{
  GPIO_InitTypeDef GPIO_InitStructure = {0};

  GPIO_InitStructure.GPIO_Pin =  ds1302Data;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	//上拉输入
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

}

//设置数据io口为输出口
void Set_DataIO_Output(void)
{
  GPIO_InitTypeDef GPIO_InitStructure = {0};

  GPIO_InitStructure.GPIO_Pin =  ds1302Data;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

}

void SendData_1302(u8 Data)
{ u8 i;
 u8 cTmp;

 Set_DataIO_Output();

 for(i=0;i<8;i++)
 { 
   cTmp= (Data& 0x01); //数据端等于tmp数据的末位值
  if(cTmp)    //1
      GPIO_SetBits(GPIOA,ds1302Data);
  else
   GPIO_ResetBits(GPIOA,ds1302Data); 
  Data>>=1;
  GPIO_SetBits(GPIOA,ds1302Clk);
  Delay_us(1);
  GPIO_ResetBits(GPIOA,ds1302Clk);
 }
}
/*写入1个或者多个字节，第1个参数是相关命令
#define WrMulti     0xbe //写入多个字节的指令代码
#define WrSingle    0x84 //写入单个字节的指令代码
第2个参数是待写入的值
第3个参数是待写入数组的指针
*/ 
void WriteByte_1302(u8 CmdDat,u8 Num,u8 *pSend)
{ 
 u8 i=0;
 GPIO_ResetBits(GPIOA,ds1302Rst);
 Delay_us(1);
 GPIO_SetBits(GPIOA,ds1302Rst);
 SendData_1302(CmdDat);
 for(i=0;i<Num;i++)
 { SendData_1302(*(pSend+i));
 }
 GPIO_ResetBits(GPIOA,ds1302Rst);
}
/*读出字节，第一个参数是命令
 #define RdMulti  0xbf //读出多个字节的指令代码
 第2个参数是读出的字节数，第3个是指收数据数组指针
 */
void RecByte_1302(u8 CmdDat,u8 Num,u8 *pRec)
{ 
 u8 i,j,tmp,cTmp;
 GPIO_ResetBits(GPIOA,ds1302Rst);//复位引脚为低电平
 Delay_us(1);
 GPIO_ResetBits(GPIOA,ds1302Clk);
 Delay_us(1);
 GPIO_SetBits(GPIOA,ds1302Rst);
 SendData_1302(CmdDat); //发送命令

 Set_DataIO_Input();

 tmp = 0;
 //此处应该改为读数据口
 for(i=0;i<Num;i++)
 { for(j=0;j<8;j++)
  { tmp>>=1;
   cTmp=GPIO_ReadInputDataBit(GPIOA,ds1302Data);
   if(cTmp)
    tmp|=0x80;
   GPIO_SetBits(GPIOA,ds1302Clk);
   Delay_us(1);
   GPIO_ResetBits(GPIOA,ds1302Clk);       
  }
  *(pRec+i)=tmp;
 }
 Delay_us(1);
 GPIO_ResetBits(GPIOA,ds1302Rst);//复位引脚为低电平
}
/*
当写保护寄存器的最高位为0时,允许数据写入寄存器。
写保护寄存器可以通过命令字节8E、8F来规定禁止写入/读出。写保护位不能在多字节传送模式下写入。
当写保护寄存器的最高位为1时，禁止数据写入寄存器。

时钟停止位操作:当把秒寄存器的第7位时钟停止位设置为0时起动时钟开始
当把秒寄存器的第7位时钟停止位设置为1时，时钟振荡器停止。
   
    根据传入的参数决定相关命令，
 第一个参数：命令字，第2个参数：写入的数据
 写允许命令；8EH,00H
 写禁止命令；8EH,80H
 振荡器允许命令；80H,00H
 振荡器禁止命令；80H,80H
*/
void WrCmd(u8 CmdDat,u8 CmdWord)
{ u8 CmdBuf[2];
 CmdBuf[0]=CmdWord;
 WriteByte_1302(CmdDat,1,CmdBuf);
}

void test_main()
{

 u8 Ds1302SendBuf[8]={0x30,0x32,0x01,0x10,0x01,0x01,0x08,33};  //发送数据缓冲区	  00,02, 
 u8 Ds1302RecBuf[8];    //接收数据缓冲区
 WrCmd(WrEnDisCmd,WrEnDat);  //写允许
 WrCmd(OscEnDisCmd,OscEnDat); //振荡器允许
 WriteByte_1302(WrMulti,8,Ds1302SendBuf);//将时间值送到DS1302中
 RecByte_1302(RdMulti,8,Ds1302RecBuf); // 读出来看看，
 }

void DS1302_Init(void)
{
  INT8U Temp[8];
  Unselect_SPI_Device();
  SPI_DS1302_Init();

  RecByte_1302(RdMulti,8,Temp); //读时间数据
  
  if((Temp[0] & 0x80 > 0))  //秒数据
  { 
    WrCmd(WrEnDisCmd,WrEnDat);  //写允许
    WrCmd(OscEnDisCmd,OscEnDat); //振荡器允许
	WrCmd(WrEnDisCmd,WrDisDat);  //写允许关闭
  }
}
/*
#define T_YEAR  0 //--除了日和年其他都从0开始计起。日从1计起，年从1900年计起
#define T_MONTH 1
#define T_DATE  2
#define T_HOUR  3
#define T_MIN   4
#define T_SEC   5
#define T_WEEK  6
*/
//获取当前时间
INT8U Set_Cur_Time(INT8U Time[])//S_Time *pTime)
{
  INT8U Temp[8];

  Temp[0] = Hex2Bcd_Byte(Time[T_SEC]);
  Temp[1] = Hex2Bcd_Byte(Time[T_MIN]);
  Temp[2] = Hex2Bcd_Byte(Time[T_HOUR]);
  Temp[3] = Hex2Bcd_Byte(Time[T_DATE]);
  Temp[4] = Hex2Bcd_Byte(Time[T_MONTH]);
  Temp[5] = Hex2Bcd_Byte(Time[T_WEEK]);
  Temp[6] = Hex2Bcd_Byte(Time[T_YEAR]);
  Temp[7] = 0;

  Unselect_SPI_Device();
  SPI_DS1302_Init(); //重新初始化SPI口

  WrCmd(WrEnDisCmd,WrEnDat);  //写允许
  WriteByte_1302(WrMulti,8,Temp);//将时间值送到DS1302中
  WrCmd(WrEnDisCmd,WrDisDat);  //写允许关闭
  return 1;
}

//设置当前时间
INT8U _Get_Cur_Time(INT8U Time[])
{
  INT8U Temp[8];

  Unselect_SPI_Device();
  SPI_DS1302_Init();  //重新初始化SPI口

  RecByte_1302(RdMulti,8,Temp); // 读出来看看，

  if((Temp[0] & 0x80)) //振荡器没有使能?
  {
    Temp[0] = Temp[0] & 0x7F;
    
	WrCmd(WrEnDisCmd,WrEnDat);  //写允许
    WrCmd(OscEnDisCmd,OscEnDat); //振荡器允许
	WrCmd(WrEnDisCmd,WrDisDat);  //写允许关闭
  }

  Time[T_SEC] = Bcd2Hex_Byte(Temp[0]);
  Time[T_MIN] = Bcd2Hex_Byte(Temp[1]);
  Time[T_HOUR] = Bcd2Hex_Byte(Temp[2]);
  Time[T_DATE] = Bcd2Hex_Byte(Temp[3]);
  Time[T_MONTH] = Bcd2Hex_Byte(Temp[4]);
  Time[T_WEEK] = Bcd2Hex_Byte(Temp[5]);
  Time[T_YEAR] = Bcd2Hex_Byte(Temp[6]);

  return 1;
}
