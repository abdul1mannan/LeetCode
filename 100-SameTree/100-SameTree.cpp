// Last updated: 10/1/2025, 12:50:22 AM
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
    
    bool isIdentical(TreeNode*p,TreeNode*q){
        
        if(p==nullptr && q==nullptr){
            return true;
        }
         if(p==nullptr || q==nullptr){
            return false;
        }
        
        
        if(p->val==q->val && isIdentical(p->left,q->left) && isIdentical(p->right,q->right)){
            return true;
        }
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
      return isIdentical(p,q);
        
    }
};