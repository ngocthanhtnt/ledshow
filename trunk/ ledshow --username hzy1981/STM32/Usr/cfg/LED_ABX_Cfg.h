#ifndef LED_ABX_CFG_H
#define LED_ABX_CFG_H
						 
//#define CARD_SUB_A0 0x00
//#define CARD_SUB_A1 0x01
//#define CARD_SUB_A2 0x02

//#define CARD_SUB_TYPE CARD_SUB_A0 //AX系列子卡类型

 //-------------------时钟相关配置---------------
#ifdef CARD_A
#define HSE_VALUE 12000000 //外部晶振频率
#define HCLK_VALUE  HSE_VALUE*2
//#define H_HCLK_VALUE HSE_VALUE*9
#define PCLK1_VALUE HCLK_VALUE/2
#define PCLK2_VALUE	HCLK_VALUE/1

#define HCLK_MUL  RCC_PLLMul_2	//正常运行时AHB速度
#define PCLK1_DIV RCC_HCLK_Div2 //最高APB/2--这是正常运行时速度,这里不能为DIV1，因为定时器使用的分频系数默认PCLK1分频>1
#define PCLK2_DIV RCC_HCLK_Div1 //最高和AHB一样,注意SPIFlash的速度是APB2/2不能超过50M,CH376的速度是APB2/8不能超过24M

#define TIM1_EN 0
#define SCAN_SCREEN_PERIOD 300//扫屏周期,单位us

#elif defined(CARD_B)
#define HSE_VALUE 12000000 //外部晶振频率
#define HCLK_VALUE  HSE_VALUE*6
//#define H_HCLK_VALUE HSE_VALUE*9
#define PCLK1_VALUE HCLK_VALUE/2
#define PCLK2_VALUE	HCLK_VALUE/1

#define HCLK_MUL  RCC_PLLMul_6	//正常运行时AHB速度
#define PCLK1_DIV RCC_HCLK_Div2 //最高APB/2--这是正常运行时速度,这里不能为DIV1，因为定时器使用的分频系数默认PCLK1分频>1
#define PCLK2_DIV RCC_HCLK_Div1 //最高和AHB一样,注意SPIFlash的速度是APB2/2不能超过50M,CH376的速度是APB2/4不能超过24M

#define TIM1_EN 1
#define SCAN_SCREEN_PERIOD 100//扫屏周期,单位us

#endif
//#define H_HCLK_MUL  RCC_PLLMul_9  //高速运行时AHB速度
//#define H_PCLK1_DIV RCC_HCLK_Div2 //高速运行时APB1速度--确保和正常运行时保持一致，这样就不需要调整各外设的Clock 
//#define H_PCLK2_DIV RCC_HCLK_Div1 //高速运行时APB2速度--确保和正常运行时保持一致，这样就不需要调整各外设的Clock 
#define MAX_PROG_NUM 16 //最大节目数
#define MAX_FILE_NUM 50 //每个节目下最大文件数

#if defined(CARD_A)
#define MAX_AREA_NUM 4 //每个节目下最大分区数
#else
#define MAX_AREA_NUM 6 //每个节目下最大分区数
#endif

//----------------------------------------
#if defined(CARD_A)
#if CARD_TYPE == CARDA0 //A0型卡是最低端卡，不支持时钟,其他类型卡均支持
#define CARD_NAME "A0"  //卡名称
#elif CARD_TYPE == CARDA1
#define CARD_NAME "A1"  //卡名称
#elif CARD_TYPE == CARDA2
#define CARD_NAME "A2"  //卡名称
#else
#error "card AX name error"
#endif
#elif defined(CARD_B)
#if CARD_TYPE == CARDB1 //A0型卡是最低端卡，不支持时钟,其他类型卡均支持
#define CARD_NAME "B1"  //卡名称
#else
#error "card BX name error"
#endif
#endif

#define MOVE_STEP_PERIOD 20//5 //移动步进时间,单位为ms
#define MOVE_STEP 1 //每个调度单位移动的数据百分比 单位%

