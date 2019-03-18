#include <iostream>
#include <vector>
#include "sudoku.h"
using namespace std;

Sudoku sudoku;
int pos = 0, cnt = 0;

bool solve() {
    int index = sudoku.getFirstZero(pos);
    if (index == -1) {
        cnt ++;
        sudoku.solved();
        return true;
    }
    for (int i = 1; i <= 9; i ++) {
        if (sudoku.isSafe(index, i)) {
            sudoku.setElement(index, i);
            pos = index;
            solve();
            sudoku.setElement(index, 0);
            pos = index;
        }
    }
    return false;
}

int main (void) {
    vector <int> board;
    board.assign(81, 0);
    for (int i = 0; i < sudoku.sudoku_size; i ++)
        cin >> board.at(i);
    sudoku.setBoard(board);
    solve();

    cout <<  min(cnt, 2) << '\n';
    if (cnt == 1)
        sudoku.printAns();

    return 0;
}