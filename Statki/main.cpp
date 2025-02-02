﻿#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Stała definiująca rozmiar planszy
#define SIZE 10

// Inicjacja planszy pustymi znakami '.', reprezentujące puste pola
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '.';  // Zmieniono 'borad' na 'board'
        }
    }
}

// Drukowanie planszy na ekranie
void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Sprawdzanie, czy dane pole jest wolne
int isPositionFree(char board[SIZE][SIZE], int x, int y) {
    // Sprawdzenie czy współrzędne są w granicach planszy i czy dane pole jest puste
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || board[x][y] != '.') {
        return 0;
    }

    // Sprawdzenie sąsiadujących pól
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int newX = x + i;
            int newY = y + j;
            if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE) {
                if (board[newX][newY] == 'x') {
                    return 0;
                }
            }
        }
    }
    return 1;
}

// Umieszczanie jednomasztowców na planszy
void placeSingleMastShips(char board[SIZE][SIZE]) {
    int count = 0;
    while (count < 4) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;

        if (isPositionFree(board, x, y)) {
            board[x][y] = 'x';
            count++;
        }
    }
}

// Umieszczanie dwumasztowców na planszy
void placeTwoMastShips(char board[SIZE][SIZE]) {
    int count = 0;

    while (count < 3) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        int orientation = rand() % 2; // 0 - poziomo, 1 - pionowo

        // Sprawdzenie, czy dwumasztowiec można umieścić poziomo
        if (orientation == 0 && y + 1 < SIZE &&
            isPositionFree(board, x, y) && isPositionFree(board, x, y + 1)) {
            board[x][y] = 'x';
            board[x][y + 1] = 'x';
            count++;
        }
        // Sprawdzenie, czy dwumasztowiec można umieścić pionowo
        else if (orientation == 1 && x + 1 < SIZE &&
            isPositionFree(board, x, y) && isPositionFree(board, x + 1, y)) {
            board[x][y] = 'x';
            board[x + 1][y] = 'x';
            count++;
        }
    }
}

// Umieszczanie trójmasztowców na planszy
void placeThreeMastShips(char board[SIZE][SIZE]) {
    int count = 0;

    while (count < 3) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        int orientation = rand() % 2; // 0 - poziomo, 1 - pionowo

        // Sprawdzenie, czy trójmasztowiec można umieścić poziomo
        if (orientation == 0 && y + 2 < SIZE && isPositionFree(board, x, y) && isPositionFree(board, x, y + 1) && isPositionFree(board, x, y + 2)) {
            board[x][y] = 'x';
            board[x][y + 1] = 'x';
            board[x][y + 2] = 'x';
            count++;
        }

        // Sprawdzenie, czy trójmasztowiec można umieścić pionowo
        else if (orientation == 1 && x + 2 < SIZE && isPositionFree(board, x, y) && isPositionFree(board, x + 1, y) && isPositionFree(board, x + 2, y)) {
            board[x][y] = 'x';
            board[x + 1][y] = 'x';
            board[x + 2][y] = 'x';
            count++;
        }
    }
}

// Umieszczanie czteromasztowca na planszy
void placeFourMastShip(char board[SIZE][SIZE]) {
    int placed = 0;

    while (!placed) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        int orientation = rand() % 2; // 0 - poziomo, 1 - pionowo

        // Sprawdzenie, czy czteromasztowiec można umieścić poziomo
        if (orientation == 0 && y + 2 < SIZE && isPositionFree(board, x, y) && isPositionFree(board, x, y + 1) && isPositionFree(board, x, y + 2) && isPositionFree(board, x, y + 3)) {
            board[x][y] = 'x';
            board[x][y + 1] = 'x';
            board[x][y + 2] = 'x';
            board[x][y + 3] = 'x';
            placed = 1;
        }

        // Sprawdzenie, czy czteromasztowiec można umieścić pionowo
        if (orientation == 1 && x + 2 < SIZE && isPositionFree(board, x, y) && isPositionFree(board, x + 1, y) && isPositionFree(board, x + 2, y) && isPositionFree(board, x + 3, y)) {
            board[x][y] = 'x';
            board[x + 1][y] = 'x';
            board[x + 2][y] = 'x';
            board[x + 3][y] = 'x';
            placed = 1;
        }
    }
}

int main() {
    char board[SIZE][SIZE];
    srand(time(NULL));

    initializeBoard(board);

    placeSingleMastShips(board);
    placeTwoMastShips(board);
    placeThreeMastShips(board);
    placeFourMastShip(board);

    printBoard(board);

    return 0;
}
