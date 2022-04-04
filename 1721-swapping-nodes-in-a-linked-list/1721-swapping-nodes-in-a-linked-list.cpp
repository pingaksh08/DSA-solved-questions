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
        // two ptr approach
       ListNode *curr = head , *leftptr = head , *rightptr = head;
       int count = 1; // because the list is 1 indexed
       
        // we traverse through the list & make the two ptrs reach their actual pos
        while(curr){
            if(count < k) leftptr = leftptr->next; // leftptr will be k distance from the start
            if(count > k) rightptr = rightptr->next; // rightptr will be k distance from curr ptr 
                                                     // i.e. k distance from the end

            curr = curr->next;
            count++;
        }
        
        swap(leftptr->val , rightptr->val);
        return head;
    }
};