class Solution {
public:
	// O(1) space
    void rotate(vector<int>& nums, int k) {
        k %= (int)nums.size();
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }

    // O(n) space
    void rotate(vector<int>& nums, int k) {
        int size = int(nums.size());
        k %= size;
        if (k == 0) return;
        
        if (k < size / 2)
        {
            nums.insert(nums.begin(), nums.begin() + size - k, nums.begin() + size);
            nums.erase(nums.end() - k, nums.end());
        } else
        {
            nums.insert(nums.end(), nums.begin(), nums.begin() + size - k);
            nums.erase(nums.begin(), nums.begin() + size - k);
        }
    }
};