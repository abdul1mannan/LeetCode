// Last updated: 10/1/2025, 12:50:26 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  vector<int>in;
    vector<int> inorderTraversal(TreeNode* root) {
         if(root==nullptr) return {};
         
     

        
         inorderTraversal(root->left);
          in.push_back(root->val);
         inorderTraversal(root->right);

         return in;
    }
};