/*Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//populate the vector using inorder traversal
//apply two sum on the vector
class Solution {
  private:
    vector<int> inOrderVector;
public:
    bool findTarget(TreeNode* root, int k) {
      getInOrderVector(root);
      return twoSum(k);
    }
    void getInOrderVector(TreeNode* root) {
      if (!root)
        return;
      getInOrderVector(root->left);
      inOrderVector.push_back(root->val);
      getInOrderVector(root->right);
    }
    bool twoSum(int k){
      unordered_map<int,int> mymap;
      for(int i=0;i<inOrderVector.size();i++) {
        if (mymap.find(inOrderVector[i]) != mymap.end()) {
          return true;
          break;
        } else {
          mymap[k-inOrderVector[i]] = i;
        }
      }
      return false;
    }
};
