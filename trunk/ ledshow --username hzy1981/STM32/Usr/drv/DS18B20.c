//=========================DS18b20.c================================//
/*
#include "stm32f10x_lib.h"
#include "DS18b20.h"
#include "SysTick_Delay.h"
*/
#include "Includes.h"

#define NO_18B20_FLAG 0x56789123
#define EXIST_18B20_FLAG 0x13452389

INT32U DS18B20_In_Flag; 

#define Delay_Nus Delay_us 
#define Delay_Nms Delay_ms
/******************************************
函数名称：GPIO_DQ_Out_Mode
功    能：设置DQ引脚为开漏输出模式
参    数：无
返回值  ：无
*******************************************/
void GPIO_DQ_Out_Mode(void)
{
    GPIO_InitTypeDef GPIO_InitStructure ;
    
    GPIO_InitStructure.GPIO_Pin = DQ_GPIO_Pin ;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD ; //开漏输出
    GPIO_Init(DQ_GPIO ,&GPIO_InitStructure) ;
}
/******************************************
函数名称：GPIO_DQ_Input_Mode
功    能：设置DQ引脚为浮空输入模式
参    数：无
返回值  ：无
*******************************************/
void GPIO_DQ_Input_Mode(void)
{
    GPIO_InitTypeDef GPIO_InitStructure ;
    
    GPIO_InitStructure.GPIO_Pin = DQ_GPIO_Pin ;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING ; //浮空输入
    GPIO_Init(DQ_GPIO ,&GPIO_InitStructure) ;
}
/******************************************
函数名称：Tx_ResetPulse
功    能：发送复位脉冲
参    数：无
返回值  ：无
*******************************************/
void Tx_ResetPulse(void)
{
    GPIO_DQ_Out_Mode() ;
    DQ_Write_0() ;  //复位脉冲
    Delay_Nus(500) ; //至少保持480us
    DQ_Write_1() ;  //加速上升沿速度
    Delay_Nus(1) ;
}
/******************************************
函数名称：Rx_PresencePulse
功    能：接受应答信号
参    数：无
返回值  ：无
*******************************************/
void Rx_PresencePulse(void)
{
    GPIO_DQ_Input_Mode() ;
    while( DQ_ReadBit()) ;  //等待DS18b20应答
    while( DQ_ReadBit() == 0) ; //DS18b20将总线拉低60~240us ,然后总线由上拉电阻拉高
    Delay_Nus(300) ;
    GPIO_DQ_Out_Mode() ;    //接受完成，主机重新控制总线
}
/******************************************
函数名称：Write_OneByte_ToDS18b20
功    能：写一个字节到DS18b20
参    数：无
返回值  ：无
*******************************************/
void Write_OneByte_ToDS18b20(unsigned char data)
{
    unsigned char i ;
    GPIO_DQ_Out_Mode() ;
    for(i=0 ;i<8 ;i++)
    {
        if(data&0x01)    //低位在前
        {
            //写1
            DQ_Write_0() ; //写时间空隙总是从总线的低电平开始
            Delay_Nus(8) ;  //15us内拉高
            DQ_Write_1() ;
            Delay_Nus(80) ; //整个写1时隙不低于60us
        }
        else
        {
            //写0
            DQ_Write_0() ;
            Delay_Nus(110) ; //保持在60us到120us之间
            DQ_Write_1() ;
            Delay_Nus(5) ;
        }
        data >>= 1 ;
    }
}
/******************************************
函数名称：Read_OneByte_FromDS18b20
功    能：从DS18b20读一个字节
参    数：无
返回值  ：读出的数据
*******************************************/
unsigned char Read_OneByte_FromDS18b20(void)
{
    unsigned char i ,data = 0 ;
    
    for(i=0 ;i<8 ;i++)
    {
        GPIO_DQ_Out_Mode() ;
        data >>= 1 ;
        DQ_Write_0() ;
        Delay_Nus(2) ;
        GPIO_DQ_Input_Mode() ;
        Delay_Nus(1) ;
        if(DQ_ReadBit())
        {
            data |= 0x80 ;
        }
        Delay_Nus(70) ;   //等待这一位数据完成传输
    }
    GPIO_DQ_Out_Mode() ;
    return data ;
}
/******************************************
函数名称：Read_Temperature
功    能：读取温度信息
参    数：*sign - 保存符号（零上或零下）
          *integer - 保存整数部分
          *decimal - 保存小数部分
返回值  ：无
*******************************************/
void Read_Temperature(unsigned char *sign ,
                      unsigned char *interger ,
                      unsigned int *decimal)
{
    unsigned char a=0;
    unsigned char b=0;
    //volatile unsigned char c=0;
    //volatile unsigned char d=0;
    //volatile unsigned char e=0;
    
    unsigned int tmp ;
    
    DS18B20_Init();
    Write_OneByte_ToDS18b20(ROM_Read_Cmd);
  
    DS18B20_Init();
    Write_OneByte_ToDS18b20(ROM_Skip_Cmd);//跳过读序列号操作
    Write_OneByte_ToDS18b20(Convert_T); //启动温度转换
    Delay_Nms(780);//等待DS18b20转换完成
    
    DS18B20_Init();
    Write_OneByte_ToDS18b20(ROM_Skip_Cmd);
    Write_OneByte_ToDS18b20(Read_Scratchpad); //读取寄存器内容（可以从寄存器0读到寄存器8）
    
    a= Read_OneByte_FromDS18b20();     //温度低8位
    b= Read_OneByte_FromDS18b20();     //温度高8位
    //c= Read_OneByte_FromDS18B20();   //TH
    //d= Read_OneByte_FromDS18B20();   //TL
    //e= Read_OneByte_FromDS18B20();   //Configuration Register
    
    Tx_ResetPulse();  //中断数据读取
    tmp = (b<<8) | a ;
    if(b & 0xF0)
    {
    *sign = 1 ;              //符号部分
    tmp = ~tmp+1 ;
    }
    else 
    {
    sign = 0 ;
    }
    *interger = (tmp>>4) & 0x00FF;  //整数部分
    *decimal = (tmp & 0x000F) * 625 ; //小数部分 
}

/******************************************
函数名称：DS18B20_Init
功    能：初始化DS18b20
参    数：无
返回值  ：无
*******************************************/
void DS18B20_Init(void)
{
    Tx_ResetPulse();
    Rx_PresencePulse(); 
}

//获取温度
INT16S Get_DS18B20_Temp(void)
{
  unsigned char sign, integer;
  unsigned int dec;
    
  Read_Temperature(&sign, &integer, &dec);
  return integer;
}

INT8U Chk_DS18B20_Sensor(void)
{
  if(DS18B20_In_Flag EQ EXIST_18B20_FLAG)
    return 1;
  else 
    return 0;
}
