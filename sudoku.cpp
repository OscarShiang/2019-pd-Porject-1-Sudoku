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

void Sudoku::printAns() {
    for (int i = 0; i < sudoku_size; i ++) {
        if (i % 9 == 0)
            cout << ans.at(i);
        else
            cout << ' ' << ans.at(i);
        if (i % 9 == 8)
            cout << '\n';
    }
}

void Sudoku::setBoard(const vector <int> ipt) {
    board.assign(ipt.begin(), ipt.end());
}

void Sudoku::setElement(int index, int value) {
    board.at(index) = value;
}

int Sudoku::getElement(int index) {
    return board.at(index);
}

int Sudoku::getFirstZero(int pos) {
    for (int i = pos; i < sudoku_size; i ++) {
        if (board.at(i) == 0)
            return i;
    }
    return -1;
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
            } else
                i ++;
        }
    } else {
        for (int i = 0, j = 72; i < 36; i ++) {
            swap(board.at(i), board.at(j + i % 9));
            if (i % 9 == 8)
                j -= 9;
        }
    }
}

bool Sudoku::isSafe(int index, int target) {
    // check for row
    for (int i = index - index % 9; i <= index - index % 9 + 8; i ++) {
        if (i == index)
            continue;
        if (board.at(i) == target)
            return false;
    }

    // check for col
    for (int i = index % 9; i <= (index % 9) + 72; i += 9) {
        if (i == index)
            continue;
        if (board.at(i) == target)
            return false;
    }

    // check for unity
    int center;
    if (index % 9 <= 2 && index % 9 >= 0)
        center = 1;
    else if (index % 9 <= 5 && index % 9 >= 3)
        center = 4;
    else if (index % 9 <= 8 && index % 9 >= 6)
        center = 7;

    if (index / 9 <= 2 && index / 9 >= 0)
        center += 9 * 1;
    else if (index / 9 <= 5 && index / 9 >= 3)
        center += 9 * 4;
    else if (index / 9 <= 8 && index / 9 >= 6)
        center += 9 * 7;

    for (int i = -9; i <= 9; i += 9) {
        for (int j = -1; j <= 1; j ++) {
            if (center + i + j == index)
                continue;
            if (board.at(center + i + j) == target)
                return false;
        }
    }
    return true;
}

void Sudoku::solved() {
    ans.assign(board.begin(), board.end());
}
