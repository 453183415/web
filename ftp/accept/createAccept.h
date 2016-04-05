/*
 * createAccept.h
 *
 *  Created on: 2015年11月24日
 *      Author: zjl
 */

#ifndef CREATEACCEPT_H_
#define CREATEACCEPT_H_

#include"getAccept.h"

class createAccept{
public:
	static Accept* getAcceptCommond(int fd,int port,std::string ip,
																													std::string path,std::string commond);
private:
	static getAccept result;
};





#endif /* CREATEACCEPT_H_ */
