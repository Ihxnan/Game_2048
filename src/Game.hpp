#ifndef GAME
#define GAME

#include "Board.hpp"

class Game
{
    Board &board;

  public:
    Game(Board &board);

    void play();
};

#endif
