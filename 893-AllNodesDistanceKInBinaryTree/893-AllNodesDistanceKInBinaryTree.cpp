// Last updated: 10/1/2025, 12:47:52 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parent) {
    queue<TreeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
        TreeNode* current = queue.front();
        queue.pop();
        if (current->left) {
            parent[current->left] = current;
            queue.push(current->left);
        }
        if (current->right) {
            parent[current->right] = current;
            queue.push(current->right);
        }
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> ans;
    unordered_map<TreeNode*, TreeNode*> parent;
    markParents(root, parent); 

    unordered_map<TreeNode*, bool> vis; 
    queue<TreeNode*> q; 
    q.push(target);
    vis[target] = true;

    int curr = 0;
    while (!q.empty()) {
        int s = q.size();
        if (curr++ == k) break;

        for (int i = 0; i < s; i++) {
            TreeNode* it = q.front();
            q.pop();
            if (it->left && !vis[it->left]) {
                q.push(it->left);
                vis[it->left] = true;
            }
            if (it->right && !vis[it->right]) {
                q.push(it->right);
                vis[it->right] = true;
            }
            if (parent[it] && !vis[parent[it]]) {
                q.push(parent[it]);
                vis[parent[it]] = true;
            }
        }
    }
    
    while (!q.empty()) {
        TreeNode* it = q.front();
        q.pop();
        ans.push_back(it->val);
    }

    return ans;


    }
};