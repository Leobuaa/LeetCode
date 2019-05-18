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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->listHead = head;
        this->length = 0;
        this->seed = 0;
        while (head) {
            this->length++;
            head = head->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        srand(this->seed++);
        int randomNumber = rand() % length;
        ListNode *node = this->listHead;
        while (randomNumber > 0) {
            node = node->next;
            randomNumber--;
        }
        return node->val;
    }
    
private:
    int length;
    int seed;
    ListNode *listHead;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */