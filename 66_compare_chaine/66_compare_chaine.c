/*
 * 66_compare_chaine.c
 *
 *  Created on: Feb 25, 2020
 *      Author: marcl
 */


#include <stdio.h>


int compare(char str1[],char str2[]){
	int lenghtstr1 = strlen(str1);
	int lenghtstr2 = strlen(str2);

	for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i ++){
		if (str1[i] < str2[i]){
			return -1;
		}
		if (str1[i] > str2[i]){
			return 1;
		}
	}
	if (lenghtstr1 < lenghtstr2){
		return -1;
	}
	if (lenghtstr1 > lenghtstr2){
		return 1;
	}
	return 0;
}


int main(int argc, char* argv[]) {

	char str1[] = "ab";
	char str2[] = "abc";
	char str3[] = "ac";

	int test1 = compare(str1, str1);
	int test2 = compare(str1, str3);
	int test3 = compare(str2, str1);
	int test4 = compare(str1, str2);

	printf("test 1, doit être 0 : %d \n"
			"test 2, doit être -1 : %d\n"
			"test 3 : doit être  1 : %d\n"
			"test 4 : doit être -1 : %d",
			test1, test2, test3, test4);
}
