/*
 * myweb.cpp
 *
 *  Created on: 2015年10月27日
 *      Author: zjl
 */
#include"connect/Connection.h"
#include"Request/RequestManager.h"
#include<cstdlib>

namespace{
int getPortFromCommandLine(char **argv){
	return atoi(argv[1]);
}

int getDefalutport(){
	return 8080;
}

int getPort(int argc,char**argv){
	if(argc==2){
		return getPortFromCommandLine(argv);
	}else{
		return getDefalutport();
	}
}
}

int main(int argc, char** argv)
{
	NetConnection connection;
	connection.listn(getPort(argc,argv));
	while(1){
		int confd=connection.accept();
		RequestManager(confd).run();
		connection.close();
	}
	return 0;
}
















