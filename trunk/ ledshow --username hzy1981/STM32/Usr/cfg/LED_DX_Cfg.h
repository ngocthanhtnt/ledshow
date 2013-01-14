#ifndef LED_DX_CFG_H
#define LED_DX_CFG_H
						 
//#define CARD_SUB_B0 0x00
//#define CARD_SUB_B1 0x01
//#define CARD_SUB_B2 0x02

//#define CARD_SUB_TYPE CARD_SUB_B0 //BX系列子卡类型

 //-------------------时钟相关配置---------------
#define HSE_VALUE 12000000 //外部晶振频率
#define HCLK_VALUE  HSE_VALUE*7
//#define H_HCLK_VALUE HSE_VALUE*9
#define PCLK1_VALUE HCLK_VALUE/2
#define PCLK2_VALUE	HCLK_VALUE/1

#define HCLK_MUL  RCC_PLLMul_7	//正常运行时AHB速度
#define PCLK1_DIV RCC_HCLK_Div2 //最高APB/2--这是正常运行时速度,这里不能为DIV1，因为定时器使用的分频系数默认PCLK1分频>1
#define PCLK2_DIV RCC_HCLK_Div1 //最高和AHB一样,注意SPIFlash的速度是APB2/2不能超过50M,CH376的速度是APB2/8不能超过24M

#define TIM1_EN 1

#define MAX_PROG_NUM 16 //最大节目数
#define MAX_AREA_NUM 8 //每个节目下最大分区数
#define MAX_FILE_NUM 50 //每个节目下最大文件数

//----------------------------------------
#if defined(CARD_D)
#if CARD_TYPE == CARDD //
#define CARD_NAME "D"  //卡名称
#elif CARD_TYPE == CARDDU
#define CARD_NAME "DU"  //卡名称
#elif CARD_TYPE == CARDDE
#define CARD_NAME "DE"  //卡名称
#elif CARD_TYPE == CARDDM
#define CARD_NAME "DM"  //卡名称
#else
#error "card DX name error"
#endif
#endif

#define SCAN_SCREEN_PERIOD 100//扫屏周期,单位us
#define MOVE_STEP_PERIOD 5//5 //移动步进时间,单位为ms
#define MOVE_STEP 1 //每个调度单位移动的数据百分比 单位%

#define IN_SPEC_EFFECT_NUM 86 //进入特效个数
#define OUT_SPEC_EFFECT_NUM 48 //退出特效个数
#define FONT_NUM 2 //内嵌字体个数

//----根据不同的屏幕和硬件配置下列项目
#define MAX_POINTS (1200*64) //最大点数--此处是双色屏的最大点数！单色屏的点数在此基础上*2
#define MAX_STORA_BLOCK_NUM  3000 //最大存储块数
#define DATA_FLASH_SIZE 2000000	//dataflash大小
#define MAX_SCAN_BLOCK_NUM 16 //最大扫描块
#define MAX_SCAN_WIDTH 2056 //最大扫描宽度

#define DATA_PREP_EN 0 //数据预准备
#define BUILD_SCAN_DATA_INDEX_EN 0 //构建扫描数据索引使能
#define SCAN_DATA_MODE SCAN_SOFT_MODE0 //0表示软件扫描方式，1表示硬件扫描方式

#define CLOCK_EN       1 //时钟使能

#define BORDER_SHOW_EN 1 //边框显示使能
#define PIC_SHOW_EN    1 //图文显示使能
#define CLOCK_SHOW_EN  1 //表盘显示使能
#define LUN_SHOW_EN    1 //农历显示使能
#define TEMP_SHOW_EN   1 //温度显示使能
#define TIME_SHOW_EN   1 //时间显示使能
#define TIMER_SHOW_EN  1 //定时显示使能 
#define HUMIDITY_SHOW_EN 1 //湿度显示使能
#define NOISE_SHOW_EN  1 //噪音显示使能
#define TXT_SHOW_EN    0

#define USE_SPI_FLASH //串行SPIFlash
//#define USE_NOR_FLASH //并行NORFlash
#if CARD_TYPE == CARDD
#define UDISK_EN  0//u盘使能
#define NET_EN	 0//网络使能
#elif CARD_TYPE == CARDDU
#define UDISK_EN  1//u盘使能
#define NET_EN	 0//网络使能
#elif CARD_TYPE == CARDDE
#define UDISK_EN  0//u盘使能
#define NET_EN	 1//网络使能
#elif CARD_TYPE == CARDDM
#define UDISK_EN  1//u盘使能
#define NET_EN	 1//网络使能
#endif

#define GPRS_EN  0//GPRS使能
#define SMS_EN   0//短信使能
//#define COM_BUF_ID 0x00
//#define NET_BUF_ID 0x01
//#define GPRS_BUF_ID 0x02



#define SHELL_EN 0//shell使能
//#if !defined (STM32F10X_LD)
//#define STM32F10X_LD
//#endif

#endif














