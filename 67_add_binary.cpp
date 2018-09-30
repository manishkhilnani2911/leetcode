/*Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"*/
class Solution {
  //Fa_Am_Ad_Go_Mi
public:
  //start adding number
  //if we get two 1's res is 0 and carry is 1
  //if we get 3 ones carry is 1 and res is 1
  //else result is 1 if we have 1 one else result is 0
    string addBinary(string a, string b) {
      if (b.empty()) {
        return a;
      }
      if (a.empty()){
        return b;
      }
      int carry = 0;
      string res;
      int i = a.length()-1;
      int j = b.length()-1;
      //cout<<"yoyo "<<i<<" "<<j<<"\n";
      while(i>=0 & j>=0) {
        //cout<<"xoxo "<<a[i]<<" "<<b[j]<<"\n";
        if (carry) {
          if (a[i] == '1' && b[j] == '1') {
            res += '1';
            carry = 1;
          } else if ((a[i] == '1' && b[j] == '0') || (a[i] == '0' && b[j] == '1')) {
            res += '0';
            carry = 1;
          } else {
            res += '1';
            carry = 0;
          }
        } else {
          if (a[i] == '1' && b[j] == '1') {
            res += '0';
            carry = 1;
            //cout<<"2\n";
          } else if ((a[i] == '1' && b[j] == '0') || (a[i] == '0' && b[j] == '1')) {
            res += '1';
            carry = 0;
            //cout<<"1\n";
          } else {
            res += '0';
            carry = 0;
          }
        }

        i--;
        j--;
        //cout<<i<<" "<<j<<"\n";
        //cout<<res<<"\n";
      }
      if (i== -1 && j==-1) {
        //cout<<"h\n";
        if (carry)
          res += '1';
        reverse(res.begin(),res.end());
        return res;
      }
      if (i == -1) {
        while (j>=0) {
          if (carry) {
            if (b[j] == '1') {
              res += '0';
              carry = 1;
            } else {
              res += '1';
              carry = 0;
            }
          } else {
            res += b[j];
          }
          j--;
        }
      } else if (j == -1) {
        //cout<<"here"<<i<<" "<<a[i]<<" "<<carry<<"\n";
        while (i>=0) {
          cout<<a[i]<<"\n";
          if (carry) {
            if (a[i] == '1') {
              res += '0';
              carry = 1;
              //cout<<"here1\n";
            } else {
              res += '1';
              carry = 0;
            }
          } else {
            res += a[i];
          }
          i--;
        }
      }
      if (carry) {
        res += '1';
      }
      reverse(res.begin(),res.end());
      //cout<<res<<"\n";
      return res;
    }
};
