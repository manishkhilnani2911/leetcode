/*
 Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
   */
class Solution {
  //Fa_Mi_Bl_Go_Am_Ad
public:
    int minSubArrayLen(int s, vector<int>& nums) {
      if (nums.size() == 0) {
        return 0;
      }
      int st = 0;
      int e = 0, sum = 0, min_len = INT_MAX;
      while(st<=e && e<nums.size()) {
        sum += nums[e]; //keep adding to the sum till it is less than s and incrementing end pointer
        while(sum >= s) { //as soon as the sum becomes more than k calculate length and keep incrementing end pointer
          min_len = min(min_len,e-st+1);
          sum -= nums[st++];
        }
        e++;
      }
      if (min_len == INT_MAX)
        return 0;
      return min_len;
    }
};
