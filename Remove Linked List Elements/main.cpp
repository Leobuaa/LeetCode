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
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val) {
            head = head->next;
        }
        ListNode* p1 = head, *p2 = head ? head->next : NULL;
        while (p2) {
            while (p2 && p2->val == val) {
               p1->next = p2->next;
               delete p2;
               p2 = p1->next;
            }
            if (p2) {
               p2 = p2->next;
               p1 = p1->next;
            }
        }
        return head;
    }
};