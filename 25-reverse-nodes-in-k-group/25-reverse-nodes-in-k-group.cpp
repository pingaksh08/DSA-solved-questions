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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL or k == 1)
            return head;
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prevptr = dummy, *currptr = dummy , *nextptr = dummy;
        int n = 0;
        
        while(currptr->next != NULL){
            n++;
            currptr = currptr->next;
        }
        
        while(n >= k){
            currptr = prevptr->next;
            nextptr = currptr->next;
            for(int i=1 ; i<k ; i++){
                //procedure to reverse a link
                // the curr will always point to the first node of thr k sized group
                currptr->next = nextptr->next;
                nextptr->next = prevptr->next;
                prevptr->next = nextptr;
                nextptr = currptr->next;
            }
            prevptr = currptr;
            n -= k;
        }
        
        return dummy->next;
    }
};