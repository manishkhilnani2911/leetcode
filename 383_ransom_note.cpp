/*Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true*/
class Solution {
  //Ap_Fa_Go_Ub_Ya
public:
    bool canConstruct(string ransomNote, string magazine) {
      //get the count of all letters in the ransom note
      vector<int> ransom(26,0);
      for (auto c : ransomNote) {
        ransom[c-'a']++;
        cout<<ransom[c]<<"\n";
      }
      //subtract the letters from the magazine in the ransom note
      //at the end ransom note should have all 0 or negative value
      for (auto c : magazine) {
        ransom[c-'a']--;
      }
      for (auto i : ransom) {
        if (i>0){
          return false;
        }
      }
      return true;
    }
};
