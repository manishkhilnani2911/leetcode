/*Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.*/
class Solution {
  //Go_Am_Fa_Ya_Mi_Ub_Ad_li
  vector<int> res;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      if (nums.size() == 0) {
        return res;
      }
      //map to store the count of each element
      unordered_map<int,int> m;
      for (auto i : nums) {
        m[i]++;
      }
      //we insert into max heap each variable and its count based on the count of each element
      priority_queue<pair<int,int>> max_heap;
      for (auto i : m) {
        max_heap.push(make_pair(i.second,i.first));
      }
      //the top k elements of the heap would be the answer
      while(k--) {
        res.push_back(max_heap.top().second);
        max_heap.pop();
      }
      return res;
    }
};
