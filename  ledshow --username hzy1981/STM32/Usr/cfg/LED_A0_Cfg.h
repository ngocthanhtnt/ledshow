#define MOVE_STEP_TIMER 20 //移动步进时间,单位为ms
//#define MIN_STAY_TIME  10//每屏最小停留时间,单位为ms
#define MOVE_STEP 10 //每个调度单位移动的数据百分比 单位%

#define IN_SPEC_EFFECT_NUM 5 //进入特效个数
#define OUT_SPEC_EFFECT_NUM 5 //退出特效个数
#define FONT_NUM 1 //内嵌字体个数

//----根据不同的屏幕和硬件配置下列项目
#define MAX_POINTS (256*32L) //最大点数--此处是三色屏的最大点数！单色屏的点数在此基础上*3
#define MAX_BLOCK_NUM  4000 //最大存储块数
#define MAX_SCAN_BLOCK_NUM 8 //最大扫描块

#define DATA_PREP_EN 0 //数据预准备

#define BORDER_SHOW_EN 1 //边框显示使能
#define PIC_SHOW_EN    1 //图文显示使能
#define CLOCK_SHOW_EN  0 //表盘显示使能
#define LUN_SHOW_EN    0 //农历显示使能
#define TEMP_SHOW_EN   0 //温度显示使能
#define TIME_SHOW_EN   0 //时间显示使能
#define TIMER_SHOW_EN  0 //定时显示使能 
#define HUMIDITY_SHOW_EN 0 //湿度显示使能
#define NOISE_SHOW_EN  0 //噪音显示使能















