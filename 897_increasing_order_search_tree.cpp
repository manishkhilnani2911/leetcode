/*Given a tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9  
Note:

The number of nodes in the given tree will be between 1 and 100.
Each node will have a unique integer value from 0 to 1000.*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//
class Solution {
  TreeNode* cur = new TreeNode(-1);
  TreeNode* dummy = cur;
public:
    TreeNode* increasingBST(TreeNode* root) {
      //traverse inorder at each node add it to right node of the previous node in the current tree
      inorder(root);
      return cur->right;
    }
    void inorder(TreeNode* root) {
      if (root) {
        inorder(root->left);
        dummy->right = new TreeNode(root->val);
        dummy = dummy->right;
        inorder(root->right);
      }
    }
};