//----根据不同的屏幕和硬件配置下列项目
#ifdef CARD_A
/*
#if CARD_TYPE == CARDA0
#define MAX_POINTS (144*64) //最大点数--此处是双色屏的最大点数！单色屏的点数在此基础上*2
#else//if CARD_TYPE == CARDA1
#define MAX_POINTS (184*64) //最大点数--此处是双色屏的最大点数！单色屏的点数在此基础上*2
#endif
*/
#define MAX_POINTS (128*64) //最大点数--此处是双色屏的最大点数！单色屏的点数在此基础上*2

#define MAX_STORA_BLOCK_NUM  1600 //最大存储块数
#define FONT_NUM 1 //内嵌字体个数
#define DATA_FLASH_SIZE (1*1024*1024) //dataflash大小

#define IN_SPEC_EFFECT_NUM 35 //进入特效个数
#define OUT_SPEC_EFFECT_NUM 25 //退出特效个数

#elif defined(CARD_B)
#define MAX_POINTS (504*64) //最大点数--此处是双色屏的最大点数！单色屏的点数在此基础上*2
#define MAX_STORA_BLOCK_NUM  3200 //最大存储块数
#define FONT_NUM 2 //内嵌字体个数
#define DATA_FLASH_SIZE (2*1024*1024)	//dataflash大小

#define IN_SPEC_EFFECT_NUM 86 //进入特效个数
#define OUT_SPEC_EFFECT_NUM 48 //退出特效个数

#endif

#define MAX_SCAN_BLOCK_NUM 4 //最大扫描块

#define DATA_PREP_EN 0 //数据预准备
#define BUILD_SCAN_DATA_INDEX_EN 0 //构建扫描数据索引使能
#define SCAN_DATA_MODE SCAN_SOFT_MODE0 //0表示软件扫描方式，1表示硬件扫描方式

#if CARD_TYPE == CARDA0 //A0型卡是最低端卡，不支持时钟,其他类型卡均支持
#define CLOCK_EN       0 //是否有时钟功能
#else
#define CLOCK_EN       1
#endif

#ifdef CARD_A //A类卡，因为程序空间问题，没有农历显示
#if CLOCK_EN
#define CLOCK_SHOW_EN  0 //表盘显示使能
#define TIME_SHOW_EN   1 //时间显示使能
#define TIMER_SHOW_EN  1 //定时显示使能
#define LUN_SHOW_EN    0 //农历显示使能
#else //A0类型卡没有时间
#define CLOCK_SHOW_EN  0 //表盘显示使能
#define TIME_SHOW_EN   0 //时间显示使能
#define TIMER_SHOW_EN  0 //定时显示使能
#define LUN_SHOW_EN    0 //农历显示使能
#endif
#define BORDER_SHOW_EN 1 //边框显示使能
#define PIC_SHOW_EN    1 //图文显示使能
#define TEMP_SHOW_EN   1 //温度显示使能
#define HUMIDITY_SHOW_EN 0 //湿度显示使能
#define NOISE_SHOW_EN  0 //噪音显示使能
#define TXT_SHOW_EN    0
#else
#define BORDER_SHOW_EN 1 //边框显示使能
#define PIC_SHOW_EN    1 //图文显示使能
#define CLOCK_SHOW_EN  1 //表盘显示使能
#define LUN_SHOW_EN    1 //农历显示使能
#define TEMP_SHOW_EN   1 //温度显示使能
#define TIME_SHOW_EN   1 //时间显示使能
#define TIMER_SHOW_EN  1 //定时显示使能 
#define HUMIDITY_SHOW_EN 1 //湿度显示使能
#define NOISE_SHOW_EN  0 //噪音显示使能
#define TXT_SHOW_EN    0
#endif

#define USE_SPI_FLASH //串行SPIFlash
//#define USE_NOR_FLASH //并行NORFlash

#define UDISK_EN  0//u盘使能
#define NET_EN	 0//网络使能
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














