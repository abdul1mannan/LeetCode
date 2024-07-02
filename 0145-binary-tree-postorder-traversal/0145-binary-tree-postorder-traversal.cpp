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
         deque<int> res;
    
    while (root) {
        if (root->right) {
            TreeNode* temp = root->right;
            while (temp->left && temp->left != root) {
                temp = temp->left;
            }
            if (!temp->left) {
                res.push_front(root->val);
                temp->left = root;
                root = root->right;
            } else {
                temp->left = nullptr;
                root = root->left;
            }
        } else {
            res.push_front(root->val);
            root = root->left;
        }
    }
    
    return vector<int>(res.begin(), res.end());
    }
        
};