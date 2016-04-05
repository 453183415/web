/*
 * loginBase.h
 *
 *  Created on: 2015年11月26日
 *      Author: zjl
 */

#ifndef LOGINBASE_H_
#define LOGINBASE_H_
#include "../response/responseBase.h"

class loginBase : public responseBase{
public:
	loginBase(const int &fd,const int &port,const std::string &ip,
													const std::string &path,const std::string &commond);
	bool check(const std::string &name,const std::string &passwd);
	void regist(const std::string &sourceip,int power);
	virtual void Execute();
protected:
	std::string getName();
	std::string  getPasswd();
	std::string  getPath();
	std::string getSourceIp();
	void getName_Passwd(const std::string & Path);
private:
	std::string userName;
	std::string passwd;
};




#endif /* LOGINBASE_H_ */
