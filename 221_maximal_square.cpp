/*Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4*/
class Solution {
  //Am_Go_Ali_Mi_Ye_Air_Eb_Fa_Ap
public:
    int maximalSquare(vector<vector<char>>& matrix) {
      int row = matrix.size();
      if (row == 0) {
        return 0;
      }
      int col = matrix[0].size();
      vector<vector<int>> dp(row,vector<int>(col,0)); //matrix to store the largest area that can be formed till index [i][j]
      int size = 0;
      for (int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
          //for the first row and first column we can just have that index in the square matrix of size 1
          if (!i || !j || matrix[i][j] == '0') {
            dp[i][j] = matrix[i][j] - '0';
          } else if (matrix[i][j] == '1') {
            //only if top, left and across elements are all one then only this index can be used to form a square of size 2
            //including the above elements
            //else this will be in matrix all by itself of size 1
            dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1])) + 1;
          }
          size = max(size,dp[i][j]);
        }
      }
      return size*size;
    }
};
