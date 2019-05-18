class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (sx < tx && sy < ty) {
            if (tx < ty) {
                ty %= tx;
            } else {
                tx %= ty;
            }
        }
        
        if (sx == tx) {
            return (ty - sy) % sx == 0;
        }
        if (sy == ty) {
            return (tx - sx) % sy == 0;
        }
        return false;
    }
};