/*
 * Accept.cpp
 *
 *  Created on: 2015年11月24日
 *      Author: zjl
 */

#include<sys/socket.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<sys/types.h>
#include"Accept.h"

void Accept::init(int port,int confd,std::string path,std::string commond,std::string ip){
	this->port=port;
	this->confd=confd;
	this->ip=ip;
	this->path=path;
	this->commond=commond;
}

int  Accept::getPort(){
	return this->port;
}

int Accept::getConfd(){
	return this->confd;
}

std::string Accept::getCommond(){
	return this->commond;
}
std::string Accept::getPath(){
	return this->path;
}

std::string Accept::getIp(){
	return this->ip;
}

void Accept::execute(){

	doExecute();
}









