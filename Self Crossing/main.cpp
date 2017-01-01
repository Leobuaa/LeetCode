class Solution {
public:
    // My first solution. It could be more simple. I need to make the code better.
    // It runs 0 ms for the test case.
    bool isSelfCrossing(vector<int>& x) {
        if (x.size() < 4) {
            return false;
        }
        int sides[4] = {x[0], x[1], 0, 0};
        int i = 2;
        while (i < x.size()) {
            if (x[i] == sides[(i + 2) % 4] && sides[(i + 1) % 4] >= sides[(i + 3) % 4]) {
                return true;
            }
            
            if (x[i] > sides[(i + 2) % 4]) {
                if (sides[(i + 1) % 4] >= sides[(i + 3) % 4]) {
                    return true;
                }
            } else {
               if (sides[(i + 3) % 4] <= sides[(i + 1) % 4]) {
                   sides[i % 4] = x[i];
                   i++;
                   continue;
               }
            
               if ((x[i] + sides[(i + 4) % 4]) < sides[(i + 2) % 4]) {
                   sides[i % 4] = x[i];
                   i++;
                   if (i < x.size() && x[i] >= sides[(i + 2) % 4]) {
                       return true;
                   }
               } else {
                   sides[i % 4] = x[i];
                   i++;
                   if (i < x.size() && (x[i] + sides[i % 4]) >= sides[(i + 2) % 4]) {
                       return true;
                   }
               }
            }
            if (i >= x.size()) {
                break;
            }
            sides[i % 4] = x[i];
            i++;
        }
        return false;
    }
};