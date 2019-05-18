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
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        TreeNode* p = root;
        vector<TreeNode*> sta;
        int count = 0;
        while (!sta.empty() || p)
        {
            while (p)
            {
                sta.push_back(p);
                p = p->left;
            }
            
            p = sta.back();
            sta.pop_back();
            count++;
            if (count == k) {
                res = p->val;
                break;
            }
                
            p = p->right;
        }
        return res;
    }
};