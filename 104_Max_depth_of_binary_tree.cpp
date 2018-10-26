/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.

*/
class Solution {
public:
    /*int maxDepth(TreeNode* root) {
      if (root == NULL) {
        return 0;
      } else if (!root->left && !root->right) {
        return 1;
      }   
      if (!root->left) {
        return maxDepth(root->right) + 1;
      }
      if (!root->right) {
        return maxDepth(root->left) + 1;
      }
      return max(maxDepth(root->left),maxDepth(root->right)) + 1;
    }*/
    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
      if (root == NULL) {
        return 0;
      } 
      int lefth = maxDepth(root->left);
      int righth = maxDepth(root->right);
      if (lefth > righth) {
        return lefth + 1;
      }
      return righth + 1;
    }
};	
