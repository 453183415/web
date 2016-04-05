/*
 * delBase.cpp
 *
 *  Created on: 2015年12月7日
 *      Author: zjl
 */
#include"delBase.h"

delBase::delBase(const int &fd,const int &port,const std::string &ip,
																					const std::string &path,
																					const std::string &commond):confd(fd),
																					port(port),ip(ip),path(path),commond(commond)
{

}


bool delBase::check(const std::string&sourceIp){

	return true;
}

bool delBase::findFile(const std::string & path){

	return true;
}

std::string delBase::getPath(){

	return path;
}

std::string delBase::getSourceIp(){

	return sourceIp;
}

void delBase::Execute(){
	if(check(getSourceIp())){
		if(findFile(getPath())){

		}
	}
}

delBase::delBase(){

}
