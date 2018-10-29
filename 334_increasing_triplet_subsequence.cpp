/*Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example 1:

Input: [1,2,3,4,5]
Output: true
Example 2:

Input: [5,4,3,2,1]
Output: false*/
class Solution {
  //Go_Fa_Am_Mi
public:
    bool increasingTriplet(vector<int>& nums) {
       if (nums.size() == 0) {
        return 0;
      }
      vector<int> LISTillPosition(nums.size(),0);
      LISTillPosition[0] = 1; //LIS at 1st location is 1;
      int res = 1;
      for (int i=1;i<nums.size();i++) {
        //get the LIS till i-1 considering that number is less than nums[i]
        int LIS = 0;
        for (int j=0; j<i;j++) {
          if (nums[i] > nums[j]) {
            LIS = max(LIS, LISTillPosition[j]);
          }
        }
        //LISAtPosition i would be updated based on the LIS value of all value till i-1 which are less than i
        LISTillPosition[i] = 1 + LIS;
        if (LISTillPosition[i] == 3) {
          return true;
        }
      }
      return false;
    }
};
