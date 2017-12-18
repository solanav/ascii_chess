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

        scanf("%c", &temp);

        printf("Move to >>> ");
        tempNextPosChar = getchar();
        scanf("%d", &tempNextPosInt);

        *whiteBlack = 1;

        scanf("%c", &temp);
    }

    *pieceToMove = coordsToInt(tempPosChar)*10 + tempPosInt;
    *pieceNewPos = coordsToInt(tempNextPosChar)*10 + tempNextPosInt;

    printf("\nDEBUG: GETUSERMOVE OK");

}

void drawBoard(int pieces[][BOARD_SIZE], int *lastMove, int whiteBlack)
{
    int x, y;

    printf("\nLast move: %d\n", *lastMove);
    printf("\n");
    printf("     0  1  2  3  4  5  6  7\n\n");

    for (x = 0; x < 8; x++)
    {
        printf(" %c  ", x+97);
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

    printf("\nDEBUG: DRAWBOARD OK");

}

int checkForKings(int pieces[][BOARD_SIZE])
{
  int i, j, oneCount;

  for(i=0; i<7;i++)
  {
    for (j=0;j<7;j++)
    {
      if(pieces[i][j]==1)
        oneCount++;
    }
  }
  if(oneCount==2)
    return 0;
  else
    return 1;
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
        movePiece(&pieceToMove, &pieceNewPos, &pieces);
        drawBoard(pieces, &pieceNewPos, whiteBlack);
        gameFinished=checkForKings(pieces);
    }
    printf("GAME OVER");

    return 0;
}
