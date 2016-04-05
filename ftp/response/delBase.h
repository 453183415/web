/*
 * delBase.h
 *
 *  Created on: 2015年11月26日
 *      Author: zjl
 */

#ifndef DELBASE_H_
#define DELBASE_H_
#include "../response/responseBase.h"
class delBase : public  responseBase{
public:
	delBase(const int &fd,const int &port,const std::string &ip,
			const std::string &path,const std::string &commond);

	virtual void Execute();
	bool check(const std::string &sourceIp);
	bool findFile(const std::string &filepath);
protected:
	std::string getPath();
	std::string getSourceIp();
};



#endif /* DELBASE_H_ */
