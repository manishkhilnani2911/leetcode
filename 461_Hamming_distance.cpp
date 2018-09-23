/*The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.*/
class Solution {
  //Ad_Ub_Fa
  //1. xor the two numbers, the digits that defer would be 1 all the rest would be 0.
  //2. keeping on anding the number by 1 and removing the last digit of the number.
public:
    int hammingDistance(int x, int y) {
      int res = x ^ y;
      int one = 1;
      int count = 0;
      while (res) {
        count += one & res;
        res = res >> 1;;
      }
      return count;
    }
};
