#include <stdio.h>

#include <string.h>

#include <sys/socket.h>

#include <arpa/inet.h>

#include <unistd.h>

#include <netinet/in.h>


int main(){
	
	int socket_desc,client_sock,c,read_size;
	
	struct sockaddr_in server,client;
	
	char client_message[3000];

	
	
	socket_desc=socket(AF_INET,SOCK_STREAM,0);
	
	if(socket_desc==-1){
		
		printf("Cant create socket");
	
	}
	
	
	puts("Socket created");

	
	
	
	server.sin_family=AF_INET;
	
	server.sin_addr.s_addr=INADDR_ANY;
	
	server.sin_port=htons(3000);
	
	
		
	if(bind(socket_desc,(struct sockaddr *)&server,sizeof(server))<0){
	
		perror("fail to bind the socket to server");
	
		return 1;
	
	}
	
	
	puts("Bind done");

	

	//listen to the client
	
	listen(socket_desc,3);

	

	//wait for incoming connection
	
	puts("waiting for incoming connection");
	
	c=sizeof(struct sockaddr_in);

	

	//accept connection from incoming client
	
	client_sock=accept(socket_desc,(struct sockaddr *)&client,(socklen_t *)&c);
	
	if(client_sock<0){
	
		perror("accept failed");
	
		return 1;
	
	}
	
	puts("connection accepted");


	read_size=recv(client_sock,client_message,3000,0);


	printf("Data received from Load Balancer:");
	printf("%s",client_message);
	
	
}
