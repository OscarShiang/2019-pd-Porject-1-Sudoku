#include <iostream>
#include <vector>
#include "sudoku.h"
using namespace std;

int main(void) {
    Sudoku sudoku;
    vector <int> board;
    board.assign(sudoku.sudoku_size, 0);
    for (int i = 0; i < sudoku.sudoku_size; i ++)
        cin >> board.at(i);
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