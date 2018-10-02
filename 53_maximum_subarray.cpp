/*Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.*/

class Solution {
//Li_Am_Al_Fa_Ap_Mi_Ad_Ub_Hu
public:
    int maxSubArray(vector<int>& nums) {
      if (nums.size() == 0)
        return 0;
      int maxSum = nums[0];
      //if the previous number is positive add to current number
        //this will take care if we have a negative number at i-1 position
      for (int i=1;i<nums.size();++i){
        if (nums[i-1] > 0){
          nums[i] += nums[i-1];
        }
      }
      for (int i=1;i<nums.size();++i){
        if (maxSum < nums[i])
          maxSum = nums[i];
      }
      return maxSum;
      //sub optimal soln is below
      /*int maxSum = INT_MIN;
      if (nums.size() == 0){
        return 0;
      }
      for (int i=0; i<nums.size(); i++){
        int sum = 0;
        for (int j = i; j<nums.size(); j++) {
          sum += nums[j];
          //cout<<sum<<"\n";
          if (sum > maxSum) {
            maxSum = sum;
          }
          //cout<<maxSum<<"\n";
        }
      }
      return maxSum;*/
    }
};
