# Statki

## Spis treści

1. [Opis programu](#opis-programu)
2. [Struktura programu](#struktura-programu)
3. [Definicje i funkcje](#definicje-i-funkcje)
   - [Makrodefinicja](#makrodefinicja)
   - [Funkcje](#funkcje)
     - [initializeBoard](#initializeboardchar-boardsize)
     - [printBoard](#printboardchar-board-size)
     - [isPositionFree](#ispositionfreechar-boardsize-int-x-int-y)
     - [placeSingleMastShips](#placesinglemastshipschar-boardsize)
     - [placeTwoMastShips](#placetwomastshipschar-boardsize)
     - [placeThreeMastShips](#placethreemastshipschar-boardsize)
     - [placeFourMastShip](#placefourmastshipchar-boardsize)
     - [main](#main)
4. [Przykład działania](#przykład-działania)
5. [Uwagi](#uwagi)

## Opis programu
Program jest implementacją gry "statki", która generuje planszę 10x10 z losowym rozmieszczeniem statków o różnych długościach. Na planszy umieszczone są cztery jednomasztowce (1 pole), trzy dwumasztowce (2 pola), trzy trójmasztowce (3 pola) i jeden czteromasztowiec (4 pola), które są oznaczone na planszy znakiem `'x'`. Program wyświetla finalną planszę na ekranie.

Zasady rozmieszczania statków:
1. Pola statku muszą być sąsiadujące w linii prostej (pionowo lub poziomo).
2. Statki nie mogą stykać się ze sobą, ani bokami, ani wierzchołkami.

## Struktura programu
Program składa się z kilku funkcji odpowiedzialnych za inicjalizację planszy, losowe rozmieszczanie statków o różnych długościach oraz wyświetlenie planszy.

## Definicje i funkcje

### Makrodefinicja
- `#define SIZE 10` - Makro definiujące rozmiar planszy 10x10.

### Funkcje
1. #### void initializeBoard(char board[SIZE][SIZE])
   - **Opis**: Inicjuje planszę, ustawiając wszystkie pola na pusty znak `'.'`, co oznacza, że dane pole jest wolne.
   - **Parametry**: `char board[SIZE][SIZE]`: Dwuwymiarowa tablica reprezentująca planszę.
   - **Zwracana wartość**: Brak.

2. #### void printBoard(char board[SIZE][SIZE])
   - **Opis**: Wyświetla aktualny stan planszy w konsoli.
   - **Parametry**: `char board[SIZE][SIZE]` - Dwuwymiarowa tablica reprezentująca planszę.
   - **Zwracana wartość**: Brak.
    
3. #### int isPositionFree(char board[SIZE][SIZE], int x, int y)
   - **Opis**: Sprawdza, czy pozycja `(x, y)` na planszy jest wolna i czy spełnia zasady sąsiedztwa z innymi statkami.
   - **Parametry**:
     - `char board[SIZE][SIZE]` - Dwuwymiarowa tablica reprezentująca planszę.
     - `int x, int y` - Współrzędne punktu na planszy do sprawdzenia.
   - **Zwracana wartość**: `1` (true) - jeśli pozycja jest wolna, `0` (false) - jeśli pozycja jest zajęta lub narusza zasady.
  
4. #### void placeSingleMastShips(char board[SIZE][SIZE])
   - **Opis**: Losowo umieszcza cztery jednomasztowce na planszy.
   - **Parametry**: `char board[SIZE][SIZE]` - Dwuwymiarowa tablica reprezentująca planszę.
   - **Zwracana wartość**: Brak.
   - **Działanie**: Dla każdego jednomasztowca losuje współrzędne i sprawdza, czy pole jest wolne, zanim ustawi na nim znak `'x'`.
     
5. #### void placeTwoMastShips(char board[SIZE][SIZE])
   - **Opis**: Losowo umieszcza trzy dwumasztowce na planszy, z zachowaniem pionowej lub poziomej orientacji.
   - **Parametry**: `char board[SIZE][SIZE]` - Dwuwymiarowa tablica reprezentująca planszę.
   - **Zwracana wartość**: Brak.
   - **Działanie**: Dla każdego dwumasztowca generuje współrzędne i orientację. Sprawdza, czy oba pola statku są wolne, zanim ustawi na nich znak `'x'`.
     
6. #### void placeThreeMastShips(char board[SIZE][SIZE])
   - **Opis**: Losowo umieszcza trzy trójmasztowce na planszy, z zachowaniem pionowej lub poziomej orientacji.
   - **Parametry**: `char board[SIZE][SIZE]` - Dwuwymiarowa tablica reprezentująca planszę.
   - **Zwracana wartość**: Brak.
   - **Działanie**: Dla każdego trójmasztowca generuje współrzędne i orientację. Sprawdza, czy wszystkie trzy pola są wolne, zanim ustawi na nich znak `'x'`.
     
7. #### void placeFourMastShip(char board[SIZE][SIZE])
   - **Opis**: Losowo umieszcza jeden czteromasztowiec na planszy, z zachowaniem pionowej lub poziomej orientacji.
   - **Parametry**: `char board[SIZE][SIZE]` - Dwuwymiarowa tablica reprezentująca planszę.
   - **Zwracana wartość**: Brak.
   - **Działanie**: Generuje współrzędne i orientację. Sprawdza, czy wszystkie cztery pola są wolne, zanim ustawi na nich znak `'x'`.
     
8. #### int main()
   - **Opis**: Funkcja główna programu, która wywołuje wszystkie potrzebne funkcje w odpowiedniej kolejności.
   - **Działanie**:
     - Inicjuje planszę.
     - Ustawia kolejno jednomasztowce, dwumasztowce, trójmasztowce i czteromasztowiec.
     - Wyświetla planszę na ekranie.
   - **Zwracana wartość**: `0` - Sukces.

## Przykład działania
```bash
. x . . . . . x . .
. . . . . . . x . .
. x . . . . . . . .
. . . . . x x x . .
. . . . . . . . . x
. . . . x . . . . .
. . . . x . x x x .
. x x . . . . . . .
. . . . . . . . . .
x . x x x x . x x x
```

- `'x'` - Pole zajęte przez statek.
- `.` - Puste pole.

## Uwagi
1. Program losowo umieszcza statki na planszy. W wyniku tego każde uruchomienie programu może wygenerować inne rozmieszczenia.
2. Funkcja `isPositionFree` sprawdza sąsiadujące pola, co zapewnia, że statki nie stykają się ze sobą.
3. W przypadku dodawania nowych typów statków do gry lub zmian w rozmiarze planszy konieczne będzie zmodyfikowanie kodu każdej z funkcji `place...Ship`.
