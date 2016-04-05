/*
 * DynamicRespondseState.cpp
 *
 *  Created on: 2015年10月27日
 *      Author: zjl
 */

#include"DynamicResponseState.h"

#include"../base/IoWrite.h"
#include<stdexcept>
#include<cstdlib>
#include<unistd.h>
#include<sys/wait.h>

namespace {
pid_t _fork(void){
	pid_t pid;
	if((pid=fork())<0){
		throw std::string("Fork error");
	}
	return pid;
}

int _dup2(int fd1, int fd2){
	int rc;
	if((rc=dup2(fd1,fd2))<0){
		throw std::string("dup2 error");
	}
	return rc;
}
void _execve(const char * filename,char * const argv[],char * const envp[]){
	if(execve(filename,argv,envp)<0){
		throw std::string("Execve error");
	}
}

pid_t _wait(int * status){
	pid_t pid ;
	if((pid = wait(status))<0){
		throw std::string("wait error");
	}
	return pid;
}
}

DynamicResponseState::DynamicResponseState(int fd, std::string fName, std::string args):
																										ResponseState(fd,fName),cgiArgs(args){

}

const std::string DynamicResponseState::buildForbiddenMsg(){
	return "i couldn't run the cgi program";
}
void DynamicResponseState::doRespond(){
	IoWrite writer(getFileDescriptor());
	writer.writeString(buildRespondHeaders());

	execveCgiProgram();
}

void DynamicResponseState::execveCgiProgram(){
	char *emptylist[]={NULL};
	if(_fork()==0){
		setenv("QUERY_STRING",cgiArgs.c_str(),1);
		_dup2(getFileDescriptor(),STDOUT_FILENO);
		_execve(getFileName().c_str(),emptylist,environ);
	}
	_wait(NULL);
}























