#include <QtGui/QApplication>
#include <QDesktopWidget>
#include <QPainter>
#include <QTextCodec>
#include <QDir>
#include <QMessageBox>
#include <QTime>
#include <QSystemSemaphore>
#include <QSharedMemory>
#include "mainwindow.h"
#include "textedit.h"
#include <Winbase.h>

MainWindow *w;
MainObj *mainObj;

/*
#define BORDER_SHOW_EN 1 //边框显示使能
#define CLOCK_SHOW_EN  0 //表盘显示使能
#define PIC_SHOW_EN    1 //图文显示使能
#define LUN_SHOW_EN    0 //农历显示使能
#define TEMP_SHOW_EN   0 //温度显示使能
#define TIME_SHOW_EN   1 //时间显示使能
#define TIMER_SHOW_EN  0 //定时显示使能
 */

/*
#define COM_RS232 0x01
#define COM_RS485 0x02
#define COM_UDISK 0x04
#define COM_ETH   0x08
#define COM_GPRS  0x10
 */
void resetCardtoCardParaFile()
{
  QSettings cardIniFile(CARD_INI_FILE,QSettings::IniFormat,0);

  cardIniFile.clear();
/*
  cardIniFile.beginGroup(QString(COMPANY_NAME) + "-A0");
  cardIniFile.setValue("maxPoints", 384*64);
  cardIniFile.setValue("flag", 0); //第0位表示是否支持全彩
  cardIniFile.setValue("maxHeight", 64);
  cardIniFile.setValue("maxAreaNum", 4);
  cardIniFile.setValue("FontNum", 1);
  cardIniFile.setValue("inModeNum", 35);
  cardIniFile.setValue("outModeNum", 25);
  cardIniFile.setValue("romSize", 1024);
  cardIniFile.setValue("fileEnWord", ((0x01<<BORDER_SHOW_BIT) |\
                                      (0x01 << PIC_SHOW_BIT) |\
                                      (0x01 << TEMP_SHOW_BIT) |\
                                      (0x01 << TXT_SHOW_EN)));

  cardIniFile.setValue("comMode", COM_RS232);
  cardIniFile.endGroup();
*/
  cardIniFile.beginGroup(QString(COMPANY_NAME) + "-A1");
  cardIniFile.setValue("maxPoints", 256*64);
  cardIniFile.setValue("flag", 0); //第0位表示是否支持全彩
  cardIniFile.setValue("maxHeight", 64);
  cardIniFile.setValue("maxAreaNum", 4);
  cardIniFile.setValue("FontNum", 1);
  cardIniFile.setValue("inModeNum", 35);
  cardIniFile.setValue("outModeNum", 25);
  cardIniFile.setValue("romSize", 1024);
  cardIniFile.setValue("fileEnWord", ((0x01<<BORDER_SHOW_BIT) |\
                                      (0x01 << PIC_SHOW_BIT) |\
                                      (0x01<<CLOCK_BIT) |\
                                      (0x01 << TIME_SHOW_BIT) |\
                                      (0x01 << TIMER_SHOW_BIT) |\
                                      (0x01 << TEMP_SHOW_BIT)));

  cardIniFile.setValue("comMode", COM_RS232);
  cardIniFile.endGroup();

  cardIniFile.beginGroup(QString(COMPANY_NAME) + "-B1");
  cardIniFile.setValue("maxPoints", 1008*64);
  cardIniFile.setValue("flag", 0); //第0位表示是否支持全彩
  cardIniFile.setValue("maxHeight", 64);
  cardIniFile.setValue("maxAreaNum", 6);
  cardIniFile.setValue("FontNum", 2);
  cardIniFile.setValue("inModeNum", IN_SPEC_EFFECT_NUM);
  cardIniFile.setValue("outModeNum", OUT_SPEC_EFFECT_NUM);
  cardIniFile.setValue("romSize", 2048);
  cardIniFile.setValue("fileEnWord", ((0x01<<BORDER_SHOW_BIT) |\
                                      (0x01 << PIC_SHOW_BIT) |\
                                      (0x01<<CLOCK_BIT) |\
                                      (0x01<<CLOCK_SHOW_BIT) |\
                                      (0x01 << TIME_SHOW_BIT) |\
                                      (0x01 << TIMER_SHOW_BIT) |\
                                      (0x01 << LUN_SHOW_BIT) |\
                                      (0x01 << TEMP_SHOW_BIT) |\
                                      (0x01 << HUMIDITY_SHOW_BIT)));

  cardIniFile.setValue("comMode", COM_RS232);
  cardIniFile.endGroup();

  cardIniFile.beginGroup(QString(COMPANY_NAME) + "-CU1");
  cardIniFile.setValue("maxPoints", 1472*64);
  cardIniFile.setValue("flag", 0);
  cardIniFile.setValue("maxHeight", 128);
  cardIniFile.setValue("maxAreaNum", 6);
  cardIniFile.setValue("FontNum", 2);
  cardIniFile.setValue("inModeNum", IN_SPEC_EFFECT_NUM);
  cardIniFile.setValue("outModeNum", OUT_SPEC_EFFECT_NUM);
  cardIniFile.setValue("romSize", 2048);
  cardIniFile.setValue("fileEnWord", ((0x01<<BORDER_SHOW_BIT) |\
                                      (0x01 << PIC_SHOW_BIT) |\
                                      (0x01<<CLOCK_BIT) |\
                                      (0x01<<CLOCK_SHOW_BIT) |\
                                      (0x01 << TIME_SHOW_BIT) |\
                                      (0x01 << TIMER_SHOW_BIT) |\
                                      (0x01 << LUN_SHOW_BIT) |\
                                      (0x01 << TEMP_SHOW_BIT) |\
                                      (0x01 << HUMIDITY_SHOW_BIT)));

  cardIniFile.setValue("comMode", COM_RS232 | COM_UDISK);
  cardIniFile.endGroup();

  cardIniFile.beginGroup(QString(COMPANY_NAME) + "-CW1");
  cardIniFile.setValue("maxPoints", 1600*64);
  cardIniFile.setValue("flag", 0);
  cardIniFile.setValue("maxHeight", 128);
  cardIniFile.setValue("maxAreaNum", 6);
  cardIniFile.setValue("FontNum", 2);
  cardIniFile.setValue("inModeNum", IN_SPEC_EFFECT_NUM);
  cardIniFile.setValue("outModeNum", OUT_SPEC_EFFECT_NUM);
  cardIniFile.setValue("romSize", 4096);
  cardIniFile.setValue("fileEnWord", ((0x01<<BORDER_SHOW_BIT) |\
                                      (0x01 << PIC_SHOW_BIT) |\
                                      (0x01<<CLOCK_BIT) |\
                                      (0x01<<CLOCK_SHOW_BIT) |\
                                      (0x01 << TIME_SHOW_BIT) |\
                                      (0x01 << TIMER_SHOW_BIT) |\
                                      (0x01 << LUN_SHOW_BIT) |\
                                      (0x01 << TEMP_SHOW_BIT) |\
                                      (0x01 << HUMIDITY_SHOW_BIT)));

  cardIniFile.setValue("comMode", COM_RS232 | COM_UDISK | COM_SMS);
  cardIniFile.endGroup();

  cardIniFile.beginGroup(QString(COMPANY_NAME) + "-CW2");
  cardIniFile.setValue("maxPoints", 1600*64);
  cardIniFile.setValue("flag", 0);
  cardIniFile.setValue("maxHeight", 128);
  cardIniFile.setValue("maxAreaNum", 6);
  cardIniFile.setValue("FontNum", 2);
  cardIniFile.setValue("inModeNum", IN_SPEC_EFFECT_NUM);
  cardIniFile.setValue("outModeNum", OUT_SPEC_EFFECT_NUM);
  cardIniFile.setValue("romSize", 4096);
  cardIniFile.setValue("fileEnWord", ((0x01<<BORDER_SHOW_BIT) |\
                                      (0x01 << PIC_SHOW_BIT) |\
                                      (0x01<<CLOCK_BIT) |\
                                      (0x01<<CLOCK_SHOW_BIT) |\
                                      (0x01 << TIME_SHOW_BIT) |\
                                      (0x01 << TIMER_SHOW_BIT) |\
                                      (0x01 << LUN_SHOW_BIT) |\
                                      (0x01 << TEMP_SHOW_BIT) |\
                                      (0x01 << HUMIDITY_SHOW_BIT)));
  cardIniFile.setValue("comMode", COM_RS232 | COM_UDISK | COM_GPRS);
  cardIniFile.endGroup();

  cardIniFile.beginGroup(QString(COMPANY_NAME) + "-D");
  cardIniFile.setValue("maxPoints", 2400*64);
  cardIniFile.setValue("flag", 0);
  cardIniFile.setValue("maxHeight", 256);
  cardIniFile.setValue("maxAreaNum", 8);
  cardIniFile.setValue("FontNum", 2);
  cardIniFile.setValue("inModeNum", IN_SPEC_EFFECT_NUM);
  cardIniFile.setValue("outModeNum", OUT_SPEC_EFFECT_NUM);
  cardIniFile.setValue("romSize", 2048);
  cardIniFile.setValue("fileEnWord", ((0x01<<BORDER_SHOW_BIT) |\
                                      (0x01 << PIC_SHOW_BIT) |\
                                      (0x01<<CLOCK_BIT) |\
                                      (0x01<<CLOCK_SHOW_BIT) |\
                                      (0x01 << TIME_SHOW_BIT) |\
                                      (0x01 << TIMER_SHOW_BIT) |\
                                      (0x01 << LUN_SHOW_BIT) |\
                                      (0x01 << TEMP_SHOW_BIT)|\
                                      (0x01 << HUMIDITY_SHOW_BIT) |\
                                      (0x01 << NOISE_SHOW_BIT)));
  cardIniFile.setValue("comMode", COM_RS232);
  cardIniFile.endGroup();

  cardIniFile.beginGroup(QString(COMPANY_NAME) + "-DU");
  cardIniFile.setValue("maxPoints", 2400*64);
  cardIniFile.setValue("flag", 0);
  cardIniFile.setValue("maxHeight", 256);
  cardIniFile.setValue("maxAreaNum", 8);
  cardIniFile.setValue("FontNum", 2);
  cardIniFile.setValue("inModeNum", IN_SPEC_EFFECT_NUM);
  cardIniFile.setValue("outModeNum", OUT_SPEC_EFFECT_NUM);
  cardIniFile.setValue("romSize", 2048);
  cardIniFile.setValue("fileEnWord", ((0x01<<BORDER_SHOW_BIT) |\
                                      (0x01 << PIC_SHOW_BIT) |\
                                      (0x01<<CLOCK_BIT) |\
                                      (0x01<<CLOCK_SHOW_BIT) |\
                                      (0x01 << TIME_SHOW_BIT) |\
                                      (0x01 << TIMER_SHOW_BIT) |\
                                      (0x01 << LUN_SHOW_BIT) |\
                                      (0x01 << TEMP_SHOW_BIT)|\
                                      (0x01 << HUMIDITY_SHOW_BIT) |\
                                      (0x01 << NOISE_SHOW_BIT)));
  cardIniFile.setValue("comMode", COM_RS232 | COM_UDISK);
  cardIniFile.endGroup();

  cardIniFile.beginGroup(QString(COMPANY_NAME) + "-DE");
  cardIniFile.setValue("maxPoints", 2400*64);
  cardIniFile.setValue("flag", 0);
  cardIniFile.setValue("maxHeight", 256);
  cardIniFile.setValue("maxAreaNum", 8);
  cardIniFile.setValue("FontNum", 2);
  cardIniFile.setValue("inModeNum", IN_SPEC_EFFECT_NUM);
  cardIniFile.setValue("outModeNum", OUT_SPEC_EFFECT_NUM);
  cardIniFile.setValue("romSize", 2048);
  cardIniFile.setValue("fileEnWord", ((0x01<<BORDER_SHOW_BIT) |\
                                      (0x01 << PIC_SHOW_BIT) |\
                                      (0x01<<CLOCK_BIT) |\
                                      (0x01<<CLOCK_SHOW_BIT) |\
                                      (0x01 << TIME_SHOW_BIT) |\
                                      (0x01 << TIMER_SHOW_BIT) |\
                                      (0x01 << LUN_SHOW_BIT) |\
                                      (0x01 << TEMP_SHOW_BIT) |\
                                      (0x01 << HUMIDITY_SHOW_BIT) |\
                                      (0x01 << TXT_SHOW_BIT) |\
                                      (0x01 << NOISE_SHOW_BIT)));
  cardIniFile.setValue("comMode", COM_RS232 | COM_ETH);
  cardIniFile.endGroup();

  cardIniFile.beginGroup(QString(COMPANY_NAME) + "-DM");
  cardIniFile.setValue("maxPoints", 2400*64);
  cardIniFile.setValue("flag", 0);
  cardIniFile.setValue("maxHeight", 256);
  cardIniFile.setValue("maxAreaNum", 8);
  cardIniFile.setValue("FontNum", 2);
  cardIniFile.setValue("inModeNum", IN_SPEC_EFFECT_NUM);
  cardIniFile.setValue("outModeNum", OUT_SPEC_EFFECT_NUM);
  cardIniFile.setValue("romSize", 2048);
  cardIniFile.setValue("fileEnWord", ((0x01<<BORDER_SHOW_BIT) |\
                                      (0x01 << PIC_SHOW_BIT) |\
                                      (0x01<<CLOCK_BIT) |\
                                      (0x01<<CLOCK_SHOW_BIT) |\
                                      (0x01 << TIME_SHOW_BIT) |\
                                      (0x01 << TIMER_SHOW_BIT) |\
                                      (0x01 << LUN_SHOW_BIT) |\
                                      (0x01 << TEMP_SHOW_BIT) |\
                                      (0x01 << HUMIDITY_SHOW_BIT) |\
                                      (0x01 << TXT_SHOW_BIT) |\
                                      (0x01 << NOISE_SHOW_BIT)));
  cardIniFile.setValue("comMode", COM_RS232 | COM_UDISK | COM_ETH);
  cardIniFile.endGroup();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //设置为支持中文---重要
    QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));
    QFont font(QObject::tr("新宋体"),9,QFont::Normal,FALSE);
    a.setFont(font);

    QSystemSemaphore sema("led designer",1,QSystemSemaphore::Open);
    sema.acquire();// 在临界区操作共享内存SharedMemory
    QSharedMemory mem("led");// 全局对象名
    if (!mem.create(1))// 如果全局对象以存在则退出
    {
        QMessageBox::information(0, QObject::tr("提示"),QObject::tr("请勿重复运行该程序!"));
        sema.release();
        return 0;
    }
    sema.release();

    fontFileOpen();

