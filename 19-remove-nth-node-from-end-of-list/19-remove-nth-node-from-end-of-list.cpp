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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        /* efficient approach using only one traversal --> 2 ptr
         init fast with nth node from start and then traverse till fast->next != NULL
         slow will point to the node to be deleted. 
        */
        
        // to tackle the case where we have to delete the head node itself
       ListNode *temp = new ListNode(0);
       temp->next = head; 
       ListNode *slow = temp, *fast = temp;
       
       for(int i=1 ; i<=n ; i++){
           fast = fast->next;
       }
        
       while(fast->next != NULL){
           slow = slow->next;
           fast = fast->next;
       }
        
        slow->next = slow->next->next;
        return temp->next;
    }
};