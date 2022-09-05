/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    void dfs(Node *root, vector<int> &v){
        if(!root) return;
        for(auto child : root->children){
            dfs(child, v);
            v.push_back(child->val);
        }
    }
    
    vector<int> postorder(Node* root) {
        vector<int> v;
        if(!root) return v;
        dfs(root, v);
        v.push_back(root->val);
        return v;
    }
};