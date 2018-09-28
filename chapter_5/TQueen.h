//
// Created by simplehe on 2018/9/29.
//

#ifndef CHAPTER_5_TQUEEN_H
#define CHAPTER_5_TQUEEN_H


#include <MacTypes.h>
#include "TPiece.h"
#include "TRook.h"

class TQueen : public TPiece {
public:
    TQueen(Point startAt, EColor color);

    TQueen(const TQueen &copy);

    TQueen &operator=(const TQueen &assign);

    ~TQueen();

    virtual Point GetCurrentLocation() const;

    virtual EMoveType MoveTo(Square toWhere, const TPiece *const chessBoard[8][8]);

    virtual Point SetCurrentLocation(Point newLocation);

private:
    Point   _current;
    TRook   _rookProxy;
    TBishop _bishopProxy
};

extern Point Board[64];

#endif //CHAPTER_5_TQUEEN_H
