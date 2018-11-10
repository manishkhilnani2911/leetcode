/*We are given head, the head node of a linked list containing unique integer values.

We are also given the list G, a subset of the values in the linked list.

Return the number of connected components in G, where two values are connected if they appear consecutively in the linked list.

Example 1:

Input: 
head: 0->1->2->3
G = [0, 1, 3]
Output: 2
Explanation: 
0 and 1 are connected, so [0, 1] and [3] are the two connected components.
Example 2:

Input: 
head: 0->1->2->3->4
G = [0, 3, 1, 4]
Output: 2
Explanation: 
0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.
Note:

If N is the length of the linked list given by head, 1 <= N <= 10000.
The value of each node in the linked list will be in the range [0, N - 1].
1 <= G.length <= 10000.
G is a subset of all values in the linked list.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  //Go
public:
    int numComponents(ListNode* head, vector<int>& G) {
      int cc = 0; //count of connected components
      unordered_set<int> kk(G.begin(), G.end());
      ListNode* temp = head;
      while(temp) {
        //if we find a value in LL
        if (inG(temp->val,kk)) {
          cc += 1;
          //keep checking the next value till you do not find value in vector, that will be the end of one cc
          while(temp->next && inG(temp->next->val,kk)) {
            temp = temp->next;
          }
        } else {
          temp = temp->next;
        }
      }
      return cc;
    }
    bool inG(int val, unordered_set<int>& G) {
      unordered_set<int>::iterator it;
      //it = find (G.begin(), G.end(), val);
      //if (it != G.end()) {
      if (G.find(val) != G.end()) {
        G.erase(val);
        return true;
      }
      return false;
    }
};
