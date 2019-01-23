/*Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

*/
class Solution {
	//Fa_Ly_Am_Ad_Ya_Go_Mi_Eb_Ye_Bl_Wa_In_Ap_Ex_Tw_Li_Sn_Ub_Nv
  vector<int> res;
public:
    vector<int> productExceptSelf(vector<int>& nums) {

      int s = nums.size();

      if (s == 0) {
        return res;
      }
      //for each number get the product of all numbers to the left and right of that number
      //res is the product of left and right for each number
      vector<int> left(s,1);
      vector<int> right(s,1);
      vector<int> res(s,1);
      left[0] = 1;
      right[s-1] = 1;
      for (int i=1; i<s; i++) {
        left[i] = left[i-1] * nums[i-1];
      }
      for(int i=s-2; i>=0; i--) {
        right[i] = right[i+1] * nums[i+1];
      }
      for (int i=0;i<s;i++) {
        res[i] = left[i]*right[i];
      }
      return res;
    }
};
