/*
 You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.
Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
 */
class Solution {
  //Go_Sa_Ba_Ad_Mi
public:
    int rob(vector<int>& nums) {
      //rob houses from 0 to n-2 and from 1 to n-1
      //the max of these two is the answer
      int size = nums.size();
      if (size == 0){
        return 0;
      }
      if (size == 1) {
        return nums[0];
      }
      vector<int> nums1(size-1,0);
      vector<int> nums2(size-1,0);

      for (int i = 0; i<size-1; i++) {
        nums1[i] = nums[i];
      }
      int j=0;
      for (int i=1;i<size;i++) {
        nums2[j++] = nums[i];
      }
      int rob1 = rob_new(nums1);
      int rob2 = rob_new(nums2);
      return max(rob1,rob2);
    }
    int rob_new(vector<int> &nums) {
      vector<int> rob(nums.size(),0);
      rob[0] = nums[0];
      for (int i=1;i<nums.size();i++) {
        rob[i] = max(rob[i-1],rob[i-2] + nums[i]);
      }
      return rob[nums.size()-1];
    }
};
