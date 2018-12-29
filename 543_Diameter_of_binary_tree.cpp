/*Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Fa_Am_Go_Mi_Bl_Ap_Ad_Ali_Sn_Ya_Sa
//for each node get the max length of left and right subtree.
//the diameter would be the sum of the pair which has the highest value
class Solution {
  int res;
public:
    int diameterOfBinaryTree(TreeNode* root) {
      if (!root)
        return 0;
      int lh = getMaxHeight(root->left);
      int rh = getMaxHeight(root->right);
      res = max(res,lh+rh);
      diameterOfBinaryTree(root->left);
      diameterOfBinaryTree(root->right);
      return res;
    }
    int getMaxHeight(TreeNode* root) {
      if (!root)
        return 0;
      int lh = getMaxHeight(root->left);
      int rh = getMaxHeight(root->right);
      if (lh > rh) {
        return lh + 1;
      }
      return rh + 1;
    }
};
//concise soln
class Solution {
  int maxD = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
      if (!root)
        return maxD;
      dfs(root);
      return maxD;
    }
    int dfs(TreeNode* root) {
      if (!root) {
        return 0;
      }
      int l = dfs(root->left);
      int r = dfs(root->right);
      maxD = max(maxD,l+r);
      if (l > r) {
        return l+1;
      }
      return r+1;
    }
};
