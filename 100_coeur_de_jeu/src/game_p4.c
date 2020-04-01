/*
 * game_p4.c
 *
 *  Created on: 30 mars 2020
 *      Author: marc
 */
#include "debug.h"
#include "game_p4.h"

static int8_t matrix[NB_OF_COLUMN][NB_OF_LINE];
/* token_top_selector = position du jeton dans ligne de sélection (de 0 à NB_OF_COLUMN -1)*/
static int8_t token_top_selector;
static int8_t active_player;


/* INITIALISE LA PARTIE
 * vide la matrice
 * fixe le active_player
 * initialise les couleurs associées à chaque joueur
 * */
void gp4_init(void) {
	for (int8_t line = 0; line < NB_OF_LINE; line++) {
		for (int8_t col = 0; col < NB_OF_COLUMN; col++) {
			matrix[col][line] = EMPTY_SPACE;
		}
	}
	active_player = PLAYER_1;
	token_top_selector = 0;
}

/*AFFFICHE LA MATRICE DE JEU AVEC LA LIGNE DE SELECTION*/
void gp4_show_board(void) {
	printf("\ntop line\t");
	for (int8_t col = 0; col < NB_OF_COLUMN; col++) {
		if (col == token_top_selector) {
			printf("%d ", active_player);
		} else {
			printf("%d ", EMPTY_SPACE);
		}
	}

	for (int8_t line = 0; line < NB_OF_LINE; line++) {
		printf("\nline %d  \t", line);
		for (int8_t col = 0; col < NB_OF_COLUMN; col++) {
			printf("%d ", matrix[col][line]);
		}
	}
	printf("\n\n");
}

/*MOUVEMENT À GAUCHE*/
void gp4_move_left(void) {
	token_top_selector--;
	if (token_top_selector < 0) {//SI JETON À L'EXTREMITÉ DE LA LIGNE IL BASCULE AU COTÉ OPPOSÉ
		token_top_selector = NB_OF_COLUMN - 1;
	}
	while (matrix[token_top_selector][0] != 0) {//SI COLONNE PLEINE LE JETON PASSE À LA COLONNE SUIVANTE
		token_top_selector--;
		if (token_top_selector < 0) {
			token_top_selector = NB_OF_COLUMN - 1;
		}
	}
}

/*MOUVEMENT À DROITE*/
void gp4_move_right(void) {
	token_top_selector++;
	if (token_top_selector > (NB_OF_COLUMN - 1)) { //SI JETON À L'EXTREMITÉ DE LA LIGNE IL BASCULE AU COTÉ OPPOSÉ
		token_top_selector = 0;
	}
	while (matrix[token_top_selector][0] != 0) {//SI COLONNE PLEINE LE JETON PASSE À LA COLONNE SUIVANTE
		token_top_selector++;
		if (token_top_selector > (NB_OF_COLUMN - 1)) {
			token_top_selector = 0;
		}
	}
}

/*VALIDATION DU COUP À JOUER*/
axis gp4_play_token(void) {
	axis token_axis;
	token_axis.y_axis = token_top_selector;
	for (int8_t line = 0; line < NB_OF_LINE; line++) {//CONTROLE SI PRÉSENCE JETON DANS LA COLONNE
		if (matrix[token_top_selector][line + 1] != 0) {
			matrix[token_top_selector][line] = active_player;
			token_axis.x_axis = line;
		}
	}
	if (matrix[token_top_selector][NB_OF_LINE - 1] == 0) { //SI COLONNE VIDE LE JETON EST TOUT EN BAS
		matrix[token_top_selector][NB_OF_LINE - 1] = active_player;
		token_axis.x_axis = NB_OF_LINE - 1;

	}
	return token_axis;
}

/*CHNAGEMENT DE JOUEUR*/
void gp4_next_player(void) {
	if (active_player == PLAYER_1) {
		active_player = PLAYER_2;
		token_top_selector = 0;
		if (matrix[0][0] != 0) { //SI LA 1ÈRE COLONNE EST PLEINE LE JETON EST DÉPLACÉ SUR LA COLONNE LIBRE LA PLUS PROCHE
			gp4_move_right();
		}
	} else {
		active_player = PLAYER_1;
		token_top_selector = 0;
		if (matrix[0][0] != 0) {
			gp4_move_right();
		}
	}
}

/*FONCTIONS DE TESTS UNITAIRE*/

void gp4_test_move_all(void) {
	debug_printf(0, "Entrée dans la fonction de test de mouvements\n");
	debug_printf(0, "initialisation matrice + mouvement joueur à gauche\n");
	gp4_init();
	gp4_show_board();
	gp4_move_left();
	gp4_show_board();
	debug_printf(0, "changement de joueur\n");
	gp4_next_player();
	gp4_show_board();
	debug_printf(0, "déplacement jeton extremité droite\n");
	token_top_selector = NB_OF_COLUMN - 1;
	gp4_show_board();
	debug_printf(0, "mouvement joueur à droite\n");
	gp4_move_right();
	gp4_show_board();
	debug_printf(0, "simulation de colonnes pleines\n");
	matrix[0][0] = 1;
	matrix[2][0] = 1;
	matrix[4][0] = 1;
	matrix[6][0] = 1;
	gp4_show_board();
	debug_printf(0,
			"4 mouvements joueur à droite\n le jeton ne doit se trouver que sur des colonnes libres\n");
	gp4_move_right();
	gp4_show_board();
	gp4_move_right();
	gp4_show_board();
	gp4_move_right();
	gp4_show_board();
	gp4_move_right();
	gp4_show_board();
	debug_printf(0, "changement de joueur\n");
	gp4_next_player();
	gp4_show_board();
	debug_printf(0, "2 mouvements joueur à gauche\n");
	gp4_move_left();
	gp4_show_board();
	gp4_move_left();
	gp4_show_board();
}

void gp4_test_play_token(void) {
	debug_printf(0,
			"Entrée dans la fonction de test de validation de mouvement\n");
	debug_printf(0,
			"initialisation matrice + 3 coups sans mouvement du joueur 1\n");
	gp4_init();
	gp4_show_board();
	gp4_play_token();
	gp4_show_board();
	gp4_play_token();
	gp4_show_board();
	gp4_play_token();
	gp4_show_board();
}
