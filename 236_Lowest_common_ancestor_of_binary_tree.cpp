/*Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself
             according to the LCA definition.
Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree. */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//get the path from the root to both the nodes and store the path in different vectors
//now the one entry before the mismatch will give us the LCS
//the below code works for both if the values are present in the tree or not
//if either of the value if not present , dfs will return false .
//modify the code in the main API to use the bool return from dfs if the nodes are
// not present in the binary tree to begin with
class Solution {
  private:
    vector<TreeNode*> v1;
    vector<TreeNode*> v2;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      dfs(root,p,v1);
      dfs(root,q,v2);
      int i;
      for (i = 0; i<v1.size() && i<v2.size(); ++i) {
        if (v1[i]->val != v2[i]->val){
          break;
        }
      }
      return v1[i-1];
    }
    bool dfs(TreeNode* root, TreeNode* node, vector<TreeNode*> &path) {
      if (!root) {
        return false;
      }
      path.push_back(root);
      if (root->val == node->val) {
        return true;
      }
      if ( (root->left && dfs(root->left,node,path)) ||
           (root->right && dfs(root->right,node,path)) ) {
        return true;
      }
      path.pop_back();
      return false;
    }
};
