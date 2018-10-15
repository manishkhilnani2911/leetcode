/*Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.*/
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
    bool isBalanced(TreeNode* root) {
      if (!root)
        return true;
      //get the height of roots subtrees
      int heightdiff = findHeight(root->left) - findHeight(root->right);
      if (abs(heightdiff) > 1) {
        return false;
      }
      //if the root is balanced, check for each left and right subtrees
      if (!isBalanced(root->left) || !isBalanced(root->right)) {
        return false;
      }
      return true;
    }
    int findHeight(TreeNode* root) {
      if (!root) {
        return 1;
      }
      return max(findHeight(root->left),findHeight(root->right)) + 1;
    }
};
