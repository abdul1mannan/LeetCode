// Last updated: 10/1/2025, 12:50:18 AM
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        bool f=true;
        vector<vector<int>>ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        if(root==nullptr){
            return ans;
        }
        while(!q.empty()){
            
            int s=q.size();
            vector<int>temp;
            for(int i=0;i<s;i++){
            auto it=q.front();
            q.pop();
                auto node=it.first;
                int level=it.second;
                int data=node->val;
            temp.push_back(data);
                
                if(node->left){
                    q.push({node->left,level+1});
                }
                 if(node->right){
                    q.push({node->right,level+1});
                }
                
            }
            if(f==true){
                ans.push_back(temp);
            }
            else{
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            
            f=!f;
           
            
        }
        return ans;
    }
};