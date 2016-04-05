/*
 * StaticResponseState.cpp
 *
 *  Created on: 2015年10月27日
 *      Author: zjl
 */
#include"StaticResponseState.h"

#include"base/IoWrite.h"
StaticResponseState::StaticResponseState(int fd,std::string fName):ResponseState(fd,fName){

}
const std::string StaticResponseState::buildForbiddenMsg(){
	return "i couldn't read the file";
}

void StaticResponseState::doResponsd(){
	IoWrite writer(getFileDescriptor());
	writer.writeString(buildRespondHeaders());
	writer.writeFile(getFileName(),getStat().st_size);
}

const std::string StaticResponseState::getFiletype(){
	std::string fileName = getFileName();
	if(fileName.find(".html")){
		return std::string("text/html");
	}else if(fileName.find(".gif")){
		return std::string("image/gif");
	}else if(fileName.find(".jpg")){
		return std::string("image/jepg");
	}else{
		return std::string("text/plain");
	}

}

























































