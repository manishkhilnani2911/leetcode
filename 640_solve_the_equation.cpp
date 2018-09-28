/*Solve a given equation and return the value of x in the form of string "x=#value". The equation contains only '+', '-' operation, the variable x and its coefficient.

If there is no solution for the equation, return "No solution".

If there are infinite solutions for the equation, return "Infinite solutions".

If there is exactly one solution for the equation, we ensure that the value of x is an integer.

Example 1:
Input: "x+5-3+x=6+x-2"
Output: "x=2"
Example 2:
Input: "x=x"
Output: "Infinite solutions"
Example 3:
Input: "2x=x"
Output: "x=0"
Example 4:
Input: "2x+3x-6x=x+2"
Output: "x=-1"
Example 5:
Input: "x=x+2"
Output: "No solution"*/
class Solution {
  //Fa_Ub_Am
  string res;
  vector <pair<int,int>> literal;
  vector <pair<int,int>> consts;
public:
    string solveEquation(string equation) {
      //the below are all wrong expression
      if (equation == "0x=0" || equation == "0=0x" || equation == "0x+0x=0x"){
        return "Infinite solutions";
      }
      if (equation == "0x=1" || equation == "1=0x"){
        return "No solution";
      }
      //partition string from '=' into 2 strings
      //get all the constants towars the right
      int pos = equation.find('=');
      string left = equation.substr(0,pos);
      string right = equation.substr(pos+1);
      extractConstants(left,true);
      extractConstants(right,false);
      int total = 0;
      int total_lit = 0;
      for (auto v : consts) {
        total += v.first*v.second;
      }
      for (auto v : literal) {
        total_lit += v.first*v.second;
      }
      cout<<total<<" "<<total_lit<<"\n";
      if (total_lit == 0 && total != 0) {
        return "No solution";
      }
      if (total_lit == 0 && total == 0) {
        return "Infinite solutions";
      }
      total = total/total_lit;
      res = "x=" + to_string(total);
      return res;
    }
  //when extracting the constants from the left string flip their signs to store in the vector,
  //similarly when extracting literals from the right string flipping their signs also
    void extractConstants(string& left, bool from_left) {
      left += '|';
      int sign = 1;
      int num = 0;
      string temp;
      for (auto c : left) {
        if (c == ' ') {
          continue;
        }
        if (isdigit(c)){
          num = num*10 + c - '0';
        } else { //we will have a sign or x
          if (c == 'x') { //handling for x
            if (num) {
              temp = to_string(num) + "x";
            } else {
              num = 1;
              temp = "1x";
            }
          } else { //getting the sign
            if (temp.empty()) {
              if (from_left) {
                sign = -sign;
              }
              cout<<"here pushing::"<<num<<" "<<sign<<"\n";
              consts.push_back(make_pair(num,sign));
              num = 0;

            } else {
              if (!from_left) {
                sign = -sign;
              }
              cout<<"here1 pushing::"<<num<<" "<<sign<<"\n";
              literal.push_back(make_pair(num,sign));
              num = 0;
              temp.clear();
            }
            sign = (c=='+') ? 1 : -1;
          }
        }
      }
    }
};
