/*Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.


A sudoku puzzle...


...and its solution numbers marked in red.

Note:

The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.*/
class Solution {
	//Vm_Go_Ub_Mi_Fa_Am_Ex_Ad_Air_Sn_Ya
public:
  bool allowed(vector<vector<char>> &board, int row, int col, char val) {
  //check every row for that column
  for (int r=0;r<9;r++) {
    if (board[r][col] == val) {
      return false;
    }
  }
  //check every column in that row
  for (int c=0;c<9;c++) {
    if (board[row][c] == val) {
      return false;
    }
  }
  //check every 3X3 block for which that element is part of
  int rr = row - row%3;
  int cc = col - col%3;
  for (int i=0;i<3;i++) {
    for (int j=0;j<3;j++) {
      if (board[i+rr][j+cc] == val) {
        return false;
      }
    }
  }
  return true;
}
bool solveSudoku(vector<vector<char>> &board, int row, int col) {
  if (row == 9) { //we have traversed entire grid
    return true;
  }
  if (col == 9) {
    //we have reached the end of a particular row, go to the next row
    return solveSudoku(board,row+1,0);
  }
  //also if the block is not empty we need to go to the next column in that row
  if (board[row][col] != '.') {
    return solveSudoku(board,row,col+1);
  }
  //now try placing all the values in the current block and pass the updated board to validate the remaining blocks
  //if not then we backtrack to change the value of the block
  for (char c='1';c<='9';c++) {
    if (allowed(board,row,col,c)) {
      //if this move is allowed fill the block with this char and try filling the remaining blocks
      board[row][col] = c;
      if (solveSudoku(board,row,col+1)) {
        return true;
      }
      //if the above move is not allowed then backtrack and try with the next number
      board[row][col] = '.';
    }
  }
  return false;
}
    void solveSudoku(vector<vector<char>>& board) {
      solveSudoku(board,0,0);
    }
};
