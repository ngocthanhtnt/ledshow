#ifndef TCPSERVER_CPP
#define TCPSERVER_CPP

#include <server.h>
#include <thread.h>

tcpServer::tcpServer(QObject *parent):QTcpServer(parent)
{

}

void tcpServer::incomingConnection(int socketDescriptor)
{
    tcpThread *Mythread = new tcpThread(socketDescriptor,this);
    connect(Mythread,SIGNAL(finished()),Mythread,SLOT(deleteLater()));
    Mythread->start();
}

#endif // TCPSERVER_CPP
