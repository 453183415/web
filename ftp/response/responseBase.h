/*
 * responseBase.h
 *
 *  Created on: 2015年11月25日
 *      Author: zjl
 */

#ifndef RESPONSEBASE_H_
#define RESPONSEBASE_H_
class responseBase{
public:
	responseBase(const int &confd,const int &port,const std::string &ip,
													const std::string &path,const std::string &commond);
	virtual ~responseBase(){

	}
	virtual void Execute()=0;
protected:
	int getConfd();
private:
	void getSourceIp(int fd);
private:
	int confd;
	int port;
	std::string ip;
	std::string path;
	std::string sourceIp;
	std::string commond;
};




#endif /* RESPONSEBASE_H_ */
