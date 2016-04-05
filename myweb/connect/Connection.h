/*
 * Connection.h
 *
 *  Created on: 2015年10月27日
 *      Author: zjl
 */

#ifndef CONNECTION_H_
#define CONNECTION_H_
class NetConnection{
public :
	NetConnection();
	void listn(int port);
	int accept();
	void close();
private:
	int listenfd;
	int confd;
};




#endif /* CONNECTION_H_ */
