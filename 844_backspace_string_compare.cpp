/*Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?*/
class Solution {
  //Go_Fa
public:
    bool backspaceCompare(string S, string T) {
      int i=0;
      //keep deleting the character and the '#' that follows it
      //in the end deleted the '#' left in the front of the string
      while(i<S.length()) {
        if (S[i+1] == '#') {
          S.erase(i,2);
          if(i)i--;
        } else {
          i++;
        }
      }
      i = 0;
      while(i<T.length()) {
        if (T[i+1] == '#') {
          T.erase(i,2);
          if(i)i--;
        } else {
          i++;
        }
      }

      i = 0;
      while (S[i] == '#') {
        i++;
      }
      S.erase(0,i);
      i = 0;
      while(T[i] == '#'){
        i++;
      }
      T.erase(0,i);
      if (S == T) {
        return true;
      }
      cout<<S<<" "<<T;
      return false;
    }
};
