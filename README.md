# SUDOKU-solver

This is a simple program written with the intention of learning c language and implementing it . It is a sudoku solver using hueristics.

The following is an explanation of how the programme works:

1. `isSafe` Function
   * The `isSafe` function determines if a number num may be placed in the provided row and column of a Sudoku problem without breaking the rules.
   * It determines whether `num` is already present in the same row, column, or 3x3 subgrid. If it exists, it returns 0 (unsafe), otherwise it returns 1 (safe)

2. `solveSudoku` Function:
    * The `solveSudoku` function is a recursive function that uses backtracking to solve the Sudoku problem.
    * It begins by locating an unassigned cell in the puzzle (with value 0).
    * If all cells have been allocated (there is no empty cell), the puzzle is deemed solved, and the method returns 1.
    * It tries inserting integers 1 to 9 one by one in the unassigned cell and tests if the placement is safe using the `isSafe` function.
    * If the placement is safe, the cell is assigned a number, and the function is used recursively to solve the updated puzzle.
    * If the recursive call returns 1 (solution found), so does the function.
    * If the recursive call does not lead to a solution, the function backtracks by setting the current cell value back to 0 and tries the next number.
    * If all numbers have been tried and no solution is found, the function returns 0.

3. `printSudoku` Function:
   * The Sudoku problem is printed using the `printSudoku` function in a grid style, with a gap between each number.
  
4. `main` Function:
    * A Sudoku puzzle grid is initialised with values (0 for empty cells and the supplied values) via the `main` function.
    * The `printSudoku` function is used to print the original Sudoku problem.
    * To solve the sudoku, it uses the `solveSudoku` function.
    * If a solution is discovered, the problem is printed as solved.
    * It shows a notice saying there is no solution if one cannot be located



   
     
