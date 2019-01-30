/*Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.*/
class Solution {
  //Ly_Ub_Go_Ad_Am_Fa_Ap_Mi
public:
    int numSquares(int n) {
      if (n<=0) {
        return 0;
      }
      //cache to store the minimum square sum to i
      vector<int> dp(n+1,INT_MAX);
      //sum of 0 requires no number
      dp[0] = 0;
      for (int i=1;i<=n;i++) {
        for (int j=1; j*j<=i; j++) {
          //the intuition here is that the sum till i can be obtained by getting a sum of i-j*j and adding 1 to get for j*j
          //eg sum of 7 can be obtained by getting to a sum of 3 and adding 2*2 to it so just adding 1 entity to sum of 3
          //we take the minimum of it
          dp[i] = min(dp[i],dp[i-j*j] + 1);
        }
      }
      return dp.back();
    }
};
