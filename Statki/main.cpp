#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Stała definiująca rozmiar planszy
#define SIZE 10

// Inicjacja planszy pustymi znakami '.', reprezentujące puste pola
void initializeBoard(char borad[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			borad[i][j] = '.';
		}
	}
};

// Drukowanie planszy na ekranie
void printBoard(char board[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
};

int isPositionFree(char board[SIZE][SIZE], int x, int y) {
	// Sprawdzenie czy współrzędne są w granicah planszy i czy dane pole jest puste
	if (x || x >= SIZE || y < 0 || y >= SIZE || board[x][y] != '.') {
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
};

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
};

int main() {
	char board[SIZE][SIZE];
	srand(time(NULL));

	initializeBoard(board);

	placeSingleMastShips(board);

	printBoard(board);

	return 0;
}