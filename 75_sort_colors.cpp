/*
 Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
 */
class Solution {
  //Mi_Fa_Go_Ya_Am_Ub_Or_Po_Bl_Vm_Ap_Ali_Ad_Ye_Te
public:
  /*
  The solution requires the use of tracking 3 positions, the Low, Mid and High.

We assume that the mid is the "Unknown" area that we must evaluate.

If we encounter a 0, we know that it will be on the low end of the array, and if we encounter a 2, we know it will be on the high end of the array.

To achieve this in one pass without preprocessing (counting), we simply traverse the unknown will generating the low and high ends.

Take this example:

Assume our input is: 1 0 2 2 1 0 (short for simplicity).

Running the algorithm by hand would look something like:

    1 0 2 2 1 0
    ^         ^
    L         H
    M

    Mid != 0 || 2
    Mid++

    1 0 2 2 1 0
    ^ ^       ^
    L M       H

    Mid == 0
    Swap Low and Mid
    Mid++
    Low++

    0 1 2 2 1 0
      ^ ^     ^
      L M     H

    Mid == 2
    Swap High and Mid
    High--

    0 1 0 2 1 2
      ^ ^   ^
      L M   H

    Mid == 0
    Swap Low and Mid
    Mid++
    Low++

    0 0 1 2 1 2
        ^ ^ ^
        L M H

    Mid == 2
    Swap High and Mid
    High--

    0 0 1 1 2 2
        ^ ^
        L M
          H

    Mid <= High is our exit case
  */
    void sortColors(vector<int>& nums) {
      int low = 0;
      int mid = 0;
      int high = nums.size();
      if (high == 0)
        return;
      high = high - 1;
      while(mid <= high) {
        if (nums[mid] == 0) {
          //swap nums[mid] and nums[low]
          int temp = nums[low];
          nums[low] = nums[mid];
          nums[mid] = temp;
          mid++;
          low++;
        } else if (nums[mid] == 1) {
          mid++;
        } else if (nums[mid] == 2) {
          //swap mid and high
          int temp = nums[high];
          nums[high] = nums[mid];
          nums[mid] = temp;
          high--;
        }
      }
    }
};

/*
void sortColors(vector<int>& nums) {
      if (nums.size()==0)
        return;
      int z = 0;
      int s = nums.size()-1;
      for (int i=0;i<nums.size();i++) {

        while(nums[i]==2 && i < s) {
          swap(nums[i],nums[s--]);
        }
        while(nums[i] == 0 && i > z) {
          swap(nums[i],nums[z++]);
        }
      }
    }
*/
