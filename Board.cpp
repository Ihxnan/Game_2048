#include "Board.hpp"
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <ios>
#include <iostream>
#include <rd>
#include <utility>
#include <vector>

Board::Board() : board(std::vector<std::vector<int>>(4, std::vector<int>(4))), score(0), top(0)
{
}

void print_num(const std::vector<int> &v)
{
    printf("%4d|%4d|%4d|%4d\n", v[0], v[1], v[2], v[3]);
}

void print__()
{
    printf("----|----|----|----\n");
}

void Board::printBoard()
{
    std::cout << "Score: " << score << " Top: " << top << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        print_num(board[i]);
        if (i < 3)
            print__();
    }
}

bool Board::check()
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (board[i][j] == 0 || (j + 1 < 4 && board[i][j] == board[i][j + 1]) ||
                (i + 1 < 4 && board[i][j] == board[i + 1][j]))
                return 1;
    return 0;
}

void move_merge_row(std::vector<int> &rows, long long &score)
{
    int s = 0;
    for (int j = 0; j < 4; ++j)
        if (rows[j])
            std::swap(rows[s++], rows[j]);
    for (int j = 0; j < 3; ++j)
        if (rows[j] == rows[j + 1])
            rows[j] += rows[j + 1], score += rows[j], rows[++j] = 0;
    s = 0;
    for (int j = 0; j < 4; ++j)
        if (rows[j])
            std::swap(rows[s++], rows[j]);
}

void moveUp(std::vector<std::vector<int>> &board, long long &score)
{
    std::vector<int> temp(4);
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
            temp[j] = board[j][i];
        move_merge_row(temp, score);
        for (int j = 0; j < 4; ++j)
            board[j][i] = temp[j];
    }
}

void moveDown(std::vector<std::vector<int>> &board, long long &score)
{
    std::vector<int> temp(4);
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
            temp[j] = board[j][i];
        reverse(temp.begin(), temp.end());
        move_merge_row(temp, score);
        reverse(temp.begin(), temp.end());
        for (int j = 0; j < 4; ++j)
            board[j][i] = temp[j];
    }
}

void moveLeft(std::vector<std::vector<int>> &board, long long &score)
{
    for (auto &p : board)
        move_merge_row(p, score);
}

void moveRight(std::vector<std::vector<int>> &board, long long &score)
{
    for (auto &p : board)
    {
        reverse(p.begin(), p.end());
        move_merge_row(p, score);
        reverse(p.begin(), p.end());
    }
}

void Board::move()
{
    auto temp = board;
again:
    std::cout << "Please enter a moving: [wasd | (q)uit]" << std::endl;
    char f;
    std::cin >> f;
    switch (f)
    {
    case 'w':
        moveUp(board, score);
        break;
    case 's':
        moveDown(board, score);
        break;
    case 'a':
        moveLeft(board, score);
        break;
    case 'd':
        moveRight(board, score);
        break;
    case 'q':
        std::cout << "The score is " << score << " !!!" << std::endl;
        save();
        exit(0);
        break;
    default:
        goto again;
    }
    if (temp == board)
    {
        std::cout << "Coun't move!!" << std::endl;
        goto again;
    }
}

void Board::rand()
{
    int x = rd() % 100 < 80 ? 2 : 4;
    std::vector<std::pair<int, int>> v;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (board[i][j] == 0)
                v.push_back({i, j});
    auto pos = v[rd() % v.size()];
    board[pos.first][pos.second] = x;
}

void Board::printScore()
{
    std::cout << "The score is " << score << " !!!" << std::endl;
}

void Board::read()
{
    std::fstream f1("../data.txt", std::ios::in);
    if (f1 >> top)
        flag = 1;
    f1.close();

    std::fstream f2("data.txt", std::ios::in);
    if (f2 >> top)
        flag = 2;
    f2.close();

    std::cout << "top: " << top << std::endl;
}

void Board::save()
{
    if (score > top)
    {
        if (flag == 1)
        {
            std::fstream f1("../data.txt", std::ios::out);
            f1 << score;
            f1.close();
        }
        if (flag == 2)
        {
            std::fstream f2("data.txt", std::ios::out);
            f2 << score;
            f2.close();
        }
    }
}
