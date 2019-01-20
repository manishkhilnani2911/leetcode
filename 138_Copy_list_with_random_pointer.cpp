/*A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
  //Bl_Mi_Am_Go_Fa_Ad_Eb_Ali_Li_Ap_Vm_Ye_Ub_Ya_Vi_Cis
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
      if (!head) {
        return NULL;
      }

      //map to store old->new relationship
      unordered_map<RandomListNode* , RandomListNode*> visited;
      RandomListNode* temp = head;
      RandomListNode* dummy = new RandomListNode(-1);
      RandomListNode* new_head = dummy;

      while(head) {
        if (visited.find(head) != visited.end()) {
          new_head->next = visited[head];
        } else {
          new_head->next = new RandomListNode(head->label);
          visited.insert(pair<RandomListNode*, RandomListNode*>(head,new_head->next));
        }
        if (head->next && visited.find(head->next) != visited.end()) {
          new_head->next->next = visited[head->next];
        } else if (head->next) {
          new_head->next->next = new RandomListNode(head->next->label);
          visited.insert(pair<RandomListNode*, RandomListNode*>(head->next,new_head->next->next));
        }
        if (head->random && visited.find(head->random) != visited.end()) {
          new_head->next->random = visited[head->random];
        } else if (head->random) {
          new_head->next->random = new RandomListNode(head->random->label);
          visited.insert(pair<RandomListNode*, RandomListNode*>(head->random,new_head->next->random));
        }
        head = head->next;
        new_head = new_head->next;
      }
      return dummy->next;
    }
};
