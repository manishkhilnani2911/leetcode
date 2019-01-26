/*Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3*/
class Solution {
  //Sa_Go_Ci_Am
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *temp1 = head;
        while(temp1){
            if(temp1->next!=NULL && temp1->val == temp1->next->val){
                cout<<"here\n";
                ListNode * temp = temp1;
                while(temp1 && temp1->val == temp->val){
                    cout<<"here1\n";
                    //cout<<&temp<<" "<<&temp1<<"\n";
                    cout<<temp1->val<<"\n";
                    temp1=temp1->next;
                }
                if(temp1 == NULL){
                    cout<<"here2\n";
                    temp->next = NULL;
                    break;
                }
                temp->next = temp1;
                temp = temp->next;
            }
            else
                temp1=temp1->next;
        }
        return head;
    }
};
