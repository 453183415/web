/*
 * ZSql.h
 *
 *  Created on: 2015年8月3日
 *      Author: zjl
 */

#ifndef ZSQL_H_
#define ZSQL_H_
#include<iostream>
#include<mysql/mysql.h>
#include<errno.h>
#include<string>
#include<string.h>
using namespace std;

class ZSql{
public:
	ZSql();
	~ZSql();
	public :
		const void setDbName(  const string  & sql);
		const void setUserName( const string &sql );
		const void setDbIp( const string & sql);
		const void setDbPasswd( const string & sql);
public:

		bool check(const std::string &content);
		MYSQL_RES *getResult(){
			return result;
		}
protected:
		bool regsit();
		MYSQL mysql;
		MYSQL_RES *result=0;
private:
		 string DbName;
		 string UserName;
		 string DbIp;
		 string DbPasswd;
};

ZSql::ZSql(){
	mysql_init(&mysql);
}

ZSql::~ZSql(){
	mysql_free_result(result);
	mysql_close(&mysql);
}

const void ZSql::setUserName( const string &  sql) {
	UserName=sql;
}
const void ZSql::setDbName( const string & sql){
	DbName = sql;
}
const void ZSql::setDbPasswd( const string & sql){
	DbPasswd=sql;
}
const void ZSql::setDbIp(  const string & sql){
	DbIp=sql;
}
bool ZSql::regsit(){
	if(mysql_real_connect(&mysql,DbIp.c_str(),UserName.c_str(),DbPasswd.c_str(),
			DbName.c_str(),NULL,NULL,0)){
		return true;
	}else{
		return false;
	}
}

bool ZSql::check(const std::string & content){
	if(regsit()){
		int status=mysql_real_query(&mysql,content.c_str(),content.length());
		result=mysql_store_result(&mysql);
		if(getResult()!=NULL){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}


#endif /* ZSQL_H_ */
