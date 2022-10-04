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
    
    void solve(TreeNode *root ,int curr ,int sum){
        if(!root) return;
        
        
        curr += root->val;
        temp.push_back(root->val);
        
        if(curr == sum and root->left == nullptr and root->right == nullptr){
            ans.push_back(temp);
            
        }
        
        solve(root->left ,curr ,sum);
        solve(root->right ,curr ,sum);
        
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) { 
       solve(root ,0 ,targetSum);
       return ans; 
    }
};