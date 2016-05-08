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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*, int>> que;
        vector<int> res;
        int cnt = 0;
        if (root) {
            que.push(make_pair(root, 1));
        }
        
        while (!que.empty()) {
            auto tmp = que.front();
            que.pop();
            if (tmp.second > cnt) {
                res.push_back(tmp.first->val);
                cnt++;
            } else {
                res[cnt - 1] = tmp.first->val;
            }
            
            if (tmp.first->left) {
                que.push(make_pair(tmp.first->left, tmp.second + 1));
            }
            
            if (tmp.first->right) {
                que.push(make_pair(tmp.first->right, tmp.second + 1));
            }
        }
        return res;
    }
};