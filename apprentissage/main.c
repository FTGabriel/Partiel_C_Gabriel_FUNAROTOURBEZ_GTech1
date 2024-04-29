#include <stdio.h>;
#include <stdlib.h>;
#include <windows.h>;
#include <string.h>;
#include <SDL.h>;
#include <SDL_image.h>;
#pragma warning(disable : 4996)
#include "main.h";
#include "nourriture.c";
#include "gestion_serpent.c";

#define CORP_SNAKE '-'
#define TETE_SNAKE 'B'
#define NOURRITURE '*'
#define CASE_VIDE ' '

int main(int argc, char* argv[]) {
    int i = 0;
    int touche = 0;
    int fail = 0;
    unSnake snake = creerSnake();
    uneDirection direction = { 0,1 };
    int aMange = 1;
    int nbCasesMangees = 0;
    int delay = 0;

    /*while (1) {
        void gererEvenement(unSnake * snake, int touche, int* fail, uneDirection * direction, int* aMange) {
            SDL_Event event;
            if (direction->ligne == 0) {
                if (touche == SDLK_UP) {
                    direction->ligne = -1;
                    direction->colonne = 0;
                }
                if (touche == SDLK_DOWN) {
                    direction->ligne = 1;
                    direction->colonne = 0;
                }
            }
            if (direction->colonne == 0) {
                if (touche == SDLK_LEFT) {
                    direction->colonne = -1;
                    direction->ligne = 0;
                }
                if (touche == SDLK_RIGHT) {
                    direction->colonne = 1;
                    direction->ligne = 0;
                }
            }

            ajouterEnTete(snake, snake->teteSnake->ligne + direction->ligne, snake->teteSnake->colonne + direction->colonne, aMange, fail);
            if (!*aMange)
                supprimerQueue(snake);
        }
    }*/

    // INITIALISATIONS
    if (argc > 1) {
        passer_murs = 1;
    }
    initscr();
    keypad(0, TRUE);
    noecho();
    cbreak();

    getmaxyx(0, nbLignes, nbColonnes);

    grille = malloc(nbLignes * sizeof(char*));
    for (i = 0; i < nbLignes; i++) {
        grille[i] = malloc(nbColonnes * sizeof(char));
    }
    initGrille();

    // Boucle de jeu
    while (!fail) {
        if (aMange) {
            genererDuManger(grille);
            nbCasesMangees++;
            delay = 101 - nbCasesMangees;
            delay = (delay < 60) ? 60 : delay;
            timeout(delay);
        }
        afficherGrille(snake);
        touche = getch();
        gererEvenement(&snake, touche, &fail, &direction, &aMange);
        erase();
    }

    // Le joueur a fail
    timeout(5000);
    erase();
    printFail();
    getch();
    endwin();
    return 0;
}
