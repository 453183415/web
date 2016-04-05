/*
 * getAccept.cpp
 *
 *  Created on: 2015年11月26日
 *      Author: zjl
 */

#include"getAccept.h"
#include"../response/response.h"

void getAccept::doExecute(){
	response(getConfd(),getPort(),getIp(),getPath(),getCommond());
}
