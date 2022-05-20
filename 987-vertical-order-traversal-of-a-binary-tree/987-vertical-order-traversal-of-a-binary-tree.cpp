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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        map<int , vector<pair<int , int>>> m; // hori , pair(vert , data)
        queue<pair<TreeNode * , pair<int , int>>> q; // (node , (hori , vert))
        q.push({root , {0,0}});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode *temp = it.first;
            int hori = it.second.first;
            int vert = it.second.second;
            
            m[hori].push_back({vert , temp->val});
            
            if(temp->left) q.push({temp->left , {hori-1 , vert+1}});
            if(temp->right) q.push({temp->right , {hori+1 , vert+1}});
            
        }
        
        for(auto it : m){
            vector<pair<int , int>> itm = it.second;
            sort(itm.begin() , itm.end());
            vector<int> row;
            for(int i=0 ; i<itm.size() ; i++){
                row.push_back(itm[i].second);
            }
            v.push_back(row);
        }
        
        return v;
    }
};