/*
 * getBase.cpp
 *
 *  Created on: 2015年12月7日
 *      Author: zjl
 */
#include"getBase.h"

#include<unistd.h>
#include<sys/types.h>


getBase::getBase(const int &fd,const int &port,const std::string &ip,
																					const std::string &path,
																					const std::string &commond):confd(fd),
																					port(port),ip(ip),path(path),commond(commond)
{

}
bool getBase::findFile(const std::string &path){

	return true;
}

std::string getBase::getPath(){

	return path;
}

void getBase::Execute(){
	if(findFile(getPath())){

	}
}
