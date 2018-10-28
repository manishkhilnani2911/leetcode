/*Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:

Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Example:

Input: root = [4,2,5,1,3], target = 3.714286, and k = 2

    4
   / \
  2   5
 / \
1   3

Output: [4,3]
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?*/
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
  priority_queue<pair<double,int>> max_heap;
  vector<int> res;
public:
    //store the differences in a max_heap
    //extract top k elements from the heap
    vector<int> closestKValues(TreeNode* root, double target, int k) {
      traverse(root,target,k);
      while(!max_heap.empty()) {
        pair<int,double> temp = max_heap.top();
        res.push_back(temp.second);
        max_heap.pop();
      }
      return res;
    }
    void traverse(TreeNode* root, double target, int k) {
      if (root) {
      traverse(root->left,target,k);
      max_heap.push(make_pair(fabs(root->val-target),root->val));
      if (max_heap.size() > k) {
        max_heap.pop();
      }
      traverse(root->right,target,k);}
    }
};
