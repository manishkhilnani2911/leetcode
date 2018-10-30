/*Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.*/
class Solution {
  //Fa_Mi
  //have two pointers one for start, one for end
  //match start and end position
  //for the first mismatch, check the remaining string by doing the following
  //1. move start to start+1 and end at the same position.
  //2. move end to end-1 and start at same position
  //any of the two should return a true
  //if none return true the remaining string is not a valid pallindrome, return false
public:
    bool validPalindrome(string s) {
      if (s.length() == 0) {
        return false;
      }
      int start = 0;
      int end = s.length()-1;
      while(start <= end) {
        if (s[start] == s[end]) {
          start++;
          end--;
        } else {
          //remaining string should be a pallindrome
          int st = start+1;
          int en = end;
          while(st<=en && s[st] == s[en]) {
            cout<<"in\n";
              st++;
              en--;
          }
          if (st>=en) {
            //succesfully traversed whole string
            return true;
          }
          st = start;
          en = end-1;
          while(st<=en && s[st] == s[en]) {
              st++;
              en--;
          }
          if (st>=en) {
            //succesfully traversed whole string
            return true;
          }
          return false;
        }
      }
      return true;
    }
};
