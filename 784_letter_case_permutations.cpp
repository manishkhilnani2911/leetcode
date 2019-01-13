/*Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:

S will be a string with length between 1 and 12.
S will consist only of letters or digits.*/
class Solution {
  //Mi_Ye_Fa
  vector<string> res;
public:
    vector<string> letterCasePermutation(string S) {
      backtrack(S,0);
      return res;
    }
    void backtrack(string &s, int pos) {
      if (pos == s.length()) {
        res.push_back(s);
        return;
      }
      //keep the current index at the same case or just skip if it is not alphanumeric and process the remaining part of the string
      backtrack(s,pos+1);
      //now toggle the case if the character is alpha numeric and then process the remaining part of the string
      if (isalpha(s[pos])) {
        if (isupper(s[pos])) {
          s[pos] = tolower(s[pos]);
        } else {
          s[pos] = toupper(s[pos]);
        }
        backtrack(s,pos+1);
      }

    }
};
