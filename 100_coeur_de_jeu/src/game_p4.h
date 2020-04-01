/*
 * game_p4.h
 *
 *  Created on: 31 mars 2020
 *      Author: marc
 */

#ifndef GAME_P4_H_
#define GAME_P4_H_

#include <stdint.h>
#include <stdio.h>

/*paramètres de jeu puissance 4 */
#define NB_OF_COLUMN 7
#define NB_OF_LINE 6
#define PLAYER_1 1
#define PLAYER_2 2
#define EMPTY_SPACE 0

typedef struct {
	int8_t x_axis;
	int8_t y_axis;
} axis;

/*COMMENTER UTILISATION DES FONCTIONS + VALEURS RETOUR*/
void gp4_init(void);
void gp4_show_board(void);
void gp4_next_player(void);
void gp4_test_move_all(void);
void gp4_test_play_token(void);

/*Valide le coup choisi par joueur
 * retourne struct de l'axe X et Y de la position finale du jeton joué*/
axis gp4_play_token(void);


#endif /* GAME_P4_H_ */