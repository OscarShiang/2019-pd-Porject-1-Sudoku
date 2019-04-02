#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>
using std::vector;

class Sudoku {
  public:
    // constructor
    Sudoku();
    Sudoku(const int ipt[][9]);

    // set and print out functions
    void printBoard();
    void setBoard(const int ipt[][9]);
    void printAns();
    // void setAns(const int ipt[][9]);

    // transform operations
    void swapNum(int x, int y);
    void swapRow(int x, int y);
    void swapCol(int x, int y);
    void rotate(int x);
    void flip(int x); // 0 -> up-down flip; 1 -> left-right flip

    // solve operations
    void solve(); // main entry
    void solve(int board[][9], int allowedValues[][9]);
    void bruteforce(int board[][9], int i, int j, int allowedValues[][9]);
    void check(int board[][9], int allowedValues[][9]);
    void check(int board[][9], int i, int j, int allowedValues[][9]);
    int fill(int board[][9], int allowedValues[][9]);
    int setValue(int board[][9], int i, int j, int value, int allowedValues[][9]);
    int getMin(int board[][9], int allowedValues[][9]);
    vector <int *> getEmpty(int board[][9]);
    bool checkLeft(int board[][9]);
    int countEmpty();

    int solCnt;
    int allowedValues[9][9];

  private:
    int board[9][9];
    int ans[9][9];
    vector<int *> candidate;
};

#endif