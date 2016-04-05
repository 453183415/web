/*
 * RequestCreate.cpp
 *
 *  Created on: 2015年10月27日
 *      Author: zjl
 */
#include"RequestCreate.h"
GetRequest RequestCreate::getHandle=GetRequest();

Request* RequestCreate::getRequestHandler(int fd,const std::string name,const std::string url){
	if(name=="GET"){
		getHandle.init(fd,url);
		return &getHandle;
	}
	return 0;
}



