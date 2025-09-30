// Last updated: 10/1/2025, 12:50:16 AM
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
    TreeNode * solve(int pres,int prend,vector<int>&preorder,vector<int>&inorder,int ins,int inend,unordered_map<int,int>&mp){
        
        if(pres>prend||ins>inend){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[pres]);
        int index=mp[root->val];
        int left=index-ins;
        
        root->left=solve(pres+1,pres+left,preorder,inorder,ins,index-1,mp);
        root->right=solve(pres+left+1,prend,preorder,inorder,index+1,inend,mp);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int,int>mp;
        int n=inorder.size();
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode*root=solve(0,n-1,preorder,inorder,0,n-1,mp);
        return root;
    }
};