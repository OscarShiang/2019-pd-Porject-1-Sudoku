#include <iostream>
#include <cstdlib>
#include "sudoku.h"
using namespace std;

int main(void) {
    srand(time(NULL));
    int seed[3][9][9] = {{
            {0, 0, 0, 5, 0, 1, 0, 0, 3},
            {6, 8, 0, 0, 0, 9, 5, 4, 0},
            {5, 0, 0, 7, 0, 0, 0, 0, 2},
            {7, 9, 8, 0, 0, 0, 0, 0, 0},
            {0, 6, 0, 3, 0, 8, 0, 9, 0},
            {0, 0, 0, 0, 0, 0, 8, 6, 5},
            {3, 0, 0, 0, 0, 7, 0, 0, 6},
            {0, 7, 2, 6, 0, 0, 0, 3, 9},
            {9, 0, 0, 1, 0, 3, 0, 0, 0}
        },

        {
            {6, 0, 0, 7, 0, 0, 0, 0, 1},
            {9, 1, 0, 0, 0, 6, 2, 7, 0},
            {0, 0, 0, 1, 0, 3, 0, 0, 9},
            {0, 0, 0, 0, 0, 0, 8, 9, 7},
            {0, 9, 0, 8, 0, 1, 0, 6, 0},
            {5, 6, 8, 0, 0, 0, 0, 0, 0},
            {1, 0, 0, 3, 0, 5, 0, 0, 0},
            {0, 4, 5, 9, 0, 0, 0, 8, 6},
            {2, 0, 0, 0, 0, 7, 0, 0, 5}
        },

        {
            {3, 0, 2, 0, 0, 5, 6, 9, 0},
            {0, 4, 0, 0, 9, 6, 0, 3, 0},
            {0, 5, 0, 0, 0, 8, 0, 0, 0},
            {1, 9, 0, 0, 8, 0, 7, 0, 3},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {5, 0, 7, 0, 3, 0, 0, 6, 1},
            {0, 0, 0, 8, 0, 0, 0, 2, 0},
            {0, 8, 0, 9, 6, 0, 0, 7, 0},
            {0, 6, 5, 7, 0, 0, 3, 0, 9}
        }
    };

    // load initial board from seed
    int index = rand() % 3;
    Sudoku sudoku(seed[index]);

    // transform the board randomly
    int times = rand() % 5 + 1;
    while (times --) {
        int command = rand() % 5 + 1;
        if (command == 1) {
            int x = rand() % 9 + 1, y = rand() % 9 + 1;
            while (x == y)
                y = rand() % 9 + 1;
            sudoku.swapNum(x, y);
        } else if (command == 2) {
            int x = rand() % 3, y = rand() % 3;
            while (x == y)
                y = rand() % 3;
            sudoku.swapRow(x, y);
        } else if (command == 3) {
            int x = rand() % 3, y = rand() % 3;
            while (x == y)
                y = rand() % 3;
            sudoku.swapCol(x, y);
        } else if (command == 4) {
            int x = rand() % 100 + 1;
            sudoku.rotate(x);
        } else if (command == 5) {
            int x = rand() % 2;
            sudoku.flip(x);
        }
    }
    sudoku.printBoard();
    return 0;
}