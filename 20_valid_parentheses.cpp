/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true*/
class Solution {
  //Fa_Am_Li_Mi_Bl_Tw_Go_Ex_Ap_Vm_Ub_Wa_Ci_Eb_Ad_Go_SAP_Ali_Sa_Ba_Ly_Vi_Pa_In_Ya_Air_Or_Qu_Ye
public:
    bool isValid(string s) {
        stack<char> mystack;
        if(s.length() == 1)
            return false;
        for(int i=0;i<s.length();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                mystack.push(s[i]);
            }
            if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                if(s[i] == ')'){
                    cout<<"here\n";
                    if( mystack.empty() || mystack.top() != '(' )
                        return false;
                    else
                        mystack.pop();
                }
                else if(s[i] == ']'){
                    if(mystack.empty() || mystack.top() != '[' )
                        return false;
                    else
                        mystack.pop();
                }
                if(s[i] == '}'){
                    if(mystack.empty() || mystack.top() != '{')
                        return false;
                    else
                        mystack.pop();
                }
            }
        }
        if(mystack.empty())
            return true;
        else
            return false;
    }
};
