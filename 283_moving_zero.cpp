/*
 Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
 */
class Solution {
  //Fa_Bl_Go_Sap_Ap_Mi_Eb_Ub_Wa_Ly_Am_Pa_Ba_Ya_Or
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        cout<<len<<endl;
        int shift = 0;
        int i;
        for(i=0;i<len;i++){
            if(nums[i] == 0)
                shift++;
            else if(nums[i] != 0)
                nums[i-shift] = nums[i];
        }
        for(i=len-shift;i<len;i++){
            nums[i] = 0;
        }
    }
};
