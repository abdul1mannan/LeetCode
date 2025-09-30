// Last updated: 10/1/2025, 12:48:21 AM
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
class BSTIterator {
    stack<TreeNode*> s;
bool reverse=true;
public:
    BSTIterator(TreeNode* root,bool isreverse) {
         reverse=isreverse;
        pushAllLeft(root);
       
    }
    
    int next() {
        TreeNode* node = s.top();
        s.pop();
        if(!reverse)
        pushAllLeft(node->right);
        
        else{
            pushAllLeft(node->left);
        }
        return node->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }

private:
    void pushAllLeft(TreeNode* node) {
        while (node != nullptr) {
             s.push(node);
            if(!reverse){
           
            node = node->left;
            }
            else{
            
                node=node->right;
            }
        }
    }
};
class Solution {
public:
 
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
    
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};