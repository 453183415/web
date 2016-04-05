/*
 * cdBase.cpp
 *
 *  Created on: 2015年12月7日
 *      Author: zjl
 */
#include"cdBase.h"

cdBase::cdBase(const int &fd,const int &port,const std::string &ip,
																					const std::string &path,
																					const std::string &commond):confd(fd),
																					port(port),path(path),commond(commond)
{

}
bool cdBase::check(const std::string &path){


	return true;
}

std::string cdBase::getPath(){

	return path;
}

void cdBase::Execute(){
	if(check(getPath())){

	}
}
