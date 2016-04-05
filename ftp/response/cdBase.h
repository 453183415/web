/*
 * cdBase.h
 *
 *  Created on: 2015年11月26日
 *      Author: zjl
 */

#ifndef CDBASE_H_
#define CDBASE_H_
#include "../response/responseBase.h"

class cdBase : public responseBase{
public:
	cdBase(const int &fd,const int &port,const std::string &ip,
			const std::string &path,const std::string &commond);
	bool check(const std::string &Path);
	virtual void Execute();
protected:
	std::string getPath();
};




#endif /* CDBASE_H_ */
