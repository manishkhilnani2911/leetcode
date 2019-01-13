/*The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.*/
class Solution {
  //Fa_Am_Ap_Mi_Ali_Ub
  vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
      vector<string> queens(n,string(n,'.'));
      //if no queens return empty
      if (n == 0) {
        res.push_back(queens);
        return res;
      }
      //solve the nqueen problem
      solve(queens,0,0,n);
      return res;
    }
    void solve(vector<string> &queens, int row, int col, int num) {
      if (col>=num) {
        //the call was made after placing the last queen , that means the last queen was successfully placed.
        //add the combination to the result
        res.push_back(queens);
        return;
      }
      //else we have queens left to be placed, now place the queen in each column and then try placing the remaining queens in the remaining columns
      for (int i=0; i<num; i++) {
        //check if it is safe to place the queen in [i][col]
        if (isSafeToPlaceQueen(queens,i,col,num)) {
          //if safe place the queen in that block
          queens[i][col] = 'Q';
          //now increase the column number and try placing the next queen in all the rows of the next column
          solve(queens,row,col+1,num);
          queens[i][col] = '.';
        }
      }
    }
    bool isSafeToPlaceQueen(vector<string>& queens, int row, int col, int num) {
      //there should be no queen placed in the same row
      for (int i=0;i<col;i++) {
        if (queens[row][i] == 'Q') {
          return false;
        }
      }

      //upper diagonal on left side
      for (int i=row,j=col; i>=0 && j>=0; i--,j--) {
        if (queens[i][j] == 'Q')
          return false;
      }

      //lower diagonal on left side
      for (int i=row,j=col; i<num && j>=0; i++,j--) {
        if (queens[i][j] == 'Q')
          return false;
      }
      return true;
    }
};
