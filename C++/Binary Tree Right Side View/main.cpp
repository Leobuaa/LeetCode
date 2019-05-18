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
    // My own solution uses queue.
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

    // A better and simple solution. DFS
    void dfs(TreeNode* node, int level, vector<int> &res) {
        if (!node) {
            return;
        }
        
        if (level >= res.size()) {
            res.push_back(node->val);
        }
        
        dfs(node->right, level + 1, res);
        dfs(node->left, level + 1, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};