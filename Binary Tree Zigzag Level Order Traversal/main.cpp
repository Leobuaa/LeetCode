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
    // Use the pair struct. There is a better solution use just queue<TreeNode*>
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<pair<TreeNode*, bool>> que;
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        
        que.push(make_pair(root, true));
        vector<int> tmp;
        bool pre = true;
        while (!que.empty()) {
            auto top = que.front();
            que.pop();
            
            if (pre != top.second) {
                if (!pre) {
                    reverse(tmp.begin(), tmp.end());
                }
                res.push_back(tmp);
                tmp.clear();
            }
            
            tmp.push_back(top.first->val);
            pre = top.second;
            
            if (top.first->left) {
                que.push(make_pair(top.first->left, !pre));
            }
            if (top.first->right) {
                que.push(make_pair(top.first->right, !pre));
            }
        }
        
        if (!pre) {
            reverse(tmp.begin(), tmp.end());
        }
        
        res.push_back(tmp);
        
        return res;
    }

    // A better one solution.
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        
        queue<TreeNode*> que;
        bool leftToRight = true;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> tmp(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                
                int index = leftToRight ? i : (size - i - 1);
                tmp[index] = node->val;
                
                if (node->left) {
                    que.push(node->left);
                }
                
                if (node->right) {
                    que.push(node->right);
                }
            }
            leftToRight = !leftToRight;
            res.push_back(tmp);
        }
        
        return res;
    }
};