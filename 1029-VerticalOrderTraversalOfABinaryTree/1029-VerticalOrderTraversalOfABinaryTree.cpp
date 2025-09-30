// Last updated: 10/1/2025, 12:47:42 AM
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>res;
        if(root==nullptr){
            return res;
        }
     map<int, map<int, vector<int>>> mp;
       queue<pair<TreeNode*, pair<int, int>>> q;
          q.push({root,{ 0,0}});

    while (!q.empty()) {
        auto it = q.front();
        q.pop();

        TreeNode* node = it.first;
        int h=it.second.first;
        int v=it.second.second;
      mp[h][v].push_back(node->val);
           if (node->left) {
            q.push({node->left,{h - 1,v+1}});
        }
            if (node->right) {
            q.push({node->right, {h + 1,v+1}});
        }
    }
      for (auto& it : mp) {
        vector<int> vertical;
        for (auto& lvl : it.second) {
           
            sort(lvl.second.begin(), lvl.second.end());
            vertical.insert(vertical.end(), lvl.second.begin(), lvl.second.end());
        }
        res.push_back(vertical);
    }
    return res;

    }
};