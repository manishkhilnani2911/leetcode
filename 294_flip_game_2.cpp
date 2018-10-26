/*You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

Example:

Input: s = "++++"
Output: true 
Explanation: The starting player can guarantee a win by flipping the middle "++" to become "+--+".
Follow up:
Derive your algorithm's runtime complexity.*/
class Solution {
public:
    bool canWin(string s) {
      //no moves possible, cannot win if cannot play!
      if(s.length() == 0) {
        return false;
      }
      for (int i=0; i<s.length()-1; i++) {
        if (s[i] == '+' && s[i+1] == '+') {
          s[i] = '-';
          s[i+1] = '-';
          //after the first move there are no more moves available the first player will win
          if (!canWin(s)) {
            return true;
          }
          s[i] = '+';
          s[i+1] = '+';
        }
      }
      //else return false
      return false;
    }
};
