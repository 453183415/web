/*
 * IoRead.h
 *
 *  Created on: 2015年10月25日
 *      Author: zjl
 */

#ifndef IOREAD_H_
#define IOREAD_H_
#include<iostream>
#include<vector>
class IoRead
{
public :
	IoRead(int fd);
	void getLineSpliteedByBlank(std::vector<std::string>& buf);
};
#endif /* IOREAD_H_ */
