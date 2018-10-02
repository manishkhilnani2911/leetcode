/*A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?



An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right*/
class Solution {
	//Am_Go_Bl_Fa_Tw
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      if (obstacleGrid.size() == 0)
        return 0;
      int row = obstacleGrid.size();
      int col = obstacleGrid[0].size();

      //int pathsum[row][col] = {0};
      vector<vector<int>> pathsum(row,vector<int>(col,0));
      if (row == 1 && col == 1) {
        if (obstacleGrid[row-1][col-1] == 0) {
          return 1;
        }
      }
      if (obstacleGrid[0][0] == 1){
        return 0;
      }
      if (obstacleGrid[row-1][col-1] == 1) {
        return 0;
      }
      pathsum[0][0] = 0; //start position, robot is present here

      //updating the first row till we do not find an obstacle in it
      for (int i = 1; i < col; i++) {
        if (obstacleGrid[0][i] == 1) {
          break;
        }
        pathsum[0][i] = 1;
      }

      //updating first column till we find an obstacle
      for (int i = 1; i < row; i++) {
        if (obstacleGrid[i][0] == 1) {
          break;
        }
        pathsum[i][0] = 1;
      }

      //update the dp matrix only if the corresponding grid location is not an obstacle.
      for(int i = 1; i<row; i++) {
        for(int j = 1; j<col; j++) {
          if (obstacleGrid[i][j] == 1) {
            continue;
            //pathsum[i][j] = 0;
          }
          //cout<<pathsum[i-1][j]<<" "<<pathsum[i][j-1]<<"\n";
          pathsum[i][j] = pathsum[i-1][j] + pathsum[i][j-1];
        }
      }
      return pathsum[row-1][col-1];
    }
};
