/*
 * mycat.cpp
 *
 *  Created on: 2015年9月16日
 *      Author: zjl
 */
#include<sys/types.h>
#include<unistd.h>
#include<regex.h>
#include<sys/stat.h>
#include<stdio.h>
#include<iostream>
#include<fcntl.h>

unsigned long get_filesize(const char *filename){  //此函数用来获取文件大小
	struct stat buf;
	stat(filename,&buf);
	return buf.st_size;
}
void put_file(int fd,char *buf,unsigned long size)//将文件内容输出到终端
{
	read(fd,buf,size);
	std::cout<<buf<<std::endl;
}

void writ(int fd,const char * buf,unsigned long size)//将文件定向写入最后一个文件路径所指的文件中
{
	write(fd,buf,size);
}

int main(int argc,char* argv[])
{
	int fd_r;;
	int fd_w;
	char* buf;
	unsigned long size_f;
	if(argv[argc-2]!=">>"){//判断是否需要重定向文件
	for(int i=1;i<argc;i++){
	if((fd_r=open(argv[i],O_RDWR))<0){
		 creat(argv[i],(O_CREAT|O_WRONLY|O_RDONLY));
		 //std::cout<<std::endl;
		 continue;
	}
		size_f=get_filesize(argv[i]);
		char *buf=new char [size_f];
		put_file(fd_r,buf,size_f);
	}
	}else if(argv[argc-2]==">>"){
		if((fd_w=open(argv[argc-1],O_RDWR))<0){//先判断目标文件是否存在，若不存在则创建该文件
						fd_w=creat(argv[argc-1],(O_CREAT|O_WRONLY|O_RDONLY));
					}

		for(int i=1;i<argc-3;i++){
			lseek(fd_w,0,SEEK_END);//将 目标文件的读写指针移动到文件尾便于添加文件
			if((fd_r=open(argv[i],O_RDWR))<0){
				 creat(argv[i],(O_CREAT|O_WRONLY|O_RDONLY));
				 std::cout<<std::endl;
				 continue;
			}
			size_f=get_filesize(argv[i]);
			char *buf=new char [size_f];
			read(fd_r,buf,size_f);
			writ(fd_w,buf,size_f);
		}
	}
	delete [] buf;
	return 0;
}


