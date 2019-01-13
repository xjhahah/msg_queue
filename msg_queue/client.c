#include "comm.h"
#include <unistd.h>

int main()
{
  int msgid = CreatMsgQueue();
  char buf[1024];
  while(1){
    buf[0] = 0;
    printf("Please Enter# ");
    fflush(stdout);
    ssize_t s = read(0, buf, sizeof(buf));
    if(s>0){
      buf[s-1] = 0;
      SendMsg(msgid,buf, CLIENT_TYPE);
      printf("send done, wait recv...\n");
    }
    RecvMsg(msgid,buf, SERVER_TYPE);
    printf("server# %s\n", buf);

  }
  return 0;
}
