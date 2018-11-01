/*Given an integer n, return the number of trailing zeroes in n!.

Example 1:

Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Note: Your solution should be in logarithmic time complexity.*/
class Solution {
  //Mi_Nu_Ba_Ad_Sa
public:
    //every power of 5 will introduce 0 at the end(by combining with every even number)
    int trailingZeroes(int n) {
        int res = 0;
        for (long long int i=5; (n/i) > 0 ; i*=5) {
          res += (n/i);
        }
        return res;
    }
};
