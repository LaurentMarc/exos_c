#include <stdio.h>
#include "leds_control.h"
#include <unistd.h>

//création des couleurs//

typedef struct{
	int RValue;
	int GValue;
	int BValue;
}color;

color white = {255, 255, 255},
		green = {0, 255, 0},
		blue = {0, 0, 255},
		red = {255, 0, 0},
		purple = {255, 0, 255},
		yellow = {255, 255, 0},
		black = {0, 0, 0};


//création tableau//
int tabsize = 7;
color matrice [7][7];
color actual_display[7][7];

void init_table(){
	for (int row = 0; row < tabsize; row ++){
		for (int col = 0; col < tabsize; col ++){
			matrice[row][col] = black;
			actual_display[row][col] = black;
		}
	}
}


//recoit un tableau et l'affiche//

void Setledmatrix(color tabline[7][7], int tabsize){
	// ajouter fonction pour comarer matrice et actual_display pour modifier que les cases nécessaires //
	for (int row = 0; row < tabsize; row ++){
		for (int col = 0; col < tabsize; col ++){

			setLedColor((row + 1), (col + 1), tabline[row][col].RValue, tabline[row][col].GValue, tabline[row][col].BValue );
		}
	}
}


//créée et affiche un tableau de couleur unie//

void Setonecolor(color color_selected,int tabsize){
	color line [7] = {color_selected, color_selected, color_selected, color_selected, color_selected, color_selected, color_selected};
	color * tabline [7] = {line, line, line, line, line, line, line};
	Setledmatrix(tabline, tabsize);
}


//créée et affiche tableau avec numéro//

