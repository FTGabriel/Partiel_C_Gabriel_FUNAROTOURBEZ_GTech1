#pragma once
#include <stdio.h>
#pragma warning(disable:4996)
#include <SDL.h>

#define CORP_SNAKE '-'
#define TETE_SNAKE 'B'
#define NOURRITURE '*'
#define CASE_VIDE ' '

struct uneCellule {
    int ligne;
    int colonne;
    struct uneCellule* suiv;
};
typedef struct uneCellule uneCellule;

struct unSnake {
    uneCellule* teteSnake;
    uneCellule* queueSnake;
};
typedef struct unSnake unSnake;

struct uneDirection {
    int ligne;
    int colonne;
};
typedef struct uneDirection uneDirection;

unSnake creerSnake() {

    unSnake snake;

    uneCellule* teteSnake = malloc(sizeof(uneCellule));
    uneCellule* queueSnake = malloc(sizeof(uneCellule));
    uneCellule* milieuSnake = malloc(sizeof(uneCellule));

    teteSnake->ligne = 1;
    teteSnake->colonne = 4;
    teteSnake->suiv = NULL;

    milieuSnake->ligne = 1;
    milieuSnake->colonne = 3;
    milieuSnake->suiv = teteSnake;

    queueSnake->ligne = 1;
    queueSnake->colonne = 2;
    queueSnake->suiv = milieuSnake;

    snake.teteSnake = teteSnake;
    snake.queueSnake = queueSnake;

    return snake;
};