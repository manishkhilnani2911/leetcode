/*
 There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
 */
class Solution {
  //Fa_Am_Go_Mi_In_Bl_Ap_Sn_Ye
  vector<int> res;
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        //same as course scheduler , only difference is that if we can take all the courses we need to return the order
        //in which to take the course which is nothing but a topological sort of the graph
      
      //this will hold the graph 
      vector<unordered_set<int>> graph(numCourses); 
      for (auto courses : prerequisites){
        graph[courses.second].insert(courses.first);
      }
      
      vector<bool> visited(numCourses, false); //keeping track of all the taken courses
      vector<bool> grey(numCourses, false); //keep track of the current visited node
      //start dfs from the first node
      for (int i=0; i<numCourses; i++) {
        //if the node is not visited visit the node and do dfs from each of its connections
        if (!visited[i]) {
          if (hascycle(i,visited,graph,grey)) {
            return vector<int>();
          }
        }  
      }
      reverse(res.begin(),res.end());
      return res;  
    }
  
    bool hascycle(int node, vector<bool>& visited, vector<unordered_set<int>> &graph,vector<bool> &grey){
      visited[node] = true;
      grey[node] = true;
      
      //visits all its neighbours
      for (auto v : graph[node]) {
        //if while visiting any of the neighbours you see an already visited node there is a cycle
        if (grey[v] == true) {
          return true;
        }
        //visit all the neighbours which are not visited yet of node and do a dfs from them
        if (visited[v] == false && hascycle(v,visited,graph,grey)) {
          return true;
        }  
      }
      grey[node] = false;
      res.push_back(node);
      return false;
    }
};
