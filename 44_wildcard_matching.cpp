/*
 Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false
   */
class Solution {
  //Mi_Fa_Ad_Am_Bl_Ali_Go_Ub_Li
public:
    bool isMatch(string s, string p) {
      //dp cache to store the result up to ith and jth character
      //eg dp[i][j] = true - this means that s till ith lenth and p till jth length are matching
      vector<vector<bool>> dp(s.length()+1, vector(p.length()+1,false));

      //if both the strings are empty then its a match
      dp[0][0] = true;
      //if the pattern is all star then it can match with any string

      for (int j=1;j<=p.length();j++) {
        if (p[j-1] == '*') {
          dp[0][j] = dp[0][j-1];
        }
      }

      for (int i = 1; i<=s.length(); i++) {
        for (int j = 1; j<=p.length(); j++) {

          //if the previous patters are equal
          if (p[j-1] == '?' || s[i-1] == p[j-1]) {
            dp[i][j] = dp[i-1][j-1];
          } else if (p[j-1] == '*') {
            //if the pattern is a '*' then we can either ignore this character dp[i][j-1]
            //or we can match this with ith character of string
            dp[i][j] = dp[i-1][j] || dp[i][j-1];
          } else {
            dp[i][j] = false;
          }
        }
      }
      return dp[s.length()][p.length()];
    }
};
