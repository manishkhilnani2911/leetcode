/*
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
 */
class Solution {
  //Mi_Am_Go_Ub_Ad_Ly_Wa_Sn_Bl_Fa_Ye_Ya_Ap_Nv_Sa_Ibm_Eb
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string sol;
        genParen(sol, 0, 0, n, res);
        return res;
    }
private:
    void genParen(string sol, int open, int close, int total, vector<string>& res) {
        static int val = 0;
        val++;
      //once we have all open and all close brackets we have one of the strings
        if (open == total && close == total) {
            cout<<"call "<<val<<" open = "<<open<<" close = "<<close<<" sol = "<<sol<<endl;
            //cout<<sol<<"\n";
            res.push_back(sol);
            return;
        }
      //keep adding open bracket until its less than total, once we finish with all open bracket start adding closing brackets
        if (open < total) {
            //sol += '(';
            cout<<"call "<<val<<" open = "<<open<<" close = "<<close<<" sol = "<<sol<<endl;
            genParen(sol+'(', open + 1, close, total, res);
            //sol.resize(sol.length() - 1);
            cout<<"here1 sol size = "<<sol.length()<<" "<<sol<<endl;
        }
        if (close < open) {
            //sol += ')';
            cout<<"call "<<val<<" open = "<<open<<" close = "<<close<<" sol ="<<sol<<endl;
            genParen(sol + ')', open, close + 1, total, res);
            //sol.resize(sol.length() - 1);
            cout<<"here2 sol size  = "<<sol.length()<<" "<<sol<<endl;
        }


    }
};
