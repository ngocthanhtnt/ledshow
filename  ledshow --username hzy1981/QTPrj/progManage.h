#ifndef PROGMANAGE_H
#define PROGMANAGE_H

#include <QtGui/QMainWindow>
#include <QDockWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QList>
#include <QVariant>

#define FILE_TYPE 1
#define AREA_TYPE 2
#define PROG_TYPE 3
#define NULL_TYPE 0

#define PROG_STR "program"
#define AREA_STR "area"
#define FILE_STR "file"

#define PROG_PROPERTY 0x00
#define AREA_PROPERTY 0x01
#define PIC_PROPERTY    0x02 //图片
#define FLASH_PROPERTY  0x03 //动画
#define CLOCK_PROPERTY  0x04 //表盘
#define TIME_PROPERTY   0x05 //日期时间
#define TIMER_PROPERTY  0x06 //定时
#define TEMP_PROPERTY   0x07 //温度



//节目管理窗
class CprogManage:public QDockWidget
{
    Q_OBJECT
private:
    //QString settingsStr;
    QTreeWidgetItem *curItem;
    //QTreeWidget *treeWidget;
    void newFile(int fileType); //新文件
    void updateTextHead(QTreeWidgetItem *item); //更新和item同级的所有item的文本头

private slots:
    void newProg(); //新节目
    void newArea(); //新分区

    void newPic(); //新图文
    void newFlash(); //新动画
    void newTime(); //新日期
    void newTimer(); //新计时
    void newClock(); //新表盘
    void newTemp(); //新温度

    void deleteItem();
    void clickItem(QTreeWidgetItem * item, int column);
public:
    QTreeWidgetItem *getCurItem();
    void saveCurItem(QTreeWidgetItem *item);

    QTreeWidget *treeWidget;
    void settingsInit(); //打开settings
    CprogManage(QWidget *parent = 0);
    ~CprogManage();
};


#endif // PROGMANAGE_H
