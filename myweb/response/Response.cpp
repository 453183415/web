/*
 * Response.cpp
 *
 *  Created on: 2015年10月27日
 *      Author: zjl
 */
#include "Response.h"

#include"../base/myError.h"
//#include"ResponseState.h"
#include"StaticResponseState.h"
#include"DynamicResponseState.h"
#include<stdexcept>
Response::Response(int fd,std::string name,std::string cgiargs, bool isStc){
	if(isStc){
		state=new StaticResponseState(fd,name);
	}else{
		state=new DynamicResponseState(fd,name,cgiargs);
	}
}
Response::~Response(){
	if(state)
		delete state;
}
void Response::respond(){
	try{
		preResponse();
		doRespond();
	}catch(myError&err){
		return state->RespondError(err.ErrNum,err.ShortMsg,err.LongMsg);
	}
	catch(std::runtime_error&err){
		return state->RespondError("500","server internal error",err.what());
	}
}
void Response::preResponse(){
	state->preRespond();
}
void Response::doRespond(){
	state->prespond();
}

