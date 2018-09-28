/*Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//visit the right most node in each level first
class Solution {
	//Fa_Am_Ap_Ad_Ma_Li_Go_Air
  int max_level = -1;
  vector<int> res;
public:
    vector<int> rightSideView(TreeNode* root) {
      if (!root) {
        return res;
      }
      rightViewUtil(root,0);
      return res;
    }
    void rightViewUtil(TreeNode* root, int level) {
      if (!root)
        return;
      if (level > max_level) {
        res.push_back(root->val);
        max_level = level;
      }
      rightViewUtil(root->right,level+1);
      rightViewUtil(root->left,level+1);
    }
};
