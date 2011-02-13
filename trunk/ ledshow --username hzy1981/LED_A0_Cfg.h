#define MOVE_STEP_TIMER 20 //移动步进时间,单位为ms
//#define MIN_STAY_TIME  10//每屏最小停留时间,单位为ms
#define MOVE_STEP 10 //每个调度单位移动的数据百分比 单位%

#define IN_SPEC_EFFECT_NUM 5 //进入特效个数
#define OUT_SPEC_EFFECT_NUM 5 //退出特效个数
#define FONT_NUM 1 //内嵌字体个数

//----根据不同的屏幕和硬件配置下列项目
#define MAX_POINTS (256*32L) //最大点数--此处是三色屏的最大点数！单色屏的点数在此基础上*3
#define MAX_PROG_NUM 10 //最大节目数
#define MAX_AREA_NUM 5 //每个节目下最大分区数
#define MAX_FILE_NUM 8 //每个分区下最大文件数
#define MAX_BLOCK_NUM  4000 //显示数据块的大小
#define BLOCK_DATA_LEN 249 //一个显示数据块的大小
#define MAX_OPEN_CLOSE_TIME 4 //最大开关机时段
#define MAX_LIGHTNESS_TIME 4 //最大亮度控制时段

#define BORDER_SHOW_EN 1 //边框显示使能
#define CLOCK_SHOW_EN  1 //表盘显示使能
#define PIC_SHOW_EN    1 //图文显示使能
#define LUN_SHOW_EN    1 //农历显示使能
#define TEMP_SHOW_EN   1 //温度显示使能
#define TIME_SHOW_EN   1 //时间显示使能
#define TIMER_SHOW_EN  1 //定时显示使能