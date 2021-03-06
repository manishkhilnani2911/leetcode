/*You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11 */

class Solution {
  //Fb_Mi_Qu_Go
private :
  int count = 0;
public:
    int pathSum(TreeNode* root, int sum) {
      if (!root) {
        return 0;
      }
      //find if there is any path starting from root that has the path sum equal to sum
      dfs(root,sum);
      //get path sum from every node
      pathSum(root->left,sum);
      pathSum(root->right,sum);
      return count;
    }
    void dfs(TreeNode* root, int sum) {
      if (!root) {
        return;
      }
      if (root->val == sum) {
        count += 1;
      }
      dfs(root->left,sum-root->val);
      dfs(root->right,sum-root->val);
    }
};
