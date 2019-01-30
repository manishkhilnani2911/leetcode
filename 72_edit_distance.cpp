/*Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')*/
class Solution {
  //Li_Go_bl_Mi_Ya_Am_Ap_Ali_Fa_Sq_Ci_Ad
public:
    int minDistance(string word1, string word2) {
      int w1 = word1.size();
      int w2 = word2.size();
      vector<vector<int>> dp(w1+1,vector<int>(w2+1,0));
      //dp[i][j] = x means that to convert w1[0...i-1] to w2[0...j-1] 3 x is the minimum number of operations that need to be performed
      for (int i=1;i<=w1;i++) {
        dp[i][0] = i;
      }
      for (int i=1;i<=w2;i++) {
        dp[0][i] = i;
      }
      for(int i=1;i<=w1;i++) {
        for (int j=1;j<=w2;j++) {
          if (word1[i-1] == word2[j-1]) {
            dp[i][j] = dp[i-1][j-1];
          } else {
            dp[i][j] = min(dp[i-1][j-1] + 1 ,/*replaced i-1 character of word1 to j-1 character of word2*/
                          min(dp[i][j-1] + 1, /*inserted j-1th character of w2 into w1 */
                          dp[i-1][j] + 1) /*deleted 1 character form w1*/);
          }
        }
      }
      return dp[w1][w2];
    }
};
