/*
 Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
 */
class NumArray {
  //Fa_Go_Ad
  vector<int> num;
public:
    NumArray(vector<int> nums) {
      //every position in num is the sum from 0 till that position;
      num.push_back(0);
      for(auto i : nums) {
        num.push_back(num.back()+i);
      }
    }

    int sumRange(int i, int j) {
      return num[j+1] - num[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
