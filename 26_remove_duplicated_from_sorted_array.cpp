/*Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.
Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}*/
class Solution {
  //Fa_Go_Mi_Am_Ub_Bl_Ci_Ad_Ya_Vm_Wal_Ap_Ali
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int index = 1, i,temp;
      //start from the first index
        for(i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]){
                temp = nums[i-1];
              //if the current element is equal to prvious element we need to remove the current element and all the successive similar elements
                while(nums[i] == temp){
                    i++;
                }
                if(i>=nums.size())
                    break;
            }
            nums[index]=nums[i];
            index++;
        }
        return index;
    }
};
