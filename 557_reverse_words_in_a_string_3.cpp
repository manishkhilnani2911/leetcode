/*Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.*/
class Solution {
  //Mi_Vm_Ad_Go
public:
    string reverseWords(string s) {
      int i = 0;
      while (i < s.length()) {
        int start = i;
        int end = start;
        //move end to the end of the word, i.e., end reaches the first space
        while (!isspace(s[end])) {
          end++;
          if (end == s.length()) {
            break;
          }
        }
        //save the location of the start of the next word or the end of string
        i = end + 1;
        //move end to the last character of the word to reverse the word
        end = end - 1;
        //cout<<start<<" "<<end<<" "<<i<<"\n";
        while(start < end) {
          swap(s[start++],s[end--]);
        }
      }
      return s;
    }
};
