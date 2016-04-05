/*
 * GetRequest.cpp
 *
 *  Created on: 2015年10月27日
 *      Author: zjl
 */
#include"GetRequest.h"
#include"../response/Response.h"

void GetRequest::doExecute(){
	std::string filename,cgiargs;

	bool isStateic = parseurl(filename,cgiargs);
	Response(getFileDescription(),filename,cgiargs,isStateic).respond();
}

bool GetRequest::parseurl(std::string & filename,std::string & cgiargs){
	if(getUrl().find("cgi_bin")==std::string::npos){
		return parseStaticContentUrl(filename);
	}else{
		return parseDynamicContentUrl(filename,cgiargs);
	}
}

bool GetRequest::parseStaticContentUrl(std::string &filename){
	std::string url=getUrl();
	filename="test-files"+url;
	if(url[url.length()-1]=='/'){
		filename+="index.html";
	}
	return true;
}

bool GetRequest::parseDynamicContentUrl(std::string&filename,std::string &cgiargs){

	assignCgiArgs(cgiargs);
	filename="."+getUrl();
	return false;
}

void GetRequest::assignCgiArgs(std::string & cgiargs){
	std::string url=getUrl();
	std::string::size_type pos=url.find_first_of("?");

	doAssignCgiArgs(pos,cgiargs);
}

void GetRequest::doAssignCgiArgs(std::string::size_type pos, std::string& cgiargs){

	if(pos!= std::string::npos){
		cgiargs=getUrl().substr(pos,getUrl().length()-1);
	}else{
		cgiargs.clear();
	}
}



















