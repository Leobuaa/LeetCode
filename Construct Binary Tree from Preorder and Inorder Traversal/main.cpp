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
};