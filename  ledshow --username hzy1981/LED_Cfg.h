
#define CS_BYTES 1
#define ROM_CS_BYTES 2
#define MAX_BORDER_POINTS (40*8)
#define MAX_LIGHTNESS_LEVEL 16

#define MAX_PROG_NUM 10 //最大节目数
#define MAX_AREA_NUM 8 //每个节目下最大分区数
#define MAX_FILE_NUM 8 //每个分区下最大文件数
#define BLOCK_DATA_LEN 489 //每块数据的大小
#define MAX_OPEN_CLOSE_TIME 4 //最大开关机时段
#define MAX_LIGHTNESS_TIME 4 //最大亮度控制时段

#define CARD_A0 0x00
#define CARD_B0 0x01
#define CARD_C0 0x02
#define CARD_D0 0x03
#define CARD_E0 0x04

//节目特征字
#define BORDER_SHOW_BIT 0x00
#define PIC_SHOW_BIT    0x01
#define CLOCK_SHOW_BIT  0x02
#define TIME_SHOW_BIT   0x03
#define TIMER_SHOW_BIT  0x04
#define LUN_SHOW_BIT    0x05
#define TEMP_SHOW_BIT   0x06
#define HUMIDITY_SHOW_BIT 0x07
#define NOISE_SHOW_BIT  0x08

#define QT_EN 1 //使用QT仿真

#if QT_EN == 0 //没有使能QT仿真 ---STM32的环境下
#define ASSERT_EN 1
#define CARD_TYPE CARD_A0

#include "STM32.h"

#if CARD_TYPE == CARD_A0
#include "LED_A0_Cfg.h"
#include "LED_A0_Drv.h"
#elif CARD_TYPE == CARD_B0
#include "LED_B0_Cfg.h"
#include "LED_B0_Drv.h"
#elif CARD_TYPE == CARD_C0
#include "LED_C0_Cfg.h"
#include "LED_C0_Drv.h"
#elif CARD_TYPE == CARD_D0
#include "LED_D0_Cfg.h"
#include "LED_D0_Drv.h"
#elif CARD_TYPE == CARD_E0
#include "LED_E0_Cfg.h"
#include "LED_E0_Drv.h"
#else
#error "Card type error"
#endif

//节目特征字
#define FILE_EN_WORD ((BORDER_SHOW_EN<<BORDER_SHOW_BIT) |\
                       (PIC_SHOW_EN << PIC_SHOW_BIT) |\
                       (CLOCK_SHOW_EN<<CLOCK_SHOW_BIT) |\
                       (TIME_SHOW_EN << TIME_SHOW_BIT) |\
                       (TIMER_SHOW_EN << TIMER_SHOW_BIT) |\
                       (LUN_SHOW_EN << LUN_SHOW_BIT) |\
                       (TEMP_SHOW_EN << TEMP_SHOW_BIT) |\
                       (HUMIDITY_SHOW_EN << HUMIDITY_SHOW_BIT) |\
                       (NOISE_SHOW_EN << NOISE_SHOW_BIT))L

#else

#include "QT_SIM.h"

#define ASSERT_EN 1

#define APP_NAME "LED播放系统"
//显示效果配置
#define MOVE_STEP_TIMER 40 //移动步进时间,单位为ms
//#define MIN_STAY_TIME  10//每屏最小停留时间,单位为ms
#define MOVE_STEP 2 //每个调度单位移动的数据百分比 单位%

#define IN_SPEC_EFFECT_NUM 43 //进入特效个数
#define OUT_SPEC_EFFECT_NUM 19 //退出特效个数
#define FONT_NUM 2 //内嵌字体个数

//----根据不同的屏幕和硬件配置下列项目
#define MAX_POINTS (1024*256L) //最大点数--此处是三色屏的最大点数！单色屏的点数在此基础上*3

#define DATA_PREP_EN 0
#define MAX_BLOCK_NUM  4000
#define MAX_SCAN_BLOCK_NUM 10

#define BORDER_SHOW_EN 1 //边框显示使能
#define CLOCK_SHOW_EN  1 //表盘显示使能
#define PIC_SHOW_EN    1 //图文显示使能
#define LUN_SHOW_EN    1 //农历显示使能
#define TEMP_SHOW_EN   1 //温度显示使能
#define TIME_SHOW_EN   1 //时间显示使能
#define TIMER_SHOW_EN  1 //定时显示使能 
#define HUMIDITY_SHOW_EN 1
#define NOISE_SHOW_EN  1

#endif