#ifdef QT_DEBUG
    qDebug("reset card para file");
    resetCardtoCardParaFile();
#endif

    QDir dataDir;
    if(dataDir.exists(".\\data") == false)
        dataDir.mkdir(".\\data");

    if(dataDir.exists(".\\cfg") == false)
        dataDir.mkdir(".\\cfg");


    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    /*
    Screen_Para.Base_Para.Width = DEF_SCN_WIDTH;
    Screen_Para.Base_Para.Height = DEF_SCN_HEIGHT;
    Screen_Para.Base_Para.Color = 0x03;

    Card_Para.Max_Points = MAX_POINTS;
    Card_Para.Prog_Num = 8;
    Card_Para.Area_Num = 8;
    Card_Para.File_Num = 8;
    Card_Para.Font_Num = 1;
    Card_Para.File_En_Word = 0xFF;
*/
    memset(Show_Data.Color_Data, 0, sizeof(Show_Data.Color_Data));
    memset(Show_Data_Bak.Color_Data, 0, sizeof(Show_Data_Bak.Color_Data));
    //-------------

    mainObj = new MainObj;
    w = new MainWindow;
    QRect desktopRect = QApplication::desktop()->availableGeometry();
    w->style()->pixelMetric(QStyle::PM_TitleBarHeight);  // 获取标题栏高度

    //w->setGeometry(0, iTitleBarHeight, desktopRect.width(), desktopRect.height() - iTitleBarHeight);  // 设置窗体充满桌面客户区
    //w->setFixedSize(desktopRect.width(), desktopRect.height() - iTitleBarHeight);      // 固定窗体大小

    w->progManage->settingsInit();
    /*
    if(w->progManage->treeWidget->topLevelItemCount()>0)
    {
      w->progManage->clickItem(w->progManage->treeWidget->topLevelItem(0), 0);
    }
    */
    //w->progManage->newProg();
    //w->progManage->newArea();

    QObject::connect(w->mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)),
            w, SLOT(updateTreeWidget(QMdiSubWindow*)));
    QObject::connect(w->progManage->treeWidget,SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)),w->progManage,SLOT(currentItemChangedProc(QTreeWidgetItem*,QTreeWidgetItem*)));
    QObject::connect(w->progManage->treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)), w->progManage, SLOT(itemCheckStateChangedProc(QTreeWidgetItem*,int)));
    //traversalControl(w->children());
    //w->show();
    w->showMaximized();
    //w->comStatus->showFullScreen();//showNormal();
    return a.exec();

}


