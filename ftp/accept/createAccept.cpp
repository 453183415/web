/*
 * creatAccept.cpp
 *
 *  Created on: 2015年11月26日
 *      Author: zjl
 */
#include "createAccept.h"

getAccept createAccept::result=getAccept();

Accept* createAccept::getAcceptCommond(int fd,int port,std::string ip,
																											std::string path,std::string commond){
	if(commond !=NULL ){
		result.init(port,fd,path,commond,ip);
		return &result;
	}
	return 0;
}
