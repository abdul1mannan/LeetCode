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
    TreeNode*prev=NULL;
    void flatten(TreeNode* root) {
        
        if(root==NULL){
            return;
        }
        
        stack<TreeNode*>st;
        
        st.push(root);
        
        while(!st.empty()){
            
            auto it =st.top();
            st.pop();
            if(it->right!=NULL){
                st.push(it->right);
            }
             if(it->left!=NULL){
                st.push(it->left);
            }
            
            if(!st.empty()){
                it->right=st.top();
            }
            it->left=NULL;
        }
//        flatten(root->right);
//         flatten(root->left);
        
//         root->right=prev;
//         root->left=NULL;
//         prev=root;
    }
};