#ifndef TCPTHREAD_CPP
#define TCPTHREAD_CPP

#include <thread.h>
#include <server.h>
#include <QDataStream>
#include <QTcpSocket>
#include <QDateTime>
#include <QSqlQuery>
#include <Qtsql>

/**************************构造函数_连接数据库**********************************/
tcpThread::tcpThread(int socketDescriptor, QObject *parent):QThread(parent),socketDescriptor(socketDescriptor)
{
    if(createConnection())
    {
        qDebug()<<"Mysql Open!";
    }
}

/**************************析构函数_提示线程退出**********************************/
tcpThread::~tcpThread()
{
    emit finished();
    qDebug()<<"A Thread Quit!";
}
/**************************run函数_进行通信及数据库存储**********************************/
void tcpThread ::run()
{
    tcpSocket = new QTcpSocket;
    dataTimer = new QTimer;
    cmdTimer = new QTimer;
    tcpSocket->setSocketDescriptor(socketDescriptor);
    dataTimer->start(3500);
    cmdTimer->start(7300);
    sendNum = 1;
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(dataTimer,SIGNAL(timeout()),this,SLOT(sendSearch()),Qt::DirectConnection);//定时器时间到，发送查询命令。Qt::DirectConnection线程内传递消息
    connect(cmdTimer,SIGNAL(timeout()),this,SLOT(sendCommand()),Qt::DirectConnection);//定时器时间到，搜索数据库中是否有需要发出的命令
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(quit()));//socket断开连接，线程退出
    qDebug()<<tcpSocket->peerAddress().toString();
    qDebug()<<tcpSocket->peerPort();
    exec();
}

/**************************数据库连接函数**********************************/
bool tcpThread::createConnection()
{
    db =new QSqlDatabase;

    if(QSqlDatabase::contains("db_test"))                       //若db_test已经打开，则使用
        *db=QSqlDatabase::database("db_test");
    else
    {
        *db = QSqlDatabase::addDatabase("QMYSQL","db_test");    //若没打开则添加
        //*db = QSqlDatabase::addDatabase("QSQLITE","db_test");    //若没打开则添加
        db->setDatabaseName("db_test");
    }

    /*
     db->setUserName("xdt");
     db->setPassword("xdt");
     db->setHostName("219.231.143.195");
     */

    db->setUserName("root");
    db->setPassword("shmily504");
    db->setHostName("localhost");
    if (!db->open())
        return false;
    return true;
}

/**************************读取socket传来数据并写入数据库**********************************/
void tcpThread::readMessage()
{
    QByteArray bytesArrived;
    qDebug()<<tcpSocket->bytesAvailable();
    bytesArrived=tcpSocket->readAll();

    QDateTime dateTime;
    QString currentTime=dateTime.currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    qDebug()<<currentTime;
    QSqlQuery mysql(*db);

    if(bytesArrived[0] == 0x02 && bytesArrived[1] == 0xFE && bytesArrived[2] == 0xFE)//26个字节数据
    {
        char deviceType = bytesArrived[3];
        int cdNum = bytesArrived[5];

        qint32 temPerature =bytesArrived[7]*256 + bytesArrived[8];
        char count_H = bytesArrived[11];
        char count_L = bytesArrived[12];
        int deviceState = bytesArrived[13];
        char energyEfficiency =bytesArrived[14];
        qint32 count= count_H*256 + count_L;

        /****************************写原始数据表tb_date_r&&tb_sense*****************/
        QString insertInto_tbSense ="insert into tb_sense(irlast,temp,time) values(?,?,?);";
        mysql.prepare(insertInto_tbSense);
        mysql.addBindValue(count);
        mysql.addBindValue(temPerature);
        mysql.addBindValue(currentTime);
        mysql.exec();
        QString insertInto_tbDateR ="insert into tb_date_r(device_num,cd_num,temp,irlast1,irlast2,device_state,efficiency,time) values(?,?,?,?,?,?,?,?);";
        mysql.prepare(insertInto_tbDateR);
        mysql.addBindValue(deviceType);
        mysql.addBindValue(cdNum);
        mysql.addBindValue(temPerature);
        mysql.addBindValue(count_H);
        mysql.addBindValue(count_L);
        mysql.addBindValue(deviceState);
        mysql.addBindValue(energyEfficiency);
        mysql.addBindValue(currentTime);
        mysql.exec();
        /*******************************更新tb_cddate*****************************/
        if(4 == cdNum)
        {
            QString update_tbCddate;
            update_tbCddate="update tb_cddate set temp=?,device_state=?,time=? where cd_num=4;";
            mysql.prepare(update_tbCddate);
            mysql.addBindValue(temPerature);
            mysql.addBindValue(deviceState);
            mysql.addBindValue(currentTime);
            mysql.exec();
        }

        if(3 == cdNum)
        {
            QString update_tbCddate;
            update_tbCddate="update tb_cddate set temp=?,device_state=?,time=? where cd_num=3;";
            mysql.prepare(update_tbCddate);
            mysql.addBindValue(temPerature);
            mysql.addBindValue(deviceState);
            mysql.addBindValue(currentTime);
            mysql.exec();
        }

        if(2 == cdNum)
        {
            QString update_tbCddate;
            update_tbCddate="update tb_cddate set temp=?,device_state=?,time=? where cd_num=2;";
            mysql.prepare(update_tbCddate);
            mysql.addBindValue(temPerature);
            mysql.addBindValue(deviceState);
            mysql.addBindValue(currentTime);
            mysql.exec();

            if(0x00 == deviceState || 0x04 == deviceState || 0x08 == deviceState || 0x0C == deviceState)
            {
                QString update_tbLight ="update tb_light set state=2,time=? where id=1";
                mysql.addBindValue(currentTime);
                mysql.exec();
            }

            if(0x01 == deviceState || 0x05 == deviceState || 0x09 == deviceState || 0x0D == deviceState)
            {
                QString update_tbLight ="update tb_light set state=1,time=? where id=1";
                mysql.addBindValue(currentTime);
                mysql.exec();
            }
        }

        if(1 == cdNum)
        {
            QString update_tbCddate;
            update_tbCddate="update tb_cddate set temp=?,device_state=?,time=? where cd_num=1;";
            mysql.prepare(update_tbCddate);
            mysql.addBindValue(temPerature);
            mysql.addBindValue(deviceState);
            mysql.addBindValue(currentTime);
            mysql.exec();

            if(0x00 == deviceState || 0x04 == deviceState || 0x08 == deviceState || 0x0C == deviceState)
            {
                QString update_tbLight ="update tb_aircondition set state=2,efficiency=?,time=? where id=1";
                mysql.addBindValue(energyEfficiency);
                mysql.addBindValue(currentTime);
                mysql.exec();
            }

            if(0x01 == deviceState || 0x05 == deviceState || 0x09 == deviceState || 0x0D == deviceState)
            {
                QString update_tbLight ="update tb_aircondition set state=1,efficiency=?,time=? where id=1";
                mysql.addBindValue(energyEfficiency);
                mysql.addBindValue(currentTime);
                mysql.exec();
            }
        }
    }

    /**************************若返回的是ACK则更新数据库tb_date_t**********************************/
    if(bytesArrived[0] == 0x04 && bytesArrived[1] == 0x55 && bytesArrived[2] == 0x11)
    {
        uint sum = 0;
        QByteArray temp = bytesArrived.toHex().right(2);
        qDebug()<<temp;
        if(temp[0]<='9')
            sum +=(temp[0]-'0')*16;
        else
            sum +=(temp[0]-'a'+10)*16;

        if(temp[1]<='9')
            sum +=temp[1]-'0';
        else
            sum +=temp[1]-'a'+10;

        uint taskId = sum%256;
        qDebug()<<taskId;
        QString update_tbDateT = "update tb_date_t set state=2,time=? where id=? and state=1";
        qDebug()<<update_tbDateT;
        mysql.prepare(update_tbDateT);
        mysql.addBindValue(currentTime);
        mysql.addBindValue(taskId);
        mysql.exec();
    }
}

