#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>

class tcpServer : public QTcpServer
{
    Q_OBJECT
    public:
        tcpServer(QObject *parent = 0);
    protected:
        void incomingConnection(int socketDescriptor);
 };

#endif // TCPSERVER_H
