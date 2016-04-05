/*
 * ppfork.c
 *
 *  Created on: 2015年10月27日
 *      Author: zjl
 */
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
void fun(int fd,char*buf)
{
	int i;
	int fd1;
	struct stat buff;
	int n;
	fd1=open("b.txt",O_RDWR,0);

	for(n=0,i=0;i<3;n+=3,i++){
				read(fd1,buf,30);
				printf("%s\n",buf);
				lseek(fd,0,SEEK_END);
				write(fd,buf,strlen(buf));
				sleep(1);
	}
}
int main()
{
	int fd;
	int n=0;
	char buf[1024];
	pid_t pid;
#if(0)
	fd=open("a.txt",O_RDWR|O_TRUNC,0);
	pid=fork();
	if(pid==0){
		fun(fd,buf);
	}
	if(pid>0){
		lseek(fd,0,SEEK_SET);
		read(fd,buf,1024);
		printf("%s",buf);
	}
#endif
	if(pid==0)
		while(1);
	if(pid>0)
		while(1);
}



