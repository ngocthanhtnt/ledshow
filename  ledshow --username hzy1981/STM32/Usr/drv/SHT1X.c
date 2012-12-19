#include "Includes.h"
/*
#include<stm32f10x_lib.h>
#include "sys.h"
#include "delay.h"
#include "1602.h"
*/
#if TEMP_SHOW_EN || HUMIDITY_SHOW_EN
#define NO_SHT1X_FLAG 0x1235A9A5
#define EXIST_SHT1X_FLAG 0x87394203

#define noACK 0 //用于判断是否结束SHT10通讯
#define ACK 1 //结束数据传输
						  // r/w
#define STATUS_REG_W 0x06 // 0
#define STATUS_REG_R 0x07 // 1
#define MEASURE_TEMP 0x03 // 1
#define MEASURE_HUMI 0x05 // 1
#define RESET 0x1E        // 0

#define SCLL SHT1X_SCL_PORT->ODR&=~SHT1X_SCL_PIN//GPIOE->ODR&=~(1<<11)
#define SCLH SHT1X_SCL_PORT->ODR|=SHT1X_SCL_PIN//GPIOE->ODR|=1<<11
#define SDAL SHT1X_SDA_PORT->ODR&=~SHT1X_SDA_PIN //GPIOE->ODR&=~(1<<13)
#define SDAH SHT1X_SDA_PORT->ODR|=SHT1X_SDA_PIN //GPIOE->ODR|=1<<13
/*
#define ReadState() {GPIOE->CRH&=0xFF0FFFFF; GPIOE->CRH|=0x00800000; GPIOE->ODR&=~(1<<13);}
#define WriteState() {GPIOE->CRH&=0xFF0FFFFF; GPIOE->CRH|=0x00300000;}
*/
#define DATA() ((SHT1X_SDA_PORT->IDR & SHT1X_SDA_PIN) > 0?1:0)//(GPIOE->IDR>>13)&1

#define delay_us Delay_us

enum{TEMP,HUMI};

unsigned int Temperature,Humidity;
u8 t[2];

INT32U SHT_In_Flag;

void ReadState(void)
{
  GPIO_InitTypeDef GPIO_InitStructure = {0};

  GPIO_InitStructure.GPIO_Pin =  SHT1X_SDA_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	//上拉输入
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(SHT1X_SDA_PORT, &GPIO_InitStructure);
}

void WriteState(void)
{
  GPIO_InitTypeDef GPIO_InitStructure = {0};

  GPIO_InitStructure.GPIO_Pin =  SHT1X_SDA_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(SHT1X_SDA_PORT, &GPIO_InitStructure);
}

void SHT_Init(void)
{
  INT16S Temp, Humidity;
  GPIO_InitTypeDef GPIO_InitStructure = {0};

  GPIO_InitStructure.GPIO_Pin =  SHT1X_SCL_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(SHT1X_SCL_PORT, &GPIO_InitStructure);

  //连续读3次SHT1X,如果3次都没有读到，认为没有连接传感器
  SHT_In_Flag = EXIST_SHT1X_FLAG;
  if(Get_Temp_Humidity(&Temp, &Humidity) EQ 0)
  {
    Delay_ms(100);
	if(Get_Temp_Humidity(&Temp, &Humidity) EQ 0)
	{
	  Delay_ms(100);
	  if(Get_Temp_Humidity(&Temp, &Humidity) EQ 0)
	    SHT_In_Flag = NO_SHT1X_FLAG;
	}
  }
}

//启动传输
//       _____         ________ 
// DATA:      |_______| 
//           ___     ___ 
// SCK : ___|   |___|   |______ 
void TransStart(){
	SDAH;
	SCLL;
	delay_us(1);
	SCLH;
	delay_us(1);
	SDAL;
	delay_us(1);
	SCLL;
	delay_us(1);
	SCLH;
	delay_us(1);
	SDAH;
	delay_us(1);
	SCLL;
	delay_us(1);
}

// 通讯复位: DATA-line=1 and at least 9 SCK cycles followed by transstart 
//       _____________________________________________________         ________ 
// DATA:                                                      |_______| 
//          _    _    _    _    _    _    _    _    _        ___     ___ 
// SCK : __| |__| |__| |__| |__| |__| |__| |__| |__| |______|   |___|   |______ 
void ConnectionReset(){
	unsigned char i;
	SDAH;
	SCLL;
	delay_us(1);
	for(i=0;i<9;i++){
		SCLH;
		delay_us(1);
		SCLL;
		delay_us(1);
	}
	TransStart();
}

char ReadByte(unsigned char ack){
	unsigned char i,val=0;
	SDAH;
	ReadState();
	for(i=0x80;0<i;i/=2){
		SCLH;
		delay_us(1);
		if(DATA())
			val=(val|i);
		delay_us(1);
		SCLL; 
		delay_us(1);
	}
	WriteState();
	if(ack==1)
		SDAL;
	else
		SDAH;
	delay_us(1);
	SCLH;
	delay_us(1);
	SCLL;	 
	delay_us(1);
	SDAH;
	return val;
}

char WriteByte(unsigned char value){//从高位开始发送
	unsigned char i,error=0;
	for(i=0x80;0<i;i/=2){
		if(i&value)
			SDAH;
		else
			SDAL;
		SCLH;
		delay_us(1);
		SCLL;
	}
	SDAH;//release DATA-line 
	SCLH;//clk #9 for ack
	delay_us(1);
	ReadState();
	error=DATA();//DATA在第9个上升沿将被SHT10自动下拉为低电平
	WriteState();
	delay_us(1);
	SCLL;
	SDAH;//release DATA-line
	return error;
}

char Measure(unsigned char *pCheckSum,unsigned char mode, unsigned char t[]){
	unsigned char error=0;
	TransStart();
	switch(mode){
		case TEMP:
			error+=WriteByte(MEASURE_TEMP);
			break;
		case HUMI:
			error+=WriteByte(MEASURE_HUMI);
			break;
		default:
			break;
	}
	ReadState();
	delay_us(320000);
	if(DATA())// 或超时 (约2 sec.)
		error+=1;  
	WriteState();
	t[0]=ReadByte(ACK);
	t[1]=ReadByte(ACK);
	*pCheckSum=ReadByte(noACK);
	return error;
}
/*
//温度暂时设定值为0-99，可以根据需要更改
void Display(u32 x){
//	x=x%1000;
//	WriteData(x/100+'0');
	WriteData((x%100)/10+'0');
	WriteData(x%10+'0');
}

int main(){

	SHT_GPIO_Config();
	delay_us(11000);
	ConnectionReset();
	while(1){
		WriteCmd(0x01);
		error=0;
		error+=Measure(&CheckSum,TEMP, t);
		if(error!=0){
			ConnectionReset();
			WriteData(error+'0');
			delay_us(500000);
			continue;
		}
		Temperature=(u32)(((t[0]<<8)+t[1])*0.01-40);
		Display(Temperature);
		delay_us(500000);
	}
}
*/

INT8U Get_Temp_Humidity(INT16S *pTemp, INT16S *pHumidity)
{
  INT8U buf[5], sum;

  if(SHT_In_Flag EQ NO_SHT1X_FLAG)
    return 0;

  Measure(&sum, TEMP, buf);

  Screen_Status.Temperature = (u32)(((buf[0]<<8)+buf[1])*0.01-40);

  Measure(&sum, HUMI, buf);

  return 0;
}
#endif

