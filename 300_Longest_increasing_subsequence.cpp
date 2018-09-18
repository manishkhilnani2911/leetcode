/*Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?*/
class Solution {
  //Fb_AM_Go_Vm_Mi_Ap_Ub
public:
    int lengthOfLIS(vector<int>& nums) {
      if (nums.size() == 0)
        return 0;
      vector<int> LISAtPosition(nums.size(),0); // this will store the LIS till that position
      LISAtPosition[0] = 1; //is there is only one element in the array the LIS is 1
      int LIS = 1;
      for (int i=1;i<nums.size();++i) {
        int maxLISAtPosition = 0;
        for (int j=0;j<i;j++) { // for the number at ith position we find the max LIS till i-1 position
          if (nums[i] > nums[j]) {
            maxLISAtPosition = max(maxLISAtPosition,LISAtPosition[j]);
          }
        }
        LISAtPosition[i] = maxLISAtPosition + 1; // max LIS at position i is 1 + maxLIS til position i-1
        LIS = max(LIS,LISAtPosition[i]); // keep updating LIS at each iteration of i
      }
      return LIS;
    }
};
