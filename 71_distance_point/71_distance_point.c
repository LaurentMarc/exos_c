/*
 * 71_distance_point.c
 *
 *  Created on: Feb 25, 2020
 *      Author: marcl
 */


#include <stdio.h>
#include <math.h>


float distance_between_two_points(float xa, float xb, float ya, float yb){
	float coord_x;
	float coord_y;
	float distance;
	coord_x = xb - xa;
	coord_y = yb - ya;
	coord_x = coord_x * coord_x;
	coord_y = coord_y * coord_y;
	distance = coord_y + coord_x;
	distance = sqrt(distance);
	return distance;
}



int main(int argc, char* argv[]){
	float xa = 1;
	float xb = 2;
	float ya = 1;
	float yb = 2;

	float test = distance_between_two_points(xa, xb, ya, yb);

	printf("%f", test);

}
