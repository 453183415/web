/*
 * ResponseState.h
 *
 *  Created on: 2015年10月27日
 *      Author: zjl
 */

#ifndef RESPONSESTATE_H_
#define RESPONSESTATE_H_

#include<string>
#include<unistd.h>
#include<sys/stat.h>
#include<sstream>

class ResponseState{
public:
	ResponseState(int fd, std::string fName);
	void preRespond();
	void prespond();
	void RespondError(const std::string errNum,const std::string shortMsg,std::string longMsg);
	virtual ~ResponseState(){}

protected:
	int getFileDescriptor();
	const std::string getFileName();
	struct stat& getStat();
	const std::string sizeTypeToStr(std::string::size_type szeType);
	virtual const std::string buildRespondHeaders();
private:
	virtual const std::string buildForbiddenMsg()=0;
	virtual void doRespond()=0;
	const std::string buildRespondErrorHeaders(const std::string errNum,
																										const std::string shortMsg);
	const std::string buildRespondErrorBody(const std::string errNum,
																									const std::string shortMsg,std::string longMsg);
private:
	struct stat sbuf;
	int fileDescriptor;
	std::string fileName;
};



#endif /* RESPONSESTATE_H_ */
