#include "Includes.h"
/*
#include<stm32f10x_lib.h>
#include "sys.h"
#include "delay.h"
#include "1602.h"
*/
#if TEMP_SHOW_EN && HUMIDITY_SHOW_EN
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

INT32U SHT1X_In_Flag;

const char CRC8Table[]={
  0, 94, 188, 226, 97, 63, 221, 131, 194, 156, 126, 32, 163, 253, 31, 65,
  157, 195, 33, 127, 252, 162, 64, 30, 95, 1, 227, 189, 62, 96, 130, 220,
  35, 125, 159, 193, 66, 28, 254, 160, 225, 191, 93, 3, 128, 222, 60, 98,
  190, 224, 2, 92, 223, 129, 99, 61, 124, 34, 192, 158, 29, 67, 161, 255,
  70, 24, 250, 164, 39, 121, 155, 197, 132, 218, 56, 102, 229, 187, 89, 7,
  219, 133, 103, 57, 186, 228, 6, 88, 25, 71, 165, 251, 120, 38, 196, 154,
  101, 59, 217, 135, 4, 90, 184, 230, 167, 249, 27, 69, 198, 152, 122, 36,
  248, 166, 68, 26, 153, 199, 37, 123, 58, 100, 134, 216, 91, 5, 231, 185,
  140, 210, 48, 110, 237, 179, 81, 15, 78, 16, 242, 172, 47, 113, 147, 205,
  17, 79, 173, 243, 112, 46, 204, 146, 211, 141, 111, 49, 178, 236, 14, 80,
  175, 241, 19, 77, 206, 144, 114, 44, 109, 51, 209, 143, 12, 82, 176, 238,
  50, 108, 142, 208, 83, 13, 239, 177, 240, 174, 76, 18, 145, 207, 45, 115,
  202, 148, 118, 40, 171, 245, 23, 73, 8, 86, 180, 234, 105, 55, 213, 139,
  87, 9, 235, 181, 54, 104, 138, 212, 149, 203, 41, 119, 244, 170, 72, 22,
  233, 183, 85, 11, 136, 214, 52, 106, 43, 117, 151, 201, 74, 20, 246, 168,
  116, 42, 200, 150, 21, 75, 169, 247, 182, 232, 10, 84, 215, 137, 107, 53
};

//计算CRC-8校验
unsigned char CRC8_Table(unsigned char *p, char counter)
{
    unsigned char crc8 = 0;

    for( ; counter > 0; counter--){
        crc8 = CRC8Table[crc8^*p];
        p++;
    }
    return(crc8);

}
/*
void main()
{
    unsigned  char  a[] = {0x02, 0x03};

    printf("%d", CRC8_Table(&a, 2));

    getch();
}
*/

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

