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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = root;
        while (lca)
        {
            if (lca->val > p->val && lca->val > q->val)
                lca = lca->left;
            else if (lca->val < p->val && lca->val < q->val)
                lca = lca->right;
            else
                return lca;
        }
    }
};