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
    void DFS(TreeNode* node, vector<int>& tmpVec, int tmpSum, int sum, vector<vector<int>>& res) {
        if (!node) {
            return;
        }
        tmpVec.push_back(node->val);
        tmpSum += node->val;
        if (!node->left && !node->right && tmpSum == sum) {
            res.push_back(tmpVec);
        }
        DFS(node->left, tmpVec, tmpSum, sum, res);
        DFS(node->right, tmpVec, tmpSum, sum, res);
        tmpVec.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> tmpVec;
        vector<vector<int>> res;
        DFS(root, tmpVec, 0, sum, res);
        return res;
    }
};