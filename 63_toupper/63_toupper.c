/*
 * 63_toupper.c
 *
 *  Created on: Feb 24, 2020
 *      Author: marcl
 */


#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[]){

	FILE *src_text_file = fopen("text.txt","r");
	FILE *dest_text_file = fopen("dest_text", "a+");

	if (src_text_file == NULL){
		printf("impossible ouvrir fichier source");
	}
	if (dest_text_file == NULL){
		printf("impossible de créer ou ouvrir fichier destination");
	}

	char line [128];

	while (fgets(line, 128, src_text_file)){
		for (int i = 0; line[i] != '\0'; i++){
			if (line[i] >= 65 && line[i] <= 90){
				line[i] = line[i] + 32;
			}
			else if (line[i] >= 97 && line[i] <= 122){
				line[i] = line[i] - 32;
			}
			fputc(line[i], dest_text_file);
		}
		printf("%s\n", line);
	}
	fclose(src_text_file);
	fclose(dest_text_file);
	return 0;
}
