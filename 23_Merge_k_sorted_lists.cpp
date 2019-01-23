/*Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  //Fa_Am_Go_Mi_Bl_Or_Ad_Li_Ap_Vm_Wa_Sa_Ub_Ali_Eb_In_Ly_Air_Pa_Dr_Zill_Ya_Sn_Tw
  struct compare {
    bool operator() (ListNode* l, ListNode* r) {
      return l->val > r->val;
    }
  };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

      if (lists.size() == 0) {
        return NULL;
      }
      priority_queue<ListNode *, vector<ListNode*>, compare> min_heap;
      for (auto n : lists) {
        //insert top three elements of the list in min heap
        if (n)
          min_heap.push(n);
      }
      if (min_heap.size() == 0) {
        return NULL;
      }
      ListNode* head = new ListNode(-1);
      ListNode* temp = head;
      while(!min_heap.empty()) {
        //top element is the least in min_heap. Remove it. Add to the final list. push its next element onto the heap if present
        temp->next = min_heap.top();
        temp = temp->next;
        if (min_heap.top()->next) {
          min_heap.push(min_heap.top()->next);
        }
        min_heap.pop();
      }
      return head->next;
    }
};
