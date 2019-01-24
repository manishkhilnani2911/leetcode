/*Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?*/
class Solution {
  //Bl_Go_Mi_Ap_Ya_Ub_Fa_Am_Pay_Vm_Sn_Sa_Ir_Ci_Ye
public:
    bool isAnagram(string s, string t) {
        int lens = s.length();
        int lent = t.length();
      //if the lengths are not equal return false
        if(lens != lent)
            return false;
        int count[26] = {0};
        int i;
        for(i=0;i<lens;i++){
          //if both have the same characters the result in count entries would be all zeroes
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for(i=0;i<26;i++){
            if(count[i] != 0)
                return false;
        }
        return true;
    }
};
