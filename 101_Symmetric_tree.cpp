/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//for each level the extreme right node should be equal to extreme left
//and one node right of extreme right should be equal to one node left of extreme left, we continue moving inwards till we find 
//non equal nodes
//else the tree is symmetric
class Solution {
private:
  queue<TreeNode*> myq;
public:
    bool isSymmetric(TreeNode* root) {
      if (!root) {
        return true;
      }
      myq.push(root->left);
      myq.push(root->right);
      while(!myq.empty()) {
        TreeNode* left_node = myq.front();
        myq.pop();
        TreeNode* right_node = myq.front();
        myq.pop();
        if (!left_node && !right_node) {
          continue;
        }
        if ( !left_node || !right_node || left_node->val != right_node->val) {
          return false;
        }
        myq.push(left_node->left);
        myq.push(right_node->right);
        myq.push(left_node->right);
        myq.push(right_node->left);
      }
      return true;
    }
};
