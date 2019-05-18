class Solution {
public:
    struct TreeNode {
        TreeNode *next[2];
        TreeNode() {
            this->next[0] = NULL;
            this->next[1] = NULL;
        }
    };
    
    void buildTree(int n, TreeNode *root) {
        int mask = 1 << 30;
        TreeNode *cur = root;
        for (int i = 1; i <= 31; i++) {
           if (mask & n) {
               if (cur->next[1]) {
                   cur = cur->next[1];
               } else {
                   cur->next[1] = new TreeNode();
                   cur = cur->next[1];
               }
           } else {
               if (cur->next[0]) {
                   cur = cur->next[0];
               } else {
                   cur->next[0] = new TreeNode();
                   cur = cur->next[0];
               }
           }
           mask >>= 1;
        }
    }
    
    int findMaximumXOR(vector<int>& nums) {
        TreeNode *root = new TreeNode();
        for (int n : nums) {
            buildTree(n, root);
        }
        
        int res = 0;
        for (int n : nums) {
            int find = n ^ INT32_MAX;
            int tmp = 0, mask = 1 << 30;
            TreeNode *cur = root;
            for (int i = 1; i <= 31; i++) {
                if (cur->next[((find & mask) != 0)]) {
                    tmp |= mask;
                    cur = cur->next[((find & mask) != 0)];
                } else {
                    cur = cur->next[((find & mask) == 0)];
                }
                mask >>= 1;
            }
            res = max(res, tmp);
        }
        
        return res;
    }
};