#include "Queen.h"
#define PieceType 'q'

#define CHECKMATE_MOVE 8
#define ILLEGAL_MOVE 6
#define VALID_MOVE 0

int Queen::move(Position dst, Manager board)
{
    int moveCode = checkMove(dst, board);
    if (moveCode == 0 || moveCode == 8)
    {
        Piece::_pos = dst;
    }
    return moveCode;
}

int Queen::checkMove(Position dst, const Manager& board) const
{
    int bMoveCode = Bishop::checkMove(dst, board);
    int rMoveCode = Rook::checkMove(dst, board);

    if (bMoveCode != VALID_MOVE || bMoveCode != CHECKMATE_MOVE && rMoveCode != VALID_MOVE || rMoveCode != CHECKMATE_MOVE) // if the move did not work
    {
        if (bMoveCode == ILLEGAL_MOVE && rMoveCode == ILLEGAL_MOVE) // checking if both moves are not possible with the piece
        {
            return ILLEGAL_MOVE;
        }
        else if (bMoveCode == ILLEGAL_MOVE) // checking if the move was done with the rook
        {
            return rMoveCode;
        }
        else if (rMoveCode == ILLEGAL_MOVE) // checking if the move was done with the bishop
        {
            return bMoveCode;
        }
    }
    else
    {
        if (bMoveCode == ILLEGAL_MOVE) // checking if the move was done with the rook
        {
            return rMoveCode;
        }
        else if (rMoveCode == ILLEGAL_MOVE) // checking if the move was done with the bishop
        {
            return bMoveCode;
        }
    }
}