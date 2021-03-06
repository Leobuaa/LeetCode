class Solution {
public:
    // From leetcode discuss. It runs 6ms. More simple and clear.
    int thirdMax(vector<int>& nums) {
        int a, b, c;
        a = b = c = INT32_MIN;
        int minNum = INT32_MAX;
        for (int num : nums) {
            minNum = min(num, minNum);
            if (num <= c || num == b || num == a) {
                continue;
            }
            c = num;
            if (c > b) {
                swap(b, c);
            }
            
            if (b > a) {
                swap(a, b);
            }
        }
        
        return (c >= minNum && b > c)? c : a;
    }

    // My solution. It runs 9ms. Not so good.
    int thirdMax(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        
        vector<int> res = {nums[0]};
        
        for (int i = 1; i < nums.size(); i++) {
            bool flag = false;
            for (int j = 0; j < res.size(); j++) {
                if (nums[i] == res[j]) {
                    flag = true;
                }
            }
            
            if (flag) {
                continue;
            }
            
            if (nums[i] < res[res.size() - 1] && res.size() < 3) {
                res.push_back(nums[i]);
                continue;
            }
            
            for (int j = 0; j < res.size(); j++) {
                if (nums[i] > res[j]) {
                    res.insert(res.begin() + j, nums[i]);
                    break;
                }
            }
            
            if (res.size() > 3) {
                res.erase(res.begin() + 3);
            }
        }
        
        if (res.size() == 3) {
            return res[2];
        }
        
        return res[0];
    }
};