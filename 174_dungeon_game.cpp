/*The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

 

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)
 

Note:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.*/
class Solution {
  //Mi_Ad
public:
  /*
  We can solve this problem through bottom-up table filling dynamic programing technique.

To begin with, we should maintain a 2D array dp of the same size as the grid, where dp[i][j] represents the minimum points that guarantees the continuation of the journey to destination before entering the cell (i, j). It’s but obvious that dp[0][0] is our final solution. Hence, for this problem, we need to fill the table from the bottom right corner to left top.
Now, let us decide minimum points needed to leave cell (i, j) (remember we are moving from bottom to up). There are only two paths to choose: (i+1, j) and (i, j+1). Of course we will choose the cell that the player can finish the rest of his journey with a smaller initial points. Therefore we have: min_Points_on_exit = min(dp[i+1][j], dp[i][j+1])
Now we know how to compute min_Points_on_exit, but we need to fill the table dp[][] to get the solution in dp[0][0].

How to compute dp[i][j]?
     The value of dp[i][j] can be written as below.

dp[i][j] = max(min_Points_on_exit – points[i][j], 1)


Let us see how above expression covers all cases.

If points[i][j] == 0, then nothing is gained in this cell; the player can leave the cell with the same points as he enters the room with, i.e. dp[i][j] = min_Points_on_exit.
If dp[i][j] < 0, then the player must have points greater than min_Points_on_exit before entering (i, j) in order to compensate for the points lost in this cell. The minimum amount of compensation is " – points[i][j] ", so we have dp[i][j] = min_Points_on_exit – points[i][j].
If dp[i][j] > 0, then the player could enter (i, j) with points as little as min_Points_on_exit – points[i][j]. since he could gain “points[i][j]” points in this cell. However, the value of min_Points_on_exit – points[i][j] might drop to 0 or below in this situation. When this happens, we must clip the value to 1 in order to make sure dp[i][j] stays positive:
dp[i][j] = max(min_Points_on_exit – points[i][j], 1).
Finally return dp[0][0] which is our answer.
  */
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
      int row = dungeon.size();
      if (row == 0)
        return 0;
      int col = dungeon[0].size();
      //this will store the health of the awarrior before entering index(i,j) to ensure it can leave that index without dying(health<=0)
      vector<vector<int>> health(row,vector<int>(col,0));
      //for the last element if the last index at dungeon is positive we can enter it with 1 health
      //if it is negative then we need -value + 1 to remain at 1 health after entering that index
      health[row-1][col-1] = dungeon[row-1][col-1] > 0 ? 1 : abs(dungeon[row-1][col-1]) + 1;
      //cout<<"here1\n";
      //need to fill up last row of the health array from back to front
      for (int i=col-2; i>=0;i--) {
        health[row-1][i] = max(1,health[row-1][i+1] - dungeon[row-1][i]);
        cout<<health[row-1][i]<<" ";
      }
      cout<<"\n";
      //need to fill up last col of the health array from back to front
      for (int i=row-2; i>=0;i--) {
        health[i][col-1] = max(1,health[i+1][col-1] - dungeon[i][col-1]);
        cout<<health[i][col-1]<<" ";
      }
      cout<<"\n";
      for (int rr = row-2;rr>=0;rr--){
        for(int cc= col-2;cc>=0;cc--) {
          //if (dungeon[rr][cc] >= 0) {
            int poe = min(health[rr+1][cc],health[rr][cc+1]);
          //} else {
            health[rr][cc] = max(1,poe - dungeon[rr][cc]);
         }
          //out<<health[rr][cc]<<" ";
        }
        cout<<"\n";
      return health[0][0];
    }
};
