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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* h1 = headA;
        ListNode* h2 = headB;
        int n1=0,n2=0,count = 0;
        while(h1){ //counting total nodes in list1
            h1 = h1->next;
            n1++;
        }
        while(h2){ //counting total nodes in list2
            h2=h2->next;
            n2++;
        }
        //trying to get h1 or h2 to a node from which there are equal number of nodes till the end
        if(n1>n2){ 
            while(count<(n1-n2)){
                headA = headA->next;
                count++;
            }
        }
        else if(n2>n1){
            while(count<(n2-n1)){
                headB = headB->next;
                count++;
            }
        }
        while(headA){
            if(headA->val == headB->val)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};