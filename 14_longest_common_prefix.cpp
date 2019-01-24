/*
 Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
 */
class Solution {
  //Fa_Ad_Ap_Go_Qu_Ya_Or_Pin_Mi_Air_Ye_Am_Ali_Ex_Sa_Vm
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        int j;
      //first string is the current common prefix
        string res = strs[0];
      //iterate over the list one by one starting from the second string
        for (int i=1;i<strs.size();i++){
            if (strs[i].length()==0)
                return "";
          //find common prefix between second string and the common prefix till now
            for (j=0;j<strs[i].length() && j<res.length();j++){
                if(res[j] != strs[i][j])
                    break;
            }
          //update the common prefix
            res = res.substr(0,j);
        }
        return res;
    }
};
