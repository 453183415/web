/*
 * sctp_client.cpp
 *
 *  Created on: 2016年1月24日
 *      Author: zjl
 */
#include"../unix.h"

#define MAXSIZE 1024

void sctp_cli(FILE *, int , struct sockaddr * , socklen_t);

int main(int argc ,  char** argv)
{
	int sockfd,connfd;
	struct sockaddr_in servaddr;
	struct sctp_event_subscribe events;
	int echo_to_all = 0;
	if(argc<2)
		return -1;
	if(argc >2)
		echo_to_all = 1;
	sockfd = socket(AF_INET,SOCK_SEQPACKET, IPPROTO_SCTP);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(55555);
	inet_pton(AF_INET,argv[1],&servaddr);
	bzero(&events,sizeof(events));
	events.sctp_data_io_event = 1;
	setsockopt(sockfd,IPPROTO_SCTP,SCTP_EVENTS,&events,sizeof(events));
	connfd=connect(sockfd,(struct sockaddr * )&servaddr,sizeof(servaddr));
	if(echo_to_all ==0)
		sctp_cli(stdin,connfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
//	else
//		sctp_cli_all(stdin,sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	close(sockfd);
	return 0;
}

void sctp_cli(FILE*fp, int sockfd, struct sockaddr * to, socklen_t tolen){
	struct sockaddr_in peeraddr;
	struct sctp_sndrcvinfo sri;
	char sendbuf[MAXSIZE] , recvbuf[MAXSIZE];
	socklen_t len;
	int out_str, rd_sz;
	int msg_flags;
	bzero(&peeraddr,sizeof(peeraddr));
	bzero(&sri,sizeof(sri));
	while(fgets(sendbuf,MAXSIZE,fp)){

		if(sendbuf[0]!='['){
			printf("error, line must be of the form '[x]' text\n");
			continue;
		}
		sri.sinfo_stream= strtol(&sendbuf[1],NULL,0);
		out_str=strlen(sendbuf);
		rd_sz= sctp_sendmsg(sockfd,sendbuf,out_str,
														to,tolen,0,0,sri.sinfo_stream,0,0);
		len=sizeof(peeraddr);
		rd_sz=sctp_recvmsg(sockfd,recvbuf,sizeof(recvbuf),
														(struct sockaddr *)&peeraddr,&len,&sri,&msg_flags);
		printf("from str : %d seq: %d (assoc: 0x %x):",sri.sinfo_stream,sri.sinfo_ssn,(u_int)sri.sinfo_assoc_id);
		printf("%.*s",rd_sz,recvbuf);
	}

}
