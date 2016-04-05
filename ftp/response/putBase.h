/*
 * putBase.h
 *
 *  Created on: 2015年11月26日
 *      Author: zjl
 */

#ifndef PUTBASE_H_
#define PUTBASE_H_
#include "../response/responseBase.h"

class putBase : public responseBase{
public:
	putBase(const int &fd,const int &port,const std::string &ip,
								const std::string &path,const std::string &commond);
	virtual void Execute();
	bool check(const std::string &sourceip);
protected:
	std::string getSourceIp();
};




#endif /* PUTBASE_H_ */
