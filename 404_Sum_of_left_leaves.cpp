/*Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24. */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Ad_Go_Bl_Fa
class Solution {
  int sum;
public:
    int sumOfLeftLeaves(TreeNode* root) {
      return dfs(root, false);
      return sum;
    }
    void dfs(TreeNode* root, bool val) {
      if (!root) {
        return ;
      }
      //bool val is to tell whether its a right node or left node, left_node == true, else false
      if (!root->left && !root->right) {
        if (val) {
          sum += root->val;
        } 
      }
      dfs(root->left, true);
      dfs(root->right, false);
    }
};
