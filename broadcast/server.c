#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <arpa/inet.h>


#define ERR(s) do{perror(s);exit(-1);}while(0)

#define PORT 8080
#define IP "192.168.20.255"
#define BACKLOG 10

int main(int argc,char **argv)
{
	int sockfd;
	struct sockaddr_in destaddr;

	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd < 0)
		ERR("socket failed: ");
	int flag = 1;
	if(setsockopt(sockfd,SOL_SOCKET,SO_BROADCAST,&flag,sizeof(flag)) < 0)
		ERR("setsockopt failed: ");

	bzero(&destaddr,sizeof(destaddr));
	destaddr.sin_family = AF_INET;
	destaddr.sin_port = htons(PORT);
	inet_pton(AF_INET,IP,&destaddr.sin_addr);
	char msg[] = "hello world";
	int count = 0;
	while(count != 30)
	{
		sleep(1);
		sendto(sockfd,msg,strlen(msg),0,(struct sockaddr *)&destaddr,sizeof(struct sockaddr_in));
		count++;
	}
	close(sockfd);
	return 0;
}
