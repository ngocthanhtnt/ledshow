#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //设置为支持中文---重要
    QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));
    QFont font(QObject::tr("新宋体"),9,QFont::Normal,FALSE);
    a.setFont(font);

    MainWindow w;
    w.show();
    
    return a.exec();
}
