/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while (root) {
            TreeLinkNode *cur = root;
            while (cur && cur->left) {
                cur->left->next = cur->right;
                
                if (cur->next) {
                    cur->right->next = cur->next->left;
                }
                
                cur = cur->next;
            }
            root = root->left;
        }
     }
};