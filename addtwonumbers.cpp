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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        //cout<<head->val<<endl;
        ListNode* head1 = head;
        int result = 0,carry = 0,sum = 0;
        while(l1 || l2){
            result = (l1?l1->val:0)+(l2?l2->val:0)+carry;
            sum = result % 10;
            carry = result / 10;
            //cout<<result<<" "<<sum<<" "<<carry<<" "<<endl;
            ListNode* node = new ListNode(sum);
            head->next = node;
            //cout<<head->next->val<<endl;
            //cout<<head1->next->val<<endl;
            l1=l1?l1->next:l1;
            l2=l2?l2->next:l2;
            head = head->next;
        }
        if(carry!=0){
            head->next = new ListNode(carry);
        }
        return head1->next;
    }
};