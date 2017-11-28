#include <stdio.h>

#include <string.h>

#include <sys/socket.h>

#include <arpa/inet.h>

#include <unistd.h>

#include <netinet/in.h>


int main(){

	int sock;

	struct sockaddr_in server;

	char message[3000];

	
	//create socket

	sock=socket(AF_INET,SOCK_STREAM,0);

	if(sock==-1){

	   printf("Could not create socket");

	}

	puts("socket created");

	//socket specification

	server.sin_addr.s_addr=inet_addr("192.168.189.129");

	server.sin_family=AF_INET;

	server.sin_port=htons(1000);


	//connect to server

	if(connect(sock,(struct sockaddr *)&server,sizeof(server))<0){

		perror("fail to connect to loadbalancer");

		return 1;
	}


		printf("Input your choice(Student/Lecturer):");

		scanf("%s",message);

	if(send(sock,message,strlen(message),0)<0){

	puts("Fail to send");

	return 1;
	
	}

	close(sock);

	return 0;

}
