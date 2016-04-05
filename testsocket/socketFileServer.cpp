/*
 * socketFileServer.cpp
 *
 *  Created on: 2016年3月1日
 *      Author: zjl
 */
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/signal.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<iostream>
void handle(int fd);
void handleSig(int signal);
int main(int argc ,char ** argv){

	if(argc < 2){
		printf("error");
		exit(0);
	}
	int sockfd,connfd;
	int opt=1;
	pid_t pid;
	struct sockaddr_in serveraddr,clientaddr;
	bzero(&serveraddr,sizeof(serveraddr));
	serveraddr.sin_family= AF_INET;
	serveraddr.sin_port = htons(8000);
	serveraddr.sin_addr.s_addr=INADDR_ANY;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
	bind(sockfd,(sockaddr *)&serveraddr,sizeof(serveraddr));
	listen(sockfd,1024);
	signal(SIGCHLD,handleSig);
	socklen_t clientlen;
	clientlen= sizeof(clientaddr);
	while(1){
		connfd=accept(sockfd,(struct sockaddr *)&clientaddr,&clientlen);
		pid=fork();
		 if(pid == 0){
			 close(sockfd);
			handle(connfd);
		}else
		 if(pid>0){
			 close(connfd);
		 }
	}
	return 0;
}

void handle(int fd){
	char buf[1024];
	struct stat buf1;
	int filefd;
	ssize_t n,ptrlen;
	ptrlen=0;
	bzero(&buf,1024);
	n=read(fd,buf,1024);
#if(1)
	stat(buf,&buf1);
	std::cout<<buf1.st_size<<std::endl;
	filefd=open(buf,O_RDONLY);
	if(filefd<0){
		printf("open file error");
//		write(fd,"open file error",15);
		close(fd);
		exit(0);
	}
	bzero(&buf,1024);
	sprintf(buf,"%lu",buf1.st_size);
	printf("%s",buf);
	write(fd,buf,sizeof(buf));
#if(1)
	bzero(&buf,1024);
	while(ptrlen<=buf1.st_size){
		n=read(filefd,buf,1024);
		ptrlen+=n;
		write(fd,buf,sizeof(buf));
		printf("%s",buf);
		sleep(6);
		bzero(&buf,1024);
	}
#endif
#endif
	close(fd);
	close(filefd);
	exit(0);
}
void handleSig(int signal){
	pid_t pid;
	int stat;
	while((pid= waitpid(-1,&stat,WNOHANG))>0);
}


