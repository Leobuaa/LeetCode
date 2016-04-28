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
    int DFS(TreeNode* node, int depth)
    {
        if (!node)  return depth - 1;
        if (node && !node->left && !node->right)
            return depth;
        int l = DFS(node->left, depth + 1), r = DFS(node->right, depth + 1);
        if (!node->left){
            return r;
        }
        
        if (!node->right) {
            return l;
        }
        
        return min(l, r);
    }

    int minDepth(TreeNode* root) {
        return DFS(root, 1);
    }

    // A better one
    int minDepth(TreeNode *root) {
        if(!root) return 0;
        if(!root->left) return 1 + minDepth(root->right);
        if(!root->right) return 1 + minDepth(root->left);
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
};