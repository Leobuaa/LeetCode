class Solution {
public:
    // It runs 40ms.
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum = (C - A) * (D - B) + (G - E) * (H - F);
        if (A >= G || B >= H || C <= E || D <= F)
            return sum;
        vector<int> height = {B, D, F, H};
        vector<int> width = {A, C, E, G};
        
        sort (height.begin(), height.end());
        sort (width.begin(), width.end());
        return sum - (height[2] - height[1]) * (width[2] - width[1]);
    }

    // This one looks better.
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum = (C - A) * (D - B) + (G - E) * (H - F);
        if (A >= G || B >= H || C <= E || D <= F)
            return sum;
        int left = max(A, E), right = min(C, G);
        int bottom = max(B, F), top = min(D, H);
        
        return sum - (right - left) * (top - bottom);
    }

    // It runs 36ms.
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum = (C - A) * (D - B) + (G - E) * (H - F);
        int left = max(A, E), right = max(left, min(C, G));
        int bottom = max(B, F), top = max(bottom, min(D, H));
        
        return sum - (right - left) * (top - bottom);
    }
};