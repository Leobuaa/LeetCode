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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* posA = headA, * posB = headB;
        if (!posA || !posB) return NULL;
        while (posA && posB)
        {
            if (posA == posB)   return posA;
            posA = posA->next;
            posB = posB->next;
            
            if (posA == posB)   return posA;
            if (!posA)  posA = headB;
            if (!posB)  posB = headA;
        }
        return NULL;
    }
};