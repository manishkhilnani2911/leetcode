/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.*/
class Solution {
  //Go_Am_Wa_Sa_Al_Ma_Mi_Fa_Ba_Ub_Ad_Air_Li
public:
    int rob(vector<int>& nums) {
      int size = nums.size();
      if (size == 0) {
        return 0;
      }
      vector<int> rob(size,0);
      rob[0] = nums[0];
      for (int i = 1; i<size; i++) {
        //for each house there are two possibilities
        //1. it has robbed the previous house so it will not rob the current house
        //2. it has not robbed the previous house but i-2 house so it will rob the current house
        rob[i] = max(rob[i-1],rob[i-2] + nums[i]);
      }
      return rob[size-1];
    }
};
