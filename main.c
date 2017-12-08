#include "stdio.h"
#include "ctype.h"
#include "lib.h"

void getUserMove(int *whiteBlack, int *pieceToMove, int *pieceNewPos)
{
    char tempPosChar;
    int tempPosInt;

    if (*whiteBlack == 0)
    {
        printf("White moves\nMove from >>> ");
        tempPosChar = getchar();
        scanf("%d", &tempPosInt);
        
        printf("Move to >>> ");
        scanf("%d", pieceNewPos);

        *whiteBlack++;
    }
    else
    {
        printf("Black moves\n>>> ");

        *whiteBlack--;
    }

}

void drawBoard(int pieces[][BOARD_SIZE], int lastMove, int whiteBlack)
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
    int gameFinished = 0;
    int whiteBlack = 0;
    int pieceToMove;
    int pieceNewPos;

    initBoard(pieces);

    while (gameFinished == 0)
    {
        getUserMove(&whiteBlack, &pieceToMove, &pieceNewPos);
        drawBoard(pieces, 45, whiteBlack);
    }

    return 0;
}