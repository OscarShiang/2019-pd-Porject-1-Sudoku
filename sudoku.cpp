#include <iostream>
#include <cmath>
#include <cstring>
#include "sudoku.h"
using namespace std;

Sudoku::Sudoku() {
    solCnt = 0;
    memset(board, 0, sizeof(int) * 81);
    // for (int i = 0; i < 9; i ++) {
    //     for (int j = 0; j < 9; j ++)
    //         allowedValues[i][j] = 511;
    // }
    memset(allowedValues, -1, sizeof(int) * 81);
}

Sudoku::Sudoku(const int ipt[][9]) {
    solCnt = 0;
    setBoard(ipt);
    // for (int i = 0; i < 9; i ++) {
    //     for (int j = 0; j < 9; j ++)
    //         allowedValues[i][j] = 511;
    // }
    memset(allowedValues, -1, sizeof(int) * 81);
}

void Sudoku::printBoard() {
    for (int i = 0; i < 9; i ++) {
        cout << board[i][0];
        for (int j = 1; j < 9; j ++)
            cout << ' ' << board[i][j];
        cout << '\n';
    }
}

void Sudoku::setBoard(const int ipt[][9]) {
    // set the initial board
    // for (int i = 0; i < 9; i ++) {
    //     for (int j = 0; j < 9; j ++)
    //         board[i][j] = ipt[i][j];
    // }
    memcpy(board, ipt, sizeof(int) * 81);
}

void Sudoku::swapNum(int x, int y) {
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++) {
            if (board[i][j] == x)
                board[i][j] = y;
            else if (board[i][j] == y)
                board[i][j] = x;
        }
    }
}

void Sudoku::swapRow(int x, int y) {
    x *= 3;
    y *= 3;
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 9; j ++)
            swap(board[x + i][j], board[y + i][j]);
    }
}

void Sudoku::swapCol(int x, int y) {
    x *= 3;
    y *= 3;
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 9; j ++)
            swap(board[j][x + i], board[j][y + i]);
    }
}

void Sudoku::rotate(int x) {
    int tmp[9][9];
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++)
            tmp[i][j] = 0;
    }
    x %= 4;
    while (x --) {
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++)
                tmp[j][8 - i] = board[i][j];
        }
        setBoard(tmp);
    }
}

void Sudoku::flip(int x) {
    if (x) {
        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 9; j ++)
                swap(board[j][i], board[j][8 - i]);
        }
    } else {
        for (int i = 0; i < 4; i ++) {
            for (int j = 0; j < 9; j ++)
                swap(board[i][j], board[8 - i][j]);
        }
    }
}

void Sudoku::printAns() {
    for (int i = 0; i < 9; i ++) {
        cout << ans[i][0];
        for (int j = 1; j < 9; j ++)
            cout << ' ' << ans[i][j];
        cout << '\n';
    }
}

int countOnes(int value) {
    int cnt = 0;
    for (int i = 0; i < 9; i ++) {
        if (value & (1 << i))
            cnt ++;
    }
    return cnt;
}

void Sudoku::solve() {
    // main entry
    solve(board, allowedValues);
}

void Sudoku::solve(int board[][9], int allowedValues[][9]) {
    int left = 81;
    check(board, allowedValues);
    left -= fill(board, allowedValues);
    // left -= lema(board, allowedValues);
    if (left > 0) {
        int pos = getMin(board, allowedValues);
        bruteforce(board, pos / 9, pos % 9, allowedValues);
    }
}

void Sudoku::bruteforce(int board[][9], int i, int j, int allowedValues[][9]) {
    // cout << "attempt bruteforce\n";
    for (int x = 0; x < 9; x ++) {
        if (allowedValues[i][j] & (1 << x)) {
            int tmpBoard[9][9], tmpAllowed[9][9];
            // for (int a = 0; a < 9; a ++) {
            //     for (int b = 0; b < 9; b ++) {
            //         tmpBoard[a][b] = board[a][b];
            //         tmpAllowed[a][b] = allowedValues[a][b];
            //     }
            // }
            memcpy(tmpBoard, board, sizeof(tmpBoard));
            memcpy(tmpAllowed, allowedValues, sizeof(tmpAllowed));

            setValue(board, i, j, x + 1, allowedValues);

            int pos = getMin(board, allowedValues);
            if (pos != -1) {
                bruteforce(board, pos / 9, pos % 9, allowedValues);
            }

            if (countLeft(board) == 0) {
                solCnt ++;
                if (solCnt > 1)
                    return;
                memcpy(ans, board, sizeof(int) * 81);
            }
            // for (int a = 0; a < 9; a ++) {
            //     for (int b = 0; b < 9; b ++) {
            //         board[a][b] = tmpBoard[a][b];
            //         allowedValues[a][b] = tmpAllowed[a][b];
            //     }
            // }
            memcpy(board, tmpBoard, sizeof(tmpBoard));
            memcpy(allowedValues, tmpAllowed, sizeof(tmpAllowed));

            if (allowedValues[i][j] & (1 << x))
                allowedValues[i][j] ^= (1 << x);
        }
    }
}

