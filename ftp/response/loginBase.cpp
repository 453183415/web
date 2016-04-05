/*
 * loginBase.cpp
 *
 *  Created on: 2015年12月7日
 *      Author: zjl
 */

#include"loginBase.h"
#include<vector>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
namespace{
	void fun( std::vector<std::string>&buf,const std::string & path){
		char name[20];
		char passwd[20];
		std::string path_;
		path_=path;
		sscanf(path_.c_str(),"%s%s",name,passwd);
		buf.push_back(name);
		buf.push_back(passwd);
	}
}

loginBase::loginBase(const int &fd,const int &port,const std::string &ip,
												const std::string &path,const std::string &commond):
														confd(fd),port(port),ip(ip),path(path),commond(commond)
{

}
bool loginBase::check(const std::string & name,const std::string &passwd){
	return true;
}

void loginBase::regist(const std::string &source,int power){
	//register
}

std::string loginBase::getPasswd(){
	return  passwd;
}
std::string loginBase::getName(){

	return userName;
}

std::string loginBase::getPath(){
	return path;

}
std::string loginBase::getSourceIp(){
	return sourceIp;
}

void loginBase::getName_Passwd(const std::string & path){
         std::vector<std::string> buf;
         fun(buf,path);
         this->userName=buf[0];
         this->passwd=buf[1];
}

void loginBase::Execute(){
	int power;
	if(check(getName(),getPasswd())){
		regist(getSourceIp(),power);
	}
}
