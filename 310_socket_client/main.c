/*
 * main.c
 *
 *  Created on: Mar 13, 2020
 *      Author: marcl
 */
#include "client.h"
#include "debug.h"
#include<unistd.h>

int main(int argc , char *argv[]){

	int socket_desc = -1;
	int delay;
	char* message;
	int send_msg_error;
	int send_msg_result;

	message = "mooordu !\n";
	delay = 2;
	debug_setlevel(3);

	while(1){
		socket_desc = establish_server(socket_desc);
		send_msg_error = 3;
		while(send_msg_error != 0){
			send_msg_result = send_message_with_delay(socket_desc, message, delay);
			if(send_msg_result == -1){
				send_msg_error--;
			}
		}
		//close(socket_desc);
	}
	return 0;
}
