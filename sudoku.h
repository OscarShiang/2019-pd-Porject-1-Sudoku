#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>

class Sudoku {
  public:
    // constructor
    Sudoku();
    Sudoku(const std::vector <int> ipt);

    // set and print out functions
    void printBoard();
    void setBoard(const std::vector <int> ipt);
    void setElement(int index, int value);
    int getElement(int index);
    int getFirstZero(int pos);

    // transform operations
    void swapNum(int x, int y);
    void swapRow(int x, int y);
    void swapCol(int x, int y);
    void rotate(int x);
    void flip(int x); // 0 -> up-down flip; 1 -> left-right flip

    // solve methods
    bool isSafe(int index, int target);

    static const int sudoku_size = 81;

  private:
    std::vector <int> board;
};

#endif