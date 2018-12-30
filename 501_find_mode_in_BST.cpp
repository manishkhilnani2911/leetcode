/*Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

For example:
Given BST [1,null,2,2],

   1
    \
     2
    /
   2
 

return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count). */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Go_Sn
//similar to traversing a sorted array and keeping track of the highest frequency number
class Solution {
  vector<int> modes;
  int maxCount = 0;
  int preVal = 0;
  int count = 0;
public:
    vector<int> findMode(TreeNode* root) {
      inOrder(root);
      return modes;
    }
    void inOrder(TreeNode* root) {
      if (root == NULL) {
        return;
      }
      inOrder(root->left);
      if (root->val == preVal) {
        count += 1;
      } else {
        preVal = root->val;
        count = 1;
      }
      if (count > maxCount) {
        modes.clear();
        modes.push_back(root->val);
        maxCount = count;
      } else if (count == maxCount) {
        modes.push_back(root->val);
      }
      inOrder(root->right);
    }
};
