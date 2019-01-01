/*Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2
Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Go_Al_Am
class Solution {
  int ans = INT_MIN;
public:
    int longestUnivaluePath(TreeNode* root) {
      if (!root)
        return 0;
      dfs(root);
      return ans;
    }
    int dfs(TreeNode* root) {
      if (!root)
        return 0;
      //get the node in the left tree
      int l = dfs(root->left);
      //get nodes in right tree
      int r = dfs(root->right);
      int le = 0,ri = 0;
      //for each node if its child has the same value, this path is a univalue path
      if (root->left && root->val == root->left->val) {
        le = l + 1;
      }
      if (root->right && root->val == root->right->val) {
        ri = r + 1;
      }
      //update the univalue path max value for each root
      ans = max(ans,le+ri);
      return max(le,ri);
    }
};
