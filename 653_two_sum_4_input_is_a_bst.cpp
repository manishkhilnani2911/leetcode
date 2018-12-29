/*Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Am_Go_Fa_Sa
class Solution {
  //can also use unordered_set
  unordered_map<int,int> m;
  bool res = false;
public:
    bool findTarget(TreeNode* root, int k) {
      if (!root) {
        return false;
      }
      dfs(root,k);
      return res;
    }
    void dfs(TreeNode* root, int k) {
      if (root) {
        dfs(root->left,k);
        //find in map if present mark res to true;
        if (m.find(root->val) != m.end()) {
          //found in map
          res = true;
        } else {
          //insert k-val into the map;
          m.insert({k-root->val,1});
        }
        dfs(root->right,k);
      }
    }
};
