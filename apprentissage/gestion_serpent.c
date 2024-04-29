#include <stdio.h>;
#include <stdlib.h>;
#include <windows.h>;
#include <string.h>;
#include <SDL.h>;
#include <SDL_image.h>;
#pragma warning(disable : 4996)
#include "nourriture.h";
#include "main.h";

void ajouterEnTete(unSnake* snake, int ligne, int colonne, int* aMange, int* fail) {
    uneCellule* nouvelleTete = malloc(sizeof(uneCellule));
    nouvelleTete->ligne = ligne;
    nouvelleTete->colonne = colonne;
    nouvelleTete->suiv = NULL;
    snake->teteSnake->suiv = nouvelleTete;
    grille[(snake->teteSnake->ligne)][(snake->teteSnake->colonne)] = CORP_SNAKE;
    snake->teteSnake = snake->teteSnake->suiv;

    // Gestions des collisions 
    if (passer_murs) {
        if (snake->teteSnake->ligne < 0) {
            snake->teteSnake->ligne = nbLignes - 1;}
        else if (snake->teteSnake->ligne > nbLignes - 1) {
            snake->teteSnake->ligne = 0;}
        else if (snake->teteSnake->colonne < 0) {
            snake->teteSnake->colonne = nbColonnes - 1;}
        else if (snake->teteSnake->colonne > nbColonnes - 1) {
            snake->teteSnake->colonne = 0;}
        else if (grille[snake->teteSnake->ligne][snake->teteSnake->colonne] == CORP_SNAKE) {
            *fail = 1;}}
    else {
        if (snake->teteSnake->ligne < 0 ||
            snake->teteSnake->ligne > nbLignes - 1 ||
            snake->teteSnake->colonne < 0 ||
            snake->teteSnake->colonne > nbColonnes - 1)
            *fail = 1;}
    if (!*fail) {
        *aMange = (grille[snake->teteSnake->ligne][snake->teteSnake->colonne] == NOURRITURE) ? 1 : 0;
        grille[snake->teteSnake->ligne][snake->teteSnake->colonne] = TETE_SNAKE;
    }}

// Supprime la queue du snake
void supprimerQueue(unSnake* snake) {
    uneCellule* auxi;

    auxi = snake->queueSnake;
    grille[snake->queueSnake->ligne][snake->queueSnake->colonne] = CASE_VIDE;
    snake->queueSnake = snake->queueSnake->suiv;
    free(auxi);
}

void initGrille() {
    int i, j = 0;
    for (i = 0; i < nbLignes; i++) {
        for (j = 0; j < nbColonnes; j++) {
            grille[i][j] = CASE_VIDE;
        }
    }
}

void afficherGrille(unSnake snake) {
    int i, j = 0;
    for (i = 0; i < nbLignes; i++) {
        for (j = 0; j < nbColonnes; j++) {
            printw("%c", grille[i][j]);
        }
    }
}

void printFail() {
    move(nbLignes / 2 - 5 / 2, nbColonnes / 2 - 37 / 2);
    printw("    _/_/_/_/    _/_/    _/_/_/  _/   \n");
    move(1 + nbLignes / 2 - 5 / 2, nbColonnes / 2 - 37 / 2);
    printw("   _/        _/    _/    _/    _/    \n");
    move(2 + nbLignes / 2 - 5 / 2, nbColonnes / 2 - 37 / 2);
    printw("  _/_/_/    _/_/_/_/    _/    _/     \n");
    move(3 + nbLignes / 2 - 5 / 2, nbColonnes / 2 - 37 / 2);
    printw(" _/        _/    _/    _/    _/      \n");
    move(4 + nbLignes / 2 - 5 / 2, nbColonnes / 2 - 37 / 2);
    printw("_/        _/    _/  _/_/_/  _/_/_/_/ \n");
}