#if 0
#include "..\Stm32\usr\app\Includes.h"
//#include "Pub.h"

#define TEST_SEM0_ID 0
#define TEST_SEM1_ID 1
#define TEST_SEM2_ID 2
#define TEST_SEM3_ID 3
#define TEST_SEM4_ID 4
#define TEST_SEM5_ID 5
#define TEST_MSG_Q_ID 6

#define MAX_COMMAND_NUM    2

extern INT8U Print(INT8U argc, INT8S *argv[])
{
  INT8U i;

  for(i = 0; i < argc; i ++)
  {
    printf("arg %d:%s",i, argv[i]);
  }

  return 1;
}

extern CONST S_OS_Shell_Cmd OS_Shell_Cmd[MAX_COMMAND_NUM] =
{
  {/*.pName = */"Printxx", /*.pCmdFunc = */0},
  {/*.pName = */"Print", /*.pCmdFunc = */&Print}

};

INT8S Cmd_Buf[20] = {"Print aa bb cc\r"};

OS_INT8U Test_Buf[10];

/*
#define MSG_MAX_LEN 20
#define MSG_MEM_SIZE (MSG_MAX_LEN+MSG_RESERVE_SIZE)

typedef struct
{
  OS_INT32U Head;
  OS_INT8U Buf[5][MSG_MEM_SIZE];
  OS_INT32U Tail;
}S_Msg_Buf;

S_Msg_Buf _Msg_Buf;

S_Msg_Q_Info Msg_Q={CHK_BYTE,OS_MSG_Q,0xFFFF,{0},0,5,MSG_MEM_SIZE,_Msg_Buf.Buf,{0},CHK_BYTE};
*/

