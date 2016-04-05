/*
 * Read.cpp
 *
 *  Created on: 2015年11月23日
 *      Author: zjl
 */

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<iostream>
#include"Read.h"
#include<sys/types.h>
#include<sys/socket.h>
namespace
{
	const int max_length =8096;
	char buf[max_length];
	void receive( int fd){
		int ret= recv(fd,buf,sizeof(buf),0);
		if(ret<0)
			fprintf(stderr,"%s:  %s\n","read error",strerror(errno));
		buf[ret-1]='\0';
	}
	void parse(char*bu){
		strcpy(bu,buf);
	}
}

Read::Read(int fd){
	receive(fd);
}

void Read::getLine(std::vector<std::string>&buf){
	char userbuf[max_length],commond[max_length],url[max_length],ip[max_length],port[max_length];
	parse(userbuf);
	sscanf(userbuf,"%s %s %s %s",commond,url,ip,port);
	buf.push_back(commond);
	buf.push_back(url);
	buf.push_back(ip);
	buf.push_back(port);
}











