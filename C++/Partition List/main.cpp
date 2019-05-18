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
    // My first solution
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = NULL, *greater = NULL, *greaterHead = NULL, *lessHead = NULL;
        ListNode* p = head;
        while (p) {
            if (p->val < x) {
                if (less) {
                    less->next = p;
                    less = p;
                } else {
                    lessHead = less = p;
                }
            } else {
                if (greater) {
                    greater->next = p;
                    greater = p;
                } else {
                    greaterHead = greater = p;
                }
            }
            p = p->next;
        }
        if (less) {
            less->next = greaterHead;
        }
        if (greater) {
            greater->next = NULL;
        }
        
        return lessHead ? lessHead : greaterHead;
    }

    // A better solution with less code
    ListNode* partition(ListNode* head, int x) {
        ListNode *less = new ListNode(0);
        ListNode *greater = new ListNode(0);
        
        ListNode *lessHead = less, *greaterHead = greater;
        
        ListNode *p = head;
        while (p) {
            if (p->val < x) {
                less = less->next = p;
            } else {
                greater = greater->next = p;
            }
            p = p->next;
        }
        
        less->next = greaterHead->next;
        greater->next = NULL;
        
        return lessHead->next;
    }
};