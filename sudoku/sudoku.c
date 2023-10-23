#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>





bool isSudokuCorrect(int board[9][9]) {

    int r = 0;
    do {
        int c = 0;
        do {
            int number = board[r][c];

        // Check row for duplicates
            int i = 0;
            while (i < 9) {
                if (i != c) {
                    if (board[r][i] == number) {
                        return false; 
                    }
                }
                i++;
            }

        // Check column for duplicates
            int j = 0;
            while (j < 9) {
                if (j != r) {
                    if (board[j][c] == number) {
                        return false; 
                    }
                }
                j++;
            }

        // Check 3x3 subgrid for duplicates
            int srtR = (r / 3) * 3;
            int srtC = (c / 3) * 3;
            int a = srtR;
            while (a < srtR + 3) {
                int j = srtC;
                while (j < srtC + 3) {
                    if (a != r) {
                        if (j != c) {
                            if (board[a][j] == number) {
                                return false;
                            }
                        }
                    }
                    j++;
                }
                a++;
            }
            c++;
        } while (c < 9);
        r++;
    } while (r < 9);


    return true; // No duplicates found, the Sudoku puzzle is correct
}



bool isConflictSafe(int board[9][9], int r, int c, int number) {


    // Check the row for conflicts
    int i = 0;
    while (i < 9) {
        if (board[r][i] == number) {
            return false;
        }
        i++;
    }



    // Check the column for conflicts
    int d = 0;
    while (d < 9) {
        if (board[d][c] == number) {
            return false; // Number 'num' already exists in the column
        }
        d++;
    }



    // Check the 3x3 subgrid for conflicts
    int srtR = (r / 3) * 3;
    int srtC = (c / 3) * 3;
    int b = srtR;

    do {
        int j = srtC;

        do {
            if (board[b][j] == number) {
                return false; // Number 'num' already exists in the subgrid
            }
            j++;
        } while (j < srtC + 3);

        b++;
    } while (b < srtR + 3);


    return true; // 'num' can be safely placed in this cell
}


// Function to solve a Sudoku puzzle using backtracking
bool solvingSudoku(int board[9][9]) {
    int r = 0, c = 0;
    bool isEm = false;


    while (r < 9 && !isEm) {
        if (board[r][c] == 0) {
            isEm = true;
        } else {
            c++;
            if (c == 9) {
                c = 0;
                r++;
            }
        }
    }

    if (!isEm) {
        return true;
    }

    int number = 1;
    while (number <= 9) {
        if (isConflictSafe(board, r, c, number)) {
            board[r][c] = number;

            if (solvingSudoku(board)) {
                return true;
            }

            board[r][c] = 0;
        }
        number++;
    }

    // If no number works, reset the cell and return false
    return false;
}


// Function to check if a Sudoku puzzle has a unique solution
bool isSudokuSolvable(int board[9][9]) {
    int emCount = 0;
    int r = 0, c = 0;

    // Count empty cells
    while (r < 9) {
        if (board[r][c] == 0) {
            emCount++;
        }

        c++;
        if (c == 9) {
            c = 0;
            r++;
        }
    }

    // A Sudoku puzzle with one empty cell is solvable
    if (emCount == 1) {
        // Attempt to solve the puzzle with the one empty cell
        return solvingSudoku(board);
    } else {
        // The puzzle is not solvable because it doesn't have exactly one empty cell
        return false;
    }
}



int main(int argc, char *argv[]) {
    char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Unable to open the file: %s\n", filename);
        return EXIT_FAILURE;
    }


    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int board[9][9];

    int row = 0, col = 0;
    int emptyCount = 0;

    while (row < 9) {
        char c;
        if (fscanf(file, " %c", &c) == 1) {
            if (c == '_') {
                board[row][col] = 0;
                emptyCount++;
            } else {
                board[row][col] = c - '0';
            }
        } else {
            printf("Error reading the puzzle from the file.\n");
            fclose(file);
            return EXIT_FAILURE;
        }

        col++;
        if (col == 9) {
            col = 0;
            row++;
        }
    }


    fclose(file);


    switch (emptyCount) {
        case 0:

        if (isSudokuCorrect(board)) {

            printf("correct\n");

        } else {
            printf("incorrect\n");
        }
        break;

        case 1:

        if (isSudokuSolvable(board)) {
            printf("solvable\n");
        } else {
            printf("unsolvable\n");
        }
        break;

        default:
        printf("error\n");
        return EXIT_FAILURE;
    }


    return 0;
}