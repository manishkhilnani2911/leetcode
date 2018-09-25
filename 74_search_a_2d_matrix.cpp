/*Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false*/
class Solution {
  //Am_Mi_Fa_Ub
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      if (matrix.size() == 0) {
        return false;
      }
      int row = 0;
      //search for the row
      for (int i=1;i<matrix.size();i++) {
        cout<<matrix[i][0]<<"\n";
        if (target == matrix[i][0]) {
          return true;
        }
        if (target > matrix[i][0]) {
          row = i;
        } else
          break;
      }
      int start = 0;
      int end = matrix[row].size()-1;
      //search for the colum in that row
      while (start <= end) {
        int mid = (start+end)/2;
        if (matrix[row][mid] == target) {
          return true;
        }
        if (matrix[row][mid] > target) {
          end = mid-1;
        } else {
          start = mid+1;
        }
      }
      return false;
    }
};
