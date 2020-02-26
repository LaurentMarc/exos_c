/*
 * 72_struct.c
 *
 *  Created on: Feb 25, 2020
 *      Author: marcl
 */
#include <stdio.h>


typedef struct{
	char * name;
	int age;
}person;


int main(){

	person john;
	john.name = "John";
	john.age = 27;
	printf("%s is %d years old.\n", john.name, john.age);

	person marc;
	marc.name = "Marc";
	marc.age = 30;
	printf("%s is %d years old.", marc.name, marc.age);

}

