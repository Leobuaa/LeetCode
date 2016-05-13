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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preLeft, int preRight, int inLeft, int inRight) {
        TreeNode* res = NULL;
        if (preLeft > preRight) {
            return res;
        }
        
        res = new TreeNode(preorder[preLeft]);
        int mid = inLeft;
        while (mid <= inRight && inorder[mid] != preorder[preLeft]) {
            mid++;
        }
        int leftCnt = mid - inLeft, rightCnt = inRight - mid;
        if (leftCnt > 0) { 
            res->left = buildTree(preorder, inorder, preLeft + 1, preLeft + leftCnt, inLeft, mid - 1);
        }
        
        if (rightCnt > 0) {
            res->right = buildTree(preorder, inorder, preLeft + leftCnt + 1, preRight, mid + 1, inRight);
        }
        return res;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* res = buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
        return res;
    }

    // Recursive method. It runs 16ms.
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* res = NULL;
        if (preorder.size() <= 0) {
            return res;
        }
        stack<TreeNode*> sta;
        res = new TreeNode(preorder[0]);
        sta.push(res);
        int index = 0;
        for (int i = 1; i < preorder.size(); i++) {
            TreeNode* top = sta.top();
            if (top->val != inorder[index]) {
                top->left = new TreeNode(preorder[i]);
                sta.push(top->left);
            } else {
                while (!sta.empty() && sta.top()->val == inorder[index]) {
                    top = sta.top();
                    sta.pop();
                    index++;
                }
                top->right = new TreeNode(preorder[i]);
                sta.push(top->right);
            }
        }
        return res;
    }
};