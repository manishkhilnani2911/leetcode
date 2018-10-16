/*Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.*/
class Solution {
  //Am_Fa_Bl_Ad_Go_Mi_Ap_Or_Ye_Pa_Wa_Ya_Eb_Air_Ub_Ex_Li_Vm_Vi
public:
    int lengthOfLongestSubstring(string s) {
      int start = -1;
      vector<int> dict(256, -1);
      int maxlen = 0;
      for (int i=0;i<s.length();i++) {
        //keep moving the start position as we keep on seeing duplicates
        //eg for abcabcd on seeing the second 'a' the current position of start will be after the first a new string
        //would be 'bca' and so on
        if (dict[s[i]] > start) {
          //the element has been seen before, then the start postition would move to one position after this element
          start = dict[s[i]];
        }
        dict[s[i]] = i;
        maxlen = max(maxlen,i-start);
      }
      return maxlen;
    }
};
