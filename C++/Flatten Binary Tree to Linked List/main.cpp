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
    // DFS
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        TreeNode* lEnd = root->left;
        flatten(root->left);
        flatten(root->right);
        while (lEnd && lEnd->right) {
            lEnd = lEnd->right;
        }
        if (lEnd) {
            lEnd->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
};