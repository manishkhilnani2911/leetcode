/*Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.*/
class Solution {
  //Am_Zi_Ub_Fa_Bl_Mi_Ya_Li_Jp_Pi_Go_Ly_Wa_Sn_Ad_Al_Sq_Ye_Ap
public:
    bool exist(vector<vector<char>>& board, string word) {
      //look for the first character of the word;
      int row = board.size();
      int col = board[0].size();
      vector<vector<bool>> used(row,vector<bool>(col,false));
      for (int i=0;i<row;i++) {
        for (int j=0; j<col; j++) {
          //search for first character
          if (board[i][j] == word[0]) {
            used[i][j] = true;
            //cout<<"UP found "<<word[0]<<" at::"<<i<<" "<<j<<"\n";
            //search next character in its neighbours
            if (dfs(board,i,j,1,word,used)) {
              return true;
            }
            used[i][j] = false;
          }
        }
      }
      return false;
    }

    int dfs(vector<vector<char>>& board, int row, int col, int count, string& word, vector<vector<bool>>& used) {
      //found all the letters return true
      if (count >= word.length()) {
        return true;
      }
      vector<pair<int,int>> neighbours{{0,1},{0,-1},{1,0},{-1,0}};
      //if the neighbour is the next word then do a dfs from them
      int rr,cc;
      for (auto n : neighbours) {
         rr = row + n.first;
         cc = col + n.second;
        //if neighbour not equal to next word go to the next neighbour
        if (rr < 0 || rr >= board.size() || cc < 0 || cc >= board[0].size() || used[rr][cc]) {
          continue;
        }
        //if we found the next word in any of the neighbour look in its neighbour for the next word
        if (board[rr][cc] == word[count]) {
          //cout<<"found "<<word[count]<<" at::"<<rr<<" "<<cc<<"\n";
          //setting used to true since this word cannot be used to form the word in the current search
          used[rr][cc] = true;
          if (dfs(board,rr,cc,count+1,word,used)) {
            return true;
          }
          used[rr][cc] = false;
        }
      }
      return false;
    }
};
