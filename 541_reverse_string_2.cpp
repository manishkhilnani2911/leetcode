/*Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]*/
class Solution {
  //Go
public:
    string reverseStr(string s, int k) {
      int start = 0;
      if (k > s.length()) {
        reverse(s.begin(),s.end());
        return s;
      }
      for (int i = 0;i <s.length(); i = i + 2*k) {
        //is we have more than k character left reverse the first k characters
        if (s.length()-i >= k) {
          int start = i;
          int end = i + k - 1;
          while (start < end) {
            swap(s[start++],s[end--]);
          }
        } else { //if there are less than k characters left, reverse all the remaining characters
          int start = i;
          int end = s.length()-1;
          while(start < end) {
            swap(s[start++],s[end--]);
          }
        }
      }
      return s;
    }
};
