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
    stack<TreeNode*>s1,s2;
        if(root==NULL){
            return res;
        }
        s1.push(root);
        
        while(!s1.empty()){
            auto it=s1.top();
            s1.pop();
            s2.push(it);
            if(it->left!=NULL){
                s1.push(it->left);
            }
            if(it->right!=NULL){
                s1.push(it->right);
            }
            
            
        }
        while(!s2.empty()){
            auto it=s2.top();
            s2.pop();
            res.push_back(it->val);
        }
            return res;
    }
        
};