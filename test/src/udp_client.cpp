/*
 * udp_client.cpp
 *
 *  Created on: 2016年3月4日
 *      Author: zjl
 */
#include<sys/socket.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main(int argc ,char **argv)
{
	char buf[1024];
	int sockfd;
	struct sockaddr_in cli_addr;
	bzero(&cli_addr,sizeof(cli_addr));
	cli_addr.sin_family=AF_INET;
	cli_addr.sin_port=htonl(10000);
	inet_pton(AF_INET,argv[1],&cli_addr.sin_addr);
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
int ret=connect(sockfd,(struct sockaddr*)&cli_addr,sizeof(cli_addr));
printf("%d",ret);
	ssize_t len=sizeof(sockaddr_in);
	while(1){
		scanf("%s",buf);

		if(write(sockfd,buf,sizeof(buf))<0)
			printf("error");
		printf("%s\n",buf);
		bzero(&buf,1024);
//		recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr *)&cli_addr,&len);
//		printf("%s\n",buf);
	}
}

