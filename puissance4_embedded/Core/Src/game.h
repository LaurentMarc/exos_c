/*
 * game.h
 *
 *  Created on: 9 avr. 2020
 *      Author: marc
 */

#ifndef GAME_H_
#define GAME_H_

#include "leds_control.h"
#include "game_p4.h"
#include "configuration.h"
#include"timer.h"
#include "stm32f4xx_hal.h"


#define TAB_SIZE 7
#define MAX_NUMBER 9
#define MIN_NUMBER 0
#define INIT_OK 1
#define MSG_SIZE 5
#define READ_BUTTON_BUFER_SIZE 5
#define STOP_TIMER -1
#define BLINK_TIMER 3

typedef enum {
	OFF, ON
}status;

typedef enum {
	PAD_1 = 49,
	PAD_2 = 50,
	DOWN = 100,
	LEFT = 108,
	RIGHT = 114,
	UP = 117,
	PRESSED = 100,
} pad_command;

typedef enum {
	WIN, INPUT, TIMER, NO_COMMAND, INIT
}type_msg;

typedef struct {
	point_t first_token;
	point_t last_token;
	victory_t type;
}victory_msg;

typedef struct {
	type_msg type;
	pad_command pad;
	pad_command command;
	move_token token;
	timer_msg timer;
	victory_msg victory;
} data_msg;

typedef struct User_input user_input;
struct User_input {
	void *data;
	size_t size_of_data;
	user_input *next;
};

typedef struct {
	color board[TAB_SIZE][TAB_SIZE];
	int init;
} Matrix;

osMessageQueueId_t queue_user_to_appHandle;
osMessageQueueId_t queue_app_to_displayHandle;

/* THREAD */
void user_button(void *arg);
void show_board(void *arg);
void application(void *arg);
void timers(void *arg);

/* FONCTIONS */
void set_number(int nbr);
void init_matrix(void);
void send_message(QUEUE_ID queue_id, void* message);

#endif /* GAME_H_ */
