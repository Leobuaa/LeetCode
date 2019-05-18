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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *node = new ListNode(0);
        node->next = head;
        ListNode *pre = node, *p = head;
        int sameVal = 0;
        while (p && p->next) {
            if (p->val == p->next->val) {
                sameVal = p->val;
                while (p && p->val == sameVal) {
                    pre->next = p->next;
                    delete p;
                    p = pre->next;
                }
            } else {
                p = p->next;
                pre = pre->next;
            }
        }
        return node->next;
    }
};