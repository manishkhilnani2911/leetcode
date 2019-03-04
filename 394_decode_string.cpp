/*Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
Given an encoded string, return it's decoded string.

Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/
class Solution {
  //Bl_Go_Am_Fa_Mi_Ya_Or_Ap_Sn_Ye
  string res;
public:
    string decodeString(string s) {
      int i = 0;
      return decode(s,i);
    }
  //everytime when we see a [ find the corresposnding closing bracket recursively, this will take care of nested brackets
    string decode(string s, int& pos) {
      int num = 0;
      string r;
      for (;pos<s.length();pos++) {
        if (s[pos] == '[') {
          //look for the string in between "[" and "]"
          string temp = decode(s,++pos);
          while(num) {
            r += temp;
            num--;
          }
        } else if (s[pos] == ']') {
          return r;
        } else if (isdigit(s[pos])) {
          num = num*10 + s[pos]-'0';
        } else {
          r += s[pos];
        }
      }
      return r;
    }
};

