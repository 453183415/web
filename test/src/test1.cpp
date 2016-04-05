/*
 * test1.cpp
 *
 *  Created on: 2015年11月22日
 *      Author: zjl
 */
#include<iostream>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>


int main()
{
	int sockfd,confd,clientfd,confd1;
	int listenq=1024;
	int optval=1;
	pid_t pid;
	struct sockaddr_in serveraddr,clientaddr;
	char buf[1024],buf1[1024];
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	clientfd=socket(AF_INET,SOCK_STREAM,0);
	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,(void * )&optval,sizeof(int));
	bzero((char *)&serveraddr,sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	clientaddr.sin_family =AF_INET;
	serveraddr.sin_port = htons(1234);
	clientaddr.sin_port = htons(1235);
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	clientaddr.sin_addr=inet_addr("172.20.1.174");
	bind(sockfd,(struct sockaddr *)&serveraddr,sizeof(sockaddr_in));
	listen(sockfd,listenq);
	socklen_t client;
	client=sizeof(struct sockaddr_in);
	while(1){
	confd=accept(sockfd,(struct sockaddr  *)&clientaddr,&client);
	if((pid=fork())==0){
			//std::cout<<"dsfsdf"<<std::endl;
		int n=10,i=0;
		while(i<3){
	int ret=recv(confd,buf,sizeof(buf),0);
	confd1=connect(clientfd,(struct sockaddr*)&clientaddr,sizeof(struct sockaddr));
	buf[ret-1]='\0';
	std::cout << buf<<"\n input:"<<std::endl;
	std::cin>>buf1;
	send(confd1,buf1,sizeof(buf1),0);
	i++;
	}
	close(confd);
	close(sockfd);
	exit(0);
	}else
	close(confd);
	}

}



