/*
 * lsBsae.cpp
 *
 *  Created on: 2015年12月6日
 *      Author: zjl
 */
#include"lsBase.h"
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>



lsBase::lsBase(const int &fd,const int &port,const std::string &ip,
																					const std::string &path,const std::string &commond):
																					confd(fd),port(port),ip(ip),path(path),commond(commond)
{

}

bool lsBase::check(const std::string  &path){

	//lianjie shujuku chankan quanxian
	return true;
}

std::string lsBase::getPath(){
	return path;
}

void lsBase::Execute(){
	if(check(getPath())){

	}
}
