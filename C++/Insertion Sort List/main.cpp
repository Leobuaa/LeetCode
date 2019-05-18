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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* pre = newHead, *p = head;
        while (p) {
            ListNode* preNode = newHead;
            ListNode* node = newHead->next;
            while (node != p && node->val <= p->val) {
                preNode = node;
                node = node->next;
            }
            
            if (node != p) {
                pre->next = p->next;
                p->next = node;
                preNode->next = p;
                p = pre->next;
            } else {
                pre = pre->next;
                p = p->next;
            }
            
        }
        
        return newHead->next;
    }
};