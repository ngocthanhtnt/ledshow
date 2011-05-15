#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QextSerialPort>
#include <QextSerialEnumerator>
#include <QString>
#include <QProgressDialog>
#include <QThread>
#include <QTextEdit>
#include <QListView>
#include <QDockWidget>
#include <QProgressBar>

#include "..\Stm32\usr\app\Includes.h"
/*
class SerialThread: public QThread
{
        //QextSerialPort * port;

        protected:
                virtual void run()
                {
                        QString inStr;
                        QTextStream in(stdin);
                        QTextStream out(stdout);

                        out << "Special commands: open close bye" << endl << endl;
                        while(inStr.compare("bye") != 0) {
                                in >> inStr;
                                if (inStr.compare("close") == 0) {
                                        out << "requesting close... " << endl;
                                        port->close();
                                }
                                else if (inStr.compare("open") == 0) {
                                        out << "opening port... ";
                                        out << port->open(QIODevice::ReadWrite);
                                        out << endl;
                                } else if (inStr.compare("bye") != 0)
                                        port->write(inStr.toAscii().constData(), inStr.length());
                        }
                        port->close();
                }

        public:
                SerialThread(QextSerialPort * port, QObject * parent = 0):
                        QThread(parent)
                {
                        this->port = port;
                }
};
*/

class CcomThread:public QThread
{
    Q_OBJECT
private:


    //串口
    QextSerialPort * port;

    //QWidget *dialog;
    //QProgressDialog *progressDialog;
    //QLabel *statusLabel;

    //通信接收缓冲区
    INT8U Rcv_Buf[1000];
    int Rcv_Posi;
    INT8U Rcv_Flag;
    INT8U Rcv_Ch;

    QString comReStr; //通信结果字符串

signals:
    void comStatusChanged(QString str);
    void comProgressChanged(int progress);
    void comEnd(bool flag);
//public slots:
    //void comStart();
protected:
    void run();
public:
        INT8U COM_Mode;//通信方式
        QString COM_Port;

        int frameCounts; //当前发送帧数
        int totalFrameCounts; //总帧数

        //通信参数
        S_COM_Para COM_Para; //PC端通信参数
        S_ETH_Para ETH_Para;
        S_GPRS_Para GPRS_Para;

        QString protoFileName;

        bool connect(); //连接屏幕
        bool disConnect(); //断开连接

        int sendFrame(char *data, int len);


        int waitComRcv(int ms); //等待通信返回数据

        bool comRun();
        int clearRcvData(); //清除接收数据

        CcomThread(QObject * parent = 0);
public slots:
        /**
         * Receive data from serial port.
         */
        int comReceive();
};

class CcomStatus:public QDockWidget//QWidget
{
    Q_OBJECT
private:
    //QLabel *statusLabel;
    QLineEdit *screenNameEdit;

    QTextEdit *statusEdit;
    QTextEdit *paraEdit;
    QListView *progressList;
    QProgressBar *progressBar;
signals:
    void start();
public slots:
    void statusChange(QString str);
    void progressChange(int progress);
    void comEnd(bool flag);

    void comStart();
public:
    //bool checkComMode();
    void setTotalFrameCounts(int counts);
    void sendProtoFile(QString fileName);
    void getCOMParaFromSettings(QString str); //获取通信参数
    void setComMode(int mode);
    CcomThread *comThread;
    CcomStatus(QWidget * parent = 0);
};

bool checkComMode(INT8U COM_Mode);
QStringList getComPortList();
#endif // COMMUNICATION_H
