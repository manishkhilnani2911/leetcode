/*
 Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
 */
class Solution {
  //Fa_Am_Bl_Go_Mi_Sn_In_Ali
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> presum;//(nums.size(),0); // map to store sum and its count
      //we will calculate the sum till ith location and for each sum we will check if sum-k was seen in the map
      //eg [1,1,1] at first location we save 1 in the map
      //at the third location we get a sum of 3 and we search for 3-2(k==2) in the map this means that if a sum of 1 was present earlier then
      //from after that location we can get a sum of 2 till the current location
        int sum = 0; //to store the sum upto the ith number
        int res = 0;
        for (int i=0; i<nums.size();i++) {
          sum += nums[i];
          if (sum == k) {
            res++;
          }
          if (presum.find(sum-k) != presum.end()) {
            //cout<<"found::"<<sum-k<<"\n";
            res += presum[sum-k];
          }
          {
            //cout<<"inserting::"<<sum<<"\n";
            presum[sum]++;
          }
        }
        return res;
    }
};
