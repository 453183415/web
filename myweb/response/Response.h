/*
 * response.h
 *
 *  Created on: 2015年10月27日
 *      Author: zjl
 */

#ifndef RESPONSE_H_
#define RESPONSE_H_

#include<string>
class ResponseState;
class Response{
public:
	Response(int fd,std::string name,std::string cgiargs, bool isStc);
	~Response();
	void respond();
private:
	void preResponse();
	void doRespond();
	Response(const Response &);
	Response& operator=(const Response &);
private:
	ResponseState* state;
};



#endif /* RESPONSE_H_ */
