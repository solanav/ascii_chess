#include <stdio.h>
#include <ctype.h>
#include "lib.h"

int coordsToInt(char coords)
{
    switch (coords)
    {
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        case 'f':
            return 5;
        case 'g':
            return 6;
        case 'h':
            return 7;
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

void initBoard(int pieces[][BOARD_SIZE])
{
    int x, y;
    int z = 1;

    for (x = 0; x <= 7; x += 7)
    {
        pieces[x][0] = z * ROOK;
        pieces[x][1] = z * KNIGHT;
        pieces[x][2] = z * BISHOP;
        pieces[x][3] = z * QUEEN;
        pieces[x][4] = z * KING;
        pieces[x][5] = z * BISHOP;
        pieces[x][6] = z * KNIGHT;
        pieces[x][7] = z * ROOK;

        z = -1;
    }

    z = 1;

    for (x = 1; x <= 6; x += 5)
    {
        for (y = 0; y <= 7; y++)
        {
            pieces[x][y] = z * PAWN;
        }
        z = -1;
    }


}
void movePiece(int *pieceToMove, int *pieceNewPosition, int (*pieces)[][BOARD_SIZE])
{
    int valuePiece;
    int coordLetter, coordNumber;
    int newCoordLetter,newCoordNumber;

    coordNumber=*pieceToMove%10;
    if(coordNumber>7)
    {
        printf("Wrong coordinates\n");
        //Insert something to make the user go back and change them coordinates
    }
    coordLetter=(*pieceToMove-coordNumber)/10;
    if(coordLetter>7)
    {
        printf("Wrong coordinates\n");
        //Idem
    }
    valuePiece=(*pieces)[coordLetter][coordNumber];

    newCoordNumber=*pieceNewPosition%10;
    if(newCoordNumber>7)
    {
        printf("Wrong coordinates\n");
        //Insert something to make the user go back and change them coordinates
    }
    newCoordLetter=(*pieceNewPosition-newCoordNumber)/10;//Maybe I don't need to subtract that since it's an int(?)
    if(newCoordLetter>7)
    {
        printf("Wrong coordinates\n");
        //Idem
    }

    (*pieces)[coordLetter][coordNumber]=0;
    (*pieces)[newCoordLetter][newCoordNumber]=valuePiece;

    printf("DEBUG: MOVEPIECE OK");
}
