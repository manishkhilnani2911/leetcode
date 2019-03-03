/*We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

 

Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)
 

Note:

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000*/
class Solution {
  //Am_Fa_Go
  //add all the elements based on their distances in a minHeap and push the top K elements from the heap to the res vec.
  struct compare {
    bool operator () (const vector<int> &a, const vector<int> &b) {
      //a is the top element of the heap and b is the one you are pushing onto the heap
      //if a > b then b would be top of heap
      return a[0]*a[0] + a[1]*a[1] > b[0]*b[0] + b[1]*b[1];
    }
  };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
      priority_queue<vector<int>, vector<vector<int>>, compare> minHeap(points.begin(),points.end());
      vector<vector<int>> res;
      /*for (auto p : points) {
        minHeap.push(p);
        if (minHeap.size() > K) {
          minHeap.pop();
        }
      }

      while (!minHeap.empty()) {
        res.push_back(minHeap.top());
        minHeap.pop();
      }*/
      for (int i=0;i<K;i++) {
        res.push_back(minHeap.top());
        minHeap.pop();
      }
      return res;
    }
};
