/*
 * manageAccept.cpp
 *
 *  Created on: 2015年11月26日
 *      Author: zjl
 */
#include"manageAccept.h"
#include"Accept.h"
#include"createAccept.h"
#include"../base/Read.h"
#include<iostream>
#include<stdlib.h>
namespace{
	class parse{
		public:
			parse(int confd){
				parseAccept(confd);
			}
			const std::string getComondName(){
				return commond;
			}
			const std::string getPath(){
				return path;
			}
			const int getPort(){
				return port;
			}
			const std::string getIp(){
				return ip;
			}
		private:
			void parseAccept(int fd){
					Read reade(fd);
					std::vector<std::string>content;
					reade.getLine(content);
					commond =content[0];
					path=content[1];
					ip=content[2];
					port=atoi(content[3].c_str());

			}
		private:
			int port;
			std::string commond;
			std::string ip;
			std::string path;
};
}

manageAccept::manageAccept(int fd):confd(fd),accepted(0){

}
void manageAccept::run(){
	if(getAcceptCommond()){
		accepted->execute();
	}
}

Accept* manageAccept::getAcceptCommond(){
	parse parser(confd);
	return accepted=createAccept::getAcceptCommond(confd,parser.getPort(),parser.getIp(),
																													parser.getPath(),parser.getComondName());
}





























