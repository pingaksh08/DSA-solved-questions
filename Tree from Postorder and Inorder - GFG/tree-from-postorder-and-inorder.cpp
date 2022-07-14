// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.

void createmapping(int in[] , map<int,int> &nodetoindex , int n){
        for(int i=0 ; i<n ; i++){
            nodetoindex[in[i]] = i;
        }
    }
    
    Node* solve(int in[] , int post[] , int &index , int instart , int inend , int n , map<int,int> &nodetoindex){
        
        // base case
        if(index < 0 or instart > inend) return NULL;
        
        int element = post[index--]; // to get the root
        Node *root = new Node(element);
        int pos = nodetoindex[element]; // position of root in inorder
        
        // recursive calls
        root->right = solve(in , post , index , pos+1 , inend , n , nodetoindex);
        root->left = solve(in , post , index , instart , pos-1 , n , nodetoindex);
        return root;
    }
    
    Node* buildTree(int in[],int post[], int n)
    {
        int postend = n-1;
        map<int,int> nodetoindex;
        createmapping(in , nodetoindex , n);
        Node *ans = solve(in , post , postend , 0 , n-1 , n , nodetoindex);
        return ans;
    }
