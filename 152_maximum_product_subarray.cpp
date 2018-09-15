/*Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.*/

class Solution {
  //Li_Mi_Ye_Ex
public:
    int maxProduct(vector<int>& nums) {
      int maxP = nums[0];
      int minP = nums[0];
      int r = nums[0];
      for(int i=1;i<nums.size();i++){
        //if the number is negative, we have to swap max and min
        //because multiplying a negative number with smaller number gives larger number
        if ( nums[i]< 0){
          swap(maxP,minP);
        }
        maxP = max(nums[i],maxP*nums[i]);
        minP = min(nums[i],minP*nums[i]);
        r = max(r,maxP);
      }
      return r;
    }
};
