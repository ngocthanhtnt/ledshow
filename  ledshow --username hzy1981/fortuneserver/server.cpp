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

fileServer::fileServer(QObject *parent)
{
  //初始化fileInfo信息
  memset(fileInfo, 0, sizeof(fileInfo));

  for(int i = 0; i < MAX_RAM_FILE_NUM; i ++)
  {
      fileInfo[i].head = CHK_BYTE;
      fileInfo[i].tail = CHK_BYTE;
  }
}

int fileServer::readFile(int index, char* fileName, int offset, int len, char *pDst, int dstLen) //读取文件
{
    if(strcmp(fileName, fileInfo[index].fileName) != 0) //文件索引和文件名对不上！
    {
        qDebug("索引和文件名不对应, index = %d, name = %s", index, fileInfo[index].fileName);
        return 0;
    }

    if(offset + len > fileInfo[index].fileLen)
    {
        qDebug("读取文件越界, offset = %d, len = %d, filelen = %d", offset, len, fileInfo[index].fileLen);
        return 0;
    }

    if(len > dstLen)
        return 0;

    memcpy(pDst, fileInfo[index].pBuf + offset, len);

    return len;
}

//检查文件内容是否在ram中如果再则返回索引
int fileServer::chkFileInRam(char* fileName)
{
  //char temp[200];

  if(strlen(fileName) >= 100)
  {
      qDebug("fileName lenght error");
      return 0;
  }

  //strcpy(temp, fileName);

  for(int i = 0; i < MAX_RAM_FILE_NUM; i ++)
  {
      if(strcmp(fileName, fileInfo[i].fileName) EQ 0)
          return i + 1;
  }

  return 0;
}

//读取文件存储到内存ram中
int fileServer::getFileToRam(char *fileName)
{
  FILE *file;
  size_t len;

  file = fopen(fileName, "rb");
  if(file EQ 0)
  {
      qDebug("找不到文件%s", (const char *)fileName);
      return 0;
  }

  fseek(file, 0, SEEK_END);
  len = ftell(file); //文件大小

  for(int i = 0; i < MAX_RAM_FILE_NUM; i ++)
  {
    if(fileInfo[i].fileName[0] EQ 0) //没有文件名--该条索引没有被占用
    {
        fileInfo[i].pBuf = (char *)malloc(len); //申请动态内存
        if(fileInfo[i].pBuf EQ 0)
        {
            qDebug("申请内存失败，大小%d", len);
            fclose(file);
            return 0;
        }

        //读取文件失败，释放资源
        if(fread(fileInfo[i].pBuf, len, 1, file) != len)
        {
            qDebug("读取文件%s失败", (const char *)fileName);

            free(fileInfo[i].pBuf);
            fileInfo[i].pBuf = 0;
            fclose(file);

            return 0;
        }

        fileInfo[i].fileLen = len;
        strcpy(fileInfo[i].fileName, fileName);
        fclose(file);

        return i + 1;

    }
  }


  return 0;
}

#endif // TCPSERVER_CPP
