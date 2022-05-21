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
    
    int height(TreeNode* root){
        if(root == nullptr)
            return 0;
        
        
        int h1 = height(root->left);
        int h2 = height(root->right);
        return 1 + max(h1,h2);
        
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        int h1 = height(root->left);
        int h2 = height(root->right);
        int h = abs(h1-h2);
        if(h>1){
            return false;
        }
        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);
        
        return l&r;
    }
};