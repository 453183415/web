/*
 * IoWrite.cpp
 *
 *  Created on: 2015年10月26日
 *      Author: zjl
 */
#include"IoWrite.h"
#include<cstdio>
#include<unistd.h>
#include<cstring>
//#include<string>
#include<fcntl.h>
#include<cstdlib>
#include<sys/mman.h>
#include<cerrno>
#include<sys/types.h>
#include<sys/stat.h>
namespace{
	void unix_error(char*msg)
	{
		fprintf(stderr,"%s:%s\n",msg,strerror(errno));
		exit(0);
	}
	ssize_t rio_write(int fd,void *usrbuf,size_t n){
		size_t nleft=n;
		ssize_t nwrite;
		char *bufp=reinterpret_cast<char *>(usrbuf);

		while( nleft >0){
			if((nwrite= write(fd,bufp,nleft))<=0){
				if(errno==EINTR){
					nwrite=0;
				}else{
					return -1;
				}
			}
			nleft-=nwrite;
			bufp+=nwrite;
		}
		return n;
	}

	void Rio_write(int fd,void *usrbuf,size_t n){
		if(rio_write(fd,usrbuf,n)!=n){
			unix_error("Rio_write error");
		}
	}

	int Open(const char *pathname,int flags,mode_t mode)
	{
		int rc;
		if((rc == open(pathname,flags,mode))<0){
			unix_error("open error");
		}
		return rc;
	}
	void Close(int fd)
	{
		int rc;
		if((rc=close(fd))<0){
			unix_error("close error");
		}
	}

	void * Mmap(void *addr,size_t len ,int prot, int flags, int fd,off_t offset)
	{
		void *ptr;
		if((ptr = mmap(addr,len,prot,flags,fd,offset))==((void *) -1)){
			unix_error("mmap error");
		}
		return ptr;
	}

	void Munmap(void *start,size_t length){
		if(munmap(start,length)<0){
			unix_error("munmap error");
		}
	}

}
 IoWrite::IoWrite(int fd):fileDescriptor(fd){

 }

 void IoWrite::writeString( const std::string &str)
 {
	 Rio_write(fileDescriptor,const_cast<char *>(str.c_str()),str.length());
 }

void IoWrite::writeFile(const std::string&fileName,int filesSize)
{
	int srcfd;
	char *srcp;
	srcfd = Open(const_cast<char*>(fileName.c_str()),O_RDONLY,0);
	srcp= reinterpret_cast<char *>(Mmap(0,filesSize,PROT_READ,MAP_PRIVATE,srcfd,0));
	Close(srcfd);
	Rio_write(fileDescriptor,srcp,filesSize);
	Munmap(srcp,filesSize);
}






























