/*
 * example.cpp
 *
 *  Created on: 2015年11月4日
 *      Author: zjl
 */
#include<iostream>
#include<pthread.h>
#include<cstdlib>
#include<unistd.h>
void * thread(void * )
{
	int i;
	for(i=0;i<3;i++)
	{
		std::cout <<"this is pthread"<<std::endl;
		sleep(1);
	}
	return NULL;
}

int main()
{
	pthread_t pid;
	int ret;
	ret=pthread_create(&pid,NULL,&thread,NULL);
	if(ret!=0){
		std::cout <<"create pthread error !"<<std::endl;
		exit(0);
	}
	for(int i=0;i<3;i++){
		sleep(1);
		std::cout <<"this is main process."<<std::endl;
	}
	pthread_join(pid,NULL);
	return 0;
}


