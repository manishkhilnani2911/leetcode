/*Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6*/
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
  //Fa_Fa_Ya_Am
  int res = 0;
public:
    int countNodes(TreeNode* root) {
      if (!root) {
        return 0;
      }
      int hl = 0;
      int hr = 0;
      TreeNode* l = root;
      TreeNode* r = root;
      while(l) {
        hl++;
        l = l->left;
      }
      while(r) {
        hr++;
        r = r->right;
      }
      //if both heights are equal then we have a perfect binary tree starting at the root
      if (hl == hr) {
        return pow(2,hl)-1;
      }
      //if not then individually process the left and right subtrees
      return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
