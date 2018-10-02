/*A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.*/
class Solution {
  //Go_Bl_Tw_Am_Ya_Fa_Mi_Ap_Ad_Wa
public:
    int uniquePaths(int m, int n) {
      if (m == 0 && n == 0){
        return 0;
      }
      //only one solution if start and end are the same
      if (m == 1 && n == 1)
        return 1;
      int numpath[m][n] = {-1};
      numpath[0][0] = 0;
      //update the first row, there is only one way to reach each index
      for(int i = 1; i< n; i++) {
        numpath[0][i] = 1;
      }
      //update first col similar way to the row
      for (int i=1;i<m; i++) {
        //cout<<i<<"\n";
        numpath[i][0] = 1;
      }
      //for each index, the total num of path would be the sum of paths of left and above grid location, i.e., ij = i-1,j + i,j-1
      for (int i = 1; i< m; i++) {
        for (int j = 1; j<n; j++) {
          numpath[i][j] = numpath[i-1][j] + numpath[i][j-1];
        }
      }
      //cout<<numpath[m-1][n-1];
      //return m-1 and n-1 index
      return numpath[m-1][n-1];
    }
};
