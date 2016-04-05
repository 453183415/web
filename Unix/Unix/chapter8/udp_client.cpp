/*
 * udp_client.cpp
 *
 *  Created on: 2016年1月23日
 *      Author: zjl
 */
#include"../unix.h"

#define MAXSIZE 1024

void udp_cli(FILE *,  int ,  const struct sockaddr *,  socklen_t);

int main(int argc , char** argv)
{
	int sockfd;
	struct sockaddr_in clientaddr;
	if(argc!= 2)
		return -1;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	clientaddr.sin_family = AF_INET;
	clientaddr.sin_port = htons(55555);
	inet_pton(AF_INET, argv[1], &clientaddr.sin_addr);
	udp_cli(stdin, sockfd, (struct sockaddr *)&clientaddr, sizeof(clientaddr));
	return 0;
}

void udp_cli(FILE* fp,int sockfd, const struct sockaddr*cliaddr, socklen_t len){
	int n;
	char sendline[MAXSIZE], recvline[MAXSIZE+1];
	while( fgets( sendline,MAXSIZE, fp) !=NULL){
		sendto(sockfd,sendline,strlen(sendline), 0,  cliaddr, len);
		bzero(&sendline,sizeof(sendline));
		n=recvfrom(sockfd,recvline,MAXSIZE, 0, NULL, NULL);
		recvline[n]='\0';
		fputs(recvline,stdout);
		bzero(recvline,sizeof(recvline));
	}



}
