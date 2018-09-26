/*Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.*/
class Solution {
  //Fa_Ub_Sa_Go_Mi_Am_Ap
private:
  stack<int> st;
public:
    int calculate(string s) {
      //initializing sign by '+' since the first number is always positive
      stack<int> st;
      char sign = '+';
      int num = 0;
      for (int i = 0 ; i<s.length(); i++) {
        if (s[i] == ' ')
          continue;
        if (s[i] >= '0' && s[i] <= '9') {
          num = num*10 + (s[i]-'0');
          //cout<<num<<"\n";
        } else {
          //switching on the previous sign, the current sign is assigned after the processing
          //for previous sign has been finished
            switch(sign) {
              case '+' : break;
              case '-' : num = -num; break;
              case '*' : num = st.top() * num; st.pop(); break;
              case '/' : num = st.top() / num; st.pop(); break;
            }
            st.push(num);
            sign = s[i];
            num = 0;
        }
      }
      //since we are processing only the first previous number from the sign, last number would need to be processed.
      //processing last number
      if (sign == '+') {
        st.push(num);
      } else if (sign == '-') {
        st.push(-num);
      } else if (sign == '*') {
        int temp = st.top();
        st.pop();
        st.push(temp*num);
      } else {
        int temp = st.top();
        st.pop();
        st.push(temp/num);
      }

      int res = 0;
      while (!st.empty()) {
        res += st.top();
        st.pop();
      }
      return res;
    }
};
