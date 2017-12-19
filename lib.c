#include <stdio.h>
#include <ctype.h>
#include "lib.h"

void clear(int lines)
{
    int x;

    for (x = 0; x < lines; x++)
    {
        printf("\n");
    }
}

int coordsToInt(char coords)
{
    switch (coords)
    {
        case 'a':
            return 1;
        case 'b':
            return 2;
        case 'c':
            return 3;
        case 'd':
            return 4;
        case 'e':
            return 5;
        case 'f':
            return 6;
        case 'g':
            return 7;
        case 'h':
            return 8;
        default:
            return -1;
    }
}

char intToLetter(int pieceInt)
{
    if (pieceInt < 0)
    {
        pieceInt *= -1;
    }

    switch(pieceInt)
    {
        case 0:
            return '.';
        case 1:
            return 'k';
        case 2:
            return 'q';
        case 3:
            return 'r';
        case 4:
            return 'b';
        case 5:
            return 'n';
        case 6:
            return 'p';
        default:
            return 'X';
    }

}

void initBoard(int (*pieces)[][BOARD_SIZE])
{
    (*pieces)[8][1] = +ROOK;
    (*pieces)[8][2] = +KNIGHT;
    (*pieces)[8][3] = +BISHOP;
    (*pieces)[8][4] = +QUEEN;
    (*pieces)[8][5] = +KING;
    (*pieces)[8][6] = +BISHOP;
    (*pieces)[8][7] = +KNIGHT;
    (*pieces)[8][8] = +ROOK;

    (*pieces)[1][1] = -ROOK;
    (*pieces)[1][2] = -KNIGHT;
    (*pieces)[1][3] = -BISHOP;
    (*pieces)[1][4] = -QUEEN;
    (*pieces)[1][5] = -KING;
    (*pieces)[1][6] = -BISHOP;
    (*pieces)[1][7] = -KNIGHT;
    (*pieces)[1][8] = -ROOK;

    (*pieces)[7][1] = +PAWN;
    (*pieces)[7][2] = +PAWN;
    (*pieces)[7][3] = +PAWN;
    (*pieces)[7][4] = +PAWN;
    (*pieces)[7][5] = +PAWN;
    (*pieces)[7][6] = +PAWN;
    (*pieces)[7][7] = +PAWN;
    (*pieces)[7][8] = +PAWN;

    (*pieces)[2][1] = -PAWN;
    (*pieces)[2][2] = -PAWN;
    (*pieces)[2][3] = -PAWN;
    (*pieces)[2][4] = -PAWN;
    (*pieces)[2][5] = -PAWN;
    (*pieces)[2][6] = -PAWN;
    (*pieces)[2][7] = -PAWN;
    (*pieces)[2][8] = -PAWN;
}

int checkForKings(int pieces[][BOARD_SIZE])
{
    int kingCount = 0;
    int i, j;

    for(i=0; i<=8;i++)
    {
        for (j=0;j<=8;j++)
        {
            if(pieces[i][j]==1 || pieces[i][j]==-1)
            {
                kingCount++;
            }
        }
    }

    if(kingCount==2)
    {
        // continue playing
        return 0;
    }
    else
    {
        // game over
        return 1;
    }
}

int checkMove(int pieces[][BOARD_SIZE], int pieceToMove, int pieceNewPos, int whiteBlack)
{
    int valuePiece;
    int coordLetter, coordNumber;
    int newCoordLetter,newCoordNumber;
    int pieceToEat;
    int eating = 0;

    // get piece to move
    coordNumber = pieceToMove%10;
    coordLetter = (pieceToMove-coordNumber)/10;

    // what piece is it
    valuePiece = pieces[coordNumber][coordLetter];

    // new place for piece
    newCoordNumber = pieceNewPos%10;
    newCoordLetter = (pieceNewPos-newCoordNumber)/10;

    // something in new place?
    pieceToEat = pieces[newCoordNumber][newCoordLetter];

    if (pieceToEat != 0)
    {
        eating = 1;
    }

    if (whiteBlack == 0 && valuePiece < 0)
    {
        printf("\nThat's a white piece\n");
        return 1;
    }
    if (whiteBlack == 1 && valuePiece > 0)
    {
        printf("\nThat's a black piece\n");
        return 1;
    }
    return 0;
}