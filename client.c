#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

void main(){
  int sock;
  char smsg[256],cmsg[256];
  struct sockaddr_in saddr;
  socklen_t addr_size;

  sock=socket(AF_INET, SOCK_DGRAM, 0);
  saddr.sin_family = AF_INET;
  saddr.sin_port = htons(7891);
  saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
   
  addr_size = sizeof saddr;
  while(1){
    printf("client:");
    fgets(cmsg,256,stdin);
    sendto(sock,cmsg,strlen(cmsg),0,(struct sockaddr *)&saddr,addr_size);
    memset(cmsg,'\0',sizeof(cmsg));
    recvfrom(sock,smsg,256,0,NULL, NULL);
    printf("server: %s",smsg);
    memset(smsg,'\0',sizeof(smsg));

  	}
}

