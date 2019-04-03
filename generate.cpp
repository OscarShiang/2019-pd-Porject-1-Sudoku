#include <iostream>
#include <cstdlib>
#include "sudoku.h"
using namespace std;

int main(void) {
    srandom(time(NULL));
    int seed[4][9][9] = {{
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
            {0, 0, 0, 0, 0, 0, 2, 0, 0},
            {5, 9, 0, 0, 7, 0, 0, 0, 0}, 
            {1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 7, 3}, 
            {0, 4, 0, 8, 0, 2, 0, 0, 0}, 
            {0, 0, 0, 0, 0, 3, 0, 0, 0}, 
            {0, 0, 2, 0, 0, 0, 8, 0, 0},
            {6, 0, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 5, 0, 0, 9, 0}
        },

        {
            {0, 5, 0, 0, 0, 0, 0, 9, 0}, 
            {1, 0, 0, 0, 0, 6, 0, 0, 0}, 
            {0, 0, 0, 2, 0, 0, 0, 0, 8}, 
            {3, 0, 0, 0, 0, 0, 0, 0, 0}, 
            {2, 0, 8, 0, 4, 0, 0, 0, 0}, 
            {0, 0, 0, 0, 0, 0, 3, 7, 0}, 
            {0, 0, 0, 0, 0, 1, 0, 0, 0},
            {0, 7, 0, 0, 9, 5, 0, 0, 0}, 
            {0, 0, 0, 0, 0, 0, 0, 0, 2}
        }
    };

    // load initial board from seed
    int index = random() % 4;
    Sudoku sudoku(seed[index]);

    // transform the board randomly
    int times = random() % 5 + 1;
    while (times --) {
        int command = random() % 5 + 1;
        if (command == 1) {
            int x = random() % 9 + 1, y = random() % 9 + 1;
            while (x == y)
                y = random() % 9 + 1;
            sudoku.swapNum(x, y);
        } else if (command == 2) {
            int x = random() % 3, y = random() % 3;
            while (x == y)
                y = random() % 3;
            sudoku.swapRow(x, y);
        } else if (command == 3) {
            int x = random() % 3, y = random() % 3;
            while (x == y)
                y = random() % 3;
            sudoku.swapCol(x, y);
        } else if (command == 4) {
            int x = random() % 100 + 1;
            sudoku.rotate(x);
        } else if (command == 5) {
            int x = random() % 2;
            sudoku.flip(x);
        }
    }
    sudoku.printBoard();
    return 0;
}