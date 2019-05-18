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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)  return head;
        ListNode* p = head, *pn = head->next, *res = pn;
        ListNode* pp = head;
        while (p && pn)
        {
            pp->next = pn;
            p->next = pn->next;
            pn->next = p;
            pp = p;
            p = p->next;
            if (p) {
                pn = p->next;
            }
        }
        
        return res;
    }
};