/*
 * responseBase.cpp
 *
 *  Created on: 2015年12月6日
 *      Author: zjl
 */

#include"responseBase.h"
#include<sys/socket.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

responseBase::responseBase(const int &confd,const int &port,const std::string &ip,
													const std::string &path,const std::string &commond):confd(confd),
													port(port),ip(ip),path(path),commond(commond),sourceIp(NULL){
	getSourceIp(getConfd());
}

void responseBase::getSourceIp(int fd){
	socklen_t len=sizeof(struct sockaddr_in);
	struct sockaddr_in cli;
	if(getpeername(fd,(struct sockaddr*)&cli,&len)==0){
		sourceIp=inet_ntoa(cli.sin_addr);
	}
}

int responseBase::getConfd(){
	return confd;
}

