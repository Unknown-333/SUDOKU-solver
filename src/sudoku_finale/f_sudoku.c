#include <stdio.h>
#include <stdlib.h>

#define N 9

// Function to check if a number can be placed in the given row and column
int isSafe(int puzzle[N][N], int row, int col, int num) {
    // Check if the number already exists in the row
    for (int i = 0; i < N; i++) {
        if (puzzle[row][i] == num) {
            return 0;
        }
    }

    // Check if the number already exists in the column
    for (int i = 0; i < N; i++) {
        if (puzzle[i][col] == num) {
            return 0;
        }
    }

    // Check if the number already exists in the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (puzzle[i + startRow][j + startCol] == num) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to solve the Sudoku puzzle using backtracking
int solveSudoku(int puzzle[N][N]) {
    int row, col;

    // Find an unassigned cell
    int isComplete = 1;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (puzzle[row][col] == 0) {
                isComplete = 0;
                break;
            }
        }
        if (!isComplete) {
            break;
        }
    }

    // If all cells are assigned, the puzzle is solved
    if (isComplete) {
        return 1;
    }

    // Try placing numbers 1 to 9 in the unassigned cell
    for (int num = 1; num <= N; num++) {
        if (isSafe(puzzle, row, col, num)) {
            puzzle[row][col] = num;
            // Recursively solve the puzzle
            if (solveSudoku(puzzle)) {
                return 1;
            }
            // If the current assignment doesn't lead to a solution, backtrack and try the next number
            puzzle[row][col] = 0;
        }
    }

    return 0;
}

// Function to print the Sudoku puzzle
void printSudoku(int puzzle[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", puzzle[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int puzzle[N][N] = {
    
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 2, 0, 1, 9, 5, 8},
        {0, 5, 0, 0, 0, 6, 0, 0, 0},
        {6, 0, 0, 0, 2, 8, 0, 7, 9},
        {0, 0, 0, 1, 0, 0, 8, 6, 0}
    };

    printf("Sudoku puzzle:\n");
    printSudoku(puzzle);

    // Solve the Sudoku puzzle
    if (solveSudoku(puzzle)) {
        printf("\nSolution:\n");
        printSudoku(puzzle);
    } else {
        printf("\nNo solution exists.\n");
    }

    return 0;
}

/*
The solveSudoku function uses recursion to try different numbers in empty cells until a valid solution is found. The isSafe function checks if a number can be placed in a specific row, column, and 3x3 subgrid without violating the Sudoku rules.

The printSudoku function is used to print the original puzzle and the solution
*/