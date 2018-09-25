/*Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]*/
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
  //Mi_Am_Fa_Ub_Go
public:
  //reverse the breadth first array alternatively.
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> res;
      if (!root) {
        return res;
      }
      queue<TreeNode*> q;
      q.push(root);
      bool from_left = false;;
      while(!q.empty()) {
        vector<int> tempv;
        int size = q.size();
        cout<<size<<"\n";
        while(size) {
          TreeNode* temp = q.front();
          q.pop();
          tempv.push_back(temp->val);
          if (temp->left) q.push(temp->left);
          if (temp->right) q.push(temp->right);
          size--;
        }
        if (!from_left)
          res.push_back(tempv);
        else {
          reverse(tempv.begin(),tempv.end());
          res.push_back(tempv);
        }
        tempv.clear();
        from_left = !from_left;
      }
      return res;
    }
};
