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
    void levelOrder(TreeNode* node, vector<vector<int>> &res, int level)
    {
        if (!node)  return;
        if (level == res.size())
            res.push_back(vector<int>());
        res[level].push_back(node->val);
        
        levelOrder(node->left, res, level + 1);
        levelOrder(node->right, res, level + 1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)  return res;
        levelOrder(root, res, 0);
        reverse(res.begin(), res.end());
        return res;
    }
};