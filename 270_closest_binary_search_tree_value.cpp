/*Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:

Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
Example:

Input: root = [4,2,5,1,3], target = 3.714286

    4
   / \
  2   5
 / \
1   3

Output: 4*/
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
  //Fa_Am_Mi_Li_Go_Eb_Sn
  double min_diff = INT64_MAX;
  int val;
public:
    int closestValue(TreeNode* root, double target) {
      //traverse the tree and get the difference from each node, the value with minimum difference is tha answer
      if (!root->left && !root->right) {
        return root->val;
      }
      traverse(root,target);
      return val;
    }
    void traverse(TreeNode* root, double target) {
      if (root) {
        traverse(root->left,target);
        double res = root->val;
        //cout<<res<<" "<<abs(res-target)<<"\n";
        if (abs(res-target) < min_diff) {
          val = root->val;
          min_diff = abs(res-target);
          cout<<val<<"\n";
        }
        traverse(root->right,target);
      }
    }
};
