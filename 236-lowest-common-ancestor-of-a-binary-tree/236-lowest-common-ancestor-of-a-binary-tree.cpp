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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(!root or root == p or root == q)
            return root;
        
        // lca is either through leftside or righrside
        TreeNode *leftside = lowestCommonAncestor(root->left , p , q);
        TreeNode *rightside = lowestCommonAncestor(root->right , p , q);
        
        //if it is not at leftside , that means it is on right side and vice vresa
        if(!leftside)
            return rightside;
        
        else if(!rightside)
            return leftside;
        
        // if both aren't null , we have got the result
        else
            return root;
    }
};