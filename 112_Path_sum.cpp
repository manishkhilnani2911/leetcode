/*Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.*/


class Solution {
public:
    
    bool hasPathSum(TreeNode* root, int sum) {
      //we have reached a leaf node or the root is empty
      //return false in such a case
      if (!root) 
        return false;
      //found a leaf node with the needed sum   	
      if (root->val == sum && !root->right && !root->left) {
        return true;  
      } else 
      //recur in the left and right sub tree, subtracting the root value
      //from the sum
        return hasPathSum(root->right, sum-root->val) || hasPathSum(root->left, sum-root->val);   
      
    }
};
