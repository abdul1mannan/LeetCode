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
    
    
    TreeNode *solve(vector<int>&a,int &i,int upperbound){
        if(i==a.size()||a[i]>upperbound) return NULL;
        TreeNode *root=new TreeNode(a[i++]);
        root->left=solve(a,i,root->val);
        root->right=solve(a,i,upperbound);
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
    int i=0;
        return solve(preorder,i,INT_MAX);
    
    }
};