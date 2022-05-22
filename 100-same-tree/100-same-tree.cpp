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
     two trees are identical when the following 3 conditions are true-->
     1. t1.val == t2.val(corres. values identical)
     2. t1.left == t2.left(corres. left sub trees identical )
     3. t1.right == t2.right(corres. right sub trees identical)
     */   
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if(!p and !q) return true;
       else if(!p or !q) return false;
        return ((p->val == q->val) and (isSameTree(p->left , q->left)) and (isSameTree(p->right , q->right)));
    }
};