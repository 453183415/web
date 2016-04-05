/*
 * Read.h
 *
 *  Created on: 2015年11月23日
 *      Author: zjl
 */

#ifndef BASE_READ_H_
#define BASE_READ_H_
#include<string>
#include<vector>
#include<iostream>

class Read{
public:
	Read(int fd);
	void getLine(std::vector<std::string>&buf);
};



#endif /* BASE_READ_H_ */
