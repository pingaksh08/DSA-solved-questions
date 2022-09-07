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
    /*
    optimal approach -->
    reverse the linked list from after the mid, then compare
    */
    ListNode *reverse(ListNode *head){
        ListNode *curr = head , *prev = NULL , *nex = NULL;
        while(curr != NULL){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
       if(head == NULL or head->next == NULL){
           return true;
       } 
       
        ListNode *slow = head , *fast = head->next;
        while(fast != NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse after mid
        slow->next = reverse(slow->next);
        slow = slow->next;
        ListNode *temp = head; // to compare with head
        
        while(slow != NULL){
            if(temp->val != slow->val){
                return false;
            }
            temp = temp->next;
            slow = slow->next;
        }
        
        return true;
    }
};