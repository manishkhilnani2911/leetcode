/*Given a string, find the length of the longest substring T that contains at most k distinct characters.

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: T is "ece" which its length is 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: T is "aa" which its length is 2.
*/
class Solution {
  //Go_Fa_Am_Sn_Qu
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
      unordered_map<char,int> count;
      int j = 0;
      int res = 0;
      for(int i=0;i<s.length();i++) {
        //keep adding the distinct element in the map
        count[s[i]]++;
        //if the size of the map becomes greater than k, start from the beginning and keep moving inwards
        if (count.size() > k) {
          count[s[j]]--;
          if (count[s[j]] == 0) {
            count.erase(s[j]);
          }
          j++;
        }
        //at each index get the maximum length of the array
        res = max(res,i-j+1);
      }
      return res;
    }
};
