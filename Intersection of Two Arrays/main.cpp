class Solution {
public:
    // Use STL, 16ms.
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> n1(nums1.begin(), nums1.end());
        set<int> n2(nums2.begin(), nums2.end());
        vector<int> res;
        for (int x1 : n1) {
            if (n2.find(x1) != n2.end()) {
                res.push_back(x1);
            }
        }
        return res;
    }
};