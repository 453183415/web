/*
 * ResponseState.cpp
 *
 *  Created on: 2015年10月27日
 *      Author: zjl
 */

#include"ResponseState.h"
#include "base/myError.h"
#include "base/IoWrite.h"

ResponseState::ResponseState(int fd, std::string fName):fileDescriptor(fd),fileName(fName){

}
void ResponseState::preRespond(){
	if(stat(const_cast<char*>(fileName.c_str()),&sbuf)<0){
		throw myError("404","not found","Couldn't find this file");
	}
	if(!(S_ISREG(sbuf.st_mode))||!(S_IRUSR&sbuf.st_mode)){
		throw myError("403","Forbidden",buildForbiddenMsg());
	}
}
void ResponseState::prespond(){
	doRespond();
}

void ResponseState::RespondError(const std::string errNum,
																					const std::string shortMsg,const std::string longMsg){
	IoWrite(getFileDescriptor()).writeString(buildRespondErrorHeaders(errNum,shortMsg)+
																					buildRespondErrorBody(errNum,shortMsg,longMsg));
}

const std::string ResponseState::buildRespondErrorHeaders(const std::string errNum,
																																		const std::string shortMsg){
	return "HTTP/1.0"
			+errNum
			+":"
			+shortMsg
			+"\r\n"
			+std::string("Content-type: text/html\r\n");
}

const std::string ResponseState::buildRespondErrorBody(const std::string errNum,
																							const std::string shortMsg,const std::string longMsg){
	std::string bodyContent="<html><title>my Error</title>"
						+std::string ("<body bgcocor = ffffff >\r\n")
						+errNum
						+":"
						+shortMsg
						+"\r\n"
						+longMsg
						+":"
						+fileName
						+"<hr><em>The my web server</em>\r\n";
	return "Content-length:"
			+sizeTypeToStr(bodyContent.length())
			+"\r\n\r\n"
			+bodyContent;
}

const std::string ResponseState::sizeTypeToStr(std::string::size_type sizeType){
	std::stringstream ss;
	std::string s;
	ss<<sizeType;
	ss>>s;
	return s;
}

const std::string ResponseState::buildRespondHeaders(){
	return "HTTP/1.0 200 OK\r\n"+std::string("Server:my Web Server\r\n");
}

int ResponseState::getFileDescriptor(){
	return fileDescriptor;
}

const std::string ResponseState::getFileName(){
	return fileName;
}

struct stat &ResponseState::getStat(){
	return sbuf;
}












