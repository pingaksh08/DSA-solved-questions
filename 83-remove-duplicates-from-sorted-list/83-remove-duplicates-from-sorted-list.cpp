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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr = head;
        if(!curr or !curr->next)
            return curr;
        
        while(curr and curr->next){
            ListNode *nexptr = curr->next;
            if(curr->val == nexptr->val){
                ListNode *temp = nexptr; // to traverse till will encounter same values
                curr->next = temp->next;
                nexptr = curr;
            }
            
            else{
                curr = curr->next;
            }
        }
        
        return head;
    }
};