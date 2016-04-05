/*
 * reponse.h
 *
 *  Created on: 2015年11月24日
 *      Author: zjl
 */

#ifndef RESPONSE_H_
#define RESPONSE_H_

class responseBase;

class response{
	public:
		response(const int &fd,const  int &port,const std::string &ip,
														const std::string &path,const std::string &commond);
		~response();
	protected:
		void log(const std::string &ip,const std::string &path,const std::string &commond);
	private:
		responseBase *state;

};


#endif /* RESPONSE_H_ */
