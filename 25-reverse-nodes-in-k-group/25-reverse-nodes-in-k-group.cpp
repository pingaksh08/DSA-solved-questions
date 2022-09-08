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
        if(head == NULL or head->next == NULL)
            return head;
        
        ListNode *temp = head , *prev = NULL , *curr = head , *nex = NULL;
        int count = 0, itm = 0;
        
        // to check that whether there are last k nodes remaining or not
        while(temp != NULL){
            temp = temp->next;
            itm++;
            if(itm == k) break;
        }
        
        // if there is a group of k, reverse all nodes in it 
        if(itm == k){
            while(curr != NULL and count < k){
                // to reverse a ll
                nex = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nex;
                count++;
            }
        }
        
        // recursive call for next group
        if(nex != NULL)
            head->next = reverseKGroup(nex, k);
        
        // as after reverse, prev becomes the new head
        if(itm == k)
            return prev;
        
        else
            return head;
    }
};