/*You are given a license key represented as a string S which consists only alphanumeric character and dashes. The string is separated into N+1 groups by N dashes.

Given a number K, we would want to reformat the strings such that each group contains exactly K characters, except for the first group which could be shorter than K, but still must contain at least one character. Furthermore, there must be a dash inserted between two groups and all lowercase letters should be converted to uppercase.

Given a non-empty string S and a number K, format the string according to the rules described above.

Example 1:
Input: S = "5F3Z-2e-9-w", K = 4

Output: "5F3Z-2E9W"

Explanation: The string S has been split into two parts, each part has 4 characters.
Note that the two extra dashes are not needed and can be removed.
Example 2:
Input: S = "2-5g-3-J", K = 2

Output: "2-5G-3J"

Explanation: The string S has been split into three parts, each part has 2 characters except the first part as it could be shorter as mentioned above.
Note:
The length of string S will not exceed 12,000, and K is a positive integer.
String S consists only of alphanumerical characters (a-z and/or A-Z and/or 0-9) and dashes(-).
String S is non-empty.*/
class Solution {
  //Go_Am
public:
    string licenseKeyFormatting(string S, int K) {
      string res = "";
      int i = S.length()-1;
      int n = 0;
      //start from the end of the string,
      //ignore all the '-',
      while(i>=0) {
        if (S[i] == '-') {
          i--;
          continue;
        }
        //add the digits to the result string
        if (isdigit(S[i])) {
          res = S[i] + res;
        } else if (isupper(S[i])) { //add the uppercase characters
          res = S[i] + res;
        } else { //convert lower case to upper case and add to the string
          char c = toupper(S[i]);
          res = c + res;
        }
        n++;
        //after every K steps add a '-' to the string
        if (n == K) {
          res = '-' + res;
          n = 0;
        }
        i--;
      }
      //we need to remove the '-' that were added to the start of the string
      if (res[0] == '-') {
        for (int i = 1; i<res.length(); i++) {
          if (res[i] == '-') {
            i++;
          } else {
            res = res.substr(i);
            break;
          }
        }
      }
      return res;
    }
};
