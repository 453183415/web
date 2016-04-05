/*
 * myError.h
 *
 *  Created on: 2015年10月27日
 *      Author: zjl
 */

#ifndef MYERROR_H_
#define MYERROR_H_

#include<string>

struct myError{
	myError(const std::string& errNum,const std::string&shortMsg,const std::string&longMsg):ErrNum(errNum),ShortMsg(shortMsg),LongMsg(longMsg){}
	~myError() throw(){}
	std::string ErrNum;
	std::string ShortMsg;
	std::string LongMsg;
};


#endif /* MYERROR_H_ */
