class NumArray {
public:
    struct TreeNode {
        int value, start, end;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int v, int s, int e) : value(v), start(s), end(e), left(NULL), right(NULL) {}
    };

    TreeNode *root;

    NumArray(vector<int> nums) {
        int size = nums.size();
        if (size <= 0) {
            return;
        }
        root = build(nums, 0, size - 1);
    }
    
    void update(int i, int val) {
        int num = sumRange(i, i);
        int change = val - num;
        
        TreeNode *cur = root;
        while (cur) {
            cur->value += change;
            int mid = (cur->start + cur->end) >> 1;
            if (i <= mid) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
    }
    
    int sumRange(int i, int j) {
        return sum(i, j, root);
    }
    
    int sum(int i, int j, TreeNode* node) {
        if (i > j || !node) {
            return 0;
        }
        
        if (node->start == i && node->end == j) {
            return node->value;
        }
        
        int mid = (node->start + node->end) >> 1;
        if (i > mid) {
            return sum(i, j, node->right);
        }
        if (j <= mid) {
            return sum(i, j, node->left);
        }
        return sum(i, mid, node->left) + sum(mid + 1, j, node->right);
    }
    
    TreeNode *build(vector<int> &nums, int l, int r) {
        TreeNode *root = NULL;
        
        if (l < r) {
            int mid = (l + r) >> 1;
            root = new TreeNode(0, l, r);
            root->left = build(nums, l, mid);
            root->right = build(nums, mid + 1, r);
            root->value = root->left->value + root->right->value;
        } else if (l == r) {
            root = new TreeNode(nums[l], l, r);
        }
        
        return root;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */