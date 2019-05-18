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
    // My solution. It is too long.
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head->next || m == n)
        {
            return head;
        }
        
        ListNode* pp1, *p1, *np2, *p2;
        pp1 = p1 = p2 = head;
        np2 = head->next;
        int cnt = 1;
        while (cnt < m)
        {
            pp1 = p1;
            p1 = p1->next;
            cnt++;
        }
        
        cnt = 1;
        while (cnt < n)
        {
            p2 = np2;
            np2 = np2->next;
            cnt++;
        }
        
        ListNode* cur = p1;
        ListNode* curNext = p1->next;
        while (cur != p2)
        {
            ListNode* np = curNext->next;
            curNext->next = cur;
            cur = curNext;
            curNext = np;
        }
        
        if (m != 1)
        {
            pp1->next = cur;
        }
        p1->next = np2;
        
        if (m == 1)
        {
            return p2;
        }
        
        return head;
    }

    // A clear and better solution from discuss
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* res = new ListNode(0);
        res->next = head;
        if (m == n) {
            return head;
        }
        int cnt = n - m;
        ListNode* pre = res;
        while (--m) {
            pre = pre->next;
        }
        ListNode* cur = pre->next;
        while (cnt--) {
            ListNode* curNext = cur->next;
            cur->next = curNext->next;
            curNext->next = pre->next;
            pre->next = curNext;
        }
        return res->next;
    }
};