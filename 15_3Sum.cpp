/*Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]*/
//Fa_Ad_Ap_Go_Mi_Am_Qu_Bl_Co_Sa_Visa_Ya_Pa_Eb_Ub_Ba_Ali_Air_Ex_Ye_Sq_Li_Vm_Tw

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> res;
      if (nums.size() == 0) {
        return res;
      }
      sort(nums.begin(),nums.end());
      for (int i=0;i<nums.size();i++) {

        //cout<<a<<"\n";
        //if the current number is the same as previous number we have already calculated the triplet for this in the previous
        //iteration so skip this number
        if(i!=0 && nums[i] == nums[i-1]) {
          continue;
        }

        int a = nums[i];
        //two pointer one pointing to the next element and one pointing to the last element
        int j = i + 1;
        int k = nums.size() - 1;

        //cout<<b<<" "<<c<<"\n";
        //cout<<a<<" "<<nums[b]<<" "<<nums[c]<<"\n";
        while (j < k) {
          int b = nums[j];
          int c = nums[k];
          if (a+b+c == 0) {
            //found a triplet
            vector<int> temp;
            temp.push_back(a);
            temp.push_back(b);
            temp.push_back(c);
            res.push_back(temp);
            //increment k to found more combinations
            --k;
            //removing duplicates
            while(j < k && nums[k] == nums[k+1]) --k;
          } else if (a+b+c < 0) {
            ++j;
          } else {
            --k;
          }
        }
      }
      return res;
    }
};
