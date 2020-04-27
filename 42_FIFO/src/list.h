#ifndef LIST_H_
#define LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <errno.h>

typedef struct User_input user_input;
struct User_input {
	int nombre;
	int autre_data;
	user_input *next;
};

typedef struct Queue queue;
struct Queue {
	user_input *first;
	user_input *last;
};

queue *liste_thread;
pthread_mutex_t mutex;
extern sem_t semaphore;

queue *initialiser();
void add_to_list(queue *list, int nvNombre, int numcase);
int delete_first_element(queue *list, user_input *element);
void show_list(queue *list);
void *Push(void *arg);
void *Pop(void *arg);

#endif
