/*Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"*/
class Solution {
  //Fa_Mi_Go_Am_Ad_Ex_Ali_Ap_Ub_Sa
public:
    int longestValidParentheses(string s) {
      stack<int> st;
      //push the index of any open bracket to the stack
      //if we found a closing bracket then check the top of the stack:
        //if top of the stacks index corresponds to a opening bracket pop from stack
        //else push the closing bracket on top of the stack
      int len = s.length();
      for (int i=0;i<len;i++) {
        if (s[i] == '(') {
          st.push(i);
        } else {
          if (!st.empty() && s[st.top()] == '(') {
            st.pop();
          } else {
            st.push(i);
          }
        }
      }
      //now the indexes in the stack are the ones which do not have their corresponding brackets, the in between
      //indices comprised of valid parenthesis. Traverse the stack and look for the indices with max length in between them
      if(st.empty()) {
        return len;
      }
      int res = 0;
      int end = len;
      int start;
      while(!st.empty()) {
        start = st.top();
        st.pop();
        cout<<end<<" "<<start<<"\n";
        res = max(res,end-start-1);
        end = start;
      }
      res = max(res,end-0);
      return res;
    }
};
