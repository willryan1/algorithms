#include <iostream>
#include <vector>
using namespace std;

/*
Checks if a potential character [1-9] is able to be placed in the specific location
at index (i, j) within the board. Checks the row, column, and 3x3 grid for the character
if it is not present, it is a valid location.

Input: board (current sudoku board), i (row of board), j (column of board), c (character to be placed)
Output: true if available, false otherwise
*/
bool isAvailable(vector<vector<char>>& board, int i, int j, char c) {
    for(int row = 0; row < 9; ++row) if(board[i][row] == c) return false;
    for(int col = 0; col < 9; ++col) if(board[col][j] == c) return false;
    int iAdj = i % 3; int jAdj = j % 3;
    for(int row = 0; row < 3; ++row) {
        for(int col = 0; col < 3; ++col) {
            if(board[i - iAdj + row][j - jAdj + col] == c) 
                return false;
        }
    }
    return true;
}

/*
Solves the board using the backtracking algorithm. If the current position is empty, try
all possible characters [1-9] to see if it is an available move. If it is try to solve the
remaining board using that character. If this presents an inconsistency, then backtrack and
try a new character.

Input: board (current sudoku board), r (current row), c (current column)
Output: true (if the sudoku board is solved), false otherwise

The resulting solved board will be saved in the board vector
*/
bool solve(vector<vector<char>>& board, int r, int c) {
    if(r == 9) return true; // Board is solved
    if(c == 9) return solve(board, r + 1, 0); // Move on to next row
    if(board[r][c] != '.') return solve(board, r, c+1);
    for(int i = '1'; i <= '9'; ++i) {
        if(isAvailable(board, r, c, i)) {
            board[r][c] = i;
            if(solve(board, r, c+1)) return true;
            board[r][c] = '.';
        }
    }
    return false;
}

/*
To solve a sudoku board, replace the board vector with the corresponding starter
values and run the program with the following arguments.

```
g++ -std=c++11 -O2 -Wall -Werror sudoku-solver.cpp
./a.out
```
*/
int main() {
    vector<vector<char>> board {
        {'.','.','.','.','.','.','.','3','8'},
        {'5','7','.','.','9','8','2','6','.'},
        {'.','.','8','4','.','.','.','9','.'},
        {'.','.','.','.','.','4','1','.','.'},
        {'9','6','.','.','5','.','.','4','7'},
        {'.','.','5','6','.','.','.','.','.'},
        {'.','.','.','.','.','5','6','.','.'},
        {'.','.','.','8','3','.','.','7','2'},
        {'.','3','1','.','.','.','.','.','.'}
    };

    solve(board, 0, 0);

    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
