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
    TreeNode* searchBST(TreeNode* root, int val) {
        
        if(!root) return nullptr;
        
        TreeNode *temp = root;
        if(temp->val == val)
            return temp;
        if(temp->val > val)
            return searchBST(temp->left , val);
        else
            return searchBST(temp->right , val);
    }
};