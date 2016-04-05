/*
 * DynameicResponseState.h
 *
 *  Created on: 2015年10月27日
 *      Author: zjl
 */

#ifndef DYNAMICRESPONSESTATE_H_
#define DYNAMICRESPONSESTATE_H_

#include"ResponseState.h"

class DynamicResponseState: public ResponseState{
public:
	DynamicResponseState(int fd,std::string fName,std::string args);

private:
	virtual const std::string buildForbiddenMsg();
	virtual void doRespond();
	void execveCgiProgram();

private:
	std::string cgiArgs;

};




#endif /* DYNAMICRESPONSESTATE_H_ */
