/*Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.*/
class Solution {
  //Go_Ub_Fa_Bl_Ad
  unordered_map<string, unordered_map<string,double>> gr;  //to store graph in form of adjacency list
  vector<double> res;
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        //create the map from the given equations
        for (int i=0;i<equations.size();i++) {
          gr[equations[i].first].insert(make_pair(equations[i].second,values[i]));  // a --2--> b
          gr[equations[i].second].insert(make_pair(equations[i].first,1/values[i]));  // b --(1/2)-->a
        }

      //for each of the queries we have to find a path from the first value to the second value in the graph and keep on multiplying their weights
        for (auto i : queries) {
          unordered_set<string> visited;
          //check if both the query variables are the same and they were present in the equations(present in the graph)
            //do a dfs from first to second multiplying all the weights of the edges traversed to reach the destination
            double tmp = dfs(i.first,i.second,visited);
            if (tmp) {
              res.push_back(tmp);
            } else {
              res.push_back(-1.0);
            }
          }
        return res;
    }

  double dfs(string source, string dest, unordered_set<string>& visited) {
    //if destination is in source adjacency list that means we have a path from source to dest, just return the weigh of the path
    if (gr[source].find(dest) != gr[source].end()) {
      return gr[source][dest];
    }
    visited.insert(source);
    //visit all the nodes in the adjacency list of the source and see if we find the dest
    for (auto i : gr[source]) {
      if (visited.find(i.first) == visited.end()) {
        visited.insert(i.first);
        double tmp = dfs(i.first,dest,visited);
        if (tmp) {
          return tmp*i.second;
        }
      }
    }
    return 0;
  }
};
