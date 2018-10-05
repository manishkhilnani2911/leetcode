/*
 Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/   

class Solution {
  //Go_Am_Air_Fa
public:
    void solve(vector<vector<char>>& board) {
      //find the connected components of the boundary 'O's
      //mark all of them as '*'
      //now the remaining O's would be the one which are completely surrounded by X, mark them as X.
      //in the end mark the '*' as O
      int row = board.size();
      if (row == 0){
        return;
      }
      int col = board[0].size();
      for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++) {
          if (i == 0 || j == 0 || i == row-1 || j == col-1) { //these are boundary elements
            if (board[i][j] == 'O') {
              dfs(board,i,j);
            }
          }
        }
      }
      for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++) {
          if (board[i][j] == 'O') {
            board[i][j] = 'X';
          } else if (board[i][j] == '*') {
            board[i][j] = 'O';
          }
        }
      }
      /*for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++) {
          if (board[i][j] == '*') {
            board[i][j] = 'O';
          }
        }
      }*/
    }
    void dfs(vector<vector<char>>& board, int row, int col) {
      //get all the neighbours of current index and mark them '*' if they are O
      cout<<row<<" "<<col<<"\n";
      board[row][col] = '*';
      vector<pair<int,int>> neigh = {{-1,0}, {1,0}, {0,1}, {0,-1}};
      for (auto n : neigh) {
        int rr = row + n.first;
        int cc = col + n.second;
        //for out of bounds elements skip
        if (rr < 0 || rr >= board.size() || cc < 0 || cc >= board[0].size()) {
          continue;
        }
        //for all the neighbouring 'O's do a dfs marking them as '*'
        if (board[rr][cc] == 'O') {
          dfs(board,rr,cc);
        }
      }
    }
};
