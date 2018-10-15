/*Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.*/
class Solution {
  //Fa_Am_Go_Mi_Ap_Nv_Tw_Li_Sn_Eb_Al_Bl_Ya_Air_Ye
public:
    int findKthLargest(vector<int>& nums, int k) {
     priority_queue<int, vector<int>, greater<int>> pq; //min heap
      //ensuring a heap size of k will have the kth element as the top element of the heap at the end of the iteration
      for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};
