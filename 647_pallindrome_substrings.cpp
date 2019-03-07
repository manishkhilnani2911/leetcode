/*647. Palindromic Substrings
Medium

1194

62

Favorite

Share
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Note:

The input string length won't exceed 1000.*/
class Solution {
  //Am_Go_Fa_Co_Mi_Ad_Sap_Tw_Ex_Ap_Ub_Li
public:
    int countSubstrings(string s) {
      //cache to store the result till length [i][j] , if dp[i][j] = 1 then s[i-to-j] is a pallindrome
      vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
      //if s[i] == s[i+1] we have a pallindrome of two letters
      for (int i=0;i<s.size();i++) {
        dp[i][i] = 1;
        if (i==s.size()-1) {
          break;
        }
        dp[i][i+1] = (s[i]==s[i+1]);
      }
      int size = s.size();
      //for any i to j substr if substring from i+1 to j-1 is a pallindrome and s[i] == s[j],
      //then current string is also a pallindrome.
      for (int i=size-3;i>=0;i--) {
        for (int j=i+2;j<size;j++) {
          dp[i][j] = (dp[i+1][j-1] && s[i]==s[j]);
        }
      }
      int res = 0;
      for (int i=0;i<size;i++) {
        for (int j=i;j<size;j++) {
          res += dp[i][j];
        }
      }
      return res;
    }
};
