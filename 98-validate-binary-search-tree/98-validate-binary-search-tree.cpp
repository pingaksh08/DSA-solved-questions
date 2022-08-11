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
    
    bool solve(TreeNode *root, long long minval, long long maxval){
        if(!root) return true;
        if(root->val > minval and root->val < maxval){
            return (solve(root->left, minval, root->val) and solve(root->right, root->val, maxval));
        }
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
       return solve(root, LONG_MIN, LONG_MAX);
    }
};