/*
 Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  //Ba_Fa_Mi_Ad_Ya_Ali_Hu_Am_Te
public:
  //trying merge sort for linklist
    ListNode* sortList(ListNode* head) {
      //if only one node or no node, return head
      if (!head || !head->next) {
        return head;
      }
      //divide list into two parts
      ListNode* slow = head;
      ListNode* fast = head;
      while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
      }
      ListNode* lefthead = head;
      ListNode* righthead = slow->next;
      slow->next = NULL;
      //sort left and right halves
      ListNode* L = sortList(lefthead);
      ListNode* R = sortList(righthead);
      //merge and return final list
      return merge(L,R);
    }
    ListNode* merge(ListNode* left, ListNode* right) {
      ListNode* head = new ListNode(0);
      ListNode* headCopy = head;
      while(left && right) {
        if (left->val < right->val) {
          head->next = left;
          left = left->next;
        } else {
          head->next = right;
          right = right->next;
        }
        head = head->next;
      }
      if (left) {
        head->next = left;
      }
      if (right) {
        head->next = right;
      }
      return headCopy->next;
    }
};
