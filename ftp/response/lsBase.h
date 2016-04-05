/*
 * lsBase.h
 *
 *  Created on: 2015年11月26日
 *      Author: zjl
 */

#ifndef LSBASE_H_
#define LSBASE_H_
#include "../response/responseBase.h"

class lsBase : public responseBase{
public:
	lsBase(const int &fd,const int &port,const std::string &ip,
								const std::string &path,const std::string &commond);
	bool check(const std::string &path);
	virtual void Execute();
protected:
	std::string getPath();
};




#endif /* LSBASE_H_ */
