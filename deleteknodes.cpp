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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p1 = head;
        ListNode* current = head;
        ListNode* nxt = NULL;
        ListNode* prev = NULL;
        int i = 0;
        while(p1){
            p1=p1->next;
            i++;
        }
        int n = i/k;
        if(n==0)
            return head;
        if(head == NULL)
            return head;
        int count = 0;
        while(current && count<k){
            nxt = current->next;
            current->next = prev;
            prev = current;
            current = nxt;
            count++;
        }
        if(nxt!=NULL)
            head->next = reverseKGroup(nxt,k);
        return prev;
    }
};
