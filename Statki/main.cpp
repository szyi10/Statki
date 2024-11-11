#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Stała definiująca rozmiar planszy
#define SIZE 10

// Inicjacja planszy pustymi znakami '.', reprezentujące puste pola
void initializeBoard(char borad[SIZE][SIZE]);
// Drukowanie planszy na ekranie
void printBoard(char board[SIZE][SIZE]);

int main() {
	char board[SIZE][SIZE];
	srand(time(NULL));

	initializeBoard(board);
	printBoard(board);

	return 0;
}