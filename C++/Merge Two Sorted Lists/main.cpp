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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)    return l2;
        if (!l2)    return l1;
        
        ListNode* cur = NULL;
        if (l1->val < l2->val) {
            cur = l1;
            l1 = l1->next;
        } else {
            cur = l2;
            l2 = l2->next;
        }
        
        ListNode* res = cur;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        
        cur->next = l1 ? l1 : l2;
        
        return res;
    }
};