#ifndef PROGMANAGE_H
#define PROGMANAGE_H

#include <QtGui/QMainWindow>
#include <QDockWidget>
#include <QTreeWidget>
#include <QTreeView>
#include <QTreeWidgetItem>
#include <QList>
#include <QVariant>
#include <QTimer>
#include <showArea.h>

#define FILE_TYPE 1
#define AREA_TYPE 2
#define PROG_TYPE 3
#define NULL_TYPE 0

#define PROG_STR "program"
#define AREA_STR "area"
#define FILE_STR "file"

#define NULL_PROPERTY   0xFF
#define SCREEN_PROPERTY 0x00
#define PROG_PROPERTY   0x01
#define AREA_PROPERTY   0x02
#define PIC_PROPERTY    0x03 //图片
#define CLOCK_PROPERTY  0x05 //表盘
#define TIME_PROPERTY   0x06 //日期时间
#define TIMER_PROPERTY  0x07 //定时
#define TEMP_PROPERTY   0x08 //温度
#define LUN_PROPERTY    0x09    //农历
#define HUMIDITY_PROPERTY 0x0A //湿度
#define NOISE_PROPERTY 0x0B //噪音

#define PIC_TABLE_PROPERTY  0x30
#define PIC_FLASH_PROPERTY  0x31 //动画
#define PIC_MTEXT_PROPERTY  0x32
#define PIC_STEXT_PROPERTY  0x33

#define SUB_INDEX_EN 0


//节目管理窗
class CprogManage:public QDockWidget
{
    Q_OBJECT
private:
    //QString settingsStr;
    QTreeWidgetItem *curItem;
    //QTreeWidget *treeWidget;
    void newFile(int fileType, int subType); //新文件

public slots:
    void newScreen(); //新屏幕
    void newProg(); //新节目
    void newArea(); //新分区

    void newSText(); //字幕
    void newPic(); //新图文
    void newFlash(); //新动画
    void newTime(); //新日期
    void newTimer(); //新计时
    void newClock(); //新表盘
    void newTemp(); //新温度
    void newLun(); //新农历
    void newHumidity(); //新湿度
    void newNoise(); //新噪音

    void _deleteItem(int flag);
    void deleteItem();
    void clickItem(QTreeWidgetItem * item, int column);
    void currentItemChangedProc(QTreeWidgetItem * current, QTreeWidgetItem * previous);

public:
    /*
    QMainWindow *previewWin;
    CscreenArea *previewArea;
    QTimer *timer;
    int timerFlag;
    INT8U previewProgNo;
*/
    void updateTextHead(QTreeWidgetItem *item); //更新和item同级的所有item的文本头
    QTreeWidgetItem *getCurItem();
    void saveCurItem(QTreeWidgetItem *item);



    QTreeWidget *treeWidget;
    void settingsInit(); //打开settings
    CprogManage(QWidget *parent = 0);
    ~CprogManage();
};
int checkItemType(QTreeWidgetItem *item);
int checkStrType(QString str);
#endif // PROGMANAGE_H
