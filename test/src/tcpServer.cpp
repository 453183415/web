/*
 * tcpServer.cpp
 *
 *  Created on: 2016年3月3日
 *      Author: zjl
 */
#include<sys/socket.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>

int main(int argc, char** argv)
{
	char buf[1024];
	int sockfd,connfd;
	ssize_t n;
	socklen_t cli_len;
	struct sockaddr_in ser_addr,cli_addr;
	bzero(&ser_addr,sizeof(ser_addr));
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port=htonl(10000);
	ser_addr.sin_addr.s_addr=INADDR_ANY;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	bind(sockfd,(struct sockaddr *)&ser_addr,sizeof(ser_addr));
	listen(sockfd,5);
	cli_len=sizeof(cli_addr);
	connfd=accept(sockfd,(struct sockaddr *)&cli_addr,&cli_len);
	while(1){
		n=read(sockfd,buf,1024);
		printf("%s\n",buf);
		write(sockfd,buf,n);
		bzero(&buf,1024);
	}
	return 0;
}



