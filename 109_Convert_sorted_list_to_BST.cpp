/*Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//middle node of the LL becomes the root of the tree,
//left node of the root will be the middle node of the left list and vice versa
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
      if (!head) {
        return NULL;
      }
      if (!head->next)
        return new TreeNode(head->val);
      cout<<"here\n";
      ListNode* prev = NULL;
      ListNode* slow = head;
      ListNode* fast = head;
      while(slow && fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
      }
      if (prev) {
        prev->next = NULL;
      }
      if (prev)
        cout<<"prev::"<<prev->val<<"\n";
      cout<<"head::"<<head->val<<"\n";
      if (slow->next)
        cout<<"slow::"<<slow->next->val<<"\n";

      TreeNode* root = new TreeNode(slow->val);
      root->left = sortedListToBST(head);
      root->right = sortedListToBST(slow->next);
      return root;
    }
};
