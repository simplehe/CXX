//
// Created by simplehe on 2018/9/28.
//

#include "TPiece.h"
#include "TRook.h"

EMoveType TPiece::MoveTo(Square toWhere, const TPiece *const (*chessBoard)[8]) {
    if (toWhere < 0 || toWhere > 63) {
        return eInvalid;
    }
    Point to = Board[toWhere];

    const TPiece *piece = chessBoard[to.row][to.column];
    if (piece == 0) return eValid;

    if (piece->GetColor() == this->GetColor() && piece->GetIdentity() != eKing){
        return  eInvalid;
    }
    else {
        //车王易位
    }
    if(piece->GetIdentity() == eKing){
        return eInvalid
    }
    return eValid;
}
