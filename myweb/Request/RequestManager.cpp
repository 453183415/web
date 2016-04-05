/*
 * RequestManager.cpp
 *
 *  Created on: 2015年10月27日
 *      Author: zjl
 */
#include"RequestManager.h"
#include"Request.h"
#include"RequestCreate.h"
#include"../base/IoRead.h"

namespace{
class Parser{
public:
	Parser(int confd){
		parseRequestHeadlers(confd);
	}
	const std::string getUrl(){
		return url;
	}
	const std::string getMethodName(){
		return method;
	}
private:
	void parseRequestHeadlers(int fd){
		IoRead reade(fd);
		std::vector<std::string>header;
		reade.getLineSpliteedByBlank(header);

		method=header[0];
		url=header[1];
		version=header[2];
	}
private:
	std::string method;
	std::string url;
	std::string version;
};
}

RequestManager::RequestManager(int confd):fileDescriptor(confd),request(0){

}

void RequestManager::run(){
	if(getRequestHandle()){
		request->execute();
	}
}

Request* RequestManager::getRequestHandle(){
	Parser parser(fileDescriptor);
	return request=RequestCreate::getRequestHandler(fileDescriptor,
			parser.getMethodName(),parser.getUrl());
}























