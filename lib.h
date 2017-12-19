#ifndef LIB_H
#define LIB_H

#define BOARD_SIZE 9

#define NONE    0
#define KING    1
#define QUEEN   2
#define ROOK    3
#define BISHOP  4
#define KNIGHT  5
#define PAWN    6

void drawBoard(int pieces[][BOARD_SIZE], int *lastMove, int whiteBlack);
void initBoard(int (*pieces)[][BOARD_SIZE]);
int getUserMove(int pieces[][BOARD_SIZE], int *whiteBlack, int *pieceToMove, int *pieceNewPos);
void movePiece(int *pieceToMove, int *pieceNewPosition, int (*pieces)[][BOARD_SIZE]);

void clear(int lines);
int checkForKings();
char intToLetter(int pieceInt);
int coordsToInt(char coords);
int checkMove(int pieces[][BOARD_SIZE], int pieceToMove, int pieceNewPos, int whiteBlack);

#endif
