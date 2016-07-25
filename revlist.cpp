class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    ListNode* current = head;
    ListNode* prev = NULL;
    ListNode* nxt = NULL;
    while(current){
	    nxt = current->next;
	    current->next = prev;
	    prev = current;
	    current = nxt;
    }
    return prev;
}
};
