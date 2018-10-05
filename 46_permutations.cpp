/*
 
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
class Solution {
  //Go_Li_Fa_Am_Mi_Wa_Ad_Pa_Ya_Sa_Air_Tw_Ap_Eb_Vm
  vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
      int size = nums.size();
      if(size==0)
        return res;
      permute(nums,0,nums.size());
      return res;
    }
    void permute(vector<int> &nums, int start, int end){
      if (start == end) {
        res.push_back(nums);
        return;
      }
      //for 123 we swap 1 with 2 and which calls recur again and we swap 1 and 3 in it to get 213,231 similarly we do for remaining 4
      for (int i = start; i<end;i++) {
        swap(nums[start],nums[i]);
        permute(nums,start+1,end);
        swap(nums[start],nums[i]);
      }
    }
};
