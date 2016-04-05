/*
 * Request.cpp
 *
 *  Created on: 2015年10月27日
 *      Author: zjl
 */
#include"Request.h"

void Request::init(int fd, std::string url){
	this->fileDescriptor=fd;
	this->url=url;
}

void Request::execute(){
	doExecute();
}

int Request::getFileDescription()const{
	return fileDescriptor;
}

const std::string&Request::getUrl()const{
	return url;
}
