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

#define COM_OUT    0x00 //当前不在通信过程中
#define COM_ING    0x01 //当前正在通信
#define COM_FAILED 0x02 //当前通信失败
#define COM_OK     0x03 //通信成功
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



signals:
    void comStatusChanged(QString str);
    void comProgressChanged(int progress);
    void comEnd(bool flag);
//public slots:
    //void comStart();
protected:
    void run();
public:
        //通信接收缓冲区
        INT8U Rcv_Buf[1000];
        int Rcv_Posi;
        INT8U Rcv_Flag;
        INT8U Rcv_Ch;

        char status;
        INT8U COM_Mode;//通信方式
        QString COM_Port;

        int frameCounts; //当前发送帧数
        int totalFrameCounts; //总帧数

        //通信参数
        S_COM_Para COM_Para; //PC端通信参数
        S_ETH_Para ETH_Para;
        S_GPRS_Para GPRS_Para;

        QString protoFileName;
        QString comReStr; //通信结果字符串
        bool connect(); //连接屏幕
        bool disConnect(); //断开连接

        bool sendFrame(char *data, int len, int bufLen);


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
    QPushButton *clrButton;
    QPushButton *hideButton;
protected:
    virtual void closeEvent(QCloseEvent *e);
    virtual void showEvent(QShowEvent * e);
    virtual void hideEvent(QHideEvent * e);
signals:
    void start();
public slots:
    void statusChange(QString str);
    void progressChange(int progress);
    void comEnd(bool flag);

    void comStart();
    void comShow();
public:
    //bool checkComMode();
    void setTotalFrameCounts(int counts);
    void sendProtoFile(QString fileName);
    void getCOMParaFromSettings(QString str); //获取通信参数
    void getUDiskParaFromSettings(QString str);
    void setComMode(int mode);
    char getComStatus();
    bool waitComEnd(INT8U *pDst, int maxLen, int *pDstLen);
    QString getComReStr();
    CcomThread *comThread;
    CcomStatus(QWidget * parent = 0);
};

//bool waitComEnd(INT8U *pDst, int maxLen, int *pDstLen);
void sleepMs(int ms);
void sleepSec(int ms);
bool checkComMode(INT8U COM_Mode);
QStringList getComPortList();
#endif // COMMUNICATION_H
