function standardChessPosition()
{
    define starting chess positions
    transfer position to board
}

function drawBoard()
{    
    if (player is in checkmate)
    {
        display end of game
    }
    else if (player is in check)
    {
        display check alert
    }
    else
    {
        draw board from positions matrix
    }
}

function getUserMove()
{
    pieceToMove = get input
    whereToMovePiece = get input

    if (move is correct)
    {
        transfer move to board
    }
    else
    {
        print wrong move message
        getUserMove()
    }
}

function main()
{
    standardChessPosition()

    while not in check mate
    {
        drawBoard()
        getUserMove()
    }
}