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
    // Iteratively
    bool isSymmetric(TreeNode* root) {
        if (!root)  return true;
        TreeNode* leftNode = root->left, * rightNode = root->right;
        queue<TreeNode*> que;
        que.push(leftNode);
        que.push(rightNode);
        while (!que.empty()) {
            TreeNode* n1 = que.front();
            que.pop();
            TreeNode* n2 = que.front();
            que.pop();
            if (n1 && !n2) {
                return false;
            }
            if (n2 && !n1) {
                return false;
            }
            if (n1 && n2) {
                if (n1->val != n2->val) {
                    return false;
                }
                que.push(n1->left);
                que.push(n2->right);
                que.push(n1->right);
                que.push(n2->left);
            }
        }
        
        return true;
    }

    // Recursively
    bool isMirror(TreeNode* n1, TreeNode* n2) {
        if (!n1 || !n2) {
            return n1 == n2;
        }
        return (n1->val == n2->val) && isMirror(n1->left, n2->right) && isMirror(n1->right, n2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isMirror(root->left, root->right);
    }
};