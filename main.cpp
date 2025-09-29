#include "Board.hpp"
#include "Game.hpp"

int main()
{
    Board board;
    Game game(board);
    game.play();
    return 0;
}
