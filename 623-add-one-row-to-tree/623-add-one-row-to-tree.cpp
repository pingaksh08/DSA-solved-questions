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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return root;
        
        if(depth == 1){
            TreeNode *node = new TreeNode(val);
            node->left = root;
            return node;
        }
        
        int level = 1;
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode *curr = q.front();
                q.pop();
                
                if(level == depth-1){
                   TreeNode *newl = new TreeNode(val);
                   TreeNode *newr = new TreeNode(val);
                    
                   newl->left = curr->left;
                   newr->right = curr->right;
                    
                   curr->left = newl;
                   curr->right = newr; 
                }
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
            level++;
        }
        
        return root;
    }
};