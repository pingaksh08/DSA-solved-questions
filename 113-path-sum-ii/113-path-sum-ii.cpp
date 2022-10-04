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
    
    vector<vector<int>> ans;
    vector<int> temp;
    
    void solve(TreeNode *root ,int sum){
        if(!root) return;
        
        
        sum -= root->val;
        temp.push_back(root->val);
        
        if(sum == 0 and root->left == nullptr and root->right == nullptr){
            ans.push_back(temp);
            
        }
        
        solve(root->left , sum);
        solve(root->right , sum);
        
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) { 
       solve(root ,targetSum);
       return ans; 
    }
};