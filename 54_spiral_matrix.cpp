/*Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]*/

class Solution {
  //Mi_Go_Bl_Am_Ap_Ad_Ub_Ye_Eb_Fa_Ya_Wa_Pa_Or
  vector<int> res;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      if (matrix.size() == 0) {
        return res;
      }
      int r = matrix.size();
      int c = matrix[0].size();
      int up = 0, down = r - 1;
      int left = 0, right = c - 1;
      vector<int> res(r*c);
      int k = 0;
      //fill first row and increase up
      //fill last column and decrease right
      //fill last row and decrease down
      //fill first column and increase left
      while(true) {
        //traverse the row from left to right
        for(int col = left; col <= right; col++) {
          res[k++] = matrix[up][col];
        }
        if(++up > down) break; //if we have filled the last row break

        //traverse the last column from up to down
        for (int row = up; row <= down; row++) {
          res[k++] = matrix[row][right];
        }
        if (--right < left) break; //we have filled the first column

        //traverse the last row from right to left
        for (int col = right; col>=left; col--) {
          res[k++] = matrix[down][col];
        }
        if (--down < up) break;//we have reached the last row

        //traverse the first colum from down to up
        for (int row = down;row>=up;row--) {
          res[k++] = matrix[row][left];
        }
        if (++left > right) break;
      }
      return res;
    }
};
