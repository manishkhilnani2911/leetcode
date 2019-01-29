/*Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.*/
class Solution {
  //Ap_Mi
  /*
  Each Power of 2 has exactly only 1 bit. (2 : 0010 , 4: 0100, 8:1000, 16:10000)
Each number after the power of 2 follows a pecular pattern :
0 → 0
1 → 0
2 → 1 + dp[0] Nearest Power of 2
3 → 1 + dp[1] 1 greater than nearest
4 → 1 + dp[0] Nearest
5 → 1+ dp[1] 1 greater than nearest
6 → 1+ dp[2] 2 greater than nearest
7 → 1+ dp[3] 3 greater than nearest
8 → 1+ dp[0] Nearest
9 → 1+ dp[1]
10 → 1+ dp[2]
11 → 1+ dp[3]
12 → 1+ dp[4]
You can easily see the pattern here.
  */
public:

    vector<int> countBits(int num) {
      vector<int> dp(num+1);
      dp[0] = 0;
      if (num >= 1) {
        dp[1] = 1;
      }
      int cur = 2;
      int nearest = 2;
      while(cur<=num) {
        nearest = isPowerOfTwo(cur) ? cur : nearest;
        dp[cur] = dp[cur-nearest] + 1;
        cur++;
      }
      return dp;
    }
    bool isPowerOfTwo(int n) {
      return (n&n-1) == 0;
    }
};
