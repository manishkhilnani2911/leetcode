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
//for each node get the max length of left and right subtree.
//the diameter would be the sum of the pair which has the highest value
class Solution {
  int res;
public:
    int diameterOfBinaryTree(TreeNode* root) {
      if (!root) {
        return 0;
      }
      getMaxDiameter(root);
      return res;
    }
    void getMaxDiameter(TreeNode* root) {
      if (!root) {
        return;
      }
      //get the max length of right and left subtree having the current node as the root
      int ll = getMaxTreeLength(root->left) + 1;
      int rl = getMaxTreeLength(root->right) + 1;
      res = max(res,ll+rl-2);
      getMaxDiameter(root->left);
      getMaxDiameter(root->right);
    }
    int getMaxTreeLength(TreeNode* root) {
      if (!root){
        return 0;
      } else if (!root->right && !root->left) {
        return 1;
      }
      return max(getMaxTreeLength(root->right), getMaxTreeLength(root->left)) + 1;
    }
};
