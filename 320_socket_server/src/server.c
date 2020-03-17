/*
 * server.c
 *
 *  Created on: 17 mars 2020
 *      Author: marc
 */
#include<stdio.h>
#include<string.h>
#include<unistd.h> // sleep
#include<sys/socket.h>
#include<arpa/inet.h>
#include"debug.h"
#include<errno.h> // strerror
#include"server.h"

// return fd of socket created
int create_socket(void) {
	int socket_error;
	int socket_desc = -1;
	while (socket_desc == -1) {
		socket_desc = socket(AF_INET, SOCK_STREAM, 0);
		if (socket_desc == -1) {   //If socket creation failed
			socket_error = errno;
			error_printf("Could not create socket, error num : %d (%s)\n",
					socket_error, strerror(socket_error));
			sleep(1);
		}
	}
	debug_printf(0, "socket created\n", socket_desc);
	return socket_desc;
}

// return fd of socket connected
int establish_server(int inSocketDesc) {
	int socket_desc = inSocketDesc;
	int connect_error;
	int connection_status = -1;
	struct sockaddr_in server;
	server.sin_addr.s_addr = inet_addr(SRV_IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(SRV_PORT);

	while (connection_status == -1) {
		if (socket_desc >= 0) {
			close(socket_desc);
		}
		socket_desc = create_socket();
		connection_status = connect(socket_desc, (struct sockaddr *) &server,
				sizeof(server));
		if (connection_status == -1) {  //If connecting to server failed
			connect_error = errno;
			error_printf("connect error, error num : %d (%s)\n", connect_error,
					strerror(connect_error));
			close(socket_desc);
			socket_desc = -1;
			sleep(1);
		}
	}
	debug_printf(1, "Connected fd = %d\n", socket_desc);
	return socket_desc;
}

