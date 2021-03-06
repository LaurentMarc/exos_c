/*
 * client.h
 *
 *  Created on: 17 mars 2020
 *      Author: marc
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#define SRV_PORT 5001
#define SRV_IP "192.168.1.34"
/* return -1 if sending message failed, return 1 when message sent
 return fd of socket connected
 return fd of socket created

 */
int create_socket(void);
int establish_server(int inSocketDesc);
int send_message_with_delay(int socket_desc,char* message,int delay);



#endif /* CLIENT_H_ */
