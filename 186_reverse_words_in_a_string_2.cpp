/*Given an input string , reverse the string word by word. 

Example:

Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
Note: 

A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces.
The words are always separated by a single space.
Follow up: Could you do it in-place without allocating extra space?*/
class Solution {
  //Mi_Ap_Am_Te_Fa_Bl_Ub
public:
    void reverseWords(vector<char>& str) {
      for(int start = 0; start < str.size(); start++){
        int end = start;
        //get to the end of each word
        while(end < str.size() && str[end] != ' ') end++;
        //reverse each word
        reverse(str.begin()+start,str.begin()+end);
        start = end;
      }
      //finally reverse the entire string
      reverse(str.begin(),str.end());
    }
};
