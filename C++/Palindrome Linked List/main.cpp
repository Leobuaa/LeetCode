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
    // My solution. Time complexity: O(n), Spcae complexity: O(n)
    bool isPalindrome(ListNode* head) {
        stack<int> sta;
        ListNode* pos = head;
        int len = 0;
        while (pos)
        {
            sta.push(pos->val);
            pos = pos->next;
            len++;
        }
        
        len /= 2;
        pos = head;
        while (len--)
        {
            if (sta.top() != pos->val)  return false;
            sta.pop();
            pos = pos->next;
        }
        
        return true;
    }

    // Another solution is to reverse half of the list. But I think it's not good to change the input.
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode* slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* p = slow->next, *pNext = p->next;
        slow->next = NULL;
        p->next = NULL;
        while (pNext) {
            ListNode* tmp = pNext->next;
            pNext->next = p;
            if (!tmp) {
                break;
            }
            p = pNext;
            pNext = tmp;
        }
        
        ListNode* p1 = head, *p2 = pNext ? pNext : p;
        while (p1 && p2) {
            if (p1->val != p2->val) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }


    // Another brilliant solution from discuss.
    ListNode* temp;
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }

    bool check(ListNode* p) {
        if (!p) {
            return true;
        }
        bool isPal = check(p->next) & (temp->val == p->val);
        temp = temp->next;
        return isPal;
    }
};