DECLARE_MSG_Q(Test11,3+7,5+5,0xFF);
/*
#define Msg_Num 10
#define Msg_Len 12
#define Rcv_Flag 0xFF
typedef struct{\
             OS_INT32U Head;\
             OS_INT8U Buf[Msg_Num][Msg_Len+MSG_RESERVE_SIZE];\
             OS_INT32U Tail;\
             }S_XXQ_Info_NameXX_Buf;\
S_XXQ_Info_NameXX_Buf XXQ_Info_NameXX_Buf={.Head=CHK_BYTE,\
  .Tail=CHK_BYTE;\
              };\
S_Msg_Q_Info Q_Info_Name={\
              .Head=CHK_BYTE,\
              .Msg_Flag=OS_MSG_Q;\
              .Msg_Rcv_Flag=Rcv_Flag;\
              .Msg_Max_Num=Msg_Num;\
              .Msg_Mem_Size=Msg_Len+MSG_RESERVE_SIZE;\
              .Msg=XXQ_Info_NameXX_Buf.Buf;\
              .Tail=CHK_BYTE;};
*/

//Tick钩子函数，注意：该函数中不能调用操作系统提供的调用
void OS_Tick_Hook(void)
{
 OS_Mem_Use_Time_Stat(OS_MS_PER_TICK);

}




