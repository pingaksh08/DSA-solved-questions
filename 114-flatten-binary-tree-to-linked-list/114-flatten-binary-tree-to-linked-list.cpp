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
    using recursion-->
    in this, first tackle the right side
    then the left side and then simply set the left node to null 
    and set the right node to the prev node and update the prev node 
    with the curr node.
    --> dry run for proper understanding
    tc -- O(n) sc --> O(n) for skewed tree
    */
    TreeNode *prev = NULL;
    void flatten(TreeNode* root) {
      if(!root)
          return;
        
      flatten(root->right);
      flatten(root->left);
      
      root->right = prev;
      root->left = NULL;
      prev = root;  
        
    }
};