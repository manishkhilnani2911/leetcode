/*Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with same node values.

Example 1:

        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
The following are two duplicate subtrees:

      2
     /
    4
and

    4
Therefore, you need to return above trees' root in the form of a list.*/
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
  //Am_Ub_Go
  private:
  unordered_map<string,int> m;
  vector<TreeNode*> res;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
      preOrder(root);
      return res;
    }
  //for every node, store the preorder string from that node as root, in a map.
  //for every second occurence of any string add the root into the result
    string preOrder(TreeNode* root) {
      if (!root)
        return "#";
      string ans = to_string(root->val) + "," + preOrder(root->left) + "," + preOrder(root->right);
      //cout<<"string at "<<root->val<<" is "<<ans<<"\n";
      //cout<<"for "<<ans<<" map entry is "<<m[ans]<<"\n";
      m[ans] += 1;
      if (m[ans] == 2) {
        res.push_back(root);
      }
      return ans;
    }
};
