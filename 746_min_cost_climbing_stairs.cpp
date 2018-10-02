/*On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
Note:
cost will have a length in the range [2, 1000].
Every cost[i] will be an integer in the range [0, 999].*/
class Solution {
  //Am
public:
    int minCostClimbingStairs(vector<int>& cost) {
      int size = cost.size();
      vector<int> mincost(size,0);
      for (int i =0; i<size;i++){
        mincost[i] = 0;
      }
      mincost[0] = cost[0];
      mincost[1] = cost[1];
      for (int i = 2; i<size; i++){
        //cost of reaching a step would be the minimum of reaching current step -1 step or current step -2 step.
        mincost[i] = cost[i] + min(mincost[i-1],mincost[i-2]);
      }
      //we can reach the top by reaching the top-1 or top-2 step, so return the minimum of last two steps cost
      int res = min(mincost[size-1],mincost[size-2]);
      return res;
    }
};
