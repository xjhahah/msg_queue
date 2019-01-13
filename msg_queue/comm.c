#include "comm.h"


static int CommCreatMsgQueue(int flag)
{
  key_t k = ftok(PATHNAME,PROJID);
  if(k<0)
  {
    perror("ftok");
    return -1;
  }
  int msgid = msgget(k,flag);

  if(msgid<0)
  {
    perror("msgget");
  }
  return msgid;
}

int CreatMsgQueue()
{
  return CommCreatMsgQueue(IPC_CREAT | IPC_EXCL | 0666);
}
//打开消息队列
int OpenMsgQueue()
{
  return CommCreatMsgQueue(IPC_CREAT);
}

//删除消息队列
void DestroyMsgQueue(int msgid)
{
  msgctl(msgid,IPC_RMID,NULL);
}

//发送数据
void SendMsg(int msgid,char* msgtxt,int type)
{
  MSGBUF msg;
  msg.mtype = type;
  strncpy(msg.mtext,msgtxt,sizeof(msg.mtext));
  if(msgsnd(msgid,(void*)&msg,sizeof(msg.mtext),0)<0)
  {
    perror("msgsnd");
  }
}

void RecvMsg(int msgid,char* msg,int type)
{
  MSGBUF _msg;
  _msg.mtype = type;
  if(msgrcv(msgid,&msg,sizeof(_msg.mtext),type,0)<0)
  {
    strncpy(_msg.mtext,msg,sizeof(_msg.mtext));
  }
}











