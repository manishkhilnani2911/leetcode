/*Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.*/
class Solution {
  //Fa_Bl_Am_Zi_Ap_Mi_Ya_Go_Air_SAP_Ali_Or
public:
    int firstUniqChar(string s) {
      //or just store the unique elements in the map
      //and return the least value from it
      unordered_map<char,pair<int,int>> m;
      int min_index = s.length();
      int count = 0;
      for (int i=0;i<s.length();i++) {
        //add to the map if not already present
        if (m.find(s[i]) == m.end()) {
          m[s[i]] = make_pair(1,i);
        } else {
          //if present, we have encountered the element again, then remove it
          pair<int,int> c = m[s[i]];
          count = c.first;
          m[s[i]] = make_pair(count+1,i);
        }
      }
      for(unordered_map<char,pair<int,int>>::iterator it = m.begin(); it != m.end(); ++it) {
        if(it->second.first == 1) {
          if (it->second.second < min_index) {
            min_index = it->second.second;
          }
        }
      }
      min_index = min_index == s.length() ? -1 : min_index;
      return min_index;
    }
};
