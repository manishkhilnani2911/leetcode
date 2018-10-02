/*Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.*/
class Solution {
  //Mi_Am_Go_Bl
public:
    int minPathSum(vector<vector<int>>& grid) {
      //if grid is empty return 0
      if (grid.size()==0)
        return 0;
      int row = grid.size();
      int col = grid[0].size();
      //cout<<row<<" "<<col<<"\n";
      //below is the dp matrix, pathsum[i][j] will store the minimum path sum till i,j
      int pathsum[row][col] = {-1};
      pathsum[0][0] = grid[0][0];
      //updating first row
      //since for each element of the first row there is only one way to reach
      for (int i = 1 ; i<col; i++) {
        pathsum[0][i] = grid[0][i] + pathsum[0][i-1];
      }
      //updating first col
      //similar to first row updating, we can only reach the first column elements from the one above it
      for (int i = 1; i<row; i++) {
        pathsum[i][0] = grid[i][0] + pathsum[i-1][0];
      }
      //update each index of the pathsum matrix by selecting the minimul from above and left element and adding to it the index value.
      for (int i = 1; i<row; ++i) {
        for (int j = 1; j<col; ++j) {
          pathsum[i][j] = min(pathsum[i][j-1],pathsum[i-1][j]) + grid[i][j];
        }
      }
      //cout<<pathsum[row-1][col-1]<<"\n";
      return pathsum[row-1][col-1];
    }
};
