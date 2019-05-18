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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) {
            return head;
        }
        ListNode* odd = head;
        ListNode* even = odd ? odd->next : NULL;
        ListNode* firstEven = even;
        while (odd && even)
        {
            ListNode* nextOdd = even->next;
            ListNode* nextEven = nextOdd ? nextOdd->next : NULL;
            odd->next = nextOdd;
            even->next = nextEven;
            
            if (!nextOdd)   break;
            
            odd = nextOdd;
            even = nextEven;
        }
        
        odd->next = firstEven;
        return head;
    }
};