/*Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false*/
class Solution {
  //Fa_Am_Go_Ub_Bl_Ye_Ap_Mi_Sn_Vm_Or_Ali_Pay_Ya_Tw_Ad_Pin_Ly_Eb_In_Sq
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      //to store if the length till index is present in worddict
      vector<bool> dp(s.length()+1);
      unordered_set<string> wd(wordDict.begin(),wordDict.end());
      dp[0] = true;
      //for dp[i] to be true we need to break string from 0 to i in to substrings and check if the substring formed are present in the dictionary
      //eg "leetcode" we first check for l then le and e, then then lee, ee and e
      for (int i=1;i<=s.length();i++) {
        for (int j=0;j<i;j++) {
          string temp = s.substr(j,i-j);
          //cout<<"checking for::"<<i<<" "<<temp<<"\n";
          if (dp[j] && wd.find(temp) != wd.end()) {
            dp[i] = true;
            break;
          }
        }
      }
      return dp[s.length()];
    }
};
