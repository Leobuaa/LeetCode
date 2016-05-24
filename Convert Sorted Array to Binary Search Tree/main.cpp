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
    void createBST(TreeNode* &root, vector<int>& nums, int l, int r)
    {
        if (l >= r)
            return;
        int mid = l + ((r - l) >> 1);
        root = new TreeNode(nums[mid]);
        createBST(root->left, nums, l, mid);
        createBST(root->right, nums, mid + 1, r);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = NULL;
        int size = nums.size();
        if (size == 0)  return root;
        createBST(root, nums, 0, size);
        return root;
    }
};