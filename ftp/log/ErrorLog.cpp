/*
 * ErrorLog.cpp
 *
 *  Created on: 2015年12月11日
 *      Author: zjl
 */
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include"ErrorLog.h"
namespace{
	int Open(const std::string path){
		int fd;
		fd=open(path.c_str(),O_WRONLY|O_APPEND);
		return fd;
	}
	int Write(const std::string time, const std::string content, int fd){
		int result;
		std::string buf=content+time;
		char buff[buf.size()+1];
		buff[buf.size()+1]='\0';
		strcpy(buff,buf.c_str());
		unsigned int size=buf.size();
		result=write(fd,buff,size);
		return result;
	}
}
void ErrorLog::writen(){
	 std::string path;
	if(rank==0)
		path="/home/zjl/C++/ftp/error.txt";
	 if(rank==1)
		path="/home/zjl/C++/ftp/login.txt";
	if(rank==2)
		path="/home/zjl/C++/ftp/request.txt";
	int fd=Open(path);
	if(fd>0){

		Write(getTime(),content,fd);
	}
	else{
		exit(0);
	}
}