void SHT1X_Init(void)
{
  INT16S Temp, Humi;
  GPIO_InitTypeDef GPIO_InitStructure = {0};

  GPIO_InitStructure.GPIO_Pin =  SHT1X_SCL_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(SHT1X_SCL_PORT, &GPIO_InitStructure);

  //连续读3次SHT1X,如果3次都没有读到，认为没有连接传感器
  SHT1X_In_Flag = EXIST_SHT1X_FLAG;
  /*
  if(Get_SHT1X_Temp_Humi(&Temp, &Humi) EQ 0)
  {
    Delay_ms(10);
	if(Get_SHT1X_Temp_Humi(&Temp, &Humi) EQ 0)
	{
	  Delay_ms(10);
	  if(Get_SHT1X_Temp_Humi(&Temp, &Humi) EQ 0)
	    SHT1X_In_Flag = NO_SHT1X_FLAG;
	}
  }
  */
  Get_SHT1X_Temp_Humi(0, &Temp, &Humi);
  Delay_ms(300);
  Get_SHT1X_Temp_Humi(1, &Temp, &Humi);
  Delay_ms(300);
  if(Get_SHT1X_Temp_Humi(1, &Temp, &Humi) EQ 0)
  {
	Get_SHT1X_Temp_Humi(0, &Temp, &Humi);
	Delay_ms(300);
	Get_SHT1X_Temp_Humi(1, &Temp, &Humi);
	Delay_ms(300);
	if(Get_SHT1X_Temp_Humi(1, &Temp, &Humi) EQ 0)
	  SHT1X_In_Flag = NO_SHT1X_FLAG;
  }

  if(SHT1X_In_Flag EQ EXIST_SHT1X_FLAG)
  {
	Screen_Status.Temperature = Temp;
	Screen_Status.Humidity = Humi; 
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

void Measure_Start(unsigned char mode)
{
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
}

char Measure(unsigned char mode, unsigned char t[]){
	unsigned char error=0;
	unsigned char sum;
	/*
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
	*/
	ReadState();
	//delay_us(320000);
	if(DATA())// 或超时 (约2 sec.)
		error+=1;  
	WriteState();
	t[0]=ReadByte(ACK);
	t[1]=ReadByte(ACK);
	sum=ReadByte(noACK);

    //if(sum != CRC8_Table(t,2))
	 //error +=1;

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
void Calc_SHT1X(float *p_humidity ,float *p_temperature)   
// calculates temperature [C] and humidity [%RH]     
// input :  humi [Ticks] (12 bit)     
//          temp [Ticks] (14 bit)    
// output:  humi [%RH]    
//          temp [C]    
{ const float C1=-4.0;              // for 12 Bit (-4.0)    
  const float C2=+0.0405;           // for 12 Bit    
  const float C3=-0.0000028;        // for 12 Bit(-0.0000028)    
  const float T1=+0.01;             // for 14 Bit @ 5V    
  const float T2=+0.00008;           // for 14 Bit @ 5V     
   
  float rh=*p_humidity;             // rh:      Humidity [Ticks] 12 Bit     
  float t=*p_temperature;           // t:       Temperature [Ticks] 14 Bit    
  float rh_lin;                     // rh_lin:  Humidity linear    
  float rh_true;                    // rh_true: Temperature compensated humidity    
  float t_C;                        // t_C   :  Temperature [C]    
   
  t_C=t*0.01 - 40;                  //calc. temperature from ticks to [C]    
  rh_lin=C3*rh*rh + C2*rh + C1;     //calc. humidity from ticks to [%RH]    
  rh_true=(t_C-25)*(T1+T2*rh)+rh_lin;   //calc. temperature compensated humidity [%RH]    
  if(rh_true>99)rh_true=99;       //cut if the value is outside of//100    
  if(rh_true<0.1)rh_true=0.1;       //the physical possible range    
   
  *p_temperature=t_C;               //return temperature [C]    
  *p_humidity=rh_true;              //return humidity[%RH]    
}

//#define S_SHT1X_DILE       0x00
#define S_SHT1X_TEMP_START 0x01
#define S_SHT1X_TEMP_MEASU 0x02
//#define S_SHT1X_HUMI_START 0x02
#define S_SHT1X_HUMI_MEASU 0x03

INT8U Get_SHT1X_Temp_Humi(INT8U Flag, INT16S *pTemp, INT16S *pHumi)
{
  INT8U buf[5];
  float  humi;
  static S_Int8U state = {CHK_BYTE, S_SHT1X_TEMP_START, CHK_BYTE};
  static S_Float temp = {CHK_BYTE, 0, CHK_BYTE};;

  if(SHT1X_In_Flag EQ NO_SHT1X_FLAG)
    return 0;

  if(CHK_HT(temp) EQ 0 || CHK_HT(state) EQ 0)
    ASSERT_FAILED();

  if(state.Var EQ S_SHT1X_TEMP_START || Flag EQ 0) //起始状态或者初始化状态机
  {
    ConnectionReset();
	Measure_Start(TEMP);
	state.Var = S_SHT1X_TEMP_MEASU;

	return 0; 
  }
  else if(state.Var EQ S_SHT1X_TEMP_MEASU)
  {
    if(Measure(TEMP, buf) EQ 0)
	{
	  temp.Var = (float)((buf[0]<<8)+buf[1]);

      ConnectionReset();
	  Measure_Start(HUMI);

	  state.Var = S_SHT1X_HUMI_MEASU;
	}
	else
	  state.Var = S_SHT1X_TEMP_START;
	
	return 0;	
  }/*
  else if(state.Var EQ S_SHT1X_HUMI_START)
  {
    ConnectionReset();
	Measure_Start(HUMI);
	state.Var = S_SHT1X_HUMI_MEASU;

	return 0; 
  }*/
  else if(state.Var EQ S_SHT1X_HUMI_MEASU)
  {
    if(Measure(HUMI, buf) EQ 0)
	{
	  humi = (float)((buf[0]<<8)+buf[1]);
	  Calc_SHT1X(&humi, &temp.Var);	//校正温度和湿度

	  *pTemp = (INT16S)temp.Var * 10;
	  *pHumi = (INT16S)humi * 10;
      
	  ConnectionReset();
	  Measure_Start(TEMP);

	  state.Var = S_SHT1X_TEMP_MEASU;
	  return 1;	  
	}
	else
	  state.Var = S_SHT1X_TEMP_START;
	  
	return 0;
  }
  else
  {
	state.Var = S_SHT1X_TEMP_START;
	return 0;
  }
/*
  if(Measure(TEMP, buf) EQ 0)
  {
	temp = (float)((buf[0]<<8)+buf[1]);
	
	if(Measure(HUMI, buf) EQ 0)
	{
	  humi = (float)((buf[0]<<8)+buf[1]);
	  Calc_SHT1X(&humi, &temp);	//校正温度和湿度

	  *pTemp = (INT16S)temp * 10;
	  *pHumi = (INT16S)humi * 10;
	  return 1;
	}
  }
*/
  return 0;
}

INT8U Get_Humidity(INT16S *pHumidity)
{

  INT8U buf[5];

  if(SHT1X_In_Flag EQ NO_SHT1X_FLAG)
    return 0;

  ConnectionReset();

  Measure(HUMI, buf);

  //Screen_Status.Temperature = (u32)(((buf[0]<<8)+buf[1])*0.01-40);

  //Measure(HUMI, buf);

  return 0;
}

INT8U Chk_SHT1X_Sensor(void)
{
  if(SHT1X_In_Flag EQ EXIST_SHT1X_FLAG)
    return 1;
  else
    return 0;
}
#endif

