/*You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.*/
class Solution {
  //Ad_Am_Al_Ap_Ba
public:
    int numJewelsInStones(string J, string S) {
      if (J.empty()) {
        return 0;
      }
      unordered_set<int> jewels;
      //creating a holder for jewels with 0(1) lookup
      for (auto c : J) {
        jewels.insert(c);
      }
      int count = 0;
      for (auto c : S) {
        //counting number of jewels in S by looking into set
        if (jewels.find(c) != jewels.end()) {
          count++;
        }
      }
      return count;
    }
};
