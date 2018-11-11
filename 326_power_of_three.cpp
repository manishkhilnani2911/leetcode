/*Given an integer, write a function to determine if it is a power of three.

Example 1:

Input: 27
Output: true
Example 2:

Input: 0
Output: false
Example 3:

Input: 9
Output: true
Example 4:

Input: 45
Output: false
Follow up:
Could you do it without using any loop / recursion?*/
class Solution {
  //Fa_Go
  //the greatest integer which is also a power of three is 1162261467, therefore a number which is a divisor of this number would
  //be a power of three since three is prime
public:
    bool isPowerOfThree(int n) {
      if (n > 0 && 1162261467 % n == 0) {
        return true;
      }
      return false  ;
    }
};
