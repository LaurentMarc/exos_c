/*
 * 74_translat_point.c
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
	float distance = (b.coord_x - a.coord_x) * (b.coord_x - a.coord_x) + (b.coord_y - a.coord_y) * (b.coord_y - a.coord_y);
	distance = sqrt(distance);
	return distance;
}


void translate(point* point, int new_x, int new_y){
	(*point).coord_x = new_x;
	(*point).coord_y = new_y;
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
	printf("%f\n", test);

	int new_coord_x = 3;
	int new_coord_y = 3;

	translate(&b, new_coord_x, new_coord_y);
	printf("nouvelles coordonnées x et y de B : %d %d", b.coord_x, b.coord_y);

}
