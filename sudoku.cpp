#include <iostream>
#include "sudoku.h"
using namespace std;

Sudoku::Sudoku() {
    board.assign(sudoku_size, 0);
}

Sudoku::Sudoku(const vector <int> ipt) {
    board.assign(ipt.begin(), ipt.end());
}

void Sudoku::printBoard() {
    for (int i = 0; i < sudoku_size; i ++) {
        if (i % 9 == 0)
            cout << board.at(i);
        else
            cout << ' ' << board.at(i);
        if (i % 9 == 8)
            cout << '\n';
    }
}

void Sudoku::setBoard(const vector <int> ipt) {
    board.assign(ipt.begin(), ipt.end());
}

void Sudoku::swapNum(int x, int y) {
    for (int i = 0; i < sudoku_size; i ++) {
        if (board.at(i) == x)
            board.at(i) = y;
        else if (board.at(i) == y) 
            board.at(i) = x;
    }
}

void Sudoku::swapRow(int x, int y) {
    for (int i = 0; i < 27; i ++)
        swap(board.at(i + 27 * x), board.at(i + 27 * y));
}

void Sudoku::swapCol(int x, int y) {
    int i = 0;
    while (i < 75) {
        swap(board.at(i + x * 3), board.at(i + y * 3));
        if (i % 9 == 2)
            i += 7;
        else
            i ++;
    }
}

void Sudoku::rotate(int x) {
    vector <int> tmp;
    x %= 4;
    while (x --) {
        tmp.assign(sudoku_size, 0);
        for (int i = 0, j = 72; i < sudoku_size; i ++) {
            tmp.at(i) = board.at(j - 9 * (i % 9));
            if (j - 9 * (i % 9) < 9)
                j ++;
        }
        setBoard(tmp);
    }
}

void Sudoku::flip(int x) {
    if (x) {
        int i = 0, j = 8;
        while (i < 76) {
            swap(board.at(i), board.at(j - i % 9));
            if (i % 9 == 3) {
                i += 6;
                j += 9;
            }
            else
                i ++;
        }
    }
    else {
        for (int i = 0, j = 72; i < 36; i ++) {
            swap(board.at(i), board.at(j + i % 9));
            if (i % 9 == 8)
                j -= 9;
        }
    }
}