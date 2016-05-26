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
    int rob(TreeNode* node, int& lm, int& rm)
    {
        if (!node)  return 0;
        int lm1 = 0, lm2 = 0, rm1 = 0, rm2 = 0;
        
        lm = rob(node->left, lm1, rm1);
        rm = rob(node->right, lm2, rm2);
        
        return max(node->val + lm1 + rm1 + lm2 + rm2, lm + rm);
    }

    int rob(TreeNode* root) {
        int res = 0;
        int lm = 0, rm = 0;
        res = rob(root, lm, rm);
        return res;
    }
};