/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // two line change in bfs
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        
        queue<Node *> q;
        q.push(root);
        Node *prev;
        
        while(!q.empty()){
            int size = q.size();  
            for(int i=0 ; i<size ; i++){
               Node *temp = q.front();
               q.pop();
                
               if(i > 0){
                   prev->next = temp;
               } 
               
               if(temp->left){
                    q.push(temp->left);
               }
                
               if(temp->right){
                    q.push(temp->right);
               } 
                
               prev = temp; 
            }
        }
        
        return root;
    }
};