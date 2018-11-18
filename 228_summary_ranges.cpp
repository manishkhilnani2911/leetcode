/*228. Summary Ranges
DescriptionHintsSubmissionsDiscussSolution
Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:

Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
Example 2:

Input:  [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.*/
class Solution {
  //Go_Am_Mi_Bl_In
  vector<string> res;
public:
    vector<string> summaryRanges(vector<int>& nums) {
      if (nums.size() == 0) {
        return res;
      }

      int low = nums[0];
      int high = nums[0];
      int i = 0;
      for (i=1;i<nums.size();i++) {
        if (nums[i] == high + 1) {
          high++;
        } else {
          if (high == low) {
            //single number
            res.push_back(to_string(low));
          } else {
            res.push_back(to_string(low) + "->" + to_string(high));
          }
          high = low = nums[i];
        }
      }
     res.push_back(low == high ? to_string(low) : to_string(low) + "->" + to_string(high));
      return res;
    }
};
