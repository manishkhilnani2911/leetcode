/*Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//starting from each node see if the subtree is the same as the tree starting from a node in s
//use the algo for same tree
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
      if(s->left && s->right)
            return isSimilarTree(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);
        if(s->left && !s->right)
            return isSimilarTree(s,t) || isSubtree(s->left,t);
        if(!s->left && s->right)
            return isSimilarTree(s,t) || isSubtree(s->right,t);
        return isSimilarTree(s,t);
    }
    bool isSimilarTree(TreeNode* root1, TreeNode* root2) {
      //cout<<root1->val<<" "<<root2->val<<"\n";
      if (!root1 && !root2){
        return true;
      }
      if (!root1  || !root2) {
        return false;
      }
      if (root1->val == root2->val) {
        return (isSimilarTree(root1->left,root2->left) && isSimilarTree(root1->right,root2->right));
      } else {
        return false;
      }
      return true;
    }
};
