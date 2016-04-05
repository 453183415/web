/*
 * RequestCreate.h
 *
 *  Created on: 2015年10月27日
 *      Author: zjl
 */

#ifndef REQUESTCREATE_H_
#define REQUESTCREATE_H_
#include"GetRequest.h"
class RequestCreate{
public:
	static Request* getRequestHandler(int fd, const std::string name,const std::string url);
private:
	static GetRequest getHandle;
};




#endif /* REQUESTCREATE_H_ */
