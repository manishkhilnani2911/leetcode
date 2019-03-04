/*Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

 


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

 


The largest rectangle is shown in the shaded area, which has area = 10 unit.

 

Example:

Input: [2,1,5,6,2,3]
Output: 10*/
class Solution {
  //Am_Go_Mi_Ad_Fa_Bl_Tw_Or
public:
    int largestRectangleArea(vector<int>& heights) {
      heights.push_back(0);
      int i = 0;
      int size = heights.size();
      stack<int> s;
      int max_area = 0;
      for(i=0;i<size;i++) {
        //pop the elements from the top of stack till the top element is greater than the current height
        //for each popped element calculate the area till that element
        //for each popped height the next element on the stack would be smaller than the popped element otherwise it would have been popped
        //so from the start of that element to the current popped element calculate the area
        //eg 2,1,5,6,0
        //for each element we know the next smallest elements index on the left(next element on stack, 0 if empty) and on the right(current index)  knowing these element we can calculate the area wrt this element
        while(s.size()>0 && heights[i] <= heights[s.top()]) {
          int curr_top = s.top();
          s.pop();
          int side1 = heights[curr_top];
          int temp = s.empty() ? -1 : s.top();
          int side2 = i-temp-1;
          int current_top_area = side1*side2;
          max_area = max(max_area,current_top_area);
        }
        s.push(i);
      }
      return max_area;
    }
};
