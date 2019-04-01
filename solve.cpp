#include <iostream>
#include "sudoku.h"
using namespace std;

Sudoku sudoku;

int main (void) {
    int board[9][9];
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++)
            cin >> board[i][j];
    }
    sudoku.setBoard(board);
    sudoku.solve();
    cout << min(sudoku.solCnt, 2) << '\n';
    if (sudoku.solCnt == 1)
        sudoku.printAns();
    return 0;
}