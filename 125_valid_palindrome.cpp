/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false*/
class Solution {
  //Fa_Ap_Mi_Go_Am_Ad_Sn_Air_Ye_Ub
public:
    bool isPalindrome(string s) {
      if (s.length() == 0) {
        return true;
      }
      int start = 0;
      int end = s.length()-1;
      while(start < end) {
        //skip non alphanumeric numbers
        //if the entire string is alphanumeric start will reach end
        while(!isalnum(s[start]) && start < end) {
          start++;
        }
        while (!isalnum(s[end]) && start < end) {
          end--;
        }
        if (toupper(s[start]) != toupper(s[end])) {
          cout<<s[start]<<" "<<s[end]<<"\n";
          return false;
        }
        start++;
        end--;
      }
      return true;
    }
};
