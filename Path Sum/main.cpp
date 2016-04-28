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
    bool pathSum(TreeNode* node, int tmpSum, int sum)
    {
        if (!node)  return false;
        tmpSum += node->val;
        if (tmpSum == sum && !node->left && !node->right)  return true;
        return pathSum(node->left, tmpSum, sum) || pathSum(node->right, tmpSum, sum);
    }

    bool hasPathSum(TreeNode* root, int sum) {
        int tmpSum = 0;
        return pathSum(root, tmpSum, sum);
    }

    // A better one solution
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return false;
        }
        
        if (root->val == sum && !root->left && !root->right) {
            return true;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};