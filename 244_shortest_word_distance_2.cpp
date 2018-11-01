/*Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list. Your method will be called repeatedly many times with different parameters. 

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.*/
class WordDistance {
	//Li_Ub_Bl
  unordered_map<string,vector<int>> m; //map to store the index of each word;
public:
    WordDistance(vector<string> words) {
        for (int i=0;i<words.size();i++) {
          m[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
      int diff = INT_MAX;
      //for the two words word1 and word2 get the minimum difference of the position where they occur
      for (auto i : m[word1]) {
        for (auto j : m[word2]) {
          diff = min(diff,abs(i-j));
        }
      }
      return diff;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
