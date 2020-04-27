/*
 *****************************************************************************

 File        : main.cpp

 The MIT License (MIT)
 Copyright (c) 2019 STMicroelectronics

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.

 *****************************************************************************
 */

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *print_table(void *arg) {

	while (1) {
		printf("Hello World!\n");
		sleep(1);
	}
	/* Pour enlever le warning */
	(void) arg;
	pthread_exit(NULL);
}

void *add_to_table(void *arg) {
	while (1) {
		printf("the world is mine.\n");
		sleep(2);
	}
	(void) arg;
	pthread_exit(NULL);
}

int main(void) {
	printf("création thread H_world\n");
	pthread_t H_world;
	printf("création thread W_mine\n");
	pthread_t W_mine;

	pthread_create(&W_mine, NULL, add_to_table, NULL);
	pthread_create(&H_world, NULL, print_table, NULL);

	int count = 0;
	while (count < 10) {
		sleep(2);
		count++;
	}

	return 0;
}
