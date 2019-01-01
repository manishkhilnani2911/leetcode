/*
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
 */
class Solution {
  //Ly_Am_Fa_Bl_Go_Mi_Air_Ub_Ap_Ad_Nv_Or_Sn_Ali_Tw_Eb_In_Ba_Trip_Hua
public:
  /*
  Algorithm

Find maximum height of bar from the left end upto an index i in the array left_max.
Find maximum height of bar from the right end upto an index i in the array right_max.
Iterate over the \text{height}height array and update ans:
Add min(max_left[i],max_right[i])−height[i] to ansans
  */
    int trap(vector<int>& height) {
      if (height.size() == 0) {
        return 0;
      }
      int ans = 0;
      vector<int> left(height.size(),0);
      vector<int> right(height.size(),0);
      left[0] = height[0];
      right[height.size()-1] = height[height.size()-1];
      for (int i=1;i<height.size();i++) {
        left[i] = max(left[i-1],height[i]);
        //cout<<left[i]<<" ";
      }
      cout<<"\n";
      for(int i=height.size()-2;i>=0;i--) {
        right[i] = max(right[i+1],height[i]);
        //cout<<right[i]<<" ";
      }
      for(int i=1;i<height.size()-1;i++) {
        ans += min(left[i],right[i]) - height[i];
      }
      return ans;
    }
};
