/*Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3 */
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
private:
  vector<string> res;
  vector<int> valVec;
  public:
    vector<string> binaryTreePaths(TreeNode* root) {
      if (!root) {
        return res;
      }
      valVec.push_back(root->val);
      //collect the left subtree
      if (root->left) {
        binaryTreePaths(root->left);
      }
      //collect right subtree
      if (root->right) {
        binaryTreePaths(root->right);
      }
      //insert the path into the vector
      if (!root->right && !root->left) {
        string temp;
        int i;
        for (i = 0; i<valVec.size()-1;i++) {
          temp = temp + to_string(valVec[i]) + "->" ;
        }
        temp += to_string(valVec[i]);
        res.push_back(temp);
      }
      valVec.pop_back();
      return res;
    }
};
