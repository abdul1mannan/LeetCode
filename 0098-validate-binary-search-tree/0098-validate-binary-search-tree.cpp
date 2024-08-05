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
    
    bool solve(TreeNode*root,long maxi,long mini){
           if(root==NULL) return true;
          if(root->val>=maxi || root->val<=mini ) return false;
        
         return solve(root->left,root->val,mini) && solve(root->right,maxi,root->val);
    }
    bool isValidBST(TreeNode* root) {
       
        return solve(root,LLONG_MAX,LLONG_MIN);
     
    }
};