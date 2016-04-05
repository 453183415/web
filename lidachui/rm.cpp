/*
 * rm.cpp
 *
 *  Created on: 2015年10月7日
 *      Author: zjl
 */

#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int rm(const char *name)
{
	printf("djfhsdhfkhfdjk\n");
	struct stat buf;
	stat(name,&buf);
	if(!S_ISDIR(buf.st_mode))
		return unlink(name);
	if(S_ISDIR(buf.st_mode)){
		DIR *dir;
		struct dirent *dir_buf;
		dir=opendir(name);
		while((dir_buf=readdir(dir))!=NULL){
			char dn[256];
			sprintf(dn,"%s/%s",name,dir_buf->d_name);
			if(rm(dn)<0)
				break;
		}
		return rmdir(name);
	}

}
int main(int argc , char*argv[])
{

	struct stat buf;
	DIR *dir;
	int fd1,fd2;
	struct dirent *dir_buf;
	char arg[4];
	strcpy(arg,argv[1]);
	printf("djfhsdhfkhfdjk\n");
	stat(argv[argc-1],&buf);
	if((S_ISDIR(buf.st_mode)) &&((fd1= strcmp(arg,"-rf")==0)||(fd2=strcmp(arg,"-f")==0))){
		rm(argv[argc-1]);
	}else if((S_ISDIR(buf.st_mode)) &&((fd1= strcmp(arg,"-rf")!=0)||(fd2=strcmp(arg,"-f")!=0))){
		printf("the file is a DIR");
	}else{
		remove(argv[argc-1]);
	}
	return 0;
}


