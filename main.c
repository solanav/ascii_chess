#include "stdio.h"
#include "ctype.h"
#include "lib.h"

void movePiece(int *pieceToMove, int *pieceNewPos, int (*pieces)[][BOARD_SIZE])
{
    int valuePiece;
    int coordLetter, coordNumber;
    int newCoordLetter,newCoordNumber;

    // get piece to move
    coordNumber = *pieceToMove%10;
    coordLetter = (*pieceToMove-coordNumber)/10;

    // what piece is it
    valuePiece = (*pieces)[coordNumber][coordLetter];

    // new place for piece
    newCoordNumber = *pieceNewPos%10;
    newCoordLetter = (*pieceNewPos-newCoordNumber)/10;

    // move piece
    (*pieces)[coordNumber][coordLetter]=0;
    (*pieces)[newCoordNumber][newCoordLetter]=valuePiece;
}

int getUserMove(int pieces[][BOARD_SIZE], int *whiteBlack, int *pieceToMove, int *pieceNewPos)
{
    char temp;

    char tempPosChar;
    int tempPosInt;

    char tempNextPosChar;
    int tempNextPosInt;

    int moveCorrect = 1;

    if (*whiteBlack == 0)
    {
        printf("\nMove from >>> ");
        tempPosChar = getchar();
        scanf("%d", &tempPosInt);

        scanf("%c", &temp);

        printf("Move to >>> ");
        tempNextPosChar = getchar();
        scanf("%d", &tempNextPosInt);

        scanf("%c", &temp);
    }
    else
    {
        printf("\nMove from >>> ");
        tempPosChar = getchar();
        scanf("%d", &tempPosInt);

        scanf("%c", &temp);

        printf("Move to >>> ");
        tempNextPosChar = getchar();
        scanf("%d", &tempNextPosInt);

        scanf("%c", &temp);
    }

    int tempPieceToMove = coordsToInt(tempPosChar)*10 + tempPosInt;
    int tempPieceNewPos = coordsToInt(tempNextPosChar)*10 + tempNextPosInt;

    moveCorrect = checkMove(pieces, tempPieceToMove, tempPieceNewPos, *whiteBlack);

    if (moveCorrect == 0)
    {
        if (*whiteBlack == 0)
        {
            *whiteBlack = 1;
        }
        else
        {
            *whiteBlack = 0;
        }

        *pieceToMove = coordsToInt(tempPosChar)*10 + tempPosInt;
        *pieceNewPos = coordsToInt(tempNextPosChar)*10 + tempNextPosInt;

        return 0;
    }
    else
    {
        return 1;
    }
    
}

void drawBoard(int pieces[][BOARD_SIZE], int *lastMove, int whiteBlack)
{
    int x, y;

    int coordNumber = *lastMove%10;
    int coordLetter = (*lastMove-coordNumber)/10;

    if (whiteBlack == 0)
    {
        printf("White moves");
    }
    else 
    {
        printf("Black moves");
    }
    
    printf("\nLast move: %c%d\n\n", coordLetter+96, coordNumber);
    printf("\n");
    printf("     a  b  c  d  e  f  g  h\n\n");

    for (x = 8; x >= 1; x--)
    {
        printf(" %d  ", x);
        for (y = 1; y <= 8; y++)
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
    int pieceToMove = 0;
    int pieceNewPos = 0;
    int moveCorrect = 1;

    initBoard(&pieces);

    while (gameFinished == 0)
    {
        moveCorrect = 0;

        clear(75);
        drawBoard(pieces, &pieceNewPos, whiteBlack);

        do
        {
            moveCorrect = getUserMove(pieces, &whiteBlack, &pieceToMove, &pieceNewPos);
        } while (moveCorrect == 1);


        movePiece(&pieceToMove, &pieceNewPos, &pieces);
        gameFinished = checkForKings(pieces);
    }

    clear(75);
    drawBoard(pieces, &pieceNewPos, whiteBlack);

    printf("GAME OVER\n");
    if (whiteBlack == 0)
    {
        printf("Blacks win\n");
    }    
    else
    {
        printf("Whites win\n\n");
    }

    return 0;
}
