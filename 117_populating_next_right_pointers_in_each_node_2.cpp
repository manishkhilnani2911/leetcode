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
Example:

Given the following binary tree,

     1
   /  \
  2    3
 / \    \
4   5    7
After calling your function, the tree should look like:

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \    \
4-> 5 -> 7 -> NULL*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
//O(1) space solution
//for the current node create a linklist for the current node's children.
class Solution {
public:
    void connect(TreeLinkNode *root) {
      TreeLinkNode* head = root;
      while(head){
        TreeLinkNode* currHead = new TreeLinkNode(0);
        TreeLinkNode* currTail = currHead;
        for(TreeLinkNode* node = head; node!=NULL; node = node->next){
          if (node->left){
            currTail->next = node->left;
            currTail = currTail->next;
          }
          if (node->right){
            currTail->next = node->right;
            currTail = currTail->next;
          }
        }
        head = currHead->next;
      }
    }
};

