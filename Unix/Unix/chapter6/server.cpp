/*
 * server.cpp
 *
 *  Created on: 2016年1月22日
 *      Author: zjl
 */
#include "../unix.h"
#define MAXSIZE 1024
extern const int FD=256;
//void str_echo( int);

int  main(int argc , char** argv)
{
	int i,maxi,maxfd,listenfd,connfd,sockfd;
	int nready,client[FD];
	ssize_t n;
	fd_set rset, allset;
	char buf[MAXSIZE];
	socklen_t clilnt;
	struct sockaddr_in  clientaddr, servaddr;
	listenfd=socket(AF_INET,SOCK_STREAM,0);
	bzero(&clientaddr,sizeof(clientaddr));
	clientaddr.sin_family = AF_INET;
	clientaddr.sin_port = htons(55555);
	clientaddr.sin_addr.s_addr= htonl(INADDR_ANY);
	bind(listenfd,(struct sockaddr *) & clientaddr,sizeof(clientaddr));
	listen(listenfd,1024);
	maxfd = listenfd;
	maxi =-1;
	for(i=0; i< FD;i++)
		client[i] = -1;
	FD_ZERO(&allset);
	FD_SET(listenfd,&allset);
	for( ; ; ){
		rset = allset;
		nready= select(maxfd,&rset,NULL, NULL, NULL);
		if(FD_ISSET(listenfd,&rset)){
			clilnt=sizeof(servaddr);
			connfd= accept(listenfd,(struct sockaddr *) &servaddr,&clilnt);
			for(i=0; i < FD ; i++)
				if(client[i]<0){
					client[i]=connfd;
					break;
				}
			if(i == FD){
				printf("too many clients");
				return -1;
			}
			if( connfd > maxfd)
				maxfd = connfd;
			if(i > maxi)
				maxi = i;
			if ( --nready <= 0 )
				continue;
		}
		for(i =0; i< maxi;i++){
			if( ( sockfd= client[i]) < 0)
				continue;
			if(FD_ISSET(sockfd, &rset)){
				if( ( n = read(sockfd,buf,MAXSIZE)) ==0 ){
					close(sockfd);
					std::cout<<"lian jie" << sockfd<<"yi duan kai" << std::endl;
					FD_CLR(sockfd,&rset);
					client[i] = -1;
				}else
					write(sockfd,buf,n);
				if(--nready <= 0)
					break;
			}
		}
	}
}
