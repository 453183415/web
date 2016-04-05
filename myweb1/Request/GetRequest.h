/*
 * GetRequest.h
 *
 *  Created on: 2015年10月27日
 *      Author: zjl
 */

#ifndef GETREQUEST_H_
#define GETREQUEST_H_
#include"Request.h"

class GetRequest:public Request{
	virtual void doExecute();
	bool parseurl(std::string&filename,std::string& cdiargr);
	bool parseStaticContentUrl(std::string&filename);
	bool parseDynamicContentUrl(std::string &filename,std::string&cgiargs);
	void assignCgiArgs(std::string&cgiargs);
	void doAssignCgiArgs(std::string::size_type pos,std::string&cgiargs);
};



#endif /* GETREQUEST_H_ */
