/*Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

 

Example 1:

Input: "Hello"
Output: "hello"
Example 2:

Input: "here"
Output: "here"
Example 3:

Input: "LOVELY"
Output: "lovely"*/
class Solution {
  //Ad
public:
    string toLowerCase(string str) {
      for(auto &c : str) {

        if (c >= 'A' && c <='Z') {
          //cout<<c<<"\n";
          c = c + 32;
          //cout<<c<<"\n";
        }
      }
      return str;

    }
};
