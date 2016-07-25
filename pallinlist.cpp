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
           bool isPalindrome(ListNode* head) {
	   ListNode* slow = head;
	   ListNode* fast = head;
	   //condition for only one node
	   if(head == NULL || head->next == NULL)
	   	return true;
	   //getting slow to the centre of the link list
	   while(fast->next && fast->next->next){
	   //cout<<"h1\n";
           	slow = slow->next;
	   	fast = fast->next->next;
	   }
	  // reversing the other half of link list
	   slow->next = rev(slow->next);
	   slow = slow->next;
	   cout<<head->val<<endl;
	   cout<<slow->val<<endl;
	   //in case of pallindrome the two half should be identical so checking that
	   while(slow){
	   	if(head->val != slow->val)
	  		return false;
	   	head = head->next;
	   	slow = slow->next;
	   }
	   return true;
	   }
	
	ListNode* rev(ListNode* node){
		cout<<"here\n";
		ListNode* prev = NULL;
		ListNode* current = node;
		ListNode* nxt = NULL;
		while(current){
			nxt = current->next;
			current->next = prev;
			prev = current;
			current = nxt;
		}
		cout<<prev->val<<endl;
		return prev;
	}
};
