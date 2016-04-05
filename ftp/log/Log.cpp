/*
 * Log.cpp
 *
 *  Created on: 2015年12月11日
 *      Author: zjl
 */
#include"Log.h"
#include<time.h>

Log::Log(const std::string & content):content(content),rank(rank){

}

std::string Log::getTime(){
			  time_t now;
	          struct tm *timenow;
	           time(&now);
	          timenow=localtime(&now);
	          return asctime(timenow);
}