//打印复位前的任务堆栈使用情况,在所有任务都已经创建好后才能调用该函数
//打印所有任务堆栈信息
void Print_Task_Stk_Left()
{
  OS_INT8U i,Task_Num;

  Task_Num=OS_Get_Cur_Task_Num();
  for(i=0;i<Task_Num;i++)
    Debug_Print("Task %d Stack Left:%d\r\n",i,OS_Get_Task_Stk_Left(i));
}

#define EXT_NULL
DECLARE_HT_VAR(EXT_NULL,INT8U,a);
void Task1()
{

    while(1)
    {
      OS_TimeDly_Ms(100);
      Debug_Print("tas1 run");
    }
}

void Task2()
{
    while(1)
    {
      OS_TimeDly_Ms(200);
      Debug_Print("tas2 run");
    }
}

void Task3()
{
    while(1)
    {
      OS_TimeDly_Ms(300);
      Debug_Print("tas3 run");
    }
}

#define TASK_STK_SIZE 100000

NO_INIT OS_STK TASK_STK[3][TASK_STK_SIZE];

typedef struct
{
  INT8U a;
  INT8U b;

  INT8U CS[4];

}S_Test;

S_Test PStruct_test;

MainWindow *w;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    w = new MainWindow;

  OS_TRACE();
  OS_Shell_Init(1);
  Debug_Print("Sys Starttia");
  //OS_SET_PSTRUCT_SUM(PStruct_test,&PStruct_test,sizeof(PStruct_test));
  OS_TRACE();
  OS_TRACE_CTRL(0);//关闭断言，防止冲掉记录的掉电前的调用轨迹
  OS_Init();//操作系统初始化
  //OS_Mutex_Clr();//清信号量
