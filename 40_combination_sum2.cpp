/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]*/
class Solution {
  //Ub_Mi_Li_Sn_Ub_Am
  vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      vector<int> comb;
      sort(candidates.begin(),candidates.end());
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
        if (i == startIndex || candidates[i] != candidates[i-1]) {
          ans.push_back(candidates[i]);
          //cout<<"pushing::"<<candidates[i]<<"\n";
          combinationsum(ans,candidates,target-candidates[i],i+1);
          //cout<<"popping::"<<ans[ans.size()-1]<<"\n";
          ans.pop_back();
        }
      }
    }
};