void Sudoku::check(int board[][9], int allowedValues[][9]) {
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++) {
            if (board[i][j] > 0) {
                // check row
                for (int a = 0; a < 9; a ++) {
                    if (board[i][a] > 0)
                        continue;
                    if (allowedValues[i][a] & 1 << (board[i][j] - 1)) {
                        allowedValues[i][a] ^= 1 << (board[i][j] - 1);
                    }
                }

                // check col
                for (int b = 0; b < 9; b ++) {
                    if (board[b][j] > 0)
                        continue;
                    if (allowedValues[b][j] & 1 << (board[i][j] - 1)) {
                        allowedValues[b][j] ^= 1 << (board[i][j] - 1);
                    }
                }

                // check cell
                for (int a = i / 3 * 3; a < i / 3 * 3 + 3; a ++) {
                    for (int b = j / 3 * 3; b < j / 3 * 3 + 3; b ++) {
                        if (board[a][b] > 0)
                            continue;
                        if (allowedValues[a][b] & 1 << (board[i][j] - 1)) {
                            allowedValues[a][b] ^= 1 << (board[i][j] - 1);
                        }
                    }
                }
            }
        }
    }
}

void Sudoku::check(int board[][9], int i, int j, int allowedValues[][9]) {
    if (board[i][j] > 0) {
        // check row
        allowedValues[i][j] = 0;
        for (int a = 0; a < 9; a ++) {
            if (board[i][a] > 0)
                continue;
            if (allowedValues[i][a] & 1 << (board[i][j] - 1)) {
                allowedValues[i][a] ^= 1 << (board[i][j] - 1);
            }
        }

        // check col
        for (int b = 0; b < 9; b ++) {
            if (board[b][j] > 0)
                continue;
            if (allowedValues[b][j] & 1 << (board[i][j] - 1)) {
                allowedValues[b][j] ^= 1 << (board[i][j] - 1);
            }
        }

        // check cell
        for (int a = i / 3 * 3; a < i / 3 * 3 + 3; a ++) {
            for (int b = j / 3 * 3; b < j / 3 * 3 + 3; b ++) {
                if (board[a][b] > 0)
                    continue;
                if (allowedValues[a][b] & 1 << (board[i][j] - 1)) {
                    allowedValues[a][b] ^= 1 << (board[i][j] - 1);
                }
            }
        }
    }
}

int Sudoku::fill(int board[][9], int allowedValues[][9]) {
    int cnt = 0;
    int pos = getMin(board, allowedValues), prev;
    while (pos != -1) {
        prev = cnt;
        int i = pos / 9, j = pos % 9;
        if (board[i][j] == 0 && countOnes(allowedValues[i][j]) == 1) {
            cnt += setValue(board, i, j, log2(allowedValues[i][j]) + 1, allowedValues);
        }
        if (prev == cnt)
            break;
    }
    return cnt;
}

int Sudoku::getMin(int board[][9], int allowedValues[][9]) {
    int index = -1, mini = 10, cnt;
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++) {
            if (board[i][j] > 0)
                continue;
            if ((cnt = countOnes(allowedValues[i][j])) < mini) {
                index = i * 9 + j;
                mini = cnt;
            }
        }
    }
    return index;
}

int Sudoku::setValue(int board[][9], int i, int j, int value, int allowedValues[][9]) {
    // if (allowedValues[i][j] & (1 << (value - 1)) && board[i][j] == 0) {
    board[i][j] = value;
    check(board, i, j, allowedValues);
    // }
    return 1;
}

int Sudoku::countLeft(int board[][9]) {
    int cnt = 0;
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++) {
            if (board[i][j] == 0)
                cnt ++;
        }
    }
    return cnt;
}