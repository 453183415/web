/*
 * testaccept.cpp
 *
 *  Created on: 2015年9月5日
 *      Author: zjl
 */
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<assert.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#define BUFF_SIZE 1024

int main(int argc,char* argv[])
{
	if(argc <=2){
		printf("usage : %s ip_address prot_number \n",basename(argv[0]) );
		return 1;
	}
	const char* ip=argv[1];
	int port =atoi(argv[2]);
	struct sockaddr_in address;
	bzero(&address,sizeof(address));
	address.sin_family =AF_INET;
	inet_pton(AF_INET,ip,&address.sin_addr);
	address.sin_port=htons(port);
	int sock = socket(PF_INET,SOCK_STREAM,0);
	assert(sock >=0);
	int ret = bind(sock,(struct sockaddr*)&address,sizeof(address));
	assert(ret !=-1);
	ret = listen(sock,5);
	assert(ret!=-1);
	sleep(20);
	struct sockaddr_in client;
	socklen_t client_addrlength = sizeof(client);
	int connfd = accept(sock,(struct sockaddr*)&client,&client_addrlength);
	if(connfd <0){
		printf("error is : %d\n",errno);
	}else{
		char buff[BUFF_SIZE];
		memset(buff,'\0',BUFF_SIZE);
		ret= recv(connfd,buff,BUFF_SIZE-1,0);
		printf("got %d bytes of normal data '%s' \n",ret , buff);

		memset(buff,'\0',BUFF_SIZE);
		ret= recv(connfd,buff,BUFF_SIZE-1,MSG_OOB);
		printf("got %d bytes of oob data '%s' \n",ret , buff);

		memset(buff,'\0',BUFF_SIZE);
		ret= recv(connfd,buff,BUFF_SIZE-1,0);
		printf("got %d bytes of normal data '%s' \n",ret , buff);
		close(connfd);
	}
	close(sock);
	return 0;
}





