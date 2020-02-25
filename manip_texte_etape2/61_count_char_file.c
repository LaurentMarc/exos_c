/*
 * 61_count_char_file.c
 *
 *  Created on: Feb 21, 2020
 *      Author: marcl
 */


#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <wctype.h>
#include <ctype.h>

/* ---------------  to calculate sum of vowel --------------------------*/
int is_vowel_from_text(char char_from_file){
	char_from_file =  towlower(char_from_file);
	if ((char_from_file== 'a') || (char_from_file== 'e') || (char_from_file== 'i')
		|| (char_from_file== 'o') || (char_from_file== 'u') || (char_from_file== 'y')
		|| (char_from_file== 'é') || (char_from_file== 'è') || (char_from_file== 'à')
		|| (char_from_file== 'ù') || (char_from_file== 'ë') || (char_from_file== 'ê')) {
		return 1;
	}
	else {
		return 0;
	}
}


/* ---------------  to calculate sum of consonnant ----------------------*/
int is_consonnant_from_text(char char_from_file){
	char_from_file =  towlower(char_from_file);
	if (isspace(char_from_file) || ispunct(char_from_file) || (isdigit(char_from_file))){
		return 0;
	}
	else{
		return 1;
	}
}


int main(int argc, char* argv[]) {

	FILE* text_file = fopen("text2.txt", "r");
	int sum_vowel = 0;
	int sum_consonnant = 0;
	int is_consonnant = 0;
	int is_vowel = 0;

	char char_from_file ;
//	while (true){
//		char char_from_file = fgetc(text_file);
//		if (char_from_file == EOF){
//			break;
//		}
	while ( ( char_from_file = fgetc(text_file) ) != EOF ) {

		is_vowel =  is_vowel_from_text(char_from_file);
		sum_vowel += is_vowel;
		if (is_vowel == 0){
			is_consonnant = is_consonnant_from_text(char_from_file);
			sum_consonnant += is_consonnant;
		}

	}
	int sum_letters = sum_consonnant + sum_vowel;
	float percent_vowel = ((float) sum_vowel * 100) / (float) sum_letters ;
	float percent_consonnant = 100 - percent_vowel;
	printf("il y a %d voyelles, il y a %d consonnes et %d lettres\n Les voyelles representent %.2f %% et les consonnes %.2f %%\n", sum_vowel, sum_consonnant, sum_letters, percent_vowel, percent_consonnant);

	fclose(text_file);
}

