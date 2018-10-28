/*Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.

A string such as "word" contains only the following valid abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
Notice that only the above abbreviations are valid abbreviations of the string "word". Any other string is not a valid abbreviation of "word".

Note:
Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.

Example 1:
Given s = "internationalization", abbr = "i12iz4n":

Return true.
Example 2:
Given s = "apple", abbr = "a2e":

Return false.*/
class Solution {
  //Fa_Go
public:
  //iterate over both word and abbr simultaneously
  //if find a number in abbr, add the number to the iterator of word
    bool validWordAbbreviation(string word, string abbr) {
      int i = 0;
      int j = 0;
      int num = 0;
      while (i < word.length() && j < abbr.length()) {
        if (isdigit(abbr[j])) {
          num = 0;
          if (abbr[j] == '0') return false; //corner case handling word = "a", abbr = "01"
          while (j < abbr.length() && isdigit(abbr[j])) {
            num  = num*10 + abbr[j++] - '0';
          }
          i = i + num;
        } else {
          if (word[i++] != abbr[j++]) {
            return false;
          }
        }
      }
      //need to make sure if all characters are matched only then return true
      return i == word.length() && j == abbr.length();
    }
};
