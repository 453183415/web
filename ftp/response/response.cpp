/*
 * response.cpp
 *
 *  Created on: 2015年12月6日
 *      Author: zjl
 */
#include"response.h"
#include"responseBase.h"
#include"getBase.h"
#include"cdBase.h"
#include"putBase.h"
#include"lsBase.h"
#include"delBase.h"
#include"byeBase.h"
#include"loginBase.h"
#include"errorBase.h"
#include<stdexcept>

response::response(const int &fd,const int &port,const std::string &ip,
																					const std::string &path,const std::string &commond){
	if(commond=="GET"){
		state= new getBase(fd,port,ip,path,commond);
		log(ip,commond,path);
	}else if(commond=="CD"){
		state=new cdBase(fd,port,ip,path,commond);
		log(ip,commond,path);
	}else 	if(commond=="PUT"){
		state=new putBase(fd,port,ip,path,commond);
		log(ip,commond,path);
	}else 	if(commond=="LS"){
		state= new lsBase(fd,port,ip,path,commond);
		log(ip,commond,path);
	}else 	if(commond=="DEL"){
		state= new delBase(fd,port,ip,path,commond);
		log(ip,commond,path);
	}else 	if(commond=="BYE"){
		state= new byeBase(fd,port,ip,path,commond);
		log(ip,commond,path);
	}else 	if(commond=="LOGIN"){
		state=new loginBase(fd,port,ip,path,commond);
		log(ip,commond,path);
	}else{
		state= new errorBase();
	}
}
void response::log(const std::string &ip,const std::string &path,const std::string &commond){

}
 response::~response(){
	 if(state){
		 delete state;
	 }
 }


