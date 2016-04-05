/*
 * Accept.h
 *
 *  Created on: 2015年11月23日
 *      Author: zjl
 */

#ifndef ACCEPT_H_
#define ACCEPT_H_
class Accept{
	public:
	//	 Accept();
		 int getConfd();
		void execute();
		void init(int port,int confd,std::string path,std::string commond,std::string ip);
		virtual ~Accept(){

		}
	protected:
		int getPort();
		int getConfd();
		std::string getIp();
		std::string getPath();
		std::string getCommond();
	private:
		virtual void doExecute()=0;
	private:
		int port;
		int confd;
		std::string ip;
		std::string path;
		std::string commond;
};




#endif /* ACCEPT_H_ */
