/*
 * Request.h
 *
 *  Created on: 2015年10月27日
 *      Author: zjl
 */

#ifndef REQUEST_H_
#define REQUEST_H_

#include<string>

class Request{
public:
	void init(int fd, std::string url);
	void execute();
	virtual ~Request(){}
protected:
	int getFileDescription()const;
	const std::string& getUrl()const;
private:
	virtual void doExecute()=0;
private:
	int fileDescriptor;
	std::string url;
};



#endif /* REQUEST_H_ */
