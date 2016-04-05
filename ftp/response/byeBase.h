/*
 * byeBase.h
 *
 *  Created on: 2015年11月26日
 *      Author: zjl
 */

#ifndef BYEBASE_H_
#define BYEBASE_H_
#include "../response/responseBase.h"

class byeBase : public responseBase{
public:
	byeBase(const int &fd,const int &port,const std::string &ip,
			const std::string &path,const std::string &commond);
	virtual void Execute();
protected:
	bool logout(const std::string &sourceip);
	std::string getSourceip();
};




#endif /* BYEBASE_H_ */
