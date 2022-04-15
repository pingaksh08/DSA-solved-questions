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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)
            return root;
        
        // if the value is in range
        if(root->val >= low && root->val <= high){
            root->left = trimBST(root->left , low , high);
            root->right = trimBST(root->right , low , high);
            return root;
        }
        
        // if curr val is lower then low then rest of left val will also be lower so discard them
        if(root->val < low)
            return trimBST(root->right , low , high);
        
         // if curr val is greater then high then rest of right val will also be higher so discard them
         return trimBST(root->left , low , high);
    }
};