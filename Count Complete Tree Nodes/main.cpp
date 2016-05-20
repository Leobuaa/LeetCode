/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* node) {
        int res = 0;
        while (node) {
            res++;
            node = node->left;
        }
        return res;
    }

    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        TreeNode* p = root;
        int cnt = 0;
        while (p) {
            int left = height(p->left), right = height(p->right);
            if (left == 0) {
                cnt++;
                break;
            }
            if (left == right) {
                cnt += (int)pow(2, left - 1);
                p = p->right;
            } else {
                p = p->left;
            }
        }
        
        int h = height(root);
        return (int)pow(2, h - 1) - 1 + cnt;
    }
};