#include <iostream>
#include "sudoku.h"
using namespace std;

int main(void) {
    Sudoku sudoku;
    int board[9][9];
    for (int i = 0; i < 9; i ++) {
        for (int j = 0 ; j < 9; j ++)
            cin >> board[i][j];
    }
    sudoku.setBoard(board);
    int command = -1, opt, opt2;
    while (true) {
        cin >> command;
        if (!command)
            break;
        else if (command == 1) {
            cin >> opt >> opt2;
            sudoku.swapNum(opt, opt2);
        } else if (command == 2) {
            cin >> opt >> opt2;
            sudoku.swapRow(opt, opt2);
        } else if (command == 3) {
            cin >> opt >> opt2;
            sudoku.swapCol(opt, opt2);
        } else if (command == 4) {
            cin >> opt;
            sudoku.rotate(opt);
        } else if (command == 5) {
            cin >> opt;
            sudoku.flip(opt);
        } else
            throw "command not found\n";
    }
    sudoku.printBoard();
    return 0;
}