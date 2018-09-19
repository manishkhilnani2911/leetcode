/*Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42*/
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
  //Fb_Go_Mi_Am
private:
  int max_sum = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
      maxSum(root);
      return max_sum;
    }
    int maxSum(TreeNode* root) {
      if (!root)
        return 0;
      int Lsum = maxSum(root->left);
      //cout<<"Lsum = "<<Lsum<<" at "<<root->val<<"\n";
      int Rsum = maxSum(root->right);
      //cout<<"Rsum = "<<Rsum<<" at "<<root->val<<"\n";
      //if any of the sum is negative, adding that will only lead to lesser number
      Rsum = max(0,Rsum);
      Lsum = max(0,Lsum);
      //for each subtree update the value of max_sum
      max_sum = max(max_sum,Lsum+Rsum+root->val);
      //cout<<max_sum<<"\n";
      //for the subtree we only need to return the sum including any one child which is maximum
      return root->val + max(Lsum,Rsum);
    }
};
