/*Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//dfs to collect all the nodes in presorder
//make the left child of each node null and make the preOrder
//successor as the right child
class Solution {
  private:
    vector<TreeNode*> v1;
public:
    void flatten(TreeNode* root) {
      dfs(root);
      TreeNode* temp = root;
      for (int i = 1; i<v1.size(); ++i) {
        temp->left = NULL;
        temp->right = v1[i];
        temp = temp->right;
      }
    }
    void dfs(TreeNode* root){
      if (!root) {
        return;
      }
      v1.push_back(root);
      dfs(root->left);
      dfs(root->right);
    }
};
