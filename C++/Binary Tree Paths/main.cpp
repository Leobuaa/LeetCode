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
    void DFS (TreeNode* node, string path, vector<string>& res)
    {
        if (!node)  return;
        if (node && !node->left && !node->right)
            res.push_back(path + to_string(node->val));
        DFS(node->left, path + to_string(node->val) + "->", res);
        DFS(node->right, path + to_string(node->val) + "->", res);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        DFS(root, "", res);
        return res;
    }
};