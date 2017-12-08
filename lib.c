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