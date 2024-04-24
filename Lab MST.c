#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

bool isValidSudoku(char board[SIZE][SIZE]) {
    bool rows[SIZE][SIZE + 1] = {false}; // 9 rows, each containing numbers 1-9
    bool cols[SIZE][SIZE + 1] = {false}; // 9 columns, each containing numbers 1-9
    bool subs[SIZE][SIZE + 1] = {false}; // 9 subgrids, each containing numbers 1-9

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            char cell = board[i][j];
            if (cell == '.') continue;

            int num = cell - '0'; // Convert character to integer

            if (rows[i][num] || cols[j][num] || subs[i / 3 * 3 + j / 3][num])
                return false;

            rows[i][num] = true;
            cols[j][num] = true;
            subs[i / 3 * 3 + j / 3][num] = true;
        }
    }

    return true; // Valid Sudoku
}

int main() {
    char board[SIZE][SIZE] = {
        {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
        {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
        {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
        {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
        {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
        {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
        {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
        {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
        {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
    };

    if (isValidSudoku(board))
        printf("The given Sudoku puzzle is a correct solution.\n");
    else
        printf("The given Sudoku puzzle is NOT a correct solution.\n");

    return 0;
}
