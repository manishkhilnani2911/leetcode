/*Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:

Input: "1 + 1"
Output: 2
Example 2:

Input: " 2-1 + 2 "
Output: 3
Example 3:

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.*/
class Solution {
  //Am_Ub_Go_Fa_Mi
public:
    int calculate(string s) {
      stack<int> val;
      stack<int> op;
      int num = 0;
      int sign = 1;
      int res = 0;
      for (char c : s) {
        if (c == ' ')
          continue;
        if (isdigit(c)) {
          num = num*10 + c- '0';
        } else {
          res = res + sign*num;
          //cout<<res<<" "<<sign<<"\n";
          if (c == '+')
            sign = 1;
          else if (c == '-') {
            sign = -1;
          }
          else if (c == '(') {
            //if we encounter a opening bracket, push the result till ow into the stack
            //also push the current sign into the stack
            //eg: 1+(2+3) so here we will push 1 and '+' into stack and evaluate till we hit a closing
            //bracket at that point we will add the result of '2+3' to the result we had push on the stack previously
            //cout<<"bracket start pushing::"<<res<<" "<<sign<<"\n";
            val.push(res);
            op.push(sign);
            res = 0; //reset the res variable here to calculate the result inside the bracket;
            sign = 1;
          } else if (c == ')') {
            res = val.top() + op.top()*res;
            val.pop();
            op.pop();
          }
          num = 0;
        }
      }
      return res + sign*num;
    }
};