/*
  while(1)
  {
    OS_Cmd_Analys(OS_Shell_Cmd, 2, Cmd_Buf, 20);
  }
*/

  OS_TRACE();
  OS_Mutex_Init(TEST_SEM0_ID,1);
  OS_Mutex_Init(TEST_SEM1_ID,1);
  OS_Mutex_Init(TEST_SEM2_ID,1);
  OS_Sem_Init(TEST_SEM3_ID,3);
  OS_Msg_Init(TEST_SEM4_ID);
  OS_Msg_Q_Init(TEST_MSG_Q_ID,&Test11);
  OS_TRACE();
  OS_ASSERT_FAILED();
  //Print_Task_Stk_Left();//创建任务前可以打印各任务复位前的
  //创建任务
  OS_Create_Task(&Task1,&TASK_STK[0][TASK_STK_SIZE-1],sizeof(TASK_STK[0]),(OS_INT8U *)"Task1");
  OS_Create_Task(&Task2,&TASK_STK[1][TASK_STK_SIZE-1],sizeof(TASK_STK[1]),(OS_INT8U *)"Task2");
  OS_Create_Task(&Task3,&TASK_STK[2][TASK_STK_SIZE-1],sizeof(TASK_STK[2]),(OS_INT8U *)"Task3");

  OS_TRACE_CTRL(0xFF);//打开前8个任务的断言
  OS_ASSERT_FAILED();//打印复位前的流程
  OS_TRACE_CTRL(0x01);//只开第0号任务的断言
  Debug_Print("\r\n%s","----------uOS Start!----------");


  OS_Start();
  return a.exec();
}
#endif
