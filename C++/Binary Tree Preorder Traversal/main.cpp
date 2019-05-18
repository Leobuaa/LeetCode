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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> sta;
        sta.push(root);
        while ( ! sta.empty() )
        {
            auto tmp = sta.top();
            sta.pop();
            if (!tmp)
                continue;
            res.push_back(tmp->val);
            sta.push(tmp->right);
            sta.push(tmp->left);
        }
        return res;
    }
};