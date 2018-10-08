/*
 There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: 2, [[1,0]] 
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/
 class Solution {
  //Am_Mi_Fa_Go_Ub_In_Ye_Or_Bl_Ya_Ap
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
      //the problem is same as finding a cycle in a directed graph
      //this will hold the graph 
      //cout<<"here2\n";
      vector<unordered_set<int>> graph(numCourses); 
      for (auto courses : prerequisites){
        graph[courses.second].insert(courses.first);
      }
      
      vector<bool> visited(numCourses, false); //keeping track of all the taken courses
      vector<bool> grey(numCourses, false); //keep track of the current visited node
      //start dfs from the first node
      //cout<<"here1\n";
      for (int i=0; i<numCourses; i++) {
        //if the node is not visited visit the node and do dfs from each of its connections
        if (!visited[i]) {
          if (hascycle(i,visited,graph,grey)) {
            return false;
          }
        }  
      }
      return true;  
    }
  
    bool hascycle(int node, vector<bool>& visited, vector<unordered_set<int>> &graph,vector<bool> &grey){
      visited[node] = true;
      grey[node] = true;
      //cout<<"here\n";
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
      return false;
    } 
};
