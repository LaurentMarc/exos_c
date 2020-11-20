/*
 * readbutton.c
 *
 *  Created on: Nov 17, 2020
 *      Author: marcl
 */
#include "readbutton.h"

extern uint8_t btn_down;
extern uint8_t btn_left;
extern uint8_t btn_right;


void readbutton(void *argument)
{
	for(;;)
	{
		if(btn_down == TRUE){
			send_message(DOWN);
			btn_down = FALSE;
		}
		if(btn_left == TRUE){
			send_message(LEFT);
			btn_left = FALSE;
		}
		if(btn_right == TRUE){
			send_message(RIGHT);
			btn_right = FALSE;
		}
		osDelay(1);
	}
}

