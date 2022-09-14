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
    
    TreeNode* solve(vector<int> in , vector<int> post , int &index , int start , int end){
        
        if(index < 0 or start > end){
            return NULL;
        }
        
        int element = post[index--];
        TreeNode *root = new TreeNode(element);
        int pos = findpos(in , element);
        
        root->right = solve(in , post , index , pos+1 , end);
        root->left = solve(in , post , index , start , pos-1);
        
        return root;
    } 
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       int n = inorder.size();
       int index = n-1; 
       TreeNode *ans = solve(inorder , postorder , index , 0 , n-1);
       return ans; 
    }
};