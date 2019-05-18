int rob(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) {
            return size ? nums[0] : 0;
        }
        
        return max(rob(nums, 0, size - 2), rob(nums, 1, size - 1));
    }
    
    int rob(vector<int>& nums, int l, int r) {
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++) {
            int tmp = max(pre + nums[i], cur);
            pre = cur;
            cur = tmp;
        }
        
        return cur;
    }