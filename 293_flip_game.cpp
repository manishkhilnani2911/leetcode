/*You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to compute all possible states of the string after one valid move.

Example:

Input: s = "++++"
Output: 
[
  "--++",
  "+--+",
  "++--"
]
Note: If there is no valid move, return an empty list [].*/
class Solution {
  //Go
public:
    vector<string> generatePossibleNextMoves(string s) {
      int i = 0;
      vector<string> res;
      if (s.length() == 0)
        return res;
      while (i < s.length()-1) {
        if (s[i] == '+' && s[i+1] == '+') {
          //found two consecutive +
          //convert them to -, add the string to the vector and restore their original value
          s[i] = '-';
          s[i+1] = '-';
          res.push_back(s);
          s[i] = '+';
          s[i+1] = '+';
        }
        i++;
      }
      return res;
    }
};
