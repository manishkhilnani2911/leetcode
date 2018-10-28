/*Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.*/
class Solution {
//Fa_Am_Go_Ad_Go
public:
    int minDepth(TreeNode* root) {
      if (root == NULL) {
        return 0;
      } else if (!root->right && !root->left) {
        return 1;
      }
      if (!root->right){
        return minDepth(root->left) + 1;
      }
      if (!root->left) {
        return minDepth(root->right) + 1;
      }
      return min(minDepth(root->right),minDepth(root->left)) + 1;
    }
};
