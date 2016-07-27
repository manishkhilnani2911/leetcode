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
           ListNode* removeElements(ListNode* head, int val) {
	   while(head && head->val == val){
	   head=head->next;
	   }
	   if(head == NULL)
	        return head;
	   ListNode* temp = head;
	   while(temp->next){
	        if(temp->next->val == val){
	        temp->next = temp->next->next;
	   }
	        else{
	            temp = temp->next;
	        }
	    }
	    return head;
	 }
	};
