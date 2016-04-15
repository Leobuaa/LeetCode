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
    TreeNode* invertTree(TreeNode* root) {
    stack<TreeNode*> stack;
    stack.push(root);
    
    while (!stack.empty())
    {
        TreeNode* p = stack.top();
        stack.pop();
        if (p)
        {
            stack.push(p->left);
            stack.push(p->right);
            swap(p->left, p->right);
        }
    }
    
    return root;
    }
};