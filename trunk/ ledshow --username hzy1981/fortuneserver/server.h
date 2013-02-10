#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QString>
#include <QStringList>

#define MAX_RAM_FILE_NUM 500//构建在内存中的额最大文件数
#define CHK_BYTE 0x5A
#define EQ ==

class tcpServer : public QTcpServer
{
    Q_OBJECT
    public:
        tcpServer(QObject *parent = 0);
    protected:
        void incomingConnection(int socketDescriptor);
 };

typedef struct
{
  char head;

  char fileName[100]; //文件名
  FILE *fp;  //指向文件结构体的指针
  char *pBuf; //数据buf
  int timerCounts;
  char useFlag; //当前是否在使用
  int fileLen;

  char tail;
}sfileInfo;

class fileServer// : public QTcpServer
{
    private:
    QStringList fileName;
    FILE *fp[MAX_RAM_FILE_NUM]; //最多100个文件
    char *(fileBufp[MAX_RAM_FILE_NUM]); //每个文件对应的buf


    sfileInfo fileInfo[MAX_RAM_FILE_NUM]; //文件信息

    public:

        fileServer(QObject *parent = 0);
        int readFile(int index, char * fileName, int offset, int len, char *pDst, int dstLen); //读取文件
        int chkFileInRam(char * fileName);  //检查文件是否在ram中，是返回true，否则返回false
        int getFileToRam(char * fileName);
         //protected:
        //void incomingConnection(int socketDescriptor);
 };
#endif // TCPSERVER_H
