/*
 * StaticResponseState.h
 *
 *  Created on: 2015年10月27日
 *      Author: zjl
 */

#ifndef STATICRESPONSESTATE_H_
#define STATICRESPONSESTATE_H_
#include"ResponseState.h"
class StaticResponseState:public ResponseState{
public:
	StaticResponseState(int fd, std::string  fName);
private:
	virtual const std::string buildForbiddenMsg();
	virtual void doRespond();
	virtual const std::string buildRespondHeaders();
	const std::string getFiletype();
};



#endif /* STATICRESPONSESTATE_H_ */
