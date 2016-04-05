/*
 * Log.h
 *
 *  Created on: 2015年12月11日
 *      Author: zjl
 */

#ifndef LOG_H_
#define LOG_H_

class Log{
public:
	Log(const std::string &content,int rank);
	virtual void writen()=0;
	std::string getTime();
	virtual ~ Log(){

	}
private:
	std::string content;
	int rank;
};



#endif /* LOG_H_ */
