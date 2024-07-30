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
    
  
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int>ans;
        if(root==nullptr){
            return ans;
        }
        stack<TreeNode*>s;
        s.push(root);
        
        
        while(!s.empty()){
            auto it=s.top();
            s.pop();
            ans.push_back(it->val);
            
            if(it->right!=NULL){
                s.push(it->right);
            }
            if(it->left!=NULL){
                s.push(it->left);
            }
            
        }
        return ans;
    }
};