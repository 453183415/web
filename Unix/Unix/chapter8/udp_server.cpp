/*
 * udp_server.cpp
 *
 *  Created on: 2016年1月23日
 *      Author: zjl
 */
#include"../unix.h"

#define MAXSIZE 1024

void udp_echo( int sockfd, struct sockaddr *udpcliaddr,socklen_t clilen);

int main( int  argc , char ** argv)
{
	int sockfd ;
	struct sockaddr_in servaddr, clientaddr;
	sockfd= socket(AF_INET, SOCK_DGRAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons (55555);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(sockfd, ( struct sockaddr *)&servaddr, sizeof(servaddr));
	udp_echo(sockfd,( struct sockaddr *)&clientaddr,sizeof(clientaddr));
}

void udp_echo(int sockfd, struct sockaddr * udpcliaddr,socklen_t clilen){
	int n;
	socklen_t len;
	char buf[MAXSIZE];

	for ( ; ; ){
		len = clilen;
		n= recvfrom(sockfd, buf, MAXSIZE, 0 , udpcliaddr, &len);
		printf("%s\n",buf);
		sendto(sockfd, buf, n, 0, udpcliaddr, len);
	}
}



