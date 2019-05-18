class Solution {
public:
    void sift(vector<int>& nums, int low, int high) {
        int i = low, j = 2 * i + 1;
        while (j < high) {
            if (j < high - 1 && nums[j] < nums[j + 1]) {
                j++;
            }
            
            if (nums[i] < nums[j]) {
                swap(nums[i], nums[j]);
            } else {
                break;
            }
            
            i = j;
            j = 2 * i + 1;
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = n >> 1; i >= 0; i--) {
            sift(nums, i, n);
        }
        
        int res = nums[0];
        for (int i = 1; i < k; i++) {
            swap(nums[0], nums[n - i]);
            sift(nums, 0, n - i);
            res = nums[0];
        }
        
        return res;
    }
};