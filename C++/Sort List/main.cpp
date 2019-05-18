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
    // My solution. Not constant space.
    ListNode* mergeNode(ListNode* p1, ListNode* p2, int size1, int size2)
    {
        ListNode* res = p1;
        if (p1->val > p2->val)
            res = p2;
        
        ListNode* pp1 = NULL, *pp2 = NULL;
        while (size1 && size2)
        {
            while (size1 && p2 && p1->val <= p2->val)
            {
                size1--;
                pp1 = p1;
                p1 = p1->next;
            }
            if (pp1)
                pp1->next = p2;
            
            if (!size1)
                break;
            
            while (size2 && p1 && p2->val <= p1->val)
            {
                size2--;
                pp2 = p2;
                p2 = p2->next;
            }
            if (pp2)
                pp2->next = p1;
        }
        
        return res;
    }

    ListNode* mergeSort1(ListNode* p, int size)
    {
        if (size <= 1)
            return p;
        
        ListNode* p1 = p, *pp2 = p, *p2 = p->next;
        for (int i = 0; i < (size / 2 - 1); i++)
        {
            pp2 = p2;
            p2 = p2->next;
        }
        pp2->next = NULL;
    
        int size1 = size / 2, size2 = size - size1;
        
        p1 = mergeSort1(p1, size1);
        p2 = mergeSort1(p2, size2);
        return mergeNode(p1, p2, size1, size2);
    }

    ListNode* sortList(ListNode* head) {
        int size = 0;
        ListNode* p = head, *res = head;
        while (p)
        {
            size++;
            p = p->next;
        }
        res = mergeSort1(head, size);
        return res;
    }
};