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
	//Bl_Fa_Am_Mi_Ad_Go_Ap_Ub_Eb_Ali
public:
    void flatten(TreeNode* root) {
      //1. find the right most child of root's left child
      //2. make roots right child as right child of above found node.
      //3. make roots left child as its right child
      //move root to its right child and perform 1,2,3 again.
      while(root) {
        if (root->left && root->right) {
          TreeNode* l = root->left;
          //getting to the rightmost child of root's left child
          while(l->right) {
            l = l->right;
          }
          //make root's right child as right child of this node
          l->right = root->right;
        }
        //make left child as right child, the right child pointer is not lost because of above
        if (root->left) {
          root->right = root->left;
        }
        root->left = NULL;
        root = root->right;
      }
    }
};

/*class Solution {
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
};*/

