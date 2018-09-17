/*Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3*/

class Solution {
  //Am_Ly_Fa_Ub_Li_Go_Mi_Bl_Al_Ap_Eb_Ye_Ad
public:
  //if you encounter a one mark all it connected component "which are 1" as 0
  //this above bunch would be one island. Do this for everytime you encounter a 1 in the grid.
  //marking the connected components as zero will make sure we do not count the same 1 twice.
    int numIslands(vector<vector<char>>& grid) {
      int res = 0;
      for (int i = 0; i<grid.size();i++){
        for (int j=0;j<grid[i].size();j++){
          if (grid[i][j] == '1'){
            res++;
            dfs(grid,i,j);
          }
        }
      }
      return res;
    }
    void dfs(vector<vector<char>>& grid, int i, int j){
      if (i < 0 || i>=grid.size() || j < 0 || j >= grid[0].size()) {
        return;
      } else {
        if (grid[i][j] == '1')
        {
          grid[i][j] = '0';
          dfs(grid,i-1,j);
          dfs(grid,i+1,j);
          dfs(grid,i,j+1);
          dfs(grid,i,j-1);
        }
      }
    }
};
