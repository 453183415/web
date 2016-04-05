/*
 * putBase.cpp
 *
 *  Created on: 2015年12月6日
 *      Author: zjl
 */
#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include"putBase.h"




putBase::putBase(const int &fd,const int &port,const std::string &ip,
																					const std::string &path,const std::string &commond){
	this->confd=fd;
	this->port=port;
	this->ip=ip;
	this->path=path;
	this->commond=commond;
}

void putBase::Execute(){
		if(check(getSourceIp())){
			///////创建一个套接字与客户端传输数据
		}else{
			//返回无权限
		}
}
bool putBase::check(const std::string &ip){
                                      /////////在登陆数据库里查看是否有权限
	return true;
}



std::string putBase::getSourceIp(){
	return sourceIp;
}
