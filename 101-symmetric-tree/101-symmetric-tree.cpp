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
    
    bool solve(TreeNode *leftside , TreeNode *rightside){
        // base cases
        if(!leftside or !rightside)
            return leftside == rightside;
        
        if(leftside->val != rightside->val)
            return false;
        
        // in mirror, left = right and right = left
        return (solve(leftside->left , rightside->right) and solve(leftside->right , rightside->left));
    }
    
    bool isSymmetric(TreeNode* root) {
       if(!root)
           return true;
        
        return solve(root->left , root->right);
    }
};