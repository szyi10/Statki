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

// Umieszczanie jednomasztowców na planszy
void placeSingleMastShips(char board[SIZE][SIZE]) {
	int count = 0;
	while (count < 4) {
		int x = rand() % SIZE;
		int y = rand() % SIZE;

		// Sprawdzenie czy dane pole jest puste
		if (board[x][y] == '.') {
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