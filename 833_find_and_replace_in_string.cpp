/*To some string S, we will perform some replacement operations that replace groups of letters with new ones (not necessarily the same size).

Each replacement operation has 3 parameters: a starting index i, a source word x and a target word y.  The rule is that if x starts at position i in the original string S, then we will replace that occurrence of x with y.  If not, we do nothing.

For example, if we have S = "abcd" and we have some replacement operation i = 2, x = "cd", y = "ffff", then because "cd" starts at position 2 in the original string S, we will replace it with "ffff".

Using another example on S = "abcd", if we have both the replacement operation i = 0, x = "ab", y = "eee", as well as another replacement operation i = 2, x = "ec", y = "ffff", this second operation does nothing because in the original string S[2] = 'c', which doesn't match x[0] = 'e'.

All these operations occur simultaneously.  It's guaranteed that there won't be any overlap in replacement: for example, S = "abc", indexes = [0, 1], sources = ["ab","bc"] is not a valid test case.

Example 1:

Input: S = "abcd", indexes = [0,2], sources = ["a","cd"], targets = ["eee","ffff"]
Output: "eeebffff"
Explanation: "a" starts at index 0 in S, so it's replaced by "eee".
"cd" starts at index 2 in S, so it's replaced by "ffff".
Example 2:

Input: S = "abcd", indexes = [0,2], sources = ["ab","ec"], targets = ["eee","ffff"]
Output: "eeecd"
Explanation: "ab" starts at index 0 in S, so it's replaced by "eee". 
"ec" doesn't starts at index 2 in the original S, so we do nothing.
Notes:

0 <= indexes.length = sources.length = targets.length <= 100
0 < indexes[i] < S.length <= 1000
All characters in given inputs are lowercase letters.*/
class Solution {
  //Go
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
      string res;
      vector<pair<int,int>> index;
      for (int i=0; i<indexes.size(); i++) {
        index.push_back(make_pair(indexes[i],i));
      }
      sort(index.begin(),index.end());
      reverse(index.begin(),index.end());
      int diff = 0;
      //first letter of sources should match the char at the index for the sources
      for (int i=0;i<index.size();i++) {
        int j = index[i].first; //we have to find the string starting at this loaction
        string source = sources[index[i].second]; //the string starting at j should match this
        string target = targets[index[i].second]; //if the string at j matches source replace it with target
        //diff += target.length()-source.length();
        if (S.substr(j,source.length()) == source) {
          S = S.substr(0,j) + target + S.substr(j+source.length());
        }
      }
      cout<<S;
      return S;
    }
};
