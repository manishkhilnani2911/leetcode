/*Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2*/
class Solution {
  //Am_Go_Mi_Ba_Ap_Te_Ya_Sn_Ali_Fa_Ad_Eb
public:
  //Moore’s Voting Algorithm
  /*The algorithm for first phase that works in O(n) is known as Moore’s Voting Algorithm. Basic idea of the algorithm is that if we cancel out each occurrence of an element e with all the other elements that are different from e then e will exist till end if it is a majority element.*/
    int majorityElement(vector<int>& nums) {
      int maj_index = 0;
      int major_ele = nums[0];
      int count = 1;
      for (int i=1;i<nums.size();i++) {
        if (nums[i] == major_ele) {
          count++;
        } else {
          count--;
        }
        if (count == 0) {
          major_ele = nums[i];
          maj_index = i;
          count = 1;
        }
      }
      return major_ele;
    }
};
