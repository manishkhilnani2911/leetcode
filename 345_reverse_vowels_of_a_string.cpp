/*Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"
Note:
The vowels does not include the letter "y".*/
class Solution {
  //Go_Mi
public:
    string reverseVowels(string s) {
      int start = 0;
      int end = s.length()-1;
      while(start < end) {
        start = s.find_first_of("aeiouAEIOU",start);
        end = s.find_last_of("aeiouAEIOU",end);

        //this condition is necessary othwise we will again swap the initially swapped values which will give
        //us the original string again
        if (start < end)
        swap(s[start++],s[end--]);
        //start++;
        //end--;
      }
      return s;
    }
};
