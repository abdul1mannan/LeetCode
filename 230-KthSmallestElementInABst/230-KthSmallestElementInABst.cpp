// Last updated: 10/1/2025, 12:49:11 AM
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
    void solve(TreeNode*root,int k ,int& cnt, int &mini){
        if(root==NULL ||cnt>=k){
            return ;
        }
        
        solve(root->left,k,cnt,mini);
        
        cnt++;
        
        if(cnt==k){
            mini=root->val;
            return;
        }
        solve(root->right,k,cnt,mini);
    }
    int kthSmallest(TreeNode* root, int k) {
        int mini=INT_MIN;
        
        int cnt=0;
        solve(root,k,cnt,mini);
        return mini;
    }
};