/*
 Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
 */
class Solution {
  //Fa_Am_Mi_Bl_Li_Go_Ap_Ali_Ub_Nv_Ci_Vm_Pay_Ex_Sn_Sa_Ya_Eb_Ad_Ye_Wa
public:
    int search(vector<int>& nums, int target) {
      if (nums.size() == 0) {
        return -1;
      }
      int start = 0;
      int end = nums.size()-1;
      while(start<=end) {
        int mid = start + (end-start)/2;
        //if mid value at any time equals to target return mid index
        if (nums[mid] == target) {
          return mid;
        } else if (nums[mid] >= nums[start]) { //eg array would be 4,5,6,7,0,1,2
          //we are still in the increasing subarray
          if (target >= nums[start] && target < nums[mid]) {
            //target can be found out by a binary search in the array bounded by [start,mid-1]
            end = mid-1;
          } else {
            //we need to again find the array on which binary search needs to be applied to find target
            start = mid+1;
          }
        } else { //eg array would be 4,5,6,-1,0,1,2
          //need to find the pivot index and then do binary search on it
          if (target <= nums[end] && target > nums[mid]) {
            start = mid + 1;
          } else {
            end = mid-1;
          }
        }
      }
      return -1;
    }
};
