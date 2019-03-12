/*Given a string, determine if a permutation of the string could form a palindrome.

Example 1:

Input: "code"
Output: false
Example 2:

Input: "aab"
Output: true
Example 3:

Input: "carerac"
Output: true*/
class Solution {
  //Go_FA_Am_Mi_Ub_Bl
  bool result;
public:
    bool canPermutePalindrome(string s) {
      //check if the string is a pllindromic string, as in only one character(max) can be present odd number of times
      unordered_map<char,int> m;
      for (auto c : s) {
        m[c]++;
      }
      int oddCount = 0;
      for (auto e : m) {
        if (e.second%2 != 0) {
          oddCount += 1;
          if (oddCount >= 2) {
            return false;
          }
        }
      }
      return true;
    }
};
