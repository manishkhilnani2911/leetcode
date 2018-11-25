/*Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.

 

Example:

Input: 
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.
 

Note:

1 <= paragraph.length <= 1000.
1 <= banned.length <= 100.
1 <= banned[i].length <= 10.
The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
There are no hyphens or hyphenated words.
Words only consist of letters, never apostrophes or other punctuation symbols.*/
class Solution {
  //Am
  string res = "";
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
      //initialize set to contain banned word, lookup is faster in set compared to vector
      unordered_set<string> ban(banned.begin(),banned.end());
      //remove all punctuations from the string
      for (auto &c : paragraph) {
        if (!isalpha(c)) {
          c = ' ';
        } else {
          c = tolower(c);
        }
      }
      //extract the words from the paragraph
      unordered_map<string,int> m; //map to store count of each non banned word
      istringstream ss;
      ss.str(paragraph);
      string w;
      while(ss>>w) {
        if (ban.find(w) == ban.end()) {
          //if in map increase the count else add in map with count 1
          if (m.find(w) != m.end()) {
            m[w] += 1;
          } else {
            m[w] = 1;
          }
        }
        //cout<<w<<"\n";
      }
      int max_count = 0;
      for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second > max_count) {
          max_count = it->second;
          res = it->first;
        }
      }
      return res;

    }
};
