/*Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
Note:
The size of the given array will be in the range [1,1000].*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
//Fa_Mi
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      return construct(nums,0,nums.size());
    }
    TreeNode *construct(vector<int>& nums, int start, int end) {
      if (start == end) { //for empty nums start= 0,end = 0
        return NULL; //no tree is possible
      }
      //get the maxindex from nums
      int max_index = getMaxIndex(nums,start,end);
      //cout<<max_index<<"\n";
      TreeNode* root = new TreeNode(nums[max_index]);
      //construct left subtree from left array
      root->left = construct(nums,start,max_index);
      //construct right subtree from right array
      root->right = construct(nums,max_index+1,end);
      return root;
    }
    int getMaxIndex(vector<int> & nums, int start, int end) {
      int max_index = start;
      int max = nums[start];
      for (int i=start+1;i<end;i++) {
        if (nums[i] > max) {
          max = nums[i];
          max_index = i;
        }
      }
      return max_index;
    }
};