void Setnumber(int number, color nbr_color, color bckgrnd, int tabsize){

	if (number == 0){                  // modifie la couleur des emplacements à modifier pour former un 0 //
		for (int row = 0; row < tabsize; row ++){
			for (int col = 0; col < tabsize; col ++){
				if (row == 0 || row == 6){
					matrice[row][2] = nbr_color;
					matrice[row][3] = nbr_color;
					matrice[row][4] = nbr_color;
				}
				else if (row == 1 || row == 2 || row == 3 || row == 4 || row == 5){
					matrice[row][1] = nbr_color;
					matrice[row][5] = nbr_color;
				}
				else{
					matrice[row][col] = bckgrnd;
				}
			}
		}
	}
	if (number == 1){                  // modifie la couleur des emplacements à modifier pour former un 1 //
		for (int row = 0; row < tabsize; row ++){
			for (int col = 0; col < tabsize; col ++){
				if ((col == 4) || (row == 1 && col == 3) || (row == 2 && col == 2) || (row == 3 && col == 1)){
					matrice[row][col] = nbr_color;
				}
				else{
					matrice[row][col] = bckgrnd;
				}

			}
		}
	}
	if (number == 2){
		for (int row = 0; row < tabsize; row ++){
			for (int col = 0; col < tabsize; col ++){
				if ((row == 0 && col == 2) || (row == 0 && col == 3) || (row == 0 && col == 4)
						|| (row == 1 && col == 1) || (row == 1 && col == 5) || (row == 2 && col == 5)
						|| (row == 3 && col == 2) || (row == 3 && col == 3) || (row == 3 && col == 4)
						|| (row == 4 && col == 1) || (row == 5 && col == 1) || (row == 6 && col == 2)
						|| (row == 6 && col == 3) || (row == 6 && col == 4) ||(row == 6 && col == 5)){
					matrice[row][col] = nbr_color;
				}
				else{
					matrice[row][col] = bckgrnd;
				}

			}
		}


		color line_1 [7] = {bckgrnd, bckgrnd, nbr_color, nbr_color, nbr_color, bckgrnd, bckgrnd};
		color line_2 [7] = {bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_3 [7] = {bckgrnd, bckgrnd, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_4 [7] = {bckgrnd, bckgrnd, nbr_color, nbr_color, nbr_color, bckgrnd, bckgrnd};
		color line_5 [7] = {bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd, bckgrnd, bckgrnd};
		color line_6 [7] = {bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd, bckgrnd, bckgrnd};
		color line_7 [7] = {bckgrnd, bckgrnd, nbr_color, nbr_color, nbr_color, nbr_color, bckgrnd};
		color *number_tabline [7] = {line_1, line_2, line_3, line_4, line_5, line_6, line_7};
		Setledmatrix(number_tabline, tabsize);

	}
	if (number == 3){
		color line_1 [7] = {bckgrnd, bckgrnd, nbr_color, nbr_color, nbr_color, bckgrnd, bckgrnd};
		color line_2 [7] = {bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_3 [7] = {bckgrnd, bckgrnd, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_4 [7] = {bckgrnd, bckgrnd, bckgrnd, nbr_color, nbr_color, bckgrnd, bckgrnd};
		color line_5 [7] = {bckgrnd, bckgrnd, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_6 [7] = {bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_7 [7] = {bckgrnd, bckgrnd, nbr_color, nbr_color, nbr_color, bckgrnd, bckgrnd};
		color *number_tabline [7] = {line_1, line_2, line_3, line_4, line_5, line_6, line_7};
		Setledmatrix(number_tabline, tabsize);

	}
	if (number == 4){
		color line_1 [7] = {bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_2 [7] = {bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_3 [7] = {bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_4 [7] = {bckgrnd, bckgrnd, nbr_color, nbr_color, nbr_color, bckgrnd, bckgrnd};
		color line_5 [7] = {bckgrnd, bckgrnd, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_6 [7] = {bckgrnd, bckgrnd, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_7 [7] = {bckgrnd, bckgrnd, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color *number_tabline [7] = {line_1, line_2, line_3, line_4, line_5, line_6, line_7};
		Setledmatrix(number_tabline, tabsize);

	}
	if (number == 5){
		color line_1 [7] = {bckgrnd, nbr_color, nbr_color, nbr_color, nbr_color, nbr_color, bckgrnd};
		color line_2 [7] = {bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd, bckgrnd, bckgrnd};
		color line_3 [7] = {bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd, bckgrnd, bckgrnd};
		color line_4 [7] = {bckgrnd, bckgrnd, nbr_color, nbr_color, nbr_color, bckgrnd, bckgrnd};
		color line_5 [7] = {bckgrnd, bckgrnd, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_6 [7] = {bckgrnd, bckgrnd, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_7 [7] = {bckgrnd, nbr_color, nbr_color, nbr_color, nbr_color, bckgrnd, bckgrnd};
		color *number_tabline [7] = {line_1, line_2, line_3, line_4, line_5, line_6, line_7};
		Setledmatrix(number_tabline, tabsize);

	}
	if (number == 6){
		color line_1 [7] = {bckgrnd, bckgrnd, nbr_color, nbr_color, nbr_color, bckgrnd, bckgrnd};
		color line_2 [7] = {bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_3 [7] = {bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd, bckgrnd, bckgrnd};
		color line_4 [7] = {bckgrnd, bckgrnd, nbr_color, nbr_color, nbr_color, bckgrnd, bckgrnd};
		color line_5 [7] = {bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_6 [7] = {bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_7 [7] = {bckgrnd, bckgrnd, nbr_color, nbr_color, nbr_color, bckgrnd, bckgrnd};
		color *number_tabline [7] = {line_1, line_2, line_3, line_4, line_5, line_6, line_7};
		Setledmatrix(number_tabline, tabsize);

	}
	if (number == 7){
		color line_1 [7] = {bckgrnd, nbr_color, nbr_color, nbr_color, nbr_color, nbr_color, bckgrnd};
		color line_2 [7] = {bckgrnd, bckgrnd, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_3 [7] = {bckgrnd, bckgrnd, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_4 [7] = {bckgrnd, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd, bckgrnd};
		color line_5 [7] = {bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd};
		color line_6 [7] = {bckgrnd, bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd, bckgrnd};
		color line_7 [7] = {bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd, bckgrnd, bckgrnd};
		color *number_tabline [7] = {line_1, line_2, line_3, line_4, line_5, line_6, line_7};
		Setledmatrix(number_tabline, tabsize);

	}
	if (number == 8){
		color line_1 [7] = {bckgrnd, bckgrnd, nbr_color, nbr_color, nbr_color, bckgrnd, bckgrnd};
		color line_2 [7] = {bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_3 [7] = {bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_4 [7] = {bckgrnd, bckgrnd, nbr_color, nbr_color, nbr_color, bckgrnd, bckgrnd};
		color line_5 [7] = {bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_6 [7] = {bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_7 [7] = {bckgrnd, bckgrnd, nbr_color, nbr_color, nbr_color, bckgrnd, bckgrnd};
		color *number_tabline [7] = {line_1, line_2, line_3, line_4, line_5, line_6, line_7};
		Setledmatrix(number_tabline, tabsize);

	}
	if (number == 9){
		color line_1 [7] = {bckgrnd, bckgrnd, nbr_color, nbr_color, nbr_color, bckgrnd, bckgrnd};
		color line_2 [7] = {bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_3 [7] = {bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_4 [7] = {bckgrnd, bckgrnd, nbr_color, nbr_color, nbr_color, bckgrnd, bckgrnd};
		color line_5 [7] = {bckgrnd, bckgrnd, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_6 [7] = {bckgrnd, nbr_color, bckgrnd, bckgrnd, bckgrnd, nbr_color, bckgrnd};
		color line_7 [7] = {bckgrnd, bckgrnd, nbr_color, nbr_color, nbr_color, bckgrnd, bckgrnd};
		color *number_tabline [7] = {line_1, line_2, line_3, line_4, line_5, line_6, line_7};
		Setledmatrix(number_tabline, tabsize);
	}
	Setledmatrix(matrice, tabsize);
}


//affiche un compte à rebours

void countdown(int countdown, int tabsize){
	for(int count = countdown; count >= 0; count --){
		if (count == 9){
			Setnumber(count, white, black, tabsize);
		}
		if (count == 8){
			Setnumber(count, blue, black, tabsize);
		}
		if (count == 7){
			Setnumber(count, green, black, tabsize);
		}
		if (count == 6){
			Setnumber(count, yellow, black, tabsize);
		}
		if (count == 5){
			Setnumber(count, purple, black, tabsize);
		}
		if (count == 4){
			Setnumber(count, red, black, tabsize);
		}
		if (count == 3){
			Setnumber(count, white, green, tabsize);
		}
		if (count == 2){
			Setnumber(count, white, yellow, tabsize);
		}
		if (count == 1){
			Setnumber(count, white, purple, tabsize);
		}
		if (count == 0){
			Setnumber(count, white, red, tabsize);
		}
		sleep(4);
	}
}


int main(){

	//tableau de test initial//

	//	color line_1 [7] = {red, red, red, red, red, red, red};
	//	color line_2 [7] = {red, black, black, black, black, black, red};
	//	color line_3 [7] = {red, black, green, green, green, black, red};
	//	color line_4 [7] = {red, black, green, yellow, green, black, red};
	//	color line_5 [7] = {red, black, green, green, green, black, red};
	//	color line_6 [7] = {red, black, black, black, black, black, red};
	//	color line_7 [7] = {red, red, red, red, red, red, red};
	//	color *tabline [7] = {line_1, line_2, line_3, line_4, line_5, line_6, line_7};


	//	sleep(4);
	//	Setnumber(6, blue, white, tabsize);
	//	sleep(4);
	//	Setonecolor(black, tabsize);
	//	sleep(4);
	init_table();
	Setnumber(2, white, black, tabsize);
	sleep (2);
	init_table();
	Setledmatrix(matrice, tabsize);
	//countdown(9, tabsize);
}
