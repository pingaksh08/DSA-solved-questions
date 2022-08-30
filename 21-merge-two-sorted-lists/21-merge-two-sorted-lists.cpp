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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // merging without extra space
        if(!list1) return list2;
        if(!list2) return list1;
        
        // pointing list1 and list2 to the smallest and largest
        if(list1->val > list2->val) swap(list1, list2);
        
        // head of resultant
        ListNode *ans = list1;
        while(list1 and list2){
            // curr will keep the track of the smaller element of both
            ListNode *curr = NULL;
            while(list1 and list1->val <= list2->val){
                curr = list1; // keep going till it is smaller
                list1 = list1->next;
            }
            // linking the prev smaller to the next larger one in list2
            curr->next = list2;
            swap(list1, list2);
        }
        
        return ans;
    }
};