/*
 * uart7_com.h
 *
 *  Created on: Nov 16, 2020
 *      Author: marcl
 */

#ifndef SRC_UART7_COM_H_
#define SRC_UART7_COM_H_

#include "main.h"
#include "cmsis_os.h"

#define MAX_BUFFER_SIZE 10
#define SIZE_OF_COMMAND_PLAYER 5
#define TRUE 1
#define FALSE 0

typedef enum{
	DOWN = 'd',
	LEFT = 'l',
	RIGHT = 'r',
}btn_action;

void uart_com(void *argument);
void send_message(btn_action action);
uint8_t receive_message(char *pdata);



#endif /* SRC_UART7_COM_H_ */