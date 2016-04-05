/*
 * socketFileClient.cpp
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
#include<dirent.h>
void handleSig(int signal);
int  trave_dir(char* path){
	char filename[256];
	bzero(&filename,256);
//	strcat(filename,path);
//	printf("%s\n",filename);
		DIR *DP;
		struct dirent *file;
		struct stat sd;
		if(!(DP=opendir(path))){
			printf("error opendir %s\n",path);
			return -1;
		}
		while((file=readdir(DP))!= NULL){
			if(strcmp(file->d_name,".")==0||strcmp(file->d_name,"..")==0){
				continue;
			}
//			printf("%s\n",file->d_name);
			sprintf(filename,"%s%s",path,file->d_name);

			if(lstat(filename,&sd)<0){
				continue;
			}
			if(!S_ISDIR(sd.st_mode))
				printf("%s\n",filename);
			if(S_ISDIR(sd.st_mode)){
				trave_dir(strcat(filename,"/"));
			}
		}
		closedir(DP);
	return 0;
}
int main(int argc , char **argv)
{
	#if(0)
	if(argc <4){
		printf("error");
		exit(0);
	}
	char serverFileName[256],filename[256],buf[1024];
	int sockfd,fd;
	ssize_t n,ptrlen,len;
	len=0;
	bzero(&serverFileName,256);
	bzero(&filename,256);
	strncpy(filename,argv[3],strlen(argv[3]));
	strncpy(serverFileName,argv[2],strlen(argv[2]));

	struct sockaddr_in clientaddr;
	bzero(&clientaddr,sizeof(clientaddr));
	clientaddr.sin_family= AF_INET;
	clientaddr.sin_port = htons(8000);
	inet_pton(AF_INET,argv[1],&clientaddr.sin_addr);
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	signal(SIGCHLD,handleSig);
	int ret =connect(sockfd,(struct sockaddr *)&clientaddr,sizeof(clientaddr));

	if(ret<0){
		printf("connect error");
		close(sockfd);
		exit(0);
	}
	fd=open(filename,O_WRONLY|O_RDONLY|O_CREAT);
	write(sockfd,serverFileName,strlen(serverFileName));

		if(fd<0){
		//		creat(filename,(O_CREAT|O_WRONLY|O_RDONLY));
				printf("file create error");
				exit(0);
			}
	bzero(&buf,1024);
	read(sockfd,buf,1024);
	ptrlen=strtoul(buf,NULL,10);
	std::cout<<ptrlen<<std::endl;
	bzero(&buf,1024);
	while(len<ptrlen){
		n=read(sockfd,buf,1024);
		len+=n;
		lseek(fd,0,SEEK_END);
		write(fd,buf,sizeof(buf));
		printf("%s",buf);
		bzero(&buf,1024);
	}
	close(sockfd);
	exit(0);
	trave_dir(argv[1]);
	#endif
	char buf[1024];
	int fd,fd1;
	fd=open("/home/zjl/图片/zjl.png",O_RDONLY);
	fd1=open("/home/zjl/图片/zjll.png",O_WRONLY|O_RDONLY|O_CREAT);
	if((fd<0)&&(fd1<0)){
		printf("error");
		exit(0);
	}
	bzero(&buf,1024);
	while(read(fd,buf,1024)>0){
		write(fd1,buf,sizeof(buf));
		bzero(&buf,1024);
	}
}
void handleSig(int signal){
	pid_t pid;
	int stat;
	while((pid= waitpid(-1,&stat,WNOHANG))>0);
	exit(0);
}
