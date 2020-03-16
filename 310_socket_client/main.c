/*
 * main.c
 *
 *  Created on: Mar 13, 2020
 *      Author: marcl
 */
#include<stdio.h>
#include<string.h>
#include<unistd.h> // sleep
#include<sys/socket.h>
#include<arpa/inet.h>
#include"debug.h"
#include<errno.h> // strerror
#include"server_addr.h"

int connect_to_remote_server(void){
	int socket_desc;
	int socket_error = 1;
	int myerr;
	struct sockaddr_in server;
	server.sin_addr.s_addr = inet_addr(SRV_IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(SRV_PORT);
	while (socket_error == 1){
		//Creating socket
		socket_desc = socket(AF_INET , SOCK_STREAM , 0);
		//If socket creation failed
		if(socket_desc == -1){
			myerr = errno;
			error_printf("Could not create socket, error num : %d (%s)\n", myerr, strerror(myerr));
			socket_error = 1;
			//socket_desc = socket(AF_INET , SOCK_STREAM , 0);
		}
		else if(socket_desc != -1){
			socket_error = 0;
		}
		//Connect to remote server
		if((connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) == -1)){  //If connecting to server failed
			myerr = errno;
			error_printf("connect error, error num : %d (%s)\n", myerr, strerror(myerr));
			close(socket_desc);
			socket_error = 1;
		}
	}
	puts("Connected\n");
	return socket_desc;
}


void send_message_with_timer(int socket_desc,char* message,int delay){
	while(1){
		while( send(socket_desc , message , strlen(message) , 0) == -1){
			int myerr = errno;
			error_printf("Send failed, error num : %d (%s)\n", myerr, strerror(myerr));
		}
		puts("Data Sent\n");
		sleep(delay);
	}
}

int main(int argc , char *argv[]){

	int socket_desc;
	int delay;
	char* message;

	message = "mooordu !\n";
	delay = 2;

	socket_desc = connect_to_remote_server();
	send_message_with_timer(socket_desc, message, delay);

	return 0;
}
