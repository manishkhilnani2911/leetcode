/*Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
Note: The length of given array won't exceed 10000.*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
      vector<int> res(nums.size(),-1);
      stack<int> s;
      //put all the indexes onto the stack to smaller elements on the top
      for (int i=nums.size()-1;i>=0;i--) {
        s.push(i);
      }
      //now start looking for next greater element by looking at the elements from right to left
      //this will simulate a circular array, as we will pop indexes from 0 to n-1 while looking for next greater element for index n-1 to 0
      for (int i=nums.size()-1;i>=0;i--) {
        res[i] = -1;
        while (!s.empty() && nums[s.top()] <= nums[i]) {
          s.pop();
        }
        if (!s.empty()) {
          res[i] = nums[s.top()];
        }
        s.push(i);
      }
      return res;
    }
};
