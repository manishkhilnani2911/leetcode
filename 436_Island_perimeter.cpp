/*You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:*/
class Solution {
  //Fb_Bl
public:
    int islandPerimeter(vector<vector<int>>& grid) {
      int perimeter = 0;
      if (grid.size() == 0)
        return 0;
      for (int i=0; i<grid.size();i++){
        for (int j=0;j<grid[i].size();j++){
          //for each island, count only the side which is connected to water in the perimeter
          if (grid[i][j] == 1){
            if (i == 0 || grid[i-1][j] == 0) //checking the top block
              perimeter++;
            if (i == grid.size()-1 || grid[i+1][j] == 0) //checking bottom
              perimeter++;
            if (j == 0 || grid[i][j-1] == 0) //checking left
              perimeter++;
            if (j == grid[i].size()-1 || grid[i][j+1] == 0) //checking right
              perimeter++;
          }
        }
      }
      return perimeter;
    }
  
};
