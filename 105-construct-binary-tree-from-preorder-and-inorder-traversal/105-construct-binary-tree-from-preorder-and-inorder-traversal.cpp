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
    
    int findpos(vector<int> arr , int x){
        for(int i=0 ; i<arr.size() ; i++){
            if(arr[i] == x) 
                return i;
        }
        return -1;
    }
    
    TreeNode* solve(vector<int> pre , vector<int> in , int& index , int start , int end){
        if(index > in.size() or start > end) return NULL;
        
        int element = pre[index++];
        TreeNode* root = new TreeNode(element);
        int pos =  findpos(in , element);
        
        root->left = solve(pre , in , index , start , pos - 1);
        root->right = solve(pre , in , index , pos + 1 , end);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        TreeNode* ans = solve(preorder , inorder , index , 0 , preorder.size() - 1);
        return ans;
    }
};