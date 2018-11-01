/*Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.*/
class Solution {
  //Fa_Ly_Am_Go_Li_Mi_Bl_Ap_Ad_Te
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      unordered_map<int,int> m;
      //to store unique elements
      unordered_set<int> res;
      vector<int> res1;
      for (auto num : nums1) {
        m[num]++;
      }
      //if nums2 is in nums1
      for (auto num : nums2) {
        if (m[num] > 0) {
          res.insert(num);
        }
      }
      for ( auto it = res.begin(); it != res.end(); ++it ) {
        res1.push_back(*it);
      }
      return res1;
    }
};
