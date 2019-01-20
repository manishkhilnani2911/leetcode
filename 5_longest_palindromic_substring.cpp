/*Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"*/
class Solution {
  //Am_Mi_Fa_Go_Ad_Ap_Ya_Ali_Air_Ci_IBM_Ye_Eb_Ub_Bl_Tw_Ex_Ly_Vm_Dr_Wa_Pay_Or_Sa
public:
    string longestPalindrome(string s) {
      if (s.size() == 0) {
        return "";
      }
      string res = "";
      int n = s.size();
      vector<vector<bool>> dp(s.length(),vector<bool>(s.length(),false));
      //bool dp[n][n] = {false};
      for (int i=0;i<s.size();i++) {
        //fill in the dp cache, for each letter i the character at s[i] is a pallindrome
        //Also if s[i] == s[i+1] the two character string formed is also a pallindrome
        dp[i][i] = true;
        if (i==s.size()-1) {
          break;
        }
        dp[i][i+1] = (s[i]==s[i+1]);
      }
      //we have already filled dp[n-1][n-1], dp[n-2][n-2] and dp[n-2][n-1] while initializing and these were the only entries in n-1 and n-2 rows to be filled, that is why we are starting from n-3rd row

      for (int i=n-3;i>=0;i--) {
        for (int j=i+2;j<n;j++) {
          dp[i][j] = (dp[i+1][j-1] && s[i]==s[j]);
        }
      }

      int max_len = 0;
      for (int i=0;i<n;i++) {
        for (int j=i;j<n;j++) {
          //cout<<dp[i][j]<<"\n";
          if (dp[i][j]) {
            if (j-i+1 > max_len) {
              max_len = j-i+1;
              //cout<<max_len<<"\n";
              res = s.substr(i, j-i+1);
              //cout<<max_len<<" "<<res<<"\n";
            }
          }
        }
      }
      return res;
    }
};
