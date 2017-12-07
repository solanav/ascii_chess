#include <stdio.h>
#include <ctype.h>

#define BOARD_SIZE 8

#define NONE    0
#define KING    1
#define QUEEN   2
#define ROOK    3
#define BISHOP  4
#define KNIGHT  5
#define PAWN    6

void drawBoard(int pieces[][BOARD_SIZE]);
void initBoard(int pieces[][BOARD_SIZE]);
int drawMove(int * whiteBlack);
char intToLetter(int pieceInt);

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

int drawMove(int * whiteBlack)
{
    if (*whiteBlack == 0)
    {
        printf("White moves\nPiece >>> ");
        scanf("%d")
        *whiteBlack++;
    }
    else
    {
        printf("Black moves\n>>> ");

        *whiteBlack--;
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

void drawBoard(int pieces[][BOARD_SIZE])
{
    int x, y;

    printf("\n");
    printf("     a  a  a  a  a  a  a  a\n\n");

    for (x = 0; x < 8; x++)
    {   
        printf(" %d  ", x+1);
        for (y = 0; y < 8; y++)
        {
            if (pieces[x][y] < 0)
            {
                printf(" %c ", toupper(intToLetter(pieces[x][y])));
            }
            else
            {
                printf(" %c ", intToLetter(pieces[x][y]));
            }
        }
        printf("\n");
    }
    printf("\n");

}

int main()
{
    int pieces[BOARD_SIZE][BOARD_SIZE] = {0};
    int gameNotFinished = 0;
    int whiteBlack = 0;
    int userMove;

    initBoard(pieces);

    while (gameNotFinished == 0)
    {
        userMove = drawMove(&whiteBlack);
    }

    return 0;
}