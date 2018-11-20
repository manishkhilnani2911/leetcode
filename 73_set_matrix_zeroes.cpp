/*Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
class Solution {
  //Fa_Am_Mi_Or_Sa_Ex_go_Nu_Tw_Sn_Bl_Air_Ci
public:
    void setZeroes(vector<vector<int>>& matrix) {
      int rows = matrix.size();
      if (rows == 0) {
        return ;
      }
      int col = matrix[0].size();
      vector<int> r(rows,0);
      vector<int> c(col,0);
      for (int i=0;i<rows;i++) {
        for (int j=0;j<col;j++) {
          if (matrix[i][j] == 0) {
            r[i] = 1;
            c[j] = 1;
          }
        }
      }
      for (int i=0;i<rows;i++) {
        if (r[i]) {
          for (int cc=0;cc<col;cc++) {
            matrix[i][cc] = 0;
          }
        }
      }
      for (int i=0;i<col;i++) {
        if (c[i]) {
          for (int rr=0;rr<rows;rr++) {
            matrix[rr][i] = 0;
          }
        }
      }
    }
};

/*
 class Solution {
  //Fa_Am_Mi_Or_Sa_Ex_go_Nu_Tw_Sn_Bl_Air_Ci
public :
  void setZeroes(vector<vector<int>>& matrix) {
    //store result for all zeroes in the first of that row and first of that column
    //also we need to keep track if the first row and first column had zeroes , otherwise we risk making them all zeroes
    // in the example below if we do not keep track of first row and column then we will risk making the first row as zero which will be
    //wrong
    /*
    Ques:
      [3,4,5,2]
      [0,1,2,0]
      [1,3,1,5]
    
    Ans:
      [0,4,5,0]
      [0,0,0,0]
      [0,3,1,0]
    */
    if(matrix.empty()) return ;
    int rowSize = matrix.size(), colSize = matrix[0].size();
    bool firstRow = false, firstCol = false;
    for(int c = 0; c < colSize; ++c) {
      if(matrix[0][c] == 0) {
        firstRow = true;
        break;
      }  
    }
    for(int r = 0; r < rowSize; ++r) {
      if(matrix[r][0] == 0) {
        firstCol = true;
        break;
      }
    }      
    for(int r = 1; r < rowSize; ++r)
      for(int c = 1; c < colSize; ++c)
        if(matrix[r][c] == 0) matrix[0][c] = matrix[r][0] = 0;
    for(int c = 1; c < colSize; ++c) 
      if(matrix[0][c] == 0)
        for(int r = 1; r < rowSize; ++r)
          matrix[r][c] = 0;
    for(int r = 1; r < rowSize; ++r) 
      if(matrix[r][0] == 0)
        for(int c = 1; c < colSize; ++c)
          matrix[r][c] = 0;
    if(firstRow) for(int c = 0; c < colSize; ++c) matrix[0][c] = 0;
    if(firstCol) for(int r = 0; r < rowSize; ++r) matrix[r][0] = 0;
    }
};  
 */
