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
    // Explanation Link: https://leetcode.com/discuss/9908/o-n-solution-by-using-two-pointers-without-change-anything
    ListNode *detectCycle(ListNode *head) {
        int cnt = 0;
        bool isCycle = false;
        ListNode *slow = head, *fast = head;
        // Use two pointers to test if there is a cycle.
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            cnt++;
            if (slow == fast) {
                isCycle = true;
                break;
            }
        }
        
        if (!isCycle) {
            return NULL;
        }
        
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};