/*Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".*/

class Solution {
  //Ub_Fa
  public:
    vector<int> findAnagrams(string s, string p) {
      vector<int> forp(26,0);
      vector<int> fors(26,0);
      vector<int> res;
      if (s.length() < p.length())
        return res;
      for (int i=0;i<p.length();i++){
        forp[p[i]-'a']++;
        fors[s[i]-'a']++;
      }
      if (fors==forp){
        res.push_back(0);
      }
      for(int i=p.length();i<s.length();i++){
        fors[s[i]-'a']++;
        fors[s[i-p.length()]-'a']--;
        if (fors == forp){
          res.push_back(i-p.length()+1);
        }
      }
      return res;
    }
  //sub optimal solution before
      /*vector<int> forp(26,0);
      vector<int> res;
      if (s.length() < p.length())
        return res;
      initializep(p,forp);
      for (int i=0;i<s.length();++i){
        if (forp[s[i]-'a']){
          bool val = compareStrings(p,s,i,forp);
          if (val){
            res.push_back(i);
          }
        }
      }
      return res;
    }
    void initializep(string &p, vector<int>& forp){
      for (int i=0;i<p.length();++i){
        forp[p[i]-'a'] += 1;
      }
    }
    bool compareStrings(string& p, string& s, int startIndex, vector<int>& forp){
      vector<int> fors(26,0);
      for (int i=startIndex; i<startIndex+p.length() && i<s.length(); ++i){
        fors[s[i]-'a'] += 1;
      }
      if (fors == forp){
        return true;
      }
      return false;
    }  */
};
