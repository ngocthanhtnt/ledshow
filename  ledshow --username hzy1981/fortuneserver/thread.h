#ifndef TCPTHREAD_H
#define TCPTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QTimer>

class tcpThread : public QThread
{
    Q_OBJECT
    public:
        void run();
        tcpThread(int socketDescriptor, QObject *parent);
        ~tcpThread();
        bool createConnection();
    public slots:
        void sendSearch();
        void readMessage();
        void sendCommand();
    private:
        int socketDescriptor;
        QTcpSocket* tcpSocket;
        QTimer* dataTimer;
        QTimer* cmdTimer;
        int sendNum;
        QSqlDatabase* db;

        char fileSendFlag; //发送文件,1表示当前有文件发送，0表示无文件发送
        int fileSendOffset;   //发送文件偏移
        QString fileName; //发送文件名字
 };
#endif // TCPTHREAD_H
