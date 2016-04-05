/*
 * Conection.cpp
 *
 *  Created on: 2015年11月26日
 *      Author: zjl
 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include"Connection.h"

namespace{
	const int ListenQ=1024;
	int openListenfd(int port){
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
		serveraddr.sin_port=htons((unsigned short ) port);
		serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
		if(bind(listenfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr))<0){
			return -1;
		}
		if(listen(listenfd,ListenQ)<0){
			return -1;
		}
		return listenfd;
	}

	void Close(int fd){
		int rc=close(fd);
		if(rc<0){
			//
		}
	}
}

Connection::Connection():listenfd(0),confd(0){

}

void Connection::listens(int port){
	listenfd=openListenfd(port);
}

int Connection::acceppt(){
	int clientlen;
	struct sockaddr clientaddr;
	clientlen=sizeof(clientaddr);
	confd=accept(listenfd,(struct sockaddr *)&clientaddr,reinterpret_cast<socklen_t *>(&clientlen));
	return confd;
}

void Connection::close(){
	Close(confd);
}






