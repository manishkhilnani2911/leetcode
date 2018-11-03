/*Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]*/

class Solution {
  //Bl_Go_Mi_Ye_Am_Ub_Ya_Tw_Ap
public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> res;
      if (numRows == 0) {
        return res;
      }
      for(int i=0;i<numRows;i++) {
        res.push_back(vector<int>(i+1,1)); //for outer values
        for (int j=1;j<i;j++) { //add the above rows j and j-1 values
          res[i][j] = res[i-1][j] + res[i-1][j-1];
        }
      }
      return res;
    }
};
