//
// Created by simplehe on 2018/9/28.
//

#ifndef CHAPTER_5_TPIECE_H
#define CHAPTER_5_TPIECE_H

typedef unsigned short Square;
enum EColor {
    eBlack, eWhite
};

enum EIdentity {
    eKing, eQueen, eRook, eBishop, eKnight, ePawn
};

enum EMoveType {
    eCheck, eValid, eCastle, eInvalid
};

struct Point {
    short row;
    short column;
};

class TPiece {
public:
    TPiece(EIdentity id, EColor pieceColor);

    TPiece(const TPiece &copy);

    TPiece &operator=(const TPiece &assign);

    virtual ~TPiece();

    virtual EMoveType MoveTo(Square toWhere, const TPiece *const chessBoard[8][8]) = 0;

    EIdentity GetIdentity() const;

    EColor GetColor() const;

    virtual Point GetCurrentLocation() const = 0;

    virtual Point SetCurrentLocation(Point newLocation) = 0;

private:
    EIdentity _identity;
    EColor    _colorOfPiece;
};

#endif //CHAPTER_5_TPIECE_H
