/*Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Note: 
You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?*/
class Solution {
  //Am_Fa_Bl_Ye_Ub_Al_Co_Eb_Mi_Ap_Go_Hu_Sn_Wa
  vector<int> res;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      if (nums.size() == 0) {
        return res;
      }
      if (k == 1) {
        return nums;
      }
      int max = nums[0];
      //get the maximum element in the first window
      for (int i=1;i<k;i++){
        if (max < nums[i]) {
          max = nums[i];
        }
      }
      res.push_back(max);
      //for the remaining array two possibilities can occur
      //1. if the max element from the previous window is still present in the current window then we need to check max against the
      //new added element and that would be the max of the current window
      //2. if the max of previous element is not in the current window then we will have to compare all the elements of the current window
      // to calculate max of the current window.
      for (int i=k;i<nums.size();i++) {

        if (max == nums[i-k]) {
          max = INT_MIN;
          for (int j=i-k+1;j<=i;j++) {
            if (nums[j] > max) {
              max = nums[j];
            }
          }
          res.push_back(max);
          continue;
        }
        if (max<nums[i]) {
          max = nums[i];
        }
        res.push_back(max);
      }
      return res;
    }
};
