/*Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//do level order traversal
//for each level find average and add in res, simple!
class Solution {
private:
  vector<double> res;
  public:
    vector<double> averageOfLevels(TreeNode* root) {
      if (!root) {
        return res;
      }
      queue<TreeNode*> myq;
      myq.push(root);
      while(!myq.empty()) {
        int size = myq.size();
        double sum;
        TreeNode* temp;
        int level_size = size;
        while (size) {
          temp = myq.front();
          myq.pop();
          sum += temp->val;
          size -= 1;
          if (temp->left) {
            myq.push(temp->left);
          }
          if (temp->right) {
            myq.push(temp->right);
          }
        }
        res.push_back(sum/level_size);
        size = myq.size();
        sum = 0;
      }
      return res;
    }
};
