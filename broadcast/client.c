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
	destaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(sockfd, (struct sockaddr *)&destaddr, sizeof(struct sockaddr_in)) < 0)  
		ERR("bind failed: ");
	char msg[20];
	int n = 0;
	while(1)
	{
		n = read(sockfd,msg,sizeof(msg));
		if(n < 0)
			ERR("read failed: ");
		msg[n] = '\0';
		printf("msg: %s\n",msg);
		bzero(msg,20);
	}
	close(sockfd);
	return 0;
}
