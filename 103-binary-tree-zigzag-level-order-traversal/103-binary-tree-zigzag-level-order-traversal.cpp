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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode *> q;
        q.push(root);
        int level = 1;
        
        while(!q.empty()){
            int size = q.size();
            if(level&1){
              vector<int> LTR;
                
              while(size--){
                  TreeNode *temp = q.front();
                  q.pop();
                  LTR.push_back(temp->val);
                  
                  if(temp->left) q.push(temp->left);
                  if(temp->right) q.push(temp->right);
              }
                ans.push_back(LTR);
                LTR.clear();
            }
            else{
                vector<int> RTL;
                stack<int> st;
                
                while(size--){
                   TreeNode *temp = q.front();
                   q.pop();
                   st.push(temp->val);
                  
                   if(temp->left) q.push(temp->left);
                   if(temp->right) q.push(temp->right);
                }
                
                while(!st.empty()){
                    RTL.push_back(st.top());
                    st.pop();
                }
                ans.push_back(RTL);
                RTL.clear();
            }
            level++;
        }
        
        return ans;
    }
};