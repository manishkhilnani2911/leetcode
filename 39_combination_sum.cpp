/*Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]*/
class Solution {
  //Air_Am_Go_Ub_Mi_Ap_Li_Fa_Ba_Ye_Sn_Gr
  vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<int> comb;
      combinationsum(comb,candidates,target,0);
      return res;
    }
    void combinationsum(vector<int>& ans, vector<int>& candidates, int target, int startIndex) {
      if (target == 0) {
        res.push_back(ans);
        return;
      }
      //push the first value on the stack and check if the target is still greater than 0,
      //again push second value on stack, now the function will return and the second value(same as previous one would be popped) from the stack
      for (int i = startIndex; i < candidates.size() && target > 0; i++) {
        ans.push_back(candidates[i]);
        //cout<<"pushing::"<<candidates[i]<<"\n";
        combinationsum(ans,candidates,target-candidates[i],i);
        //cout<<"popping::"<<ans[ans.size()-1]<<"\n";
        ans.pop_back();
      }
    }
};
