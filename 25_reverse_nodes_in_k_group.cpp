/*Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  //Ma_Fa_Mi_Am_Pay_Vm_Go_Bl_Ap_Eb
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    //reverses LL with given head and upto length
      ListNode* curr = head;
      ListNode* curr1 = head;
      int count = 0;
      //cout<<curr1->val<<"\n";
      while(curr1) {
        curr1 = curr1->next;
        count++;
        if (count > k) {
          break;
        }
      }
      //cout<<count<<"\n";
      if (count < k) {
        return head;
      }
      ListNode* Next = NULL;
      ListNode* prev = NULL;
      count = 0;
      //reverse the first k nodes
      while(curr && count < k) {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
        count++;
      }
      //if we still have nodes left skip next k and reverse the k nodes after that
      if (Next != NULL) {
        head->next = reverseKGroup(Next,k);
      }
      return prev;
    }
};
