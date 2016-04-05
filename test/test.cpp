#include<sys/socket.h>
#include<unistd.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<string.h>
int main()
{
	char buff[1024];
	int listenfd,confd,sockfd,optval=0;
	int listenQ=1024;
	pid_t pid;
	socklen_t client;
	struct sockaddr_in serveraddr,clientaddr;
	if( (listenfd = socket ( AF_INET,SOCK_STREAM ,0) )<0){
			return -1;
		}
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	bzero( (char*)&serveraddr ,sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	clientaddr.sin_family   = AF_INET;
	clientaddr.sin_addr = htonl(INADDR_ANY);
	serveraddr.sin_addr.s_addr =inet_addr("172.20.1.174");
	serveraddr.sin_port = htons(1234);
	clientaddr.sin_port = htons(1235);
	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,(void *)&optval,sizeof(int ));
	bind(sockfd,(struct sockaddr *)&clientaddr,sizeof(sockaddr_in));
	listen(sockfd,listenQ);
	if(( connect( listenfd, (struct sockaddr *)&serveraddr, sizeof(struct sockaddr)))<0)
	{
		std::cout<<"safaffa"<<std::endl;
		return -1;
	}
	if((pid=fork())==0){
		confd=accept(sockfd,(struct sockaddr *)&clientaddr,&client);
		int ret=recv(confd,buff,sizeof(buff),0);
		buff[ret-1]='\0';
		std::cout<<buff<<std::endl;
	}
while(1){
	std::cout << "input" << std::endl;
	std::cin >> buff ;
	send(listenfd,buff,sizeof(buff),0);
}
	return 0;
}
