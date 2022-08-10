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
    Sorted Array --> Binary Search is always an option
    */
    TreeNode* solve(vector<int> &nums, int low, int high){
        if(low > high) return NULL;
        int mid = low + (high-low)/2;
        
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = solve(nums, low, mid-1);
        root->right = solve(nums, mid+1, high);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return solve(nums, 0, nums.size()-1);
        
    }
};