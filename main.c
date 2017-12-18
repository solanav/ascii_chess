#include "stdio.h"
#include "ctype.h"
#include "lib.h"

void getUserMove(int *whiteBlack, int *pieceToMove, int *pieceNewPos)
{
    char temp;

    char tempPosChar;
    int tempPosInt;

    char tempNextPosChar;
    int tempNextPosInt;

    if (*whiteBlack == 0)
    {
        printf("\nWhite moves\nMove from >>> ");
        tempPosChar = getchar();
        scanf("%d", &tempPosInt);

        scanf("%c", &temp);

        printf("Move to >>> ");
        tempNextPosChar = getchar();
        scanf("%d", &tempNextPosInt);

        *whiteBlack = 1;

        scanf("%c", &temp);
    }
    else
    {
        printf("\nBlack moves\nMove from >>> ");
        tempPosChar = getchar();
        scanf("%d", &tempPosInt);

        printf("Move to >>> ");
        tempNextPosChar = getchar();
        scanf("%d", &tempNextPosInt);

        *whiteBlack = 0;

        scanf("%c", &temp);
        scanf("%c", &temp);
    }

    *pieceToMove = coordsToInt(tempPosChar)*10 + tempPosInt;
    *pieceNewPos = coordsToInt(tempNextPosChar)*10 + tempNextPosInt;

}

void drawBoard(int pieces[][BOARD_SIZE], int *lastMove, int whiteBlack)
{
    int x, y;

    printf("\nLast move: %d\n", *lastMove);
    printf("\n");
    printf("     a  b  c  d  e  f  g  h\n\n");

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
    drawBoard(pieces, &pieceNewPos, whiteBlack);

    while (gameFinished == 0)
    {
        getUserMove(&whiteBlack, &pieceToMove, &pieceNewPos);
        movepiece(&pieceToMove, &pieceNewPos, &pieces);
        drawBoard(pieces, &pieceNewPos, whiteBlack);
    }

    return 0;
}
