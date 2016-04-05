/*
 * IoWrite.h
 *
 *  Created on: 2015年10月26日
 *      Author: zjl
 */

#ifndef IOWRITE_H_
#define IOWRITE_H_

#include<string>
class IoWrite{
public:
	IoWrite(int fd);
	void writeString(const std::string&string);
	void writeFile(const std::string&fileName, int filesSize);
private:
	int fileDescriptor;
};



#endif /* IOWRITE_H_ */
