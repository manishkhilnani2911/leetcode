/*Given an input string, reverse the string word by word.

Example:  

Input: "the sky is blue",
Output: "blue is sky the".
Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
Follow up: For C programmers, try to solve it in-place in O(1) space.*/
class Solution {
  //Mi_Fa_Pa_Am_Wa_Ci_Li_Ap_Zi_Bl_Go_Al_Ad_Qu_Ba_Ya_Sa_Sn_Ye
public:
    void reverseWords(string &s) {
      //first remove all unnecessary spaces
      int count = removeSpaces(s);
      if (count == 0) {
        return;
      }
      //now get every word and reverse it
      int i = 0;
      while(i < s.length()) {
        int start = i;
        while (!isspace(s[i++]) && i<=s.length()) {}
        reverse(s.begin()+start,s.begin()+i-1);
      }
      reverse(s.begin(),s.end());
    }

    int removeSpaces(string &s) {
      int i = 0;
      int space = 0,count = 0;
      while(s[i++] == ' ') {
        space++;
        count++;
      }
      s.erase(0,space);
      i = s.length()-1;
      while(s[i--] == ' ') {
        s.pop_back();
        count++;
      }
      i = 0;
      while(i < s.length()) {
        if (!isspace(s[i])){
          i++;
          continue;
        }
        int start = i;
        int space_len = 0;
        while(isspace(s[i++])) {
          space_len++;
          //i++;
        }
        //cout<<start<<" "<<space_len<<"\n";
        if (space_len > 0) {
          s.erase(start,space_len-1);
          count += space_len;
        }
        i = start+1;
      }
      return count;
    }

  //revrese entire string
  //then reverse entire word
  /* STL solution
  void reverseWords(string &s) {
      reverse(s.begin(),s.end());
      std::istringstream stream(s);
      std::string word;
      string res = "";
      while (stream >> word)
      {
        reverse(word.begin(),word.end());
        res += word + ' ';
      }
      if (res.length() > 0) {
        res.pop_back();
      }
      s = res;
    }
    */
};