/**************************发送查询命令**********************************/
void tcpThread::sendSearch()
{
    char block[5];
    char cdNum;

    if(1 == sendNum)
    {
        cdNum =0x01;
        sendNum = 2;
    }
    else if(2 == sendNum)
    {
        cdNum =0x02;
        sendNum = 3;
    }
    else if(3 == sendNum)
    {
        cdNum = 0x03;
        sendNum = 4;
    }
    else if(4 == sendNum)
    {
        cdNum = 0x04;
        sendNum =1;
    }

    block[0]=0x44;
    block[1]=0x11;
    block[2]=0x01;
    block[3]=0x07;
    block[4]=cdNum;

    tcpSocket->write(block,5);
}

/**************************发送控制命令**********************************/
void tcpThread::sendCommand()
{
    QSqlQuery send(*db);
    QString haveSendFalse="update tb_date_t set state=3,time= where state=1" ;
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    send.prepare(haveSendFalse);
    send.addBindValue(currentTime);
    send.exec();
    QString waitSend="select *from tb_date_t where state =0" ;
    send.exec(waitSend);
    while(send.next())
    {
        int i,j=0,t=0;
        QString taskCmd=send.value(2).toString();
        QByteArray sendTask = taskCmd.toLatin1();
        QByteArray sendTaskcmd;
        uchar sendTemp1[10];
        uchar sendTemp2[10];
        qDebug()<<sendTask;

        /**************************STRING_TO_HEX**********************************/
        for(i=0;i<20;i++)
        {
            if(i%2 == 0)
            {
                switch(sendTask[i])
                {
                case 0x30:sendTemp1[j]=0x00;
                    break;
                case 0x31:sendTemp1[j]=0x10;
                    break;
                case 0x32:sendTemp1[j]=0x20;
                    break;
                case 0x33:sendTemp1[j]=0x30;
                    break;
                case 0x34:sendTemp1[j]=0x40;
                    break;
                case 0x35:sendTemp1[j]=0x50;
                    break;
                case 0x36:sendTemp1[j]=0x60;
                    break;
                case 0x37:sendTemp1[j]=0x70;
                    break;
                case 0x38:sendTemp1[j]=0x80;
                    break;
                case 0x39:sendTemp1[j]=0x90;
                    break;
                case 0x61:sendTemp1[j]=0xa0;
                    break;
                case 0x62:sendTemp1[j]=0xb0;
                    break;
                case 0x63:sendTemp1[j]=0xc0;
                    break;
                case 0x64:sendTemp1[j]=0xd0;
                    break;
                case 0x65:sendTemp1[j]=0xe0;
                    break;
                case 0x66:sendTemp1[j]=0xf0;
                    break;
                default:sendTemp1[j]=0x22;
                    break;
                }
                j++;
            }
            else
            {
                if(sendTask[i] <= 0x39)
                {
                    sendTemp2[t] = sendTask[i]-0x30;
                }
                else
                    sendTemp2[t] = sendTask[i]-0x57;
                t++;
            }
        }

        for(i=0;i<10;i++)
        {
            sendTaskcmd[i]=sendTemp1[i]+sendTemp2[i];
        }

        tcpSocket->write(sendTaskcmd);
    }
}
#endif // TCPTHREAD_CPP
