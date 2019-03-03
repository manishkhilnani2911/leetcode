/*
 Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 */
class Solution {
  //Go_Ad_Air_Fa
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mymap;
      //keep adding elements in the map every time an element is already in the map check the difference between the indices of current and already inserted element
        for(int i=0;i<nums.size();i++){
            if( mymap.count(nums[i]) && i-mymap[nums[i]] <=k )
                return true;
            else
                mymap[nums[i]] = i;
        }
        return false;
    }
};
