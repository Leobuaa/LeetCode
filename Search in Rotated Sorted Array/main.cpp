class Solution {
public:
    int search(vector<int>& nums, int l, int r, int target) {
        int low = l, high = r;
        int mid = (low + high) >> 1;
        while (low <= high) {
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            mid = (low + high) >> 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        } 
        
        if (nums.size() == 1) {
            return target == nums[0] ? 0 : -1;
        }
        
        int pivotPos = 0;
        queue<pair<int, int>> que;
        que.push(make_pair(0, nums.size() - 1));
        while (!que.empty()) {
            auto tmp = que.front();
            que.pop();
            int l = tmp.first, r = tmp.second, mid = (l + r) >> 1;
            if (l >= r) {
                continue;
            }
            if (l - r == 1 && nums[l] > nums[r]) {
                pivotPos = r;
                break;
            }
            
            if (mid > l && nums[mid - 1] > nums[mid]) {
                pivotPos = mid;
                break;
            }
            
            if (nums[mid] > nums[mid + 1]) {
                pivotPos = mid + 1;
                break;
            }
            
            que.push(make_pair(l, mid - 1));
            que.push(make_pair(mid + 1, r));
        }
        
        int res = search(nums, 0, pivotPos - 1, target);
        return res == -1 ? search(nums, pivotPos, nums.size() - 1, target) : res;
    }
    
};