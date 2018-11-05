/*In a string S of lowercase letters, these letters form consecutive groups of the same character.

For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".

Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.

The final answer should be in lexicographic order.

 

Example 1:

Input: "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.
Example 2:

Input: "abc"
Output: []
Explanation: We have "a","b" and "c" but no large group.
Example 3:

Input: "abcdddeeeeaabbbcd"
Output: [[3,5],[6,9],[12,14]]
 

Note:  1 <= S.length <= 1000*/
class Solution {
  //Go
public:
    vector<vector<int>> largeGroupPositions(string S) {
      vector<vector<int>> res;
      int i = 0;
      int j = 0;
      while (i<S.length()) {
        //cout<<"here\n";
        int count = 0;
        int j = i;
        vector<int> temp;
        //cout<<S[j]<<" "<<S[i]<<"\n";
        while(j < S.length() && S[j] == S[i]) {
          //cout<<S[j]<<" "<<S[i]<<"\n";
          j++;
          count++;
        }
        if (count >= 3) {
          temp.push_back(i);
          temp.push_back(j-1);
          res.push_back(temp);
        }
        i = j;
      }

      return res;
    }
};
