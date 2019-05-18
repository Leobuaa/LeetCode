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
    // Iteratively
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL, *pos = head;
        while (pos)
        {
            if (!pos->next)
            {
                pos->next = pre;
                break;
            }
            ListNode* next = pos->next;
            pos->next = pre;
            pre = pos;
            pos = next;
        }
        return pos;
    }

    // Recursive
    ListNode* reverseList(ListNode* head) {
       if (!head || !head->next) {
           return head;
       } 
       ListNode* res = reverseList(head->next);
       head->next->next = head;
       head->next = NULL;
       return res;
    }
};