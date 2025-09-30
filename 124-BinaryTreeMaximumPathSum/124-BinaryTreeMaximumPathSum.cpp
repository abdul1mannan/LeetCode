// Last updated: 10/1/2025, 12:50:06 AM
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
    
    int height(TreeNode*root ,int &sum){
        if(root==nullptr){
            return 0;
        }
        
        int lh=max(0,height(root->left,sum));
        int rh=max(0,height(root->right,sum));
        
        sum=max(sum,lh+rh+root->val);
        
        return max(lh,rh)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        
        height(root,sum);
        return sum;
    }
};