/*
 * game_p4.c
 *
 *  Created on: 30 mars 2020
 *      Author: marc
 */
#include "debug.h"
#include "game_p4.h"

static int8_t matrix[NB_OF_COLUMN][NB_OF_LINE];
/* token_top_selector = position du jeton dans ligne de sélection (de 1 à NB_OF_COLUMN)*/
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
	token_top_selector = START_POSITION;
}

/*AFFFICHE LA MATRICE DE JEU AVEC LA LIGNE DE SELECTION*/
void gp4_show_board(void) {
	printf("\ntop line\t");
	for (int8_t col = 0; col < NB_OF_COLUMN; col++) {
		if (col == token_top_selector - 1) {
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
	if (token_top_selector < 1) { //SI JETON À L'EXTREMITÉ DE LA LIGNE IL BASCULE AU COTÉ OPPOSÉ
		token_top_selector = NB_OF_COLUMN;
	}
	while (matrix[token_top_selector - 1][0] != EMPTY_SPACE) { //SI COLONNE PLEINE LE JETON PASSE À LA COLONNE SUIVANTE
		token_top_selector--;
		if (token_top_selector < 1) {
			token_top_selector = NB_OF_COLUMN;
		}
	}
}

/*MOUVEMENT À DROITE*/
void gp4_move_right(void) {
	token_top_selector++;
	if (token_top_selector > NB_OF_COLUMN) { //SI JETON À L'EXTREMITÉ DE LA LIGNE IL BASCULE AU COTÉ OPPOSÉ
		token_top_selector = 1;
	}
	while (matrix[token_top_selector - 1][0] != EMPTY_SPACE) { //SI COLONNE PLEINE LE JETON PASSE À LA COLONNE SUIVANTE
		token_top_selector++;
		if (token_top_selector > NB_OF_COLUMN) {
			token_top_selector = 1;
		}
	}
}

/*VALIDATION DU COUP À JOUER*/
pos_token_t gp4_play_token(void) {
	pos_token_t pos_token;
	pos_token.beg_position.c = token_top_selector;
	pos_token.beg_position.l = 1;
	pos_token.end_position.c = token_top_selector;
	for (int8_t line = 0; line < NB_OF_LINE; line++) {
		if (matrix[token_top_selector - 1][line + 1] != EMPTY_SPACE) { //CONTROLE SI PRÉSENCE JETON DANS LA COLONNE SUIVANTE
			matrix[token_top_selector - 1][line] = active_player;
			pos_token.end_position.l = line + 1;
			pos_token.is_ok = 1;
		}
	}
	if (matrix[token_top_selector - 1][NB_OF_LINE - 1] == EMPTY_SPACE) { //SI COLONNE VIDE LE JETON EST TOUT EN BAS
		matrix[token_top_selector - 1][NB_OF_LINE - 1] = active_player;
		pos_token.end_position.l = NB_OF_LINE;
		pos_token.is_ok = 1;
	}

	return pos_token;
}

/*CHNAGEMENT DE JOUEUR*/
void gp4_set_player(void) {
	if (active_player == PLAYER_1) {
		active_player = PLAYER_2;
		token_top_selector = START_POSITION;
		if (matrix[START_POSITION - 1][0] != EMPTY_SPACE) { //SI LA 1ÈRE COLONNE EST PLEINE LE JETON EST DÉPLACÉ SUR LA COLONNE LIBRE LA PLUS PROCHE
			gp4_move_right();
		}
	} else {
		active_player = PLAYER_1;
		token_top_selector = START_POSITION;
		if (matrix[START_POSITION - 1][0] != EMPTY_SPACE) {
			gp4_move_right();
		}
	}
}

/*FONCTION NON FINIE REVOIR AVEC STRUCTURES ÉTABLIE EN .H*/
static victory_infos gp4_check_winner(void) {
	victory_infos victory_infos;
	victory_infos.winner = 0;

	int8_t aligned_tokens_P1 = 0;
//	int8_t aligned_tokens_P2 = 0;

//VÉRIFICATION DE VICTOIRE HORIZONTALE
	for (int8_t line = 0; line < NB_OF_LINE; line++) {
		for (int8_t col = 0; col < NB_OF_COLUMN; col++) {
			if (matrix[line][col] == PLAYER_1) {
				victory_infos.token_location[aligned_tokens_P1][0] = line;
				victory_infos.token_location[aligned_tokens_P1][1] = col;
				aligned_tokens_P1++;
			} else {
				aligned_tokens_P1 = 0;
			}
		}
	}
	if (aligned_tokens_P1) {
		return victory_infos;
	}
	return victory_infos;
}

/*FONCTIONS DE TESTS UNITAIRE*/

void gp4_test_move_all(void) {
	debug_printf(0, "Entrée dans la fonction de test de mouvements\n");
	debug_printf(0, "initialisation matrice +  3 mouvements joueur à gauche\n");
	gp4_init();
	gp4_show_board();
	gp4_move_left();
	gp4_move_left();
	gp4_move_left();
	gp4_show_board();
	debug_printf(0, "quatrième mouvement joueur à gauche\n");
	gp4_move_left();
	gp4_show_board();
	debug_printf(0, "changement de joueur\n");
	gp4_set_player();
	gp4_show_board();
	debug_printf(0, "déplacement jeton extremité droite\n");
	token_top_selector = NB_OF_COLUMN;
	gp4_show_board();
	debug_printf(0, "mouvement joueur à droite\n");
	gp4_move_right();
	gp4_show_board();
	debug_printf(0, "simulation de colonnes pleines\n");
	token_top_selector++;
	matrix[0][0] = 1;
	matrix[2][0] = 1;
	matrix[3][0] = 1;
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
	gp4_set_player();
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

void gp4_test_check_winner(void) {
	debug_printf(0, "entrée dans la fonction de test de controle de gagnant\n");
	debug_printf(0, "initialisation matrice + 4 coups joueur 1");
	gp4_init();
	gp4_show_board();
	gp4_play_token();
	gp4_move_right();
	gp4_play_token();
	gp4_move_right();
	gp4_play_token();
	gp4_move_right();
	gp4_play_token();
	gp4_show_board();
	debug_printf(0, "controle de victoire");
	gp4_check_winner();

}
