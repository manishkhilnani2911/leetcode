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
           ListNode* swapPairs(ListNode* head) {
	   ListNode* prev = NULL;
	   ListNode* current = head;
	   ListNode* nxt = NULL;
	   int count = 0;
	   if(head == NULL || head->next == NULL)
		   return head;
	  //reversing first two nodes
	   while(count < 2){
		nxt = current->next;
		current->next = prev;
		prev = current;
		current = nxt;
		count++;
	   }
																		           
	  //calling recursively for the next 2 nodes till we reach the lists end
				           if(nxt != NULL)
		               head->next = swapPairs(nxt);
			                   
				           return prev;
	       }
	 };
