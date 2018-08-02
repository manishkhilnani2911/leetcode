/*Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]*/

class Solution {
private :
  vector<int> total;
  vector<vector<int>> res;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
      //base case only hit when tree is empty
      if (!root)
        return res;
      //insert the element into the vector
      total.push_back(root->val);

      //collect all the nodes in the left sub tree of the current node
      if (root->left)
        pathSum(root->left,sum);

      //collect all the nodes in the right subtree of the current node
      if (root->right)
        pathSum(root->right,sum);

      //at the leaf node check for the sum
      if (!root->right && !root->left) {
        int path_sum = 0;
        for(int j = total.size()-1; j>=0; j--) {
          path_sum += total[j];
        }
        if (path_sum == sum) {
          res.push_back(total);
        }
      }
      //remove the current node as it would be the leaf node
      total.pop_back();

      return res;
    }
};
