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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res = {};
        if (!root)
            return res;
        vector<TreeNode*> sta;
        TreeNode* p = root;
        while (!sta.empty() || p)
        {
            while (p)
            {
                sta.push_back(p);
                p = p->left;
            }
            
            if (!sta.empty())
            {
                p = sta.back();
                sta.pop_back();
                res.push_back(p->val);
                p = p->right;
            }
        }
        return res;
    }
};