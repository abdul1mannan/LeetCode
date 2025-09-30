// Last updated: 10/1/2025, 12:46:58 AM
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
    int amountOfTime(TreeNode* root, int start) {
        if(root==NULL){
            return 0;
        }
        vector<vector<int>>adj(1000000);
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
               auto front=q.front();
               q.pop();
               if(front->left!=NULL){
                adj[front->val].push_back(front->left->val);
                adj[front->left->val].push_back(front->val);
                q.push(front->left);
            }
             if(front->right!=NULL){
                adj[front->val].push_back(front->right->val);
                adj[front->right->val].push_back(front->val);
                q.push(front->right);
            }
        }
        unordered_map<int, bool> vis;
        queue<pair<int,int>>que;
        que.push({start,0});
        vis[start]=true;
        int maxDistance=0;
        
        while (!que.empty()) {
            int node = que.front().first;
            int time = que.front().second;
            que.pop();

            maxDistance = max(maxDistance, time);

            for (int neighbor : adj[node]) {
                if (!vis[neighbor]) {
                    que.push({neighbor, time + 1});
                    vis[neighbor] = true;
                }
            }
        }
            
        
        return maxDistance;

    }
};