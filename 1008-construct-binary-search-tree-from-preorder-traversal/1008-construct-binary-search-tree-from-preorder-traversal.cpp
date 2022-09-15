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
    
    TreeNode* solve(vector<int> &pre , int &index , int bound){
        if(index >= pre.size() or pre[index] >= bound)
            return NULL;
        
        TreeNode *root = new TreeNode(pre[index++]);
        root->left = solve(pre , index , root->val);
        root->right = solve(pre , index , bound);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return solve(preorder , index , 1001);
    }
};