/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
       ListNode *curr = head , *leftptr = head , *rightptr = head;
       int count = 1;
        
        while(curr){
            if(count < k) leftptr = leftptr->next;
            if(count > k) rightptr = rightptr->next;
            
            curr = curr->next;
            count++;
        }
        
        swap(leftptr->val , rightptr->val);
        return head;
    }
};