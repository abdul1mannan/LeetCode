// Last updated: 10/1/2025, 12:49:25 AM
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
    
    void rightside(vector<int>&res,int level,TreeNode*root){
        if(root==nullptr){
            return;
        }
        
        if(res.size()==level){
            res.push_back(root->val);
        }
            
            rightside(res,level+1,root->right);
            rightside(res,level+1,root->left);
            
        }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        
        rightside(res,0,root);
        return res;
    }
};