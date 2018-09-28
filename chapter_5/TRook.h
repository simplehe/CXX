//
// Created by simplehe on 2018/9/29.
//

#ifndef CHAPTER_5_TROOK_H
#define CHAPTER_5_TROOK_H

#include "TPiece.h"

class TRook : public TPiece {
public:
    TRook(Point startAt, EColor color);

    ~TRook();

    virtual Point GetCurrentLocation() const;

    virtual EMoveType MoveTo(Square toWhere, const TPiece *const chessBoard[8][8]);

    virtual Point SetCurrentLocation(Point newLocation);

private:
    Point _current;
    bool  _notMoved;
};

Point Board[64] = {
        {1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7},{1,8},
        {2,1},{2,2},{2,3},{2,4},{2,5},{2,6},{2,7},{2,8},
        {3,1},{3,2},{3,3},{3,4},{3,5},{3,6},{3,7},{3,8},
        {4,1},{4,2},{4,3},{4,4},{4,5},{4,6},{4,7},{4,8},
        {5,1},{5,2},{5,3},{5,4},{5,5},{5,6},{5,7},{5,8},
        {6,1},{6,2},{6,3},{6,4},{6,5},{6,6},{6,7},{6,8},
        {7,1},{7,2},{7,3},{7,4},{7,5},{7,6},{7,7},{7,8},
        {8,1},{8,2},{8,3},{8,4},{8,5},{8,6},{8,7},{8,8}
};

#endif //CHAPTER_5_TROOK_H
