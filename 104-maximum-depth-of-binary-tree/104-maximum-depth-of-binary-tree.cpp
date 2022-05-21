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
    int maxDepth(TreeNode* root) {
       if(!root) return 0;
        
       int op1 = 1 + maxDepth(root->left); // find height for left sub tree
       int op2 = 1 + maxDepth(root->right); // find height for right sub tree
       return max(op1 , op2);  // max of both is max depth
    }
};