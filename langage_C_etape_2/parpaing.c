/*
 * parpaing.c
 *
 *  Created on: Feb 19, 2020
 *      Author: marcl
 */
#include <stdbool.h>
#include <stdio.h>


float calcul_tolerance_max(float tolerance, float value){
	float result_tolerance_max = value + (value*(tolerance/100));
	return result_tolerance_max;
	}


float calcul_tolerance_min(float tolerance, float value){
	float result_tolerance_min = value - (value*(tolerance/100));
	return result_tolerance_min;
	}


bool compare_value(float model_value, float test_value, float tolerance){
	if (test_value < calcul_tolerance_max(tolerance, model_value) && test_value > calcul_tolerance_min(tolerance, model_value)){
		return true;
	}
	else{
		return false;
	}
}


int number_of_correct_dimensions(float L_test, float  M_test,float  H_test, float tolerance){
	float H = 200;
	float M = 200;
	float L = 500;
	int count_correct_dimensions = 0;
	bool H_is_correct = compare_value(H, H_test, tolerance);
    bool M_is_correct = compare_value(M, M_test, tolerance);
    bool L_is_correct = compare_value(L, L_test, tolerance);

    if (H_is_correct) count_correct_dimensions++;
    if (M_is_correct) count_correct_dimensions++;
    if (L_is_correct) count_correct_dimensions++;
    return count_correct_dimensions;
}


char categorize_cinderblocks_tolerance(float P_test, float  L_test, float  M_test, float  H_test, float tolerance){
	float P= 19000;
	bool P_is_correct = compare_value(P, P_test, tolerance);

    if (P_is_correct){
       if (number_of_correct_dimensions(L_test, M_test, H_test, tolerance) >= 2){
           return 'A';
       }
       else{
    	   return 'B';
       }
    }
    if (!(P_is_correct)){
       if (number_of_correct_dimensions(L_test, M_test, H_test, tolerance) <= 2){
    	   return 'C';
       }
       else{
    	   return 'B';
       }
    }
    return 0;
}


int main(int argc, char* argv[]) {
	float tolerance = 2;
    float P_test = 19000;
    float H_test = 200;
    float M_test = 200;
    float L_test = 500;
    char category_test = categorize_cinderblocks_tolerance(P_test, L_test, M_test, H_test, tolerance);
    printf("la categorie du parpaing testé est : %c\n",category_test);
}
