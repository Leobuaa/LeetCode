class Solution {
public:
/**
 * [trap description]
 * @param  height [description]
 * @return        [description]
 */
int trap(vector<int>& height) {
    int length = (int) height.size();
    int l = 0, r = length - 1;
    int res = 0, level = 0;
    while (l <= r)
    {
        int lower = height[height[l] < height[r] ? l++ : r--];
        level = max(level, lower);
        res += (level - lower);
    }
    return res;
}
};