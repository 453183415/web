/*
 * Connection.cpp
 *
 *  Created on: 2015年10月27日
 *      Author: zjl
 */
#include"Connection.h"
#include<cstdio>

#include<cstring>
#include<cstdlib>
#include<unistd.h>
#include<cerrno>
#include<arpa/inet.h>
#include<sys/socket.h>

#include<sys/types.h>
namespace{
const int LISTENQ=1024;
void unix_error(char *msg)
{
	fprintf(stderr,"%s: %s\n",msg,strerror(errno));
	exit(0);
}

int open_listenfd(int port)
{
	int listenfd,optval=1;
	struct sockaddr_in serveraddr;

	if((listenfd=socket(AF_INET,SOCK_STREAM,0))<0){
		return -1;
	}
	if(setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,(const void *)&optval,sizeof(int))<0){
		return -1;
	}
	bzero((char*)&serveraddr,sizeof(serveraddr));
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons((unsigned short)port);
	serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
	if(bind(listenfd,(sockaddr *)& serveraddr,sizeof(serveraddr))<0)
		return -1;
	if(listen(listenfd,LISTENQ)<0){
		return-1;
	}
	return listenfd;
}

int Open_listenfd(int port)
{
	int rc;
	if((rc=open_listenfd(port))<0){
		unix_error("Open_listen error");
	}
	return rc;
}

int Accept(int s, struct sockaddr *addr,socklen_t *addrlen)
{
	int rc;
	if((rc=accept(s,addr,addrlen))<0)
		unix_error("accept error");
	return rc;
}

void Close(int fd)
{
	int rc;
	if((rc=close(fd))<0){
		unix_error("close error");
	}
}
}
NetConnection::NetConnection():listenfd(-1),confd(-1){

}

void NetConnection::listn(int port){
	listenfd=Open_listenfd(port);
}

int NetConnection::accept(){
	int clientlen;
	struct sockaddr_in clientaddr;
	clientlen=sizeof(clientaddr);
	confd=Accept(listenfd,(sockaddr *)&clientaddr,reinterpret_cast<socklen_t*>(&clientlen));
	return confd;
}

void NetConnection::close(){
	Close(confd);
}





















