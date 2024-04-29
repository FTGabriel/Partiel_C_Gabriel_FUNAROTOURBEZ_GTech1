#include <stdio.h>;
#include <stdlib.h>
#include <windows.h>;
#include <string.h>;
#include <SDL.h>;
#include <SDL_image.h>;
#pragma warning(disable : 4996)
#include <time.h>;
#include "nourriture.h";

#define CORP_SNAKE '-'
#define TETE_SNAKE 'B'
#define NOURRITURE '*'
#define CASE_VIDE ' '

void generernourriture(char** grille) {
    int ligne = 0;
    int colonne = 0;
    int done = 0;

    srand(time(NULL));
    while (!done) {
        ligne = rand() % (nbLignes - 1);
        colonne = rand() % (nbColonnes - 1);
        if (grille[ligne][colonne] == CASE_VIDE) {
            grille[ligne][colonne] = NOURRITURE;
            done = 1;
        }
    }
}