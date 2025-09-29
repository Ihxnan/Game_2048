#include "Game.hpp"
#include <cstdlib>

Game::Game(Board &board) : board(board)
{
}

void Game::play()
{
    board.read();
    board.rand();
    board.rand();
    while (board.check())
    {
        system("clear");
        board.printBoard();
        board.move();
        board.rand();
    }
    system("clear");
    board.printBoard();
    board.printScore();
    board.save();
}
