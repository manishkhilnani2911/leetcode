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
//Go_Mi_Am_Fa_Ad_Al_Pa_Air_Ba_Ci_Or_Bl
class Solution {
public:
    bool isBalanced(TreeNode* root) {
      if (!root)
        return true;
      //get height of each subtree
      int l = getMaxDepth(root->left);
      int r = getMaxDepth(root->right);
      if (abs(l-r) > 1) {
        return false;
      }
      if (!isBalanced(root->left) || !isBalanced(root->right)) {
        return false;
      }
      return true;
    }
    int getMaxDepth(TreeNode* root) {
      if (!root) {
        return 0;
      }
      int l = getMaxDepth(root->left);
      int r = getMaxDepth(root->right);
      if (l>r)
        return l+1;
      return r+1;
    }
};

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
