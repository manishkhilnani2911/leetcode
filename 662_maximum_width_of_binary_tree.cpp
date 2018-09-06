/*Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:
Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:
Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:
Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:
Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Note: Answer will in the range of 32-bit signed integer.*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//assign numbers to each node on each level, the left most node starting from 0,1,2,3 and so on.
//for each level the width would be the difference between these numbers.
//the max width of the tree would be the max width among all levels
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
      if (!root){
        return 0;
      }
      int maxWidth = 0;
      queue<pair<TreeNode*,int>> q;
      q.push(make_pair(root,0));
      while(!q.empty()){
        int size = q.size();
        int left, right;
        for(int i=0;i<size;++i){
          pair<TreeNode*,int> node = q.front();
          q.pop();
          if(i==0){
            left = node.second;
          }
          if (i==size-1){
            right = node.second;
          }
          if (node.first->left){
            q.push(make_pair(node.first->left,2*node.second));
          }
          if (node.first->right){
            q.push(make_pair(node.first->right,node.second*2+1));
          }
        }
        maxWidth = max(maxWidth,(right-left+1));
      }
      return maxWidth;
    }
};
