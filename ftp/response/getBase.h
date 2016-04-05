/*
 * getBase.h
 *
 *  Created on: 2015年11月26日
 *      Author: zjl
 */

#ifndef GETBASE_H_
#define GETBASE_H_

#include "../response/responseBase.h"

class getBase : public responseBase{
public:
	getBase(const int &fd,const int &port,const std::string &ip,
			const std::string &path,const std::string &commond);
	virtual void Execute();
protected:
	bool findFile(const std::string &path);
	std::string getPath();
};



#endif /* GETBASE_H_ */
