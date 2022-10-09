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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode *> q;
        q.push(root);
        // to store curr val and its parent's val for each level
        unordered_map<int , int> mp;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode *temp = q.front();
                q.pop();
                
                if(temp->left){
                    mp[temp->left->val] = temp->val;
                    q.push(temp->left);
                }
                
                if(temp->right){
                    mp[temp->right->val] = temp->val;
                    q.push(temp->right);
                }
            }
            
            if(mp.find(x) != mp.end() and mp.find(y) != mp.end() and mp[x] != mp[y]){
                return true;
            }
            
            mp.clear();
        }
        
        return false;
    }
};