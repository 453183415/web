/*
 * RequestManager.h
 *
 *  Created on: 2015年10月27日
 *      Author: zjl
 */

#ifndef REQUESTMANAGER_H_
#define REQUESTMANAGER_H_
#include<string>
class Request;

class RequestManager{
public:
	RequestManager(int confd);
	void run();
private:
	Request* getRequestHandle();
private:
	int fileDescriptor;
	Request* request;
};




#endif /* REQUESTMANAGER_H_ */
