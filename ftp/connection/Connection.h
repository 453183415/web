/*
 * Connection.h
 *
 *  Created on: 2015年11月26日
 *      Author: zjl
 */

#ifndef CONNECTION_H_
#define CONNECTION_H_
class Connection{
	public:
		Connection();
		void listens(int port);
		int acceppt();
		void close();
	private:
		int listenfd;
		int confd;
};




#endif /* CONNECTION_H_ */
