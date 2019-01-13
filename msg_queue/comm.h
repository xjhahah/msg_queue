#ifndef __COMM_H__
#define __COMM_H__

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
 
#define PATHNAME "/tmp"
#define PROJID 0x6666

#define SERVER_TYPE 1
#define CLIENT_TYPE 2

typedef struct msgbuf
{
  long mtype;
  char mtext[64];
}MSGBUF;

//创建消息队列
int CreatMsgQueue();
int OpenMsgQueue();
void DestroyMsgQueue(int msgid);
void SendMsg(int msgid,char* msgtxt,int type);
void RecvMsg(int msgid,char* msg,int type);


#endif 
