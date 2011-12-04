#ifndef SHOWAREA_H
#define SHOWAREA_H

//#include "..\Stm32\usr\app\LED_Cfg.h"
//#include "..\Stm32\usr\app\LED_Para.h"
//#include "..\Stm32\usr\app\LED_Show.h"
#include "..\Stm32\usr\app\Includes.h"
#include <QtGui/QMainWindow>
#include <QFrame>
#include <QLabel>
#include <Qmouseevent>
#include <QPainter>
#include <QTreeWidgetItem>
#include <QMdiSubWindow>

#define DRAG_MOVE  0x00
//#define DRAG_FDIAG 0x01
//#define DRAG_HOR   0x02
//#define DRAG_VER   0x03

#define DRAG_L   0x01
#define DRAG_LU  0x02
#define DRAG_LD  0x03
#define DRAG_R   0x04
#define DRAG_RU  0x05
#define DRAG_RD  0x06
#define DRAG_U   0x07
#define DRAG_D   0x08

#define RED    0x01
#define GREEN  0x02
#define YELLOW 0x03
#define BLUE   0x04  //SCREEN背景
#define BLACK  0x05  //AREA背景

//#define AREA_POINTS 5000
#define ANTIALIAS_VALUE 102

#define MIN_AREA 8
#define DEF_SCN_WIDTH 360
#define DEF_SCN_HEIGHT 64
#define DEF_SCN_COLOR  0x01

class CshowArea:public QWidget
{
    Q_OBJECT
private:
    //int width,height;

    //QPainter *Painter;
    QPoint dragPosition;
    QPoint framePosition;
    QSize oldSize;

    //unsigned char color0[MAX_POINTS/8];
    //unsigned char color1[MAX_POINTS/8];
    //unsigned char color2[MAX_POINTS/8];


    int dragFlag;
    bool mousePressed;

    int areaType; //0表示整个屏幕，1表示区域
    //int last_x; //拖动时前一次位置
    //int last_y; //
    //QPixmap *Pixmap;
    QPainter painter;
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
public:
    bool updateFlag;

    INT8U borderData[BORDER_DATA_LEN*10]; //预留10倍空间
    S_Show_Data showDataBak;
    S_Show_Data showData;
    int previewFlag; //0表示是正常窗口，1表示是预览窗口

    //S_Show_Data showDataBak;
    QImage imageBk;

    //-----------图文参数----------//
    QString picStr; //显示的文本
    bool smLineFlag; //单多行标志
    int moveFlag; //连续左移标志
    int editMode; //文本方式或者表格方式
    int page;  //显示的页号

    int xProportion;
    int yProportion;
    //--------------------
    S_Screen_Para screenPara; //屏幕参数
    S_Prog_Para progPara; //节目参数

    //-----------------------
    U_File_Para filePara; //该分区的显示参数
    int color;
    bool focusFlag;
    int getColor();

    QTreeWidgetItem *screenItem;
    QTreeWidgetItem *progItem;
    QTreeWidgetItem *areaItem; //对应的treeitem
    QTreeWidgetItem *fileItem; //对应的文件item

    //int getWidth();
    //int getHeight();

    void draw_point(int x,int y, int value);
    void clrShowData();
    void setAreaType(int type);
    CshowArea(QWidget *parent = 0, int i = 0);
    ~CshowArea();
};

class CscreenArea:public CshowArea
{
    Q_OBJECT
private:
    int x0,y0; //新建一个分区时的位置

    CshowArea *focusArea;


public:

    CshowArea *pArea[MAX_AREA_NUM];
    //U_File_Para File_Para[MAX_AREA_NUM]; //当前分区的文件参数，更换文件时刷新之

    QTreeWidgetItem *pTreeWidgetItem[MAX_AREA_NUM];
    int areaUsed[MAX_AREA_NUM];

    void updateShowArea(QTreeWidgetItem *item);
    void screenSettingsInit(QTreeWidgetItem *item);
    void areaSettingsInit(QTreeWidgetItem *item);
    void progSettingsInit(QTreeWidgetItem *item);
    void fileSettingsInit(QTreeWidgetItem *item);

    int checkEnoughArea(); //检查剩余足够的可显示区域，有则返回索引，否则返回false
    CshowArea *getFocusArea(); //当前的显示窗口
    void setFocusArea(CshowArea *area);

    void progChangedProc(QString settingsStr);

    //int setOneAreaVisible(QString settingsStr);
    void setAreaVisible(int index, bool flag);

    QString getCurrentFileStr();
    QString getCurrentScreenStr();
    CshowArea * newShowArea();
    CscreenArea(QWidget *parent = 0, INT16U width = DEF_SCN_WIDTH, INT16U height = DEF_SCN_HEIGHT, INT8U color = DEF_SCN_COLOR);
    ~CscreenArea();

};

class CMdiSubWindow:public QMdiSubWindow
{
        Q_OBJECT
protected:
    void closeEvent(QCloseEvent *closeEvent);
public:
    int previewFlag;

    CMdiSubWindow(QWidget *parent = 0);
    ~CMdiSubWindow();
};

class CpreviewWin:public QMainWindow
{
    Q_OBJECT
protected:
    void closeEvent(QCloseEvent *closeEvent);
public:
    //int previewFlag;

    CpreviewWin(QWidget *parent = 0);
    ~CpreviewWin();
};

bool Get_Border_Show_En();
bool Get_Clock_Show_En();
bool Get_Pic_Show_En();
bool Get_Lun_Show_En();
bool Get_Temp_Show_En();
bool Get_Time_Show_En();
bool Get_Timer_Show_En();
bool Get_Humidity_Show_En();
bool Get_Noise_Show_En();
void saveScreenPara(S_Screen_Para &Screen_Para_Bak);
//保存节目参数Prog_Para到Prog_Para_Bak
void saveProgPara(S_Prog_Para &Prog_Para_Bak);
void saveCardPara(S_Card_Para &Card_Para_Bak);
//从Screen_Para_Bak中恢复参数到Screen_Para
void restoreScreenPara(S_Screen_Para &Screen_Para_Bak);
//从Prog_Para_Bak中恢复参数到Prog_Para
void restoreProgPara(S_Prog_Para &Prog_Para_Bak);
void resetShowPara(int width, int height, int color);
void restoreCardPara(S_Card_Para &Card_Para_Bak);
#endif // MAINWINDOW_H
