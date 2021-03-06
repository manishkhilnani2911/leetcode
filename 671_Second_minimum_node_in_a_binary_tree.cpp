/*Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:
Input: 
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
Example 2:
Input: 
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Li_Mi
//Traverse the graph
//keep track of the first and second smallest value by
//updating first and second at each node
class Solution {
  int first = -1;
  int second = -1;
public:
    int findSecondMinimumValue(TreeNode* root) {
      if (!root)
        return -1;
      first = root->val;
      second = INT_MAX;
      inOrder(root);
      return second == INT_MAX ? -1 : second;
    }
    void inOrder(TreeNode* root) {
      if (!root)
        return;
      inOrder(root->left);
      if (!root->left && !root->right) {
        if (root->val > first) {
          second = min(second,root->val);
        }
      }
      inOrder(root->right);
    }
};
