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
    TreeNode* clone(TreeNode* p) {
        if (!p) {
            return NULL;
        }
        TreeNode* cl = new TreeNode(p->val);
        cl->left = clone(p->left);
        cl->right = clone(p->right);
        return cl;
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n == 0) {
            return res;
        }
        res.push_back(new TreeNode(1));
        
        for (int i = 2; i <= n; i++) {
            vector<TreeNode*> temp;
            int len = (int) res.size();
            for (int j = 0; j < len; j++) {
                TreeNode* p1 = new TreeNode(i);
                p1->left = clone(res[j]);
                temp.push_back(p1);
                
                TreeNode* q = res[j];
                while (q) {
                    TreeNode* p2 = clone(res[j]);
                    TreeNode* cp2 = p2;
                    while (p2->val != q->val) {
                        p2 = p2->right;
                    }
                    TreeNode* ins = new TreeNode(i);
                    ins->left = p2->right;
                    p2->right = ins;
                    temp.push_back(cp2);
                    q = q->right;
                }
            }
            res = temp;
        }
        
        return res;
    }
};