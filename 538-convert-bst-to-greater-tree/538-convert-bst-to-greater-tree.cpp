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
    int temp = 0; // to store the curr sum
    TreeNode* convertBST(TreeNode* root) {
        if(!root)
            return nullptr;
        
        //initially traversing through right side
        convertBST(root->right);
        temp += root->val; // calc total sum
        root->val = temp; // assigning sum to curr node
        convertBST(root->left); // now repeating the same process for the left side
        return root;
    }
};