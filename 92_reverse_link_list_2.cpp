/*
 Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
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
  //Fa_Bl_Am_Ci_Go_Mi_Ad_Vm_Ya_Ali_Ap
public:
    //! @brief getting to the position from where we need to reverse
    //!        reversing using the standard, prev, curr and next approach
    //!        adding the reversed part to the original list
    ListNode* reverseBetween(ListNode* head, int m, int n) {
      if (m == n)
        return head;
      ListNode* prev = NULL;
      ListNode* Next = NULL;
      ListNode* curr = head;
      ListNode* tempHead = NULL;
      int count = 1;
      bool done = false;
      while(curr) {
        if (count == m) {
          ListNode* curr1 = curr;
          ListNode* prev1 = NULL;
          ListNode* Next1 = NULL;
          ListNode* tempHead = curr1;
          while(curr1 && count<=n){
            Next1 = curr1->next;
            curr1->next = prev1;
            prev1 = curr1;
            curr1 = Next1;
            count += 1;
          }
          if (prev) {
            prev->next = prev1;
          }
          //if the start position was to reverse from the head, then the head
          // of the reversed part becomes the new head;
          if (m == 1) {
            head = prev1;
          }
          tempHead->next = curr1;
          done = true;
        }
        if (done) {
          break;
        }
        //this is used to get to the position from where we need to reverse
        Next = curr->next;
        prev = curr;
        curr = Next;
        count += 1;
      }
      return head;
    }
};
