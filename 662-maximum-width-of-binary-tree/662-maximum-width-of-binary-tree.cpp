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
    Approach is to give indexing to the nodes i.e.
    if a node has index i, its left child and right child will be-->
    2*i + 1 and 2*i + 2.
    
    max width will be end - start + 1.
    */
    
    int max(int a , int b){
        if(a>b)
            return a;
        return b;
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode * , int>> q; // (node,index)
        long ans=0;
        q.push({root , 0});
        
        while(!q.empty()){
            int n = q.size();
            long mini = q.front().second;
            long start , end;
            
            for(int i=0 ; i<n ; i++){
                auto it = q.front();
                q.pop();
                TreeNode *curr = it.first;
                long index = it.second - mini;
                if(i == 0) start = index;
                if(i == n-1) end = index;
                if(curr->left) q.push({curr->left , 2*index + 1});
                if(curr->right) q.push({curr->right , 2*index + 2});
            }
            
            ans = max(ans , end-start+1);
        }
        
        return ans;
        
    }
};