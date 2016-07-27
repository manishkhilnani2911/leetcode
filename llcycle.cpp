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
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        if(!head || !head->next)
            return false;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};