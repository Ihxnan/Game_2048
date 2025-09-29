#ifndef BOARD
#define BOARD
#include <limits.h>
#include <string>
#include <unistd.h>
#include <vector>


class Board
{
    std::vector<std::vector<int>> board;
    long long score;
    long long top;
    std::string exePath;
    std::string exeDir;
    std::string data;

  public:
    Board();

    void printBoard();

    bool check();

    void move();

    void rand();

    void printScore();

    void read();

    void save();

    void test();
};

#endif // !BOARD
