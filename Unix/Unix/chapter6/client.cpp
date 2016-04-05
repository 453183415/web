/*
 * client.cpp
 *
 *  Created on: 2016年1月22日
 *      Author: zjl
 */

#include"../unix.h"
#define MAXSIZE 1024
void str_cli(FILE *, int );
int max(int,int);
int main(int argc , char ** argv)
{
	int sockfd, connfd;
	struct sockaddr_in client;
	bzero(&client,sizeof(client));
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	client.sin_family=AF_INET;
	client.sin_port=htons(55555);
	inet_pton(AF_INET,argv[1],&client.sin_addr);
	connfd=connect(sockfd,(struct sockaddr *)&client,sizeof(client));
	str_cli(stdin,connfd);
	return 0;
}
void str_cli( FILE *fp , int sockfd){
	int maxfdp1, stdineof;
	fd_set rset;
	char buf[MAXSIZE];
	int n;
	stdineof=0;
	FD_ZERO(&rset);
	for( ; ; ){
		if(stdineof == 0)
			FD_SET(fileno(fp),&rset);
		FD_SET(sockfd,&rset);
		maxfdp1=max(fileno(fp),sockfd ) +1;
		select(maxfdp1,&rset,NULL,NULL,NULL);
		if(FD_ISSET(sockfd,&rset) ){
			if( (n=read(sockfd,buf,MAXSIZE) ) == 0){
				if(stdineof == 1)
					return;
				else{
					printf("str_cli : server terminated prematurely");
					return;
				}
			}
			write(fileno(stdout),buf,n);
		}
		if( FD_ISSET( fileno( fp ) , &rset) ){
			if( ( n=read(fileno(fp),buf,MAXSIZE) ) ==0){
				stdineof=1;
				shutdown(sockfd,SHUT_WR);
				FD_CLR(fileno(fp), &rset);
				continue;
			}
			write(sockfd,buf,n);
		}
	}
}

int max(int a, int b){
	return ( a > b ) ? a : b ;
}
