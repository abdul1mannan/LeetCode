// Last updated: 10/1/2025, 12:48:19 AM
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        
        long long int ans=0;
        queue<pair<TreeNode*,unsigned long long int>>q;
        
        q.push({root,0});
        
        while(!q.empty()){
            
            int s=q.size();
            
            long long int mini=q.front().second;
            
            long long int f,l;
            
            for(int i=0;i<s;i++){
               long long int curr = q.front().second - mini;
                 TreeNode* node = q.front().first;
                q.pop();
                
                if(i==0){
                    f=curr;
                }
                 if (i == s - 1) {
                    l = curr;
                }
                
                 if (node->left) {
                    q.push({node->left, curr * 2 + 1});
                }
                 if (node->right) {
                    q.push({node->right, curr * 2 + 2});
                }
                
            }
             ans = max(ans, l - f + 1);
        }
        return ans;
    }
};