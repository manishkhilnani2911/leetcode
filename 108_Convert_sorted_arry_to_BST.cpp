/*Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Go_Ad_Bl_Mi_Am_Ap_Fa_Pa_Vm_Ba_Ub_Air
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return createBSTFromSortedArray(nums,0,nums.size()-1);
    }
  //make the middle element as the root of the tree
  //now the root of the left subtree would be the middle element of the array till the middle element,
  //and the root of the right subtree would be the middle element of the array starting after the middle element till the end.
    TreeNode* createBSTFromSortedArray(vector<int>& nums, int start, int end) {
      if (start > end)
        return NULL;
      int mid = (start+end)/2;
      TreeNode* root = new TreeNode(nums[mid]);

      root->left = createBSTFromSortedArray(nums,start,mid-1);
      root->right = createBSTFromSortedArray(nums,mid+1,end);
      return root;
    }
};
