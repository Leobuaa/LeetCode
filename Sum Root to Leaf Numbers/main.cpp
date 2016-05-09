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
    // My solution. It runs 4ms.
    void DFS(TreeNode* node, int num, int& sum) {
        if (!node) {
            return;
        }
        if (!node->left && !node->right) {
            sum += (num * 10 + node->val);
            return;
        }
        
        DFS(node->left, num * 10 + node->val, sum);
        DFS(node->right, num * 10 + node->val, sum);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        DFS(root, 0, sum);
        return sum;
    }
};