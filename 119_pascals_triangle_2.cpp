/*Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?*/
class Solution {
  //Ad_Go_Ap_Ba_Ci_Am
public:
    vector<int> getRow(int rowIndex) {
      vector<int> v(rowIndex+1);
      for (int i=0;i<=rowIndex;i++) {
        v[0] = 1;
        for (int j=i;j>0;j--) {
          v[j] = v[j] + v[j-1];
        }
      }
      return v;
    }
};
