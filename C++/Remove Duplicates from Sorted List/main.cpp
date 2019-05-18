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
        if (!head)  return head;
        ListNode* pos = head->next, * pre = head;
        while (pos)
        {
            if (!pos)  break;
            if (pos->val == pre->val) {
                pre->next = pos->next;
                delete pos;
                pos = pre->next;
            } else {
                pre = pre->next;
                pos = pos->next;
            }
        }
        return head;
    }
};