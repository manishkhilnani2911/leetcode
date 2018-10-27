/*Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.*/
class Solution {
  //Fa_Go_Air_Am_Li_Bl_Mi_Vm_Ub_Ali_Ap_Ya_Ad_Sn
public:
    string minWindow(string s, string t) {
        map<char, int> counts;
      //get the count of all characters in t
        for (int i = 0; i < t.size(); i++) counts[t[i]]++;

        int cnt = 0;
        int min_len = INT32_MAX;
        int start = 0;
        int min_start = 0;
      //if we find a char in s which is in t increase the cnt
        for (int i = 0; i < s.size(); i++) {
            if (counts[s[i]]-- > 0) cnt++;      // inc 'cnt' only for valid chars in 't' (that's what is the > 0 for)

            while (cnt == t.size()) {           // we have seen all chars in 't'
              //at this point everything which is in t whill have a count of 0 and everything else will have negative count
                if (i - start + 1 < min_len) {
                    min_len = i - start + 1;
                    min_start = start;
                }
                //now keep shifting start pointer to the right and if we encounter an element which was in t we decrement the counter
                if (counts[s[start]] == 0) {
                  cnt--;   // dec 'cnt' only for valid chars in 't' (that's what is the == 0 for)
                  cout<<s[start]<<"\n";
                }
                //for example
              //S = "ADOBECODEBANC", T = "ABC"
              // we are at 6th index when cnt == t.size() for the first time
              //when we move ahead start pointer from A to D we increase the count of A telling that we are looking for A
              //the above loop will only increase the count only when we encounter an A
                counts[s[start]]++;
                start++;
            }
        }
        return (min_len == INT32_MAX) ? "" : s.substr(min_start, min_len);
    }
};
