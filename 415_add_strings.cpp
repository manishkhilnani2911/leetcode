/*Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.*/
class Solution {
  //Fa_Mi_Ap_Ali_Sn_Ad_Go_Sq_Bl_Air
public:
    string addStrings(string num1, string num2) {
      //update each character of the longest string inplace
      bool n1 = true; //n1 is longer
      if (num1.empty())
        return num2;
      if (num2.empty())
        return num1;
      if (num2.length() > num1.length())
        n1 = false; //n2 is longer
      int carry = 0;
      int i = 0,j = 0;
      int res = 0,sum = 0;
      //keep adding each character of the string inplace and updating the result in the longest string
      for (i=num1.length()-1,j=num2.length()-1;i>=0 && j>=0; i--,j--) {
        //cout<<(num1[i]-'0')<<" "<<(num2[j]-'0')<<"\n";
        res = carry + (num1[i]-'0') + (num2[j]-'0');
        //cout<<res<<"\n";
        sum = res % 10;
        //cout<<sum<<"\n";
        carry = res / 10;
        char c = sum + '0';
        //cout<<c<<"\n";
        if (n1) {
          num1[i] = c;
        } else {
          num2[j] = c;
        }
      }
      //cout<<"index"<<i<<" "<<j<<" "<<n1<<" "<<carry<<"\n";
      //if we have a carry left then keep adding it to the longer string till we have a carry
      if (n1) {
        while(carry && i>=0) {
          res = (num1[i]-'0') + carry;
          sum = res % 10;
          carry = res/10;
          char c = sum + '0';
          num1[i] = c;
          i--;
        }
      } else {
        //cout<<"index"<<i<<" "<<j<<" "<<carry<<"\n";
        while(carry && j>=0) {
          //cout<<(num2[j]-'0')<<" "<<carry<<"\n";
          res = (num2[j]-'0') + carry;
          //cout<<res<<"\n";
          sum = res % 10;
          carry = res/10;
          //cout<<"down "<<sum<<" "<<res<<"\n";
          char c = sum + '0';
          num2[j] = c;
          j--;
        }
      }
      //if carry is present at the end, append the string with it and return res
      if (n1) {
        if (carry) {
          return to_string(carry) + num1;
        }
        return num1;
      }
      if (carry)
        return  to_string(carry) + num2;
      return num2;
    }
};
