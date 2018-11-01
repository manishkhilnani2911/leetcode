/*Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “makes”, word2 = “coding”
Output: 1
Input: word1 = "makes", word2 = "makes"
Output: 3
Note:
You may assume word1 and word2 are both in the list.*/
class Solution {
//Li_In	
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
      long long i1 = -1, i2 = -1, res = INT_MAX;
        bool same = word1 == word2;
        for (int i = 0;i < words.size();  i++) {
            if (words[i] == word1) {
              if (same) {
                if (i1 != -1 && i2 == -1) {
                  i2 = i;
                } else if (i1 != -1 && i2 != -1) {
                  i1 = i2;
                  i2 = i;
                } else {
                  i1 = i;
                }
              } else {
                i1 = i;
              }
            }
            else if (words[i] == word2) {
                i2 = i;
            }
            else continue;
            if (i1 != -1 && i2 != -1) res = min(abs(i1 - i2), res);
        }
        return res;
      /*int start = -1;
      int end = -1;
      int mini = INT_MAX;
      bool same = word1 == word2 ? true : false;
      unordered_map<string,vector<int>> m;
      //get the index of first word,
      for (int i=0;i<words.size();i++) {
        m[words[i]].push_back(i);
      }
      //if we have same word the get the minimum non zero difference between the index
      if (same) {
        int first = m[word1][0];
        int diff = 0;
        for (int i=0;i<m[word1].size();i++) {
          for (int j=0; j<m[word2].size();j++) {
            if (j != i) {
              diff = abs(m[word1][i]-m[word2][j]);
            }
            if (diff != 0) {
              mini = min(mini,diff);
            }
          }
        }
      } else {
        for (auto i : m[word1]) {
          for (auto j : m[word2]) {
            mini = min(mini,abs(i-j));
          }
        }
      }
      return mini;*/
    }
};
