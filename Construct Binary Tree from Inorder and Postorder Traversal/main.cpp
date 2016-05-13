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
    TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder, int postLeft, int postRight, int inLeft, int inRight) {
        TreeNode* res = NULL;
        if (postLeft > postRight) {
            return res;
        }
        
        res = new TreeNode(postorder[postRight]);
        int mid = inLeft;
        while (mid <= inRight && inorder[mid] != postorder[postRight]) {
            mid++;
        }
        int leftCnt = mid - inLeft, rightCnt = inRight - mid;
        if (leftCnt > 0) { 
            res->left = buildTree(postorder, inorder, postLeft, postLeft + leftCnt - 1, inLeft, mid - 1);
        }
        
        if (rightCnt > 0) {
            res->right = buildTree(postorder, inorder, postLeft + leftCnt, postRight - 1, mid + 1, inRight);
        }
        return res;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* res = buildTree(postorder, inorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
        return res;
    }
};