#include "uart7_com.h"

extern UART_HandleTypeDef huart7;
extern osMessageQueueId_t msgtosendHandle;
extern osMessageQueueId_t msgtoreceiveHandle;

char msg_to_send[SIZE_OF_COMMAND_PLAYER] = "p1xd\n";
char msg_to_send2[SIZE_OF_COMMAND_PLAYER] = "p2xd\n";

void send_message(btn_action action){
	msg_to_send[2] = action;
	msg_to_send2[2] = action;
	osMessageQueuePut(msgtosendHandle, msg_to_send, 0, osWaitForever);
	osMessageQueuePut(msgtosendHandle, msg_to_send2, 0, osWaitForever);
}

uint8_t receive_message(char *pdata){
	if (osMessageQueueGet(msgtoreceiveHandle, pdata, 0, 1000) == osOK){
		return TRUE;
	}
	return FALSE;
}


void uart_com(void *argument)
{
	for(;;)
	{
		unsigned char buffer[MAX_BUFFER_SIZE] = { 0 };
		if (osMessageQueueGetCount(msgtosendHandle) != 0){
			osMessageQueueGet(msgtosendHandle, &buffer, 0, osWaitForever);
			HAL_UART_Transmit(&huart7, buffer, SIZE_OF_COMMAND_PLAYER, 10);
		}
		osDelay(1);
		if (HAL_UART_Receive(&huart7, buffer, MAX_BUFFER_SIZE, 10) == HAL_OK){
			osMessageQueuePut(msgtoreceiveHandle, &buffer, 0, osWaitForever);
		}
	}
}
