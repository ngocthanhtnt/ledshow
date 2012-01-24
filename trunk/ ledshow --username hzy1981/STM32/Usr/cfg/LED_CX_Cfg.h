#ifndef LED_CX_CFG_H
#define LED_CX_CFG_H
						 
//#define CARD_SUB_B0 0x00
//#define CARD_SUB_B1 0x01
//#define CARD_SUB_B2 0x02

//#define CARD_SUB_TYPE CARD_SUB_B0 //BX系列子卡类型

 //-------------------时钟相关配置---------------
#define HSE_VALUE 25000000 //外部晶振频率
#define HCLK_VALUE  72000000
//#define H_HCLK_VALUE HSE_VALUE*9
#define PCLK1_VALUE HCLK_VALUE/2
#define PCLK2_VALUE	HCLK_VALUE/1

#define HCLK_MUL  RCC_PLLMul_9	//正常运行时AHB速度
#define PCLK1_DIV RCC_HCLK_Div2 //最高APB/2--这是正常运行时速度,这里不能为DIV1，因为定时器使用的分频系数默认PCLK1分频>1
#define PCLK2_DIV RCC_HCLK_Div1 //最高和AHB一样,注意SPIFlash的速度是APB2/2不能超过50M,CH376的速度是APB2/8不能超过24M

#define TIM1_EN 1
//----------------------------------------
#if defined(CARD_C)
#define CARD_NAME "C"  //卡名称
#else
#error "card CX name error"
#endif

#define SCAN_SCREEN_PERIOD 100//扫屏周期,单位us
#define MOVE_STEP_PERIOD 5//5 //移动步进时间,单位为ms
#define MOVE_STEP 1 //每个调度单位移动的数据百分比 单位%

#define IN_SPEC_EFFECT_NUM 53 //进入特效个数
#define OUT_SPEC_EFFECT_NUM 22 //退出特效个数
#define FONT_NUM 1 //内嵌字体个数

//----根据不同的屏幕和硬件配置下列项目
#define MAX_POINTS (744*64) //最大点数--此处是双色屏的最大点数！单色屏的点数在此基础上*2
#define MAX_STORA_BLOCK_NUM  4000 //最大存储块数
#define MAX_SCAN_BLOCK_NUM 8 //最大扫描块
#define MAX_SCAN_WIDTH 2056 //最大扫描宽度

#define DATA_PREP_EN 0 //数据预准备
#define BUILD_SCAN_DATA_INDEX_EN 0 //构建扫描数据索引使能
#define SCAN_DATA_MODE SCAN_SOFT_MODE0 //0表示软件扫描方式，1表示硬件扫描方式

#define BORDER_SHOW_EN 1 //边框显示使能
#define PIC_SHOW_EN    1 //图文显示使能
#define CLOCK_SHOW_EN  1 //表盘显示使能
#define LUN_SHOW_EN    1 //农历显示使能
#define TEMP_SHOW_EN   1 //温度显示使能
#define TIME_SHOW_EN   1 //时间显示使能
#define TIMER_SHOW_EN  1 //定时显示使能 
#define HUMIDITY_SHOW_EN 0 //湿度显示使能
#define NOISE_SHOW_EN  0 //噪音显示使能

#define USE_SPI_FLASH //串行SPIFlash
//#define USE_NOR_FLASH //并行NORFlash

#define UDISK_EN  1//u盘使能
#define CHIP_USB_HOST //定义表示使用片上USB HOST接口
#define NET_EN	 0//网络使能
#define GPRS_EN  0//GPRS使能

//#define COM_BUF_ID 0x00
//#define NET_BUF_ID 0x01
//#define GPRS_BUF_ID 0x02



#define SHELL_EN 0//shell使能
//#if !defined (STM32F10X_LD)
//#define STM32F10X_LD
//#endif

#endif














