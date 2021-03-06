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
    /*
    longest path b/w 2 nodes in a tree is called diameter.
    it may or may not passes through the root.
    3 cases -->
    1. either, dm through root
    2. or, dm through left sub tree
    3. or, dm through right sub tree
    */
    int height(TreeNode *root){
        if(!root) return 0;
        return 1 + max(height(root->left) , height(root->right));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        if(!root->left and !root->right) return 0;
        int d1 = height(root->left) + height(root->right); 
        int d2 = diameterOfBinaryTree(root->left);
        int d3 = diameterOfBinaryTree(root->right);
        return max({d1 , d2 , d3});
    }
};