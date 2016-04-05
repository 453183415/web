/*
 * pthreadpool.h
 *
 *  Created on: 2015年11月4日
 *      Author: zjl
 */

#ifndef PTHREADPOOL_H_
#define PTHREADPOOL_H_

#include<list>
#include<stdio.h>
#include<exception>
#include<pthread.h>

#include"../locker/locker.h"

template<class T>
class pthreadpool{
	private:
		int m_thread_number;
		int m_max_requests;
		pthread_t * m_threads;
		std::list<T*> m_workqueue;
		sem m_queuestat;
		locker m_queuelocker;
		bool m_stop;
	public:
		pthreadpool(int thread_number = 8, int max_request = 10000);
		virtual ~pthreadpool();
		bool append(const T * request);
	private:
		static void * worker(void * args);
		void run();
};

template<class T>
pthreadpool<T>::pthreadpool(int thread_number,int max_request):m_thread_number(thread_number),
	m_max_request(max_request),m_stop(false),m_threads(NULL){
		if((thread_number <= 0) || (max_request <= 0)){
			throw std::exception();
		}
		m_threads = new pthread_t [m_thread_number];
		if(m_threads){
			throw std::exception();
		}
		for(int i =0;i< thread_number ; i++){
			printf("create the %dth thread\n",i);
			if(pthread_create(m_threads+i,NULL, worker,this) != 0){
				delete [ ] m_threads;
				m_threads=NULL;
				throw std::exception();
			}
			if(pthread_detach(m_threads[i])){
				delete [ ] m_threads;
				m_threads =NULL;
				throw std::exception();
			}
		}
}

template<class T>
pthreadpool<T>::~pthreadpool(){
	delete [ ] m_threads;
	m_threads = NULL;
}

template<class T>
bool pthreadpool<T>::append(const T * request){
	m_queuelocker.lock();
	if(m_workqueue.size() >= m_max_requests){
		m_queuelocker.unlock();
		return false;
	}
	m_workqueue.push_back(request);
	m_queuelocker.unlock();
	m_queuestat.post();
	return true;
}

template<class T>
void * pthreadpool<T>::worker(void *args){
	pthreadpool * pool = (pthreadpool * ) args;
	pool->run();
	return pool;
}

template<class T>
void pthreadpool<T>::run(){
	while(!m_stop){
		m_queuestat.wait();
		m_queuelocker.lock();
		if(m_workqueue.empty()){
			m_queuelocker.unlock();
			continue;
		}
		T * request = m_workqueue.front();
		m_workqueue.pop_front();
		m_queuelocker.unlock();
		if(! request){
			continue;
		}
		reuqest->process();
	}
}































#endif /* PTHREADPOOL_H_ */
