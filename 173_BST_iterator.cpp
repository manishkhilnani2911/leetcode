/*Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
  //Fa_Mi_Or_Am_Go_Ub_Li_Ap
  stack<TreeNode*> s;
  void addIndividualEle(TreeNode* root) {
    while(root) {
      s.push(root);
      root = root->left;
    }
  }
public:
    BSTIterator(TreeNode *root) {
      addIndividualEle(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
      return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
      TreeNode* res = s.top();
      s.pop();
      if (res->right) {
        addIndividualEle(res->right);
      }
      return res->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
