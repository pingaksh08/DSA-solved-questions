/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
// copy the value of next node in the curr node and delete the next node
        node->val = node->next->val;
        ListNode *delnode = node->next;
        node->next = node->next->next;
        delete(delnode);
    }
};