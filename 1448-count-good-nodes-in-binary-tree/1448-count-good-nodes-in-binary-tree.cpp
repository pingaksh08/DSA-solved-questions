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
    int ans = 0;  
    void solve(TreeNode *node, int currmx){
        if(!node) 
            return;
        
        if(node->val >= currmx){
            ans++;
            currmx = node->val;
        }
        
        solve(node->left, currmx);
        solve(node->right, currmx);
    }
    
    int goodNodes(TreeNode* root) {
        solve(root, root->val);
        return ans;
    }
};