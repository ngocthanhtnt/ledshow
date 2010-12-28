
#define CS_BYTES 1
#define ROM_CS_BYTES 2
#define MAX_BORDER_POINTS (40*8)

#define QT_EN 0 //使用QT仿真

#if QT_EN == 0 //没有使能QT仿真 ---STM32的环境下
#define ASSERT_EN 1

#define MOVE_STEP_TIMER 10 //移动步进时间,单位为ms
#define MIN_STAY_TIME  10//每屏最小停留时间,单位为ms
#define MOVE_STEP 1 //每个调度单位移动的数据百分比 单位%

//----根据不同的屏幕和硬件配置下列项目
#define MAX_POINTS (1024*42L) //最大点数--此处是三色屏的最大点数！单色屏的点数在此基础上*3
#define MAX_PROG_NUM 10 //最大节目数
#define MAX_AREA_NUM 8 //每个节目下最大分区数
#define MAX_FILE_NUM 8 //每个分区下最大文件数
#define MAX_BLOCK_NUM  200 //显示数据块的大小
#define ONE_BLOCK_SIZE 250 //一个显示数据块的大小
#define MAX_OPEN_CLOSE_TIME 4 //最大开关机时段
#define MAX_LIGHTNESS_TIME 4 //最大亮度控制时段

#define BORDER_SHOW_EN 1 //边框显示使能
#define CLOCK_SHOW_EN  1 //时钟显示使能
#define PIC_SHOW_EN    1 //图文显示使能
#define LUN_SHOW_EN    1 //农历显示使能
#define TEMP_SHOW_EN   1 //温度显示使能
#define TIME_SHOW_EN   1 //时间显示使能
#define TIMER_SHOW_EN  1 //定时显示使能 

#else
#define ASSERT_EN 1

//显示效果配置
#define MOVE_STEP_TIMER 10 //移动步进时间,单位为ms
#define MIN_STAY_TIME  10//每屏最小停留时间,单位为ms
#define MOVE_STEP 1 //每个调度单位移动的数据百分比 单位%


//----根据不同的屏幕和硬件配置下列项目
#define MAX_POINTS (1024*256L) //最大点数--此处是三色屏的最大点数！单色屏的点数在此基础上*3
#define MAX_PROG_NUM 10 //最大节目数
#define MAX_AREA_NUM 8 //每个节目下最大分区数
#define MAX_FILE_NUM 8 //每个分区下最大文件数
#define MAX_BLOCK_NUM  200
#define ONE_BLOCK_SIZE 250
#define MAX_OPEN_CLOSE_TIME 4 //最大开关机时段
#define MAX_LIGHTNESS_TIME 4 //最大亮度控制时段

#define BORDER_SHOW_EN 1 //边框显示使能
#define CLOCK_SHOW_EN  1 //时钟显示使能
#define PIC_SHOW_EN    1 //图文显示使能
#define LUN_SHOW_EN    1 //农历显示使能
#define TEMP_SHOW_EN   1 //温度显示使能
#define TIME_SHOW_EN   1 //时间显示使能
#define TIMER_SHOW_EN  1 //定时显示使能 
#endif
