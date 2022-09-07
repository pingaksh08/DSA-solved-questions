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
    
    int getdiff(ListNode *h1, ListNode *h2){
        int l1 = 1 , l2 = 1;
        while(h1 != NULL){
            l1++;
            h1 = h1->next;
        }
        while(h2 != NULL){
            l2++;
            h2 = h2->next;
        }
        return (l1 - l2);
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int diff = getdiff(headA, headB);
        if(diff < 0){
            while(diff++ != 0){
                headB = headB->next;
            }
        }
        else{
            while(diff-- != 0){
                headA = headA->next;
            }
        }
        
        while(headA != NULL){
            if(headA == headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};