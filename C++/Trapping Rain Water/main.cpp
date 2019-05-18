class Solution {
public:
/**
 * [trap description]
 * @param  height [description]
 * @return        [description]
 */
// Less coder but a little bit difficult to understand
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

// More code but more clear
int trap(vector<int>& height) {
    int length = (int) height.size();
    int l = 0, r = length - 1;
    int maxLeft = 0, maxRight = 0;
    int res = 0;
    while (l <= r)
    {
        if (height[l] <= height[r])
        {
            if (height[l] > maxLeft)
            {
                maxLeft = height[l];
            } else
            {
                res += maxLeft - height[l];
            }
            l++;
        } else
        {
            if (height[r] > maxRight)
            {
                maxRight = height[r];
            } else {
                res += maxRight - height[r];
            }
            r--;
        }
    }
    return res;
}
};