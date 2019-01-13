/*Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.*/
class Solution {
  //Fa_Am_Mi_Go_Ub_Ly_Ap_Air_Bl_Or_Ad_Eb_Pa_Drop_Ye_Vm_Sn_Sq_Li_Ya_Ali
  vector<string> res;
public:
    vector<string> letterCombinations(string digits) {
      if (digits.size() == 0) {
        return res;
      }
      vector<vector<char>> table;
      table.push_back({'.'});
      table.push_back({'.'});
      table.push_back({'a', 'b', 'c'}); //2
      table.push_back({'d', 'e', 'f'});
      table.push_back({'g', 'h', 'i'}); //4
      table.push_back({'j', 'k', 'l'});
      table.push_back({'m', 'n', 'o'}); //6
      table.push_back({'p', 'q', 'r', 's'});
      table.push_back({'t', 'u', 'v'}); //8
      table.push_back({'w', 'x', 'y', 'z'});

      string temp;
      generateComb(table,temp,digits,0);
      return res;
    }
    void generateComb(vector<vector<char>>& table, string ans, string digits, int index) {
      if (index == digits.size()) {
        res.push_back(ans);
        return;
      }
      //take the first char for the first first index match it with all the chars of the subsequent indexes and so on..
      for (int i=0; i<table[digits[index]-'0'].size(); i++) {
        ans += table[digits[index]-'0'][i];
        generateComb(table,ans,digits,index+1);
        ans.pop_back();
      }
    }
};
