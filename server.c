#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

void main(){
  int sock;
  struct sockaddr_in saddr, caddr;
  socklen_t addr_size;
  char cmsg[256];
  char smsg[256];

  sock=socket(AF_INET, SOCK_DGRAM, 0);

  saddr.sin_family = AF_INET;
  saddr.sin_port = htons(7891);
  saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
 
  bind(sock, (struct sockaddr *) &saddr, sizeof(saddr));
  addr_size = sizeof caddr;
  while(1){
    recvfrom(sock,cmsg,sizeof(cmsg),0,(struct sockaddr *)&caddr,&addr_size);
	printf("client:%s",cmsg);
  	memset(cmsg,'\0',sizeof(cmsg));
	printf("server:");
	fgets(smsg,256,stdin);  
    sendto(sock,smsg,strlen(smsg),0,(struct sockaddr *)&caddr,addr_size);
  }

 
}
