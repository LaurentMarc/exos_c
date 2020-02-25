/*
 * pilotage_elcairage.c
 *
 *  Created on: Feb 20, 2020
 *      Author: marcl
 */
#include <stdbool.h>
#include <stdio.h>


int define_brightness(int hour, bool partial_night, bool night){
	if (night){
		if (hour >= 0 && hour < 300){
			return 70;
		}
		else{
			return 100;
		}
	}
	else if (partial_night){
		return 50;
	}
	else {
		return 0;
	}
}

int convert_to_minutes(int h, int m){
	int hour_in_minutes = (h * 60) + m;
	return hour_in_minutes;
}


int get_night_status(int sunrise, int sunset, int hour){
		if (hour < (sunrise - 30) || hour > (sunset + 30)){
			return true;
		}
		else{
			return false;
		}
}


int get_partial_night_status(int sunrise, int sunset, int hour){
		if ((hour >= (sunrise - 30)) && (hour <= sunrise)){
			return true;
		}
		else if ((hour <= (sunset + 30)) && (hour >= sunset)){
			return true;
		}
		else{
			return false;
		}
}


int display_saving_for_defined_day(int sunrise, int sunset){
	bool partial_night;
	bool night;
	int brightness;
	int display_count = 0;
	for (int i = 0; i < 1440; i += 30){
		display_count++;
		partial_night = get_partial_night_status(sunrise, sunset, i);
		night = get_night_status(sunrise, sunset, i);
		brightness = define_brightness(i, partial_night, night);
		printf("%d - %d min luminosité fonction display... %d - night : %d - partial night : %d\n", display_count,i , brightness, night, partial_night);
		//printf("%d %d %d %d\n", partial_night, sunrise, sunset, i);
	}
}


int main(int argc, char* argv[]) {

	int clock;
	bool night;
	bool partial_night;
	int brightness;

	night = true;
	clock = convert_to_minutes(5,0);
	partial_night = false ;

	brightness = define_brightness(clock, partial_night, night);
	printf("luminosité : %d%%\n", brightness);



	int hour_sunrise;
	int minute_sunrise;
	int hour_sunset;
	int minute_sunset;

	int sunrise_in_minute = convert_to_minutes(hour_sunrise, minute_sunrise);
	int sunset_in_minute = convert_to_minutes(hour_sunset, minute_sunset);
	int daytime_in_minutes = sunset_in_minute - sunrise_in_minute;
	display_saving_for_defined_day(420, 1140);



}
