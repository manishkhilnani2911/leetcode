/*
 Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
 */
class Solution {
  //Fa_Go_Mi_Am_Ub_Qu_Sa_Ap_Ad_Ru_Li_Air
  /*
  Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, the permutation is sorted in descending order, just reverse it to ascending order and we are done. For example, the next permutation of [3, 2, 1] is [1, 2, 3].
Find the largest index l greater than k such that nums[k] < nums[l].
Swap nums[k] and nums[l].
Reverse the sub-array from nums[k + 1] to nums[nums.size() - 1].
  */
public:
    void nextPermutation(vector<int>& nums) {
      int n = nums.size();
      int i;
      for (i=n-2;i>=0;i--) {
        if (nums[i] < nums[i+1]) {
          //first decreasing number
          break;
        }
      }
      if (i<0) {
        reverse(nums.begin(),nums.end());
        return;
      }
      int j;
      for (j=n-1;j>i;j--) {
        if (nums[j] > nums[i]) {
          break;
        }
      }
      swap(nums[i],nums[j]);
      reverse(nums.begin()+i+1,nums.end());
      return;
    }
};
