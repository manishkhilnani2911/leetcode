/*Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.*/

class Solution {
  //Go_Mi_Ub_Ye_Am_Fa_Ya_Ap
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string,vector<string>> m; //stores the sorted string and its anagrams
      int i = 0;
      for (auto s : strs) {
        sort(s.begin(),s.end());
        m[s].push_back(strs[i++]);
      }
      vector<vector<string>> res;
      for (auto i : m) {
        res.push_back(i.second);
      }
      return res;
    }
};
