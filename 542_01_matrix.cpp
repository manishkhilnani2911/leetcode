/*
 Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1: 
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2: 
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
 
 */
class Solution {
  //Go_Am_Mi
 public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
      int row = matrix.size();
      if (row == 0) {
        return vector<vector<int>>(0, vector<int>(0));
      }
      int col = matrix[0].size();
      vector<vector<int>> dist (row, vector<int>(col));
      queue<pair<int,int>> q;
      //do a bfs from from each of the 0, if the nearest element is not 0 and (dist[nearx][neary] > dist[x][y] + 1)
      //then update the distance of that element to dist[x][y] + 1
      //add that element in the queue,
      //keep doing bfs till the queue is empty
      for (int i = 0; i<row; i++) {
        for (int j=0;j<col;j++) {
          if (matrix[i][j] == 0) {
            dist[i][j] = 0;
            q.push(make_pair(i,j));
          } else {
            dist[i][j] = INT_MAX;
          }
        }
      }
      vector<pair<int,int>> neigh = {{1,0}, {-1,0}, {0,1}, {0,-1}};
      pair<int,int> temp;
      while (!q.empty()) {
        temp = q.front();
        q.pop();
        for (auto n : neigh) {
          int rr = temp.first + n.first;
          int cc = temp.second + n.second;
          if (rr < 0 || rr >= row || cc < 0 || cc >= col ) {
            continue; //out of bounds
          }
          if (dist[rr][cc] > dist[temp.first][temp.second] + 1) {
            //still hasnt been updated, distance is INT_MAX still
            dist[rr][cc] = dist[temp.first][temp.second] + 1;
            q.push(make_pair(rr,cc));
          }
        }
      }
      return dist;
    }
};
