// Last updated: 10/1/2025, 12:49:48 AM
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
 
    vector<int> preorderTraversal(TreeNode* root) {
       if(root==nullptr) return {};
        stack<TreeNode*>s;
        s.push(root);
        vector<int>pre;
        while(!s.empty()){
            TreeNode* x=s.top();
            int val=x->val;
            s.pop();
            pre.push_back(val);
            if(x->right){
                s.push(x->right);
            }
            if(x->left){
                s.push(x->left);
            }
 
        }
    
        // if(root==nullptr) return {};
         
     

        //  pre.push_back(root->val);
        //  preorderTraversal(root->left);
        //  preorderTraversal(root->right);

         return pre;
        
    }
};