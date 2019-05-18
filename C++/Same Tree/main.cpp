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
	// Recursive 
    bool isSameTree(TreeNode* p, TreeNode* q) {
    	if (!p || !q) return p==q;
    	return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    // Non-revursive
    bool isSameTree(TreeNode* p, TreeNode* q) {
    	if (!p || !q) {
    		return p == q;
    	}

    	stack<TreeNode*> sta;
    	sta.push(p);
    	sta.push(q);
    	while (!sta.empty()) {
    		TreeNode* node1 = sta.top();
    		sta.pop();
    		TreeNode* node2 = sta.top();
    		sta.pop();
    		if (node1 && node2) {
    			if (node1->val == node2->val) {
    				sta.push(node1->left);
    				sta.push(node2->left);
    				sta.push(node1->right);
    				sta.push(node2->right);
    			} else {
    				return false;
    			}
    		} else if (!node1 && !node2) {
    			continue;
    		} else {
    			return false;
    		}
    	}

    	return true;
    }
};