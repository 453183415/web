/*
 * byeBase.cpp
 *
 *  Created on: 2015年12月7日
 *      Author: zjl
 */
#include"byeBase.h"

byeBase::byeBase(const int &fd,const int &port,const std::string &ip,
																					const std::string &path,
																					const std::string &commond):confd(fd),
																					port(port),path(path),commond(commond)
{

}
bool byeBase::logout(const std::string &sourceIp){

	return true;
}

std::string byeBase::getSourceip(){
	return sourceIp;

}

void byeBase::Execute(){
	if(logout(getSourceip())){

	}
}

