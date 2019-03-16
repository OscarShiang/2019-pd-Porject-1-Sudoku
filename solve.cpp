#include <iostream>
#include <vector>
#include "sudoku.h"
using namespace std;

Sudoku sudoku;
int pos = 0;

bool solve() {
    int index = sudoku.getFirstZero(pos);
    if (index == -1) {
        return true;
    }
    for (int i = 1; i <= 9; i ++) {
        if (sudoku.isSafe(index, i)) {
            sudoku.setElement(index, i);
            pos = index;
            if (solve())
                return true;
            else
                sudoku.setElement(index, 0);
        }
    }
    return false;
}

int main (void) {
    // int seed[] = {0, 0, 0, 5, 0, 1, 0, 0, 3,
    //               6, 8, 0, 0, 0, 9, 5, 4, 0,
    //               5, 0, 0, 7, 0, 0, 0, 0, 2,
    //               7, 9, 8, 0, 0, 0, 0, 0, 0,
    //               0, 6, 0, 3, 0, 8, 0, 9, 0,
    //               0, 0, 0, 0, 0, 0, 8, 6, 5,
    //               3, 0, 0, 0, 0, 7, 0, 0, 6,
    //               0, 7, 2, 6, 0, 0, 0, 3, 9,
    //               9, 0, 0, 1, 0, 3, 0, 0, 0};
    // load the seed into sudoku object
    vector <int> board;
    board.assign(81, 0);
    for (int i = 0; i < sudoku.sudoku_size; i ++)
      cin >> board.at(i);
    sudoku.setBoard(board);

    sudoku.printBoard();
    solve();

    cout << "\n";
    sudoku.printBoard();

    return 0;
}