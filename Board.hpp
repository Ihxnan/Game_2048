#ifndef BOARD
#define BOARD
#include <vector>

class Board
{
    std::vector<std::vector<int>> board;
    long long score;
    long long top;
    int flag = 0;

  public:
    Board();

    void printBoard();

    bool check();

    void move();

    void rand();

    void printScore();

    void read();

    void save();
};

#endif // !BOARD
