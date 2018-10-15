/* Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/
class Solution {
  //Am_Go_Fa_Li_Or_Bl_Ex_MI_Tw_Eb_Ly_Ye_Sn_Ya_Air_Ad_Ub
  queue<string> words;
  int res;
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      unordered_set<string> wlist;
      for (auto s : wordList) {
        wlist.insert(s);
      }
      if (wlist.find(endWord) == wlist.end()) {
        return 0;
      }
      //begin with the startword and look for its adjacent words
      //if the adjacent words are in the wordList, put them in a queue and remove them from the wordList
      //for each word in the queue find its adjacent word
      //keep a counter everytime you find an adjacnet word which is in the list
      //the number at which you find the end word is the answer.
      words.push(endWord); //start with the last word
      wlist.insert(beginWord); //need to search till we hit begin word
      //wordList.erase(it);
      res++;
      while(!words.empty()) {
        //find adjacent words of this word in the dictionary 
        int size = words.size();
        while(size) {
          string temp = words.front();
          words.pop();
          if(temp == beginWord) {
            return res;
          }
          findAdjacentWords(temp,wlist,visited);
          size--;
        }  
        res++;
      }  
      cout<<"here";
      return 0;  
    }
    void findAdjacentWords(string temp, unordered_set<string>& wordList) {
      char letter;
      for (int i=0;i<temp.size();i++) {
        letter = temp[i];
        for (int j=0;j<26;j++) {
          temp[i] = 'a' + j;
          auto it = wordList.find(temp);
          if (it != wordList.end()) {
            words.push(temp);
            wordList.erase(it);
          }
        }
        temp[i] = letter;
      }
    }
};
