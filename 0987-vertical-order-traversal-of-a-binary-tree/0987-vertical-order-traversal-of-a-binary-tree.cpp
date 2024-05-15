/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int, int>>> q;
        q.push({root, {0,0}});
        map<int,map<int, vector<int>>> c;
        if (root == NULL) {
            return ans;
        }
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int it = p.second.first;
            int horizontal=p.second.second;
            TreeNode* node = p.first;
            c[horizontal][it].push_back(node->val);
            if (node->left != NULL) {
                q.push({node->left,{it + 1,horizontal-1}});
            }
            if (node->right != NULL) {
                q.push({node->right, {it + 1,horizontal+1}});
            }
        }
        for (const auto& it : c) {
            vector<int> temp; // Temporary vector to hold the inner elements
            for (auto p : it.second) {
               sort(p.second.begin(),p.second.end());
                    for(auto k:p.second){
                        
                        temp.push_back(k);
                    }
                    
                    // sort(temp.begin(), temp.end());
                }
                ans.push_back(temp);
            }
         return ans;
    }
   
};