/*Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Example 1:

Input: "()())()"
Output: ["()()()", "(())()"]
Example 2:

Input: "(a)())()"
Output: ["(a)()()", "(a())()"]
Example 3:

Input: ")("
Output: [""]
*/

class Solution {
  //Fa_Bl_Ub_Go_Am_Ad
  unordered_set<string> res;
public:
    vector<string> removeInvalidParentheses(string s) {
      //calculate the number of parentheses to be removed
      int rem_left = 0;
      int rem_right = 0;
      for (auto i : s) {
        if (i == '(') {
          rem_left++;
        } else if (i == ')') {
          if (rem_left) {
            rem_left--;
          } else {
            //there was no opening '(' for this closing bracket so this closing bracket needs to be removed
            rem_right++;
          }
        }
      }
      recurse(s, rem_right, rem_left, 0/*starting index*/, ""/*result string*/, 0/*pair of parentheses added in the final string*/);
      return vector<string>(res.begin(),res.end());
    }

    void recurse(string& s, int rem_right, int rem_left, int index, string ans, int pair) {
      //base condition
      if (index == s.length()) {
        if (pair == 0 && rem_left == 0 && rem_right == 0) {
          res.insert(ans);
        }
        return;
      }
      if (s[index] == '(') {
        //we can either ignore this open bracket however we need to check if there are still open bracked left to be discarded
        if (rem_left) {
          recurse(s, rem_right, rem_left-1, index+1, ans, pair);
        }
        //or we can add this to the final result string
        recurse(s, rem_right, rem_left, index+1, ans+s[index], pair+1);
      } else if (s[index] == ')') {
        //we can either ignore this close bracket however we need to check if there are still close bracked left to be discarded
        if (rem_right) {
          recurse(s, rem_right-1, rem_left, index+1, ans, pair);
        }
        //or we can add this to the final result string
        if (pair) {
          recurse(s, rem_right, rem_left, index+1, ans+s[index], pair-1);
        }
      } else {
        recurse(s, rem_right, rem_left, index+1, ans+s[index], pair);
      }
    }
};
