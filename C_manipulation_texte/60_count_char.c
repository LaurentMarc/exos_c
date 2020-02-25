/*
 * 60_count_char.c
 *
 *  Created on: Feb 21, 2020
 *      Author: marcl
 */
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <wctype.h>


/* ---------------  to display sum of vowel and consonnant, and percent of each*/
int display_count_from_text(char text []){
	int sum_vowel =  count_vowel_from_text(text);
	int sum_consonnant = count_consonnant_from_text(text, sum_vowel);
	int sum_letters = sum_consonnant + sum_vowel;
	float percent_vowel = ((float) sum_vowel * 100) / (float) sum_letters ;
	float percent_consonnant = 100 - percent_vowel;
	printf("il y a %d voyelles, il y a %d consonnes et %d lettres\n Les voyelles representent %.2f %% et les consonnes %.2f %%",
			sum_vowel, sum_consonnant, sum_letters, percent_vowel, percent_consonnant);
	return 0;
}


/* ---------------  to calculate sum of vowel --------------------------*/
int count_vowel_from_text(char text []){
	int count_vowel = 0;
	for (int i=0; text[i] != '\0'; i++){
		text[i] =  towlower(text[i]);
		if ((text[i]== 'a') || (text[i]== 'e') || (text[i]== 'i')
			|| (text[i]== 'o') || (text[i]== 'u') || (text[i]== 'y')
			|| (text[i]== '�') || (text[i]== '�') || (text[i]== '�')
			|| (text[i]== '�') || (text[i]== '�') || (text[i]== '�')) {
			count_vowel ++;
		}
	}
	return count_vowel;
}


/* ---------------  to calculate sum of consonnant ----------------------*/
int count_consonnant_from_text(char text [], int sum_vowel){
	int count_consonnant = 0 ;
	int count_letters = 0;
	int i = 0;
	while (text[i] != '\0'){
		text[i] =  towlower(text[i]);
		if (isalpha(text[i]) || (text[i] == '�') || (text[i]== '�') || (text[i]== '�')
			|| (text[i]== '�') || (text[i]== '�') || (text[i]== '�') || (text[i]== '�')){
			count_letters++;
		}
		i++;
	}
	count_consonnant = count_letters - sum_vowel;
	return count_consonnant;
}


int main(int argc, char* argv[]) {

	char text1 [] =  "Bonjour, je suis heureux d'etre au campus";

	char text2 [] = "Qu'est-ce qu'un processeur ARM ? C'est un type de processeur particulier dont l'agencement des composants"
			"�lectroniques permet une taille r�duite. ARM est l'acronyme de Advanced Risk"
			"Machine. A l'origine, le A de ARM signifiait Acorn, le nom de la soci�t� qui a"
			"�quip� pour la premi�re fois un ordinateur avec un processeur ARM, en 1987."
			"Depuis, l'architecture ARM a rencontr� un succ�s qui ne se d�ment pas,"
			"notamment ces derni�res ann�es. Des processeurs ARM, on en trouve dans tous"
			"les smartphones r�cents : iPhone 4, Samsung Galaxy S, tout comme dans l'iPad,"
			"le Nokia N97 ou le Nexus One de Google. Mais la soci�t� ARM ltd ne fabrique"
			"pas, � proprement parler, les processeurs. Elle con�oit les architectures des"
			"processeurs, leurs plans en quelque sorte. Ce sont les clients qui, apr�s"
			"achat des licences, produisent les processeurs. Par exemple, Samsung fabrique"
			"un processeur ARM pour ses t�l�phones haut de gamme (Samsung Galaxy S et"
			"Wave), reposant sur l'architecture ARM Cortex-A8, cadenc�e � 1 GHz. Le"
			"processeur Apple A4, qui �quipe les iPhone 4 et les iPad, utilise exactement"
			"la m�me architecture Cortex-A8. Ces \"petits\" processeurs connaissent un tel"
			"succ�s qu'ils �voluent tr�s rapidement : Samsung a d�j� annonc� le rempla�ant"
			"de Cortex-A8 ; celui-ci r�pond au nom de Cortex-A9 et int�gre deux coeurs,"
			"comme dans les PC. Quant au Cortex-A15, qui devrait �tre disponible dans une"
			"vingtaine de mois, on sait d�j� qu'il s'agira d'un processeur quatre coeurs"
			"cadenc� � 2,5 GHz et basse consommation ! Un tel processeur devrait avoir des"
			"performances similaires � celles d'un ordinateur portable tr�s haut de gamme,"
			"alors qu'il est pr�vu pour �tre embarqu� dans un t�l�phone de seulement"
			"quelques millim�tres d'�paisseur.";

		display_count_from_text(text1);
}
