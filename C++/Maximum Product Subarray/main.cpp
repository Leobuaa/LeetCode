class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = (int) nums.size();
        if (len <= 0) {
            return 0;
        }
        
        int res = nums[0];
        
        int frontProduct = 1, backProduct = 1;
        
        for (int i = 0; i < len; i++) {
            frontProduct *= nums[i];
            backProduct *= nums[len - 1 - i];
            res = max(res, max(frontProduct, backProduct));
            
            frontProduct = frontProduct == 0 ? 1 : frontProduct;
            backProduct = backProduct == 0 ? 1 : backProduct;
        }
        
        return res;
    }
};