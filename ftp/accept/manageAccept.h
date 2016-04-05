/*
 * manageAccept.h
 *
 *  Created on: 2015年11月24日
 *      Author: zjl
 */

#ifndef MANAGEACCEPT_H_
#define MANAGEACCEPT_H_
#include<string.h>
class Accept;
class manageAccept{
public:
	manageAccept(int fd);
	void run();
private:
	Accept *getAcceptCommond();
private:
	int confd;
	Accept* accepted;
};
#endif /* MANAGEACCEPT_H_ */
