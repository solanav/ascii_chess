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

    // coords inside bounds?
    if (coordNumber < 1 || coordNumber > 8)
    {
        if (coordLetter < 1 || coordLetter > 8)
        {
            printf("Coordinates out of bounds");
            return 1;
        }
    }
    else if (newCoordNumber < 1 || newCoordNumber > 8)
    {
        if (newCoordLetter < 1 || newCoordLetter > 8)
        {
            printf("Coordinates out of bounds");
            return 1;
        }
    }

    // eating?
    pieceToEat = pieces[newCoordNumber][newCoordLetter];

    if (pieceToEat != 0)
    {
        eating = 1;
    }

    // eating yourself?
    if (eating)
    {
        if (whiteBlack == 0 && pieceToEat < 0)
        {
            printf("Can't eat yourself\n");
            return 1;
        }
        else if (whiteBlack == 1 && pieceToEat > 0)
        {
            printf("Can't eat yourself\n");
            return 1;
        }
    }

    // are you moving your own pieces?
    if (whiteBlack == 1 && valuePiece < 0)
    {
        printf("\nThat's a white piece\n");
        return 1;
    }
    if (whiteBlack == 0 && valuePiece > 0)
    {
        printf("\nThat's a black piece\n");
        return 1;
    }

    // check piece specific movement
    if (valuePiece < 0)
    {
        valuePiece *= -1;
    }

    int numberDif = newCoordNumber - coordNumber;
    int letterDif = newCoordLetter - coordLetter;

    switch (valuePiece)
    {
        case 0: // nothing
            printf("\nThere's nothing there\n");
            return 1;
        case 1: // king
            if ((numberDif > 1 || numberDif < -1) || (letterDif > 1 || letterDif < -1))
            {
                printf("King moves 1 step per turn");
                return 1;
            }
            
            return 0;
        case 2: // queen
            if (letterDif != 0) // there is horizontal movement
            {
                if (numberDif != 0) // there is diagonal movement
                {
                    if (letterDif != numberDif && letterDif != -numberDif) // the diagonal is not ok
                    {
                        printf("Can't move like that the queen");
                        return 1;
                    }
                }
                
            }
            return 0;
        case 3: // rook
            if (letterDif != 0) // there is horizontal movement
            {
                if (numberDif != 0) // there is vertical movement
                {
                    printf("Rooks don't move diagonally");
                    return 1;
                }
            }

            return 0;
        case 4: // bishop
            printf("%d %d", numberDif, letterDif);
            if (numberDif != letterDif && numberDif != -letterDif)
            {
                printf("Bishops only move diagonally");
                return 1;
            }
            return 0;
        case 5: // knight
            return 0;
        case 6: // pawn
            if (!eating)
            {
                if (whiteBlack == 0)
                {
                    if (numberDif != 2 && numberDif != 1)
                    {
                        printf("Pawns move either 1 or 2 positions ahead\n");
                        return 1;
                    }
                    else
                    {
                        if (letterDif != 0)
                        {
                            printf("Diagonal movement with pawn not allowed\n");
                            return 1;
                        }
                        else if (numberDif == 2)
                        {
                            if (coordNumber != 2)
                            {
                                printf("Can't move 2 positions ahead from there\n");
                                return 1;
                            }
                        }
                    }
                }
                else
                {
                    if (numberDif != -2 && numberDif != -1)
                    {
                        printf("Pawns move either 1 or 2 positions ahead\n");
                        return 1;
                    }
                    else
                    {
                        if (letterDif != 0)
                        {
                            printf("Diagonal movement with pawn not allowed\n");
                            return 1;
                        }
                        else if (numberDif == -2)
                        {
                            if (coordNumber != 7)
                            {
                                printf("Can't move 2 positions ahead from there\n");
                                return 1;
                            }
                        }
                    }
                }
            }
            else
            {
                if (letterDif != 1 && letterDif != 0)
                {
                    printf("Pawns have to eat diagonally");
                    return 1;
                }
                if (whiteBlack == 0)
                {
                    if (numberDif != 1)
                    {
                        printf("Can't eat like that\n");
                        return 1;
                    }
                }
                else
                {
                    if (numberDif != -1)
                    {
                        printf("Can't eat like that\n");
                        return 1;
                    }
                }
            }

            return 0;
        default:
            printf("Default");
    }
    
    return 0;
}