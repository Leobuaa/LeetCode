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
    vector<int> postorderTraversal(TreeNode* root) {
    	vector<int> res;
    	if (!root) {
    		return res;
    	}

    	stack<TreeNode*> sta;
    	TreeNode* curNode = root, *preNode = NULL;
    	while (!sta.empty() || curNode) {
    		while (curNode) {
    			sta.push(curNode);
    			curNode = curNode->left;
    		}

    		TreeNode* topNode = sta.top();
    		if (topNode->right && topNode->right != preNode) {
    			curNode = topNode->right;
    		} else {
    			res.push_back(topNode->val);
    			preNode = topNode;
    			sta.pop();
    		}
    	}

    	return res;
    }
};