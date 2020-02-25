/*
 * light.c
 *
 *  Created on: Feb 19, 2020
 *      Author: marcl
 */
#include <stdio.h>
#include <stdbool.h>



bool change_state_light(bool state_light){
		if (state_light){
			state_light = false;
		}
		else if (state_light == false){
			state_light = true;
		}
		return state_light;
	}


int main(int argc, char* argv[]){
	bool state_light = false;
	int user_input;
	int input_nbr;

	while (true){
		printf("\n actionner interrupteur : 1 = oui, 0 = non : ");
		input_nbr = scanf("%d", &user_input);
		if (input_nbr == 1){
			state_light = change_state_light(state_light);
			fflush(stdin);
		}
		else{
			printf("saisie incorrecte");
		}
		if (state_light){
			printf("\n lumière allumée");
		}
		if (state_light == false){
			printf("\n lumière éteinte");
		}
	}
}
