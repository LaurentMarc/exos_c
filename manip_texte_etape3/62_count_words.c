/*
 * 62_count_words.c
 *
 *  Created on: Feb 24, 2020
 *      Author: marcl
 */
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <wctype.h>

int is_consonnant_from_text(char char_from_file){
	char_from_file =  towlower(char_from_file);
	if (isspace(char_from_file) || ispunct(char_from_file) || (isdigit(char_from_file))){
		return 0;
	}
	else{
		return 1;
	}
}


int is_vowel_from_text(char char_from_file){
	char_from_file =  towlower(char_from_file);
	if ((char_from_file== 'a') || (char_from_file== 'e') || (char_from_file== 'i') || (char_from_file== 'o') || (char_from_file== 'u') || (char_from_file== 'y')
		|| (char_from_file== 'é') || (char_from_file== 'è') || (char_from_file== 'à') || (char_from_file== 'ù') || (char_from_file== 'ë') || (char_from_file== 'ê')) {
		return 1;
	}
	else {
		return 0;
	}
}


int main(int argc, char* argv[]) {
	FILE* text_file = fopen("text.txt", "r");
	int count_space = 0;
	char char_from_file;
	int count_consonnant = 0;
	int count_vowel = 0;

	while (char_from_file != EOF){
		char word [20];
		char_from_file = fgetc(text_file);
	q	if (!isspace(char_from_file)){
			count_consonnant += is_consonnant_from_text(char_from_file);
			count_vowel += is_vowel_from_text(char_from_file);
			count_space += 1;
			strncat(word, &char_from_file, 1);
		}
		else{
			printf("%s\n", word);
		}
	}
}
