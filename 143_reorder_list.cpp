/*Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  //Fa_Mi_Go_Am_Hu_Bl
public:
    void reorderList(ListNode* head) {
      if (!head || !head->next) {
        return;
      }
      ListNode* slow = head;
      ListNode* fast = head->next;
      //divide list into two parts
      while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
      }
      ListNode* head1 = head;
      ListNode* head2 = slow->next;
      slow->next = NULL;

      //reverse the second half
      ListNode* prev = NULL;
      ListNode* curr = head2;
      ListNode* nn = head2;
      while(curr) {
        nn = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nn;
      }
      head2 = prev;
      //merge two LL's
      while(head1 && head2) {
        curr = head1->next;
        head1->next = head2;
        head1 = head2;
        head2 = curr;
      }
    }
};
