You are given a binary tree in which each node contains an integer value.

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
3. -3 -> 11

class Solution {
private :
  int count = 0;
  vector<int> total;
public:
    int pathSum(TreeNode* root, int sum) {
      if (!root)
        return 0;
      //insert the element into the vector
      total.push_back(root->val);

      //collect all the nodes in the left sub tree of the current node
      pathSum(root->left,sum);

      //collect all the nodes in the right subtree of the current node
      pathSum(root->right,sum);

      //at the leaf node check for the sum
      int path_sum = 0;
      for(int j = total.size()-1; j>=0; j--) {
        path_sum += total[j];
        if (path_sum == sum) {
          count += 1;
        }
      }
      //remove the current node as it would be the leaf node
      total.pop_back();

      return count;
    }
};
