/*
 Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

 



The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
 
 */
class Solution {
  //Mi_Ad_Air_Go_Fa_Am_Al_Ly_Bl_Wa_Ub_Ap
public:
    int maxArea(vector<int>& height) {
      int size = height.size();
      int start = 0;;
      int end = size-1;
      //cout<<start<<" "<<end<<"\n";
      //cout<<min(height[start],height[end])<<" "<<size-1<<"\n";
      int maxarea = 0;
      int temp = 0;
      //we have two position start and end pointing to the start and end of the array
      //we calculate the area based on start at end and move the position which has the smaller height
      while(start<=end) {
        temp = min(height[start],height[end]) * (end-start);
        maxarea = max(maxarea,temp);
        if (height[start] <= height[end] ) {
          start++;
        } else {
          end--;
        }
        temp = 0;
      }
      //cout<<maxarea;
      return maxarea;;
    }
};
