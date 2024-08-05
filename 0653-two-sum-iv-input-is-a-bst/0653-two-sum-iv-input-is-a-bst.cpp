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
        unordered_map<int,int>mp;
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
    
     
        int curr=k-root->val;
        if(mp.find(curr)!=mp.end())
        {
            return true;
        }
        else{
            mp[root->val]=1;
            return findTarget(root->left,k) || findTarget(root->right,k);
        }
            
        
    }
};