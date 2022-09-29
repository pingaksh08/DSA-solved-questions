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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *prev = NULL , *ptr = list1;
        int count = 0;
        while(count != a){
            prev = ptr;
            ptr = ptr->next;
            count++;
        }
        
        while(count != b){
            ptr = ptr->next;
            count++;
        }
        
        ListNode *tail = list2;
        while(tail->next != NULL){
            tail = tail->next;
        }
        
        prev->next = list2;
        tail->next = ptr->next;
        return list1;
    }
};