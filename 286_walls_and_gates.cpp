/*You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Example: 

Given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4*/
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
      queue<pair<int,int>> q;
      for (int i=0;i<rooms.size();i++) {
        for (int j=0;j<rooms[i].size();j++) {
          if (rooms[i][j] == 0) {
            q.push(make_pair(i,j));
          }
        }
      }
      vector<pair<int,int>> neighbours = {{1,0},{-1,0},{0,1},{0,-1}};
      while (!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        //do a bread first search from the gates and reach out to the next possible room
        //if the room has not been visited yet add the distance and add its neightbours to the queue
        //nothing to be done in case of a wall, or if the room is not infinite value(that means its distance has been updated)
        int x = cur.first;
        int y = cur.second;
        for (auto nei : neighbours) {
          int row = x + nei.first;
          int col = y + nei.second;
          if (row < 0 || row >= rooms.size() || col < 0 || col >= rooms[0].size() || rooms[row][col] <= rooms[x][y]) {
            continue;
          }
          rooms[row][col] = rooms[x][y] + 1;
          q.push(make_pair(row,col));
        }
      }
    }
};
