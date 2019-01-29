/*A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).*/
class Solution {
  //Fa_Go_Mi_Bl_Ub_Tw_Ya_Am_Sa_Sq_Ap_Ex_Pin
public:
    int numDecodings(string s) {
      if (s[0] == '0' || s.length() == 0)
        return 0;
      //cache to store the number of ways a string till index i can be decoded
      //eg dp[1] = 1, means that string of length 1 can be decoded in 1 ways
      vector<int> dp(s.length()+1,0);
      dp[0] = 1;
      dp[1] = 1;

      for (int i=2;i<=s.length();i++) {
        if (s[i-1] > '0') {
          //eg for length of 2 "12" it can be decoded into 1 2 and 12
          dp[i] = dp[i-1];
        }
        if (s[i-2] == '1' || s[i-2] == '2' && s[i-1] < '7') {
          dp[i] += dp[i-2];
        }
      }
      return dp[s.length()];

    }
};
