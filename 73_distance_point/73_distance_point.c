/*
 * 73_distance_point.c
 *
 *  Created on: Feb 26, 2020
 *      Author: marcl
 */


#include <stdio.h>
#include <math.h>


typedef struct{
	int coord_y;
	int coord_x;
}point;


float distance_between_two_points(point a, point b){
	float coord_x;
	float coord_y;
	float distance;
	coord_x = b.coord_x - a.coord_x;
	coord_y = b.coord_y - a.coord_y;
	coord_x = coord_x * coord_x;
	coord_y = coord_y * coord_y;
	distance = coord_y + coord_x;
	distance = sqrt(distance);
	return distance;
}


int main(int argc, char* argv[]){

	point a;
	a.coord_x = 1;
	a.coord_y = 1;

	point b;
	b.coord_x = 2;
	b.coord_y = 2;

	printf("coordonnées x et y du point A : %d %d\ncoordonnées x et y du point B : %d %d\n", a.coord_x, a.coord_y, b.coord_x, b.coord_y);
	float test = distance_between_two_points(a, b);
	printf("%f", test);
}
