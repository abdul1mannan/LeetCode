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
  
    
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> res;
    TreeNode *curr=root;
    while (curr!=NULL) {
        if (curr->right) {
            TreeNode* prev = curr->right;
            while (prev->left && prev->left != curr) {
                prev = prev->left;
            }
            if (prev->left==NULL) {
                res.push_back(curr->val);
                prev->left = curr;
                curr = curr->right;
            } else {
                prev->left = nullptr;
                curr = curr->left;
            }
        } else {
            res.push_back(curr->val);
            curr = curr->left;
        }
    }
    reverse(res.begin(),res.end());
    return res;
    }
        
};