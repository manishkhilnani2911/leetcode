/*Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.*/
class Solution {
  //Li_In
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
      int start = -1;
      int end = -1;
      int mini = INT_MAX;
      //get the index of word1 and word2 and subtract them to get the distance
      for (int i=0;i<words.size();i++) {
        if (words[i] == word1) {
          start = i;
          if (end != -1) { //this is for duplication
            mini = min(mini,abs(end-start));
          }
        }
        if (words[i] == word2) {
          end = i;
          if (start != -1) {
            mini = min(mini,abs(end-start));
          }
        }
      }
      return mini;
    }
};
