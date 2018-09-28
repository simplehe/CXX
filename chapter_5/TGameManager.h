//
// Created by simplehe on 2018/9/29.
//

#ifndef CHAPTER_5_TGAMEMANAGER_H
#define CHAPTER_5_TGAMEMANAGER_H

#include <string>
#include "TPiece.h"

using std::string;

class TGameManager {
public:
    TGameManager(const char playerWhite[], const char playerBlack[]);

    TGameManager(const TGameManager &copy);

    TGameManager &operator=(const TGameManager &assign);

    ~TGameManager();

    void StartGame();

    const char *GetWinner() const;

private:
    string _name1;
    string _name2;
    int    _winner;
    EColor _currentPlayer;
    TPiece *_board[8][8];
    TPiece *_capturedW[15];
    TPiece *_capturedB[15];

};

#endif //CHAPTER_5_TGAMEMANAGER_H
