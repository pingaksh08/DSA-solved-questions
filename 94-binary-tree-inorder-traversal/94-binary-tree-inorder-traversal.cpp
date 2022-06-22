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
    vector<int> inorderTraversal(TreeNode* root) {
        /*
        morris traversal --> threaded binary tree concept
        create a thread from the rightmost node of the left sub tree to 
        the curr node of that subtree
        tc --> O(n)
        sc --> O(1)
        */
        vector<int> ans;
        TreeNode *curr = root;
        
        while(curr){
            // case 1 : no left subtree exists, simply go right
            if(!curr->left){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode *prev = curr->left;
                while(prev->right and prev->right != curr){
                    prev = prev->right;
                }
                // case 2 : rightmost child of left subtree points to null , create thread and                       move curr 
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    // case 2 : rightmost child of left subtree points to curr, then break the                            thread and move curr to right 
                    prev->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        
        return ans;
    }
};