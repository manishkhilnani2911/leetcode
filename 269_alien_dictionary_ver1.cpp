/*
 There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

Example 1:

Input:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]

Output: "wertf"
Example 2:

Input:
[
  "z",
  "x"
]

Output: "zx"
Example 3:

Input:
[
  "z",
  "x",
  "z"
] 

Output: "" 

Explanation: The order is invalid, so return "".
Note:

You may assume all letters are in lowercase.
You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
 */
class Solution {
  //Air_Fa_Pin_Go_Am_Bl_Tw_Or_Ub_Ap_Mi_Ly_Sn
  typedef unordered_map<char,unordered_set<char>> graph;
  typedef unordered_map<char,int> in;
  string res = "";
  //bool hasCylce(char node, unordered_map<char, unordered_set<char>>& g, vector<bool>& visited, vector<bool>& grey);
public:
  in indegree;
  
    string alienOrder(vector<string>& words) {
      if (words.size() == 0) {
        return "";
      }
      //convert the words vector into a graph
      //do topological search in the graph and return the result
      //return empty string if there is a cycle in the graph
      
      // initialize
      //in indegree;
       for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                char c = words[i][j];
                indegree[c] = 0; 
            }
        }
      
      //converting words into a graph and updating indegree
      graph g = make_graph(words);
      
      //do a topological sort if there is a cycle in the graph return empty string else return the topological order
      vector<bool> visited(indegree.size(), false); //keeping track of all the taken courses
      vector<bool> grey(indegree.size(), false); //keep track of the current visited node
      //start dfs from the first node
      //cout<<"here1\n";
      //for (auto i : g) {
      for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words[i].size(); j++) {
        //if the node is not visited visit the node and do dfs from each of its connections
          if (!visited[words[i][j]-'a']) {
            if (hasCycle(words[i][j],g,visited,grey)) {
              return "";
            }
          }  
        }
      }  
      reverse(res.begin(),res.end());
      return res;
      
      //below part uses indegree to get to the final result
      /*queue<char> q;
      for (auto i : indegree) {
        if (i.second == 0) {
          q.push(i.first);
        }
      }
      //no nodes have indegree 0 we have a cycle in the graph return empty string
      if (q.empty()) {
        return "";
      }
      string ans = "";
      for (int i = 0; i < indegree.size(); i++) {
        if (q.empty()) {
          return "";
        }
        char c = q.front();
        q.pop();
        ans += c;
        for (char neigh : g[c])
          if (!--indegree[neigh])
            q.push(neigh);  
      }
      return ans;*/
    }
  
    bool hasCycle(char node, /*unordered_map<char, unordered_set<char>>&*/graph& g, vector<bool>& visited, vector<bool>& grey) {
      visited[node-'a'] = true;  
      grey[node-'a'] = true;
      
      //visit all the unvisited neighbours of this node
      for (auto i : g[node]) {
        if (grey[i-'a']) {
          return true;
        }
        if (!visited[i-'a'] && hasCycle(i, g, visited, grey)) {
          return true;
        }
      }
      res += node;
      cout<<res<<"\n";
      grey[node-'a'] = false;
      return false;
    }
  
  
    graph make_graph(vector<string>& words) {
      graph g;
      for (int i=0;i<words.size()-1;i++) {
        string word1 = words[i];
        string word2 = words[i+1];
        for (int i=0;i<min(word1.length(),word2.length()); i++) {
          if (word1[i] != word2[i]) {
            //record the first mismatch 
            unordered_set<char> adj = g[word1[i]];
            if (adj.find(word2[i]) == adj.end()) {
              g[word1[i]].insert(word2[i]);
              cout<<word2[i]<<" should come before "<<word1[i]<<"\n";
              //if (indegree.find(word2[i]) != indegree.end())
                indegree[word2[i]]++;
              //else indegree[word2[i]] = 1;
            }
            break;
          }  
        }
      }
      return g;
    }
};
