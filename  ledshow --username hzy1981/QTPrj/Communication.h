#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QextSerialPort>
#include <QextSerialEnumerator>
#include <QString>
#include <QProgressDialog>
#include "..\Stm32\usr\app\Includes.h"

class CcomStatus:public QWidget
{
    Q_OBJECT
private:
    INT8U COM_Mode;//通信方式
    INT8U COM_Port;

    //通信参数
    S_COM_Para COM_Para; //PC端通信参数
    S_ETH_Para ETH_Para;
    S_GPRS_Para GPRS_Para;

    //串口
    QextSerialPort * port;

    QProgressDialog *progressDialog;

    //通信接收缓冲区
    INT8U Rcv_Buf[1000];
    int Rcv_Posi;
    INT8U Rcv_Flag;
    INT8U Rcv_Ch;

    QString comReStr; //通信结果字符串

signals:
    void comStatusChanged(QString str);

public:
        int connect(QString str); //连接屏幕
        int disConnect(); //断开连接

        int sendFrame(char *data, int len);

        int sendProtoFile(QString fileName);

        void setComMode(int mode);
        int waitComRcv(int ms); //等待通信返回数据

        void getCOMParaFromSettings(QString str); //获取通信参数
        void clearRcvData(); //清除接收数据

        CcomStatus(QWidget * parent = 0);
public slots:
        /**
         * Receive data from serial port.
         */
        void comReceive();
};

QStringList getComPortList();
#endif // COMMUNICATION_H
