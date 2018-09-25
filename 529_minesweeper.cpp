/*Let's play the minesweeper game (Wikipedia, online game)!

You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.

Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:

If a mine ('M') is revealed, then the game is over - change it to 'X'.
If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
Return the board when no more squares will be revealed.
Example 1:
Input: 

[['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'M', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E']]

Click : [3,0]

Output: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Explanation:

Example 2:
Input: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Click : [1,2]

Output: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'X', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Explanation:

Note:
The range of the input matrix's height and width is [1,50].
The click position will only be an unrevealed square ('M' or 'E'), which also means the input board contains at least one clickable square.
The input board won't be a stage when game is over (some mines have been revealed).
For simplicity, not mentioned rules should be ignored in this problem. For example, you don't need to reveal all the unrevealed mines when the game is over, consider any cases that you will win the game or flag any squares.*/
class Solution {
public:
  //Go_Ub
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
      if (board.size() == 0) {
        return board;
      }
      int r = click[0];
      int c = click[1];
      //if mine is revealed then change to X and no further action is required
      if (board[r][c] == 'M') {
        board[r][c] = 'X';
        return board;
      }
      dfs(board,r,c) ;
      return board;
    }
    void dfs(vector<vector<char>>& board, int row, int col) {
      //only if we hit an unrevealed square then proceed
      if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != 'E') {
        return;
      }
      vector<pair<int,int>> nei = {{-1,-1},{-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
      //it its a E, check for the neighbouring squared to see how many mines it is surrounded by
      int mineCount = 0;
      for (auto x : nei) {
        int rr = row + x.first;
        int cc = col + x.second;
        if (rr < 0 || rr >= board.size() || cc < 0 || cc >= board[0].size()) {
          continue;
        }
        if(board[rr][cc] == 'M') {
          mineCount += 1;
        }
      }
      board[row][col] = mineCount == 0 ? 'B' : char('0' + mineCount);
      for (auto x : nei) {
        int rr = row + x.first;
        int cc = col + x.second;
        //update all the neighbours which are not already updated only if the current position has 0 mines around it.
        if (rr < 0 || rr >= board.size() || cc < 0 || cc >= board[0].size() || board[row][col] != 'B') {
          continue;
        }
        dfs(board,rr,cc);
      }
    }
};
