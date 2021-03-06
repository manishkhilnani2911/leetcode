/*Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:

Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.
Example 2:

Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.*/
class Solution {
  //Go_Mi_Am_Ya
  //explanation similar to question 340
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
      unordered_map<char,int> count;
      int j = 0;
      int res = 0;
      for(int i=0;i<s.length();i++) {
        count[s[i]]++;
        if (count.size() > 2) {
          count[s[j]]--;
          if (count[s[j]] == 0) {
            count.erase(s[j]);
          }
          j++;
        }
        res = max(res,i-j+1);
      }
      return res;
    }
};
