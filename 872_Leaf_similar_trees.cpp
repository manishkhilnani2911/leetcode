/*Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

Note:

Both of the given trees will have between 1 and 100 nodes.*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//collect all leaf nodes for both the trees doing depth first traversal
class Solution {
  vector<int> leaf1;
  vector<int> leaf2;
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      dfs(root1,leaf1);
      dfs(root2,leaf2);
      return (leaf1 == leaf2);
    }
    void dfs(TreeNode* root, vector<int>& leafNodes) {
      if(!root) {
        return;
      }
      if (!root->left && !root->right) {
        leafNodes.push_back(root->val);
      }
      dfs(root->left, leafNodes);
      dfs(root->right, leafNodes);
    }
};
