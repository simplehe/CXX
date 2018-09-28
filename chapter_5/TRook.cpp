//
// Created by simplehe on 2018/9/29.
//

#include "TRook.h"

short inline min(short a, short b) { return a > b ? b : a; }

short inline max(short a, short b) { return a > b ? a : b; }

TRook::TRook(Point startAt, EColor color) : TPiece(eRook, color), _current(startAt) {
}

TRook::~TRook() {

}

Point TRook::GetCurrentLocation() const {
    return _current;
}

EMoveType TRook::MoveTo(Square toWhere, const TPiece *const (*chessBoard)[8]) {
    EMoveType move;
    move = TPiece::MoveTo(toWhere, chessBoard);
    if (move == eInvalid || move == eCheck) {
        return move;
    }

    Point to = Board[toWhere];

    if (to.row == _current.row && to.column == _current.column)
        return eInvalid;

    if (to.row == _current.row) {
        short start = min(to.column, _current.column);
        short end   = max(to.column, _current.column);
        for (; start < end; start++) {
            if (chessBoard[to.row][start] != 0) {
                return eInvalid;
            }
        }
    } else if (to.column == _current.column) {
        short start = min(to.row, _current.row);
        short end   = max(to.row, _current.row);
        for (; start < end; start++) {
            if (chessBoard[start][to.column] != 0) {
                return eInvalid;
            }
        }
    }
    _current = to;
    return eValid;
}

Point TRook::SetCurrentLocation(Point newLocation) {
    Point oldLocation = _current;
    _current = newLocation;
    return oldLocation;
}
