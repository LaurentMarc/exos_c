/*
 * main.c
 *
 *  Created on: Mar 13, 2020
 *      Author: marcl
 */
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include"debug.h"
#include<errno.h>

int main(int argc , char *argv[])
{
	int socket_desc;
	struct sockaddr_in server;
	char *message;

//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	while (socket_desc == -1)
	{
		//printf("Could not create socket\n");
		error_printf("Could not create socket, error num : %d (%s)\n", errno, strerror(errno));
		socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	}

	server.sin_addr.s_addr = inet_addr("192.168.0.31");
	server.sin_family = AF_INET;
	server.sin_port = htons( 5001 );

//Connect to remote server

	if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) == -1)
	{
		//puts("connect error\n");
		error_printf("connect error, error num : %d (%s)", errno, strerror(errno));
	}

	puts("Connected\n");

	while(1){
//Send some data
		message = "mooordu !\n";
		if( send(socket_desc , message , strlen(message) , 0) == -1)
		{
			//puts("Send failed\n");
			error_printf("Send failed, error num : %d (%s)", errno, strerror(errno));
		}
		puts("Data Sent\n");
		sleep(2);
	}

	return 0;
}
