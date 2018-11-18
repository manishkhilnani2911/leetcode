/*According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:

Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
Follow up:

Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?*/
class Solution {
  //Dr_Am_Ub_Go_Sq_Bl_Ap_Mi_Ba_Sn
public:
    void gameOfLife(vector<vector<int>>& board) {
      if (board.size() == 0) {
        return ;
      }
      int row = board.size();
      int col = board[0].size();
      vector<vector<int>> res(row,vector<int>(col,0));
      for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
          res[i][j] = board[i][j];
        }
      }
      vector<pair<int,int>> neighbours = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
      //for each live and dead cell, check adjacent for live and update according to rule
      for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
          if (board[i][j] == 0) {
            int count = 0;
            //count number of live cells in its neighbours
            for (auto n : neighbours) {
              int roww = n.first + i;
              int coll = n.second + j;

              if (roww >= board.size() || roww < 0 || coll >= board[0].size() || coll < 0) {
                continue;
              }
              if (board[roww][coll] == 1) {
                count++;
              }
            }
            if (count == 3) {
              //has exactly three live neighbours
              //update in the res matrix
              res[i][j] = 1;
            }
          } else {
            int count = 0;
            //count number of live neighbours
            for (auto n : neighbours) {
              int roww = n.first + i;
              int coll = n.second + j;

              if (roww >= board.size() || roww < 0 || coll >= board[0].size() || coll < 0) {
                continue;
              }
              if (board[roww][coll] == 1) {
                count++;
              }
            }
            if (count < 2 || count > 3) {
              res[i][j] = 0;
            }
          }
        }
      }
      for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
          board[i][j] = res[i][j];
        }
      }
    }
};
