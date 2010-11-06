#include <QtGui/QApplication>
#include <QDesktopWidget>
#include <QPainter>
#include <QTextCodec>
#include "mainwindow.h"
#include "textedit.h"

MainWindow *w;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //设置为支持中文---重要

    QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));
    QFont font(QObject::tr("新宋体"),9,QFont::Normal,FALSE);
    a.setFont(font);

/*
    QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("gb2312"));
    QFont font("wenquanyi_120_50"); //使用wenquanyi字体
    a.setFont(font); //设置字体
*/

    w = new MainWindow;
    QRect desktopRect = QApplication::desktop()->availableGeometry();
    int iTitleBarHeight = w->style()->pixelMetric(QStyle::PM_TitleBarHeight);  // 获取标题栏高度

    w->setGeometry(0, iTitleBarHeight, desktopRect.width(), desktopRect.height() - iTitleBarHeight);  // 设置窗体充满桌面客户区
    w->setFixedSize(desktopRect.width(), desktopRect.height() - iTitleBarHeight);      // 固定窗体大小

    if(w->progManage->treeWidget->topLevelItemCount()>0)
      w->progManage->clickItem(w->progManage->treeWidget->topLevelItem(0), 0);
    //w->progManage->newProg();
    //w->progManage->newArea();
    w->show();

    return a.exec();

/*
    TextEdit mw;
    mw.resize( 700, 800 );
    mw.show();
    return a.exec();
    */
}
