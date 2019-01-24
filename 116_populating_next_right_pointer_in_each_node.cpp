/*Given a binary tree

struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space for this problem.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
Example:

Given the following perfect binary tree,

     1
   /  \
  2    3
 / \  / \
4  5  6  7
After calling your function, the tree should look like:

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \  / \
4->5->6->7 -> NULL*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
//if the current node has a left child, the next pointer of left child will point to the right child
//if the current node has a right child then the next pointer of the right child will point to the left child of currents next node if it has one otherwise NULL
class Solution {
	//Bl_Mi_Fa_Go_Am_Ap_Nu_Vm_Ub
public:
    void connect(TreeLinkNode *root) {
      if (!root)
        return;
      root->next = NULL;
      connectTree(root);
    }
    void connectTree(TreeLinkNode* root){
      if (!root)
        return;
      if (root->left){
        root->left->next = root->right;
      }
      if (root->right){
        root->right->next = root->next ? root->next->left : NULL;
      }
      connectTree(root->left);
      connectTree(root->right);
    }
};
