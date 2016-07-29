/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* h1 = head;
        if(h1 == NULL)
            return h1;
        while(h1->next){
            if(h1->next->val == h1->val){
                h1->next = h1->next->next;
            }
            else
                h1 = h1->next;
        }
        return head;
    }
};