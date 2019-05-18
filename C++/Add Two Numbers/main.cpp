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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = NULL;
        if (!l1 && !l2) return res;
        if (!l1)    return l2;
        if (!l2)    return l1;
        
        res = new ListNode(0);
        ListNode* pos = res;
        int addFlag = 0;
        while (l1 || l2 || addFlag != 0)
        {
            int temp = addFlag;
            if (l1)
            {
                temp += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                temp += l2->val;
                l2 = l2->next;
            }
            addFlag = temp / 10;
            pos->val = temp % 10;
            if (!l1 && !l2 && addFlag == 0)
            {
                break;
            }
            pos->next = new ListNode(0);
            pos = pos->next;
        }
        return res;
    }
};