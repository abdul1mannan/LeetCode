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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            root= new TreeNode(val);
            return root;
        }
        TreeNode*curr=root;
        
        while(root!=NULL){
            
            if(root->val>val){
                if(root->left)
                root=root->left;
                
                else {
                     root->left= new TreeNode(val); 
                    break;
                }
            }
            else {
                if(root->right)
                root=root->right;
                
                else{
                   root->right= new TreeNode(val); 
                    break;
                } 
            }
        }
        return curr;
    
    }